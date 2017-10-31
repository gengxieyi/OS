#include "Common.hpp"
#include "Connection.hpp"
#include "OpCtx.hpp"
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
        std::cout<< "port : " << port;
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

int ReadRequest(int st,Request* req)
{
    char buf[1024];
    int count = 0;
    int ret = recv(st,buf,1024,MSG_DONTWAIT);
    count++;
    while (ret < 0 && count < TRY_COUNT) {
        ret = recv(st,buf,1024,MSG_DONTWAIT);
        count++;
        usleep(1000);
    }
    if (ret > 0) {
        ParseToRequest(buf,req);
    }

    return ret;
}

void ParseToRequest(char* buf,Request* req)
{
    int* op = (int*) buf;
    req->mOpType = *op;
    buf += 4;
    switch (*op) {
        case ePut :
            ReadPutRequest(buf,req);
            break;
        case eGet :
            ReadGetRequest(buf,req);
            break;
        case eDelete :
            ReadDeleteRequest(buf,req);
            break;
        case eAddServer :
            ReadAddServerRequest(buf,req);
            break;
        case eQueryServer :
            ReadQueryServerRequest(buf,req);
            break;
        case eAddReplica :
            ReadAddReplicaRequest(buf,req);
            break;
        default :
            break;
    }
}

void ReadPutRequest(char* buf,Request* req)
{
    int* keysize = (int*)buf;
    buf += 4;
    req->mKey = std::string(buf,*keysize);
    buf += *keysize;
    int* valuesize =  (int*) buf;
    buf += 4;
    req->mValue = std::string(buf,*valuesize);
    buf += *valuesize;
}

void ReadGetRequest(char* buf,Request* req)
{
    int* keysize = (int*)buf;
    buf += 4;
    req->mKey = std::string(buf,*keysize);
    buf += *keysize;
}

void ReadDeleteRequest(char* buf,Request* req)
{
    int* keysize = (int*)buf;
    buf += 4;
    req->mKey = std::string(buf,*keysize);
    buf += *keysize;
}

void ReadAddServerRequest(char* buf,Request* req)
{
    int* ipsize = (int*)buf;
    buf += 4;
    req->mIP = std::string(buf,*ipsize);
    buf += *ipsize;
}

void ReadAddReplicaRequest(char* buf,Request* req)
{
    int* ipsize = (int*)buf;
    buf += 4;
    req->mIP = std::string(buf,*ipsize);
    buf += *ipsize;
    int* pathsize = (int*)buf;
    buf += 4;
    req->mPath = std::string(buf,*pathsize);
    buf += *pathsize;
}

void ReadQueryServerRequest(char* buf,Request* req)
{
}


int SendResponse(int st,OpCtx* ctx)
{
    if (ctx->GetReq()->mOpType == eGet) {
        ctx->SetResult(0,ctx->GetReq()->mValue);
    }
    int ret = send(st,ctx->GetErrStr().c_str(),ctx->GetErrStr().length(),0);
    return ret;
}
