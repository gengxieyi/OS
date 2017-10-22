#include "Connection.hpp"
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Common.hpp"

Connection::~Connection() {
    close(mClientSocket);
}

int Connection::ReadHeader() {
    mHeader = "";
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    close(mClientSocket);
	int rc = recv(mClientSocket, buf, sizeof(buf), 0);
    if (rc <= 0) {
        return -1;
    } else {	
        mHeader = std::string(buf,rc);
        std::cout << mHeader << std::endl;
    }
    return rc;
}

char* Connection::GetBlock(int& len) {
    char* buf = new char[BUFFER_SIZE];
    memset(buf, 0, BUFFER_SIZE);
	int rc = recv(mClientSocket, buf, BUFFER_SIZE, 0);
    if (rc <= 0) {
        return NULL;
    } else {
        len = rc;
        return buf;
    }

}
std::string Connection::GetHeader() {
    return mHeader;
}

int Connection::SendResponse(int err,int len) {
    std::stringstream ss;
    ss << "HTTP/1.1 " << err << " " << GetErrorString(err) << "\n";
    ss << "Content-Type: text/plain\n";
    ss << "Connection: Keep-Alive\n";
    ss <<"Accept-Ranges:bytes\n";
    ss << "Content-Length:" << len << "\n\n";
    
    return send(mClientSocket, ss.str().c_str(),ss.str().length(), MSG_NOSIGNAL);
}

int Connection::SendResponse(char* buf,int len) {
    return send(mClientSocket, buf,len, MSG_NOSIGNAL);
}

int Connection::ParseHeader() {
    int pos1 = mHeader.find(' ');
    if (pos1 == -1) {
        std::cout << "parse op type failed" << std::endl;
        return -1;
    }
    std::string op = mHeader.substr(0,pos1);
    if ( op == "PUT" ) { 
        mOpType = ePut;
    } else if (op == "GET") {
        mOpType = eGet;
    } else if (op == "DELETE") {
        mOpType = eDelete;
    } else if (op == "ADD") {
        SendResponse(200,0);
        return -1;
    } else {
        mOpType = 0;
        return -1;
    }
    int pos2 = mHeader.find(' ',pos1 + 1);
    if (pos2 == -1)  {
        std::cout << "parse path failed" << std::endl;
        return -1;
    }
    mPath = mHeader.substr(pos1 + 1,pos2 - pos1 - 1);

    if (mOpType == ePut) {
        int pos3 = mHeader.find("Content-Length");
        if (pos3 == -1) {
            std::cout << "parse content-length failed" << std::endl;
            return -1;
        }
        int pos4 = mHeader.find('\n',pos3);
        if (pos4 == -1) {
            std::cout << "parse content-length failed" << std::endl;
            return -1;
        }
        std::string length = mHeader.substr(pos3 + 16 , pos4 - pos3 - 16);
        mContentLength = atoi(length.c_str());

        int pos5 = mHeader.find("Expect",0);
        if (pos5 == -1) {
            mContent = mHeader.substr(mHeader.length() - mContentLength, mContentLength);
        } else {
            mContinue = true;
        }
    }
    return 0;
}
