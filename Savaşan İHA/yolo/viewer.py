import socket
import threading
import sys
import zmq
import base64
import numpy as np
import cv2

address=sys.argv[1]
context = zmq.Context()
footage_socket = context.socket(zmq.SUB)
footage_socket.connect('tcp://'+address+':6666')
footage_socket.setsockopt_string(zmq.SUBSCRIBE, np.unicode(''))

while True:
    try:
        frame = footage_socket.recv_string()
        img = base64.b64decode(frame)
        npimg = np.fromstring(img, dtype=np.uint8)
        source = cv2.imdecode(npimg, 1)
        cv2.imshow("Stream", source)
        cv2.waitKey(1)

    except KeyboardInterrupt:
        cv2.destroyAllWindows()
        break