import sys
import socket
import struct
import datetime

class Command(object):
    def __init__(self,ip,port):
        self.ip = ip
        self.port = port

    def write(self):
        for i in range(10000) :
            key = "key" + str(i)
            value = "value" + str(i)
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.connect((self.ip,int(self.port)));
            pattern = "<ii"+str(len(key))+"si"+str(len(value))+"s"
            data = struct.pack(pattern,1,len(key),key,len(value),value);
            s.send(data);
            result = s.recv(1024);
            print result
    def read(self):
        for i in range(10000) :
            key = "key" + str(i)
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.connect((self.ip,int(self.port)));
            pattern = "<ii"+str(len(key))+"s"
            data = struct.pack(pattern,2,len(key),key);
            s.send(data);
            result = s.recv(1024);
            if result == "value" + str(i) :
                print "success"

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print "error"
    else :
        ip = sys.argv[1]
        port = sys.argv[2]
        op = sys.argv[3]

        command = Command(ip,port)
        print datetime.datetime.now()
        if op == "put" :
            command.write()
        elif op == "get" :
            command.read()
        print datetime.datetime.now()
