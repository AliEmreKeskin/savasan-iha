import socket
import threading
import time

class ChatServer:
    sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    connections=[]

    def __init__(self):
        self.sock.bind(('0.0.0.0',10000))
        self.sock.listen(1)
        print("Server running on: ")
        print((([ip for ip in socket.gethostbyname_ex(socket.gethostname())[2] if not ip.startswith("127.")] or [[(s.connect(("8.8.8.8", 53)), s.getsockname()[0], s.close()) for s in [socket.socket(socket.AF_INET, socket.SOCK_DGRAM)]][0][1]]) + ["no IP found"])[0])
        

    def handler(self,c,a):
        while True:
            file=open("command.txt","r")
            data=file.readline()
            file.close()
            time.sleep(0.1)
            for connection in self.connections:
                connection.send(bytes(data,'utf-8'))

    def run(self):
        while True:
            c,a=self.sock.accept()
            cThread=threading.Thread(target=self.handler,args=(c,a))
            cThread.daemon=True
            cThread.start()
            self.connections.append(c)
            print(str(a[0])+':'+str(a[1]),"connected")

server=ChatServer()
server.run()