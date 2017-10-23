#include "Common.hpp"
#include "Connection.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include "Request.hpp"

int SocketCreate(int port) 
{
	int st = socket(AF_INET, SOCK_STREAM, 0);
	int on = 1;
	if (st == -1)
	{
        std::cout << "socker error : " << strerror(errno);
		return 0;
	}
	if (setsockopt(st, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
	{
        std::cout << "setsockopt failed : " << strerror(errno);
		return 0;
	}

	struct sockaddr_in sockaddr;
	memset(&sockaddr, 0, sizeof(sockaddr));
	sockaddr.sin_port = htons(port);
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if (bind(st, (struct sockaddr *) &sockaddr, sizeof(sockaddr)) == -1)
	{
        std::cout<< "bind error : " << strerror(errno);
		return 0;
	}

	if (listen(st, 100) == -1)
	{
		std::cout<< "listen failed : " << strerror(errno);
		return 0;
	}
	return st;
}

Connection* SocketAccept(int st)
{
    Connection* conn = NULL;
    fd_set fds;
    struct timeval timeout={0,0};
	int client_st;
	struct sockaddr_in client_sockaddr;
	socklen_t len = sizeof(client_sockaddr);
    FD_SET(st,&fds);
	memset(&client_sockaddr, 0, sizeof(client_sockaddr));

    int ret = select(st + 1,&fds,NULL,NULL,&timeout);
    if (ret == -1) {
	    std::cout << "select failture : " << strerror(errno);
    } else if (ret == 0) {
	    std::cout << "time out" << std::endl;
    } else if (FD_ISSET(st,&fds)) {
	    client_st = accept(st, (struct sockaddr *) &client_sockaddr, &len);
	    if (client_st == -1)
	    {
	        std::cout << "accept failture : " << strerror(errno);
	    } else {
            conn = new Connection(client_st,inet_ntoa(client_sockaddr.sin_addr),client_sockaddr.sin_port);
        }
    }
    return conn;
}

int ReadRequest(int st,Request*& req)
{
    char buf[1024];
    int ret = recv(st,buf,1024,MSG_DONTWAIT);
    if (ret > 0) {
        for (int i = 0;i < ret;i++) {
            printf("%d\n",buf[i]);
        }
        ParseToRequest(buf,req);
    }
    return ret;
}

void ParseToRequest(char* buf,Request*& req)
{
    req = new Request;
    int* op = (int*) buf;
    buf += 4;
    int* keysize = (int*)buf;
    buf += 4;
    req->mKey = std::string(buf,*keysize);
    buf += *keysize;
    int* valuesize= NULL;
    switch (*op) {
        case ePut :
            valuesize = (int*) buf;
            buf += 4;
            req->mValue = std::string(buf,*valuesize);
            buf += *valuesize;
            break;
        case eGet :
            break;
        case eDelete :
            break;
        default :
            break;
    }
}
