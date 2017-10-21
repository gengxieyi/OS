#include <iostream>
#include <stdlib.h>
#include "Common.hpp"
#include "Server.hpp"
#include "Connection.hpp"
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
    Server server(THREAD_NUM);
    server.Start();
    while(1) {
	    int client_st = SocketAccept(st);
	    close(client_st);
        if (client_st == 0) {
            std::cout << "get a client failed" << std::endl; 
            break;
        } else {
            std::cout << "get a client" << std::endl; 
        }


        Connection* conn = new Connection(client_st);
        OpCtx* ctx = new OpCtx(conn);
        server.ProcessRequest(ctx);
    }


	close(st);
    return 0;
};

