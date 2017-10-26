#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include <string>
#include <iostream>
#include "CommonDefine.hpp"
#include <sys/socket.h>
#include <unistd.h>

class Connection {
    private :
        int mClientSocket;
        std::string mIP;
        unsigned short mPort;
        int mStatus;
    public :
        Connection(int st,char* ip,unsigned short port){
            mClientSocket = st;
            mIP = std::string(ip);
            mPort = port;
        }
        ~Connection();

        std::string GetIP() {
            return mIP;
        }
        unsigned short GetPort() {
            return mPort;
        }
        int GetFD() {
            return mClientSocket;
        }

};

#endif
