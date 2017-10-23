#include "Common.hpp"
#include "Connection.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>

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
	int client_st;
	struct sockaddr_in client_sockaddr;
	socklen_t len = sizeof(client_sockaddr);

	memset(&client_sockaddr, 0, sizeof(client_sockaddr));

	client_st = accept(st, (struct sockaddr *) &client_sockaddr, &len);
	if (client_st == -1)
	{
	    std::cout << "accept failture : " << strerror(errno);
		return 0;
	} else {
        conn = new Connection(client_st,inet_ntoa(client_sockaddr.sin_addr),client_sockaddr.sin_port);
    }
    return conn;
}

