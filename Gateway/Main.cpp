#include <iostream>
#include <stdlib.h>
#include "../Common/Common.hpp"
#include "../Common/Connection.hpp"
#include <unistd.h>
#include <iostream>
#define THREAD_NUM 5

int main(int argc,char *argv[])
{
	if(argc < 2) {
        std::cout << "usage:server port" << std::endl;
		return 0;
	}
	int port = atoi(argv[1]);

	if(port <= 0) {
        std::cout << "port must be positive integer" << std::endl;
		return 0;
	}

	int st = SocketCreate(port);
	if(st == 0) {
		return 0;
	}
    std::cout << "http server start successfully" << std::endl;
    while(1) {
	    Connection* conn = SocketAccept(st);
        if (conn == NULL) {
            std::cout << "get a client failed" << std::endl; 
            break;
        } else {
            std::cout << conn->GetIP() << std::endl; 
            std::cout << conn->GetPort() << std::endl; 
            conn->Read();
            close(conn->GetFD());
            delete conn;
        }
    }


	close(st);
    return 0;
};

