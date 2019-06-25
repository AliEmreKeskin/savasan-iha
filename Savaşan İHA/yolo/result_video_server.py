import cv2
import numpy as np
from timeit import default_timer as timer
import socket
import threading
import zmq
import base64

# socket init
context = zmq.Context()
footage_socket = context.socket(zmq.PUB)
footage_socket.bind('tcp://*:6666')

while(True):
    image=cv2.imread("image.jpg",cv2.IMREAD_GRAYSCALE )
    image = cv2.resize(image, (640, 480))
    encoded, buffer = cv2.imencode('.jpg', image)
    jpg_as_text = base64.b64encode(buffer)
    footage_socket.send(jpg_as_text)