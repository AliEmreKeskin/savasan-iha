import socket
import threading
import sys

class ChatClient:
    sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    def __init__(self,address):
        self.sock.connect((address,10000))

        while True:
            data=self.sock.recv(1024)
            if not data:
                break
            print(str(data,'utf-8'))
            #angle_x, angle_y = data.split(";")

client=ChatClient(sys.argv[1])