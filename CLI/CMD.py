import sys
import socket
import struct

class Command(object):
    def __init__(self,ip,port,op,key,value):
        self.ip = ip
        self.port = port
        self.op = op
        self.key = key
        self.value = value

    def execute(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((self.ip,int(self.port)));
        pattern = "<ii"+str(len(self.key))+"si"+str(len(self.value))+"s"
        print pattern
        data = struct.pack(pattern,int(self.op),len(self.key),self.key,len(self.value),self.value);
        s.send(data);

if __name__ == "__main__":
    if len(sys.argv) < 6:
        print "error"
    else :
        ip = sys.argv[1]
        port = sys.argv[2]
        op = sys.argv[3]
        key = sys.argv[4]
        value = sys.argv[5]
        command = Command(ip,port,op,key,value)
        command.execute()
