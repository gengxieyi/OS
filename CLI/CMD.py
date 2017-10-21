import sys
import socket

class Command(object):
    def __init__(self,op,ip,port,disks):
        self.op = op
        self.ip = ip
        self.port = port
        self.disks = disks

    def execute(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((self.ip,int(self.port)));
        buf = self.op
        for disk in disks:
            buf += " " + disk
        s.send(buf);
        result = s.recv(1024);
        print result

    def output(self):
        print self.op
        print self.ip
        print self.port
        print self.disks

if __name__ == "__main__":
    if len(sys.argv) < 5:
        print "error"
    else :
        op = sys.argv[1]
        ip = sys.argv[2]
        port = sys.argv[3]
        disks = sys.argv[4:]
        command = Command(op,ip,port,disks)
        command.execute()
