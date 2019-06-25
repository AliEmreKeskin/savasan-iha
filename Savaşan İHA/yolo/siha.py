import cv2
import numpy as np
from timeit import default_timer as timer
import socket
import threading
import zmq
import base64

def get_output_layers(net):    
    layer_names = net.getLayerNames()    
    output_layers = [layer_names[i[0] - 1] for i in net.getUnconnectedOutLayers()]
    return output_layers

def draw_prediction(img, class_id, confidence, x, y, x_plus_w, y_plus_h):
    label = str(classes[class_id])
    color = COLORS[class_id]
    cv2.rectangle(img, (x,y), (x_plus_w,y_plus_h), color, 2)
    cv2.putText(img, label, (x-10,y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)

# yolo init
configPath="uav-yolov3-tiny.cfg"
weightsPath="uav-yolov3-tiny.weights"
classesPath="uav-obj.names"
classes = None
with open(classesPath, 'r') as f:
    classes = [line.strip() for line in f.readlines()]
COLORS = None
COLORS = np.random.uniform(0, 255, size=(len(classes), 3))
net = cv2.dnn.readNet(weightsPath, configPath)

# tracker init
tracker = None
initBB = None

# camera init
camera_visual_angle_horizontal=130
camera_visual_angle_vertical=camera_visual_angle_horizontal/16*9
cap=cv2.VideoCapture(0)

# socket init
context = zmq.Context()
footage_socket = context.socket(zmq.PUB)
footage_socket.bind('tcp://*:5555')

# Status init
status="Detecting"
time1=timer()

# Loop
while(True):
    ret, image = cap.read()
    Width = image.shape[1]
    Height = image.shape[0]
    cx=Width/2
    cy=Height/2
    scale = 0.00392
    angle_x=0
    angle_y=0

    # Detecting
    if(status=="Detecting"):
        cv2.putText(image, "Detecting", (5,25), cv2.FONT_HERSHEY_SIMPLEX, 1, (255,255,255), 2)

        blob = cv2.dnn.blobFromImage(image, scale, (416,416), (0,0,0), True, crop=False)
        net.setInput(blob)
        outs = net.forward(get_output_layers(net))

        class_ids = []
        confidences = []
        boxes = []
        conf_threshold = 0.5
        nms_threshold = 0.4

        for out in outs:
            for detection in out:
                scores = detection[5:]
                class_id = np.argmax(scores)
                confidence = scores[class_id]
                if confidence > 0.5:
                    center_x = int(detection[0] * Width)
                    center_y = int(detection[1] * Height)
                    w = int(detection[2] * Width)
                    h = int(detection[3] * Height)
                    x = center_x - w / 2
                    y = center_y - h / 2
                    class_ids.append(class_id)
                    confidences.append(float(confidence))
                    boxes.append([x, y, w, h])

        indices = cv2.dnn.NMSBoxes(boxes, confidences, conf_threshold, nms_threshold)

        for i in indices:
            i = i[0]
            box = boxes[i]
            x = box[0]
            y = box[1]
            w = box[2]
            h = box[3]
            initBB=(x,y,w,h)
            draw_prediction(image, class_ids[i], confidences[i], round(x), round(y), round(x+w), round(y+h))

        
        if(len(indices)>0):
            bbcx=initBB[0]+initBB[2]/2
            bbcy=initBB[1]+initBB[3]/2
            cv2.line(image,(int(cx),int(cy)),(int(bbcx),int(bbcy)),(255,0,0),2)
            vx=bbcx-cx
            vy=cy-bbcy
            angle_x=(camera_visual_angle_horizontal/2)/(Width/2)*vx
            angle_y=(camera_visual_angle_vertical/2)/(Height/2)*vy
            time2=timer()
            print(time2-time1)
            time1=time2
            print("["+status+"]\t"+str(angle_x)+" , "+str(angle_y)+"\n")
            tracker=cv2.TrackerKCF_create()
            ok = tracker.init(image, initBB)
            status="Tracking"
        else:
            time2=timer()
            print(time2-time1)
            time1=time2
            print("["+status+"]\n")

    # Tracking
    elif(status=="Tracking"):
        cv2.putText(image, "Tracking", (5,25), cv2.FONT_HERSHEY_SIMPLEX, 1, (255,255,255), 2)
        (success, box) = tracker.update(image)
        if success:
            (x, y, w, h) = [int(v) for v in box]
            cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)
            bbcx=x+w/2
            bbcy=y+h/2
            cv2.line(image,(int(cx),int(cy)),(int(bbcx),int(bbcy)),(255,0,0),2)
            vx=bbcx-cx
            vy=cy-bbcy
            angle_x=(camera_visual_angle_horizontal/2)/(Width/2)*vx
            angle_y=(camera_visual_angle_vertical/2)/(Height/2)*vy
            time2=timer()
            print(time2-time1)
            time1=time2
            print("["+status+"]\t"+str(angle_x)+" , "+str(angle_y)+"\n")
        else:
            time2=timer()
            print(time2-time1)
            time1=time2
            print("["+status+"]\n")
            status="Detecting"
            initBB=None

    # Controlling Servos
    servo_command=str(angle_x)+";"+str(angle_y)
    file = open("command.txt", "w")
    file.write(servo_command+"\n")

    # Sending Video
    image = cv2.resize(image, (640, 480))
    encoded, buffer = cv2.imencode('.jpg', image)
    jpg_as_text = base64.b64encode(buffer)
    footage_socket.send(jpg_as_text)

    # Showing Video
    cv2.imshow("object detection", image)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cv2.waitKey()    
cap.release()
cv2.destroyAllWindows()