#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include <string>
#include <iostream>
#include "CommonDefine.hpp"
#include <sys/socket.h>
#include <unistd.h>

class Connection {
    private :
        gxy_int32_t mClientSocket;
        std::string mIP;
        gxy_uint16_t mPort;
    public :
        Connection(int st,char* ip,unsigned short port){
            mClientSocket = st;
            mIP = std::string(ip);
            mPort = port;
        }
        void Read() {
            while (1) {
            char buf[4];
	        int rc = recv(mClientSocket, buf, sizeof(buf), MSG_DONTWAIT);
            if (rc > 0) {
                std::cout << std::string(buf,rc) << std::endl;
            } else if (rc == 0) {
                break;
            }
            std::cout << rc << std::endl;
            usleep(1000000);
            }
        }

        std::string GetIP() {
            return mIP;
        }
        gxy_uint16_t GetPort() {
            return mPort;
        }
        gxy_int32_t GetFD() {
            return mClientSocket;
        }
        ~Connection();

};

#endif
