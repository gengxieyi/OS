import sys
import socket
import struct

class Command(object):
    def __init__(self,op,ip,port):
        self.op = op
        self.ip = ip
        self.port = port

    def execute(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((self.ip,int(self.port)));
        buf = int(op)
        st = struct.Struct('I')

        s.send(st.pack(buf));
        result = s.recv(1024);
        print result

    def output(self):
        print self.op
        print self.ip
        print self.port

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print "error"
    else :
        op = sys.argv[1]
        ip = sys.argv[2]
        port = sys.argv[3]
        command = Command(op,ip,port)
        command.execute()
