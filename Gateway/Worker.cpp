#include "Worker.hpp"
#include "OpCtx.hpp"
#include "Connection.hpp"
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include "Common.hpp"
#include "Server.hpp"

int Worker::Start() {
	pthread_t thrd_t;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	pthread_create(&thrd_t, &attr, _entry_func_, this);
}

void Worker::PostRequest(OpCtx* ctx) {
    mQueue.push(ctx);
}

int Worker::ProcessRequest(OpCtx* ctx) {
    int ret = 0;
    std::cout << "process a request" << std::endl;
    Connection* conn = ctx->GetConn();
    ret = conn->ReadHeader();
    if (ret == -1) {
        std::cout << "read header failed" << std::endl;
        return -1;  
    }
    ret = conn->ParseHeader();
    if (ret) {
        std::cout << "parse header failed,header : " << conn->GetHeader() << std::endl;
        return -1;  
    }
    switch (conn->GetOpType()) {
        case ePut :
            ProcessPutRequest(ctx);
            break;
        case eGet :
            ProcessGetRequest(ctx);
            break;
        case eDelete :
            ProcessDeleteRequest(ctx);
            break;
        default :
            break;
    }
    delete conn;
    delete ctx;

    return 0;
}

void* Worker::entry() {
    while(1) {
        OpCtx* ctx = NULL;
        while (mQueue.empty()) {
            usleep(100000);
        }
        ctx = mQueue.front();
        mQueue.pop();
        
        int ret = ProcessRequest(ctx);
        if (ret != 0) {
            std::cout << "process request error" <<std::endl;
        }
    }    
}

void Worker::ProcessPutRequest(OpCtx* ctx) {
    Connection* conn = ctx->GetConn();
    std::string path = WORK_BASE + conn->GetPath();
    int ret = CheckPutPath(path);
    if (ret) {
        conn->SendResponse(ret,0);
        return;
    }
    std::ofstream of;
    of.open(path.c_str());
    if (conn->GetContinue()) {
        int count = 0;
        int len = 0;
        while (count < conn->GetLength()) {
            char* buf = conn->GetBlock(len);
            if (buf) {
                of.write(buf,len);
                count += len;
                len = 0;
                delete[] buf;
            } else {
                conn->SendResponse(203,0);
                delete[] buf;
                of.close();
                return;
            }
        }
        of.close();
        conn->SendResponse(200,0);
    } else {
        of << conn->GetContent();
        of.close();
        conn->SendResponse(200,0);
    }
}

void Worker::ProcessGetRequest(OpCtx* ctx) {
    Connection* conn = ctx->GetConn();
    std::string path = WORK_BASE + conn->GetPath();
    char body[BUFFER_SIZE];
    memset(body,0,BUFFER_SIZE);
    std::ifstream ifs;
    ifs.open(path.c_str(),std::ios::in);
    if (!ifs) {
        conn->SendResponse(202,0);
        return;        
    } 
    ifs.seekg(0, std::ios_base::end);
    int len = ifs.tellg();
    conn->SendResponse(200,len);
    ifs.seekg(0, std::ios_base::beg);
    while (!ifs.eof()) {
        ifs.read(body,BUFFER_SIZE);
        if (len >= BUFFER_SIZE) {
            conn->SendResponse(body,BUFFER_SIZE);
            len -= BUFFER_SIZE;
        } else {
            conn->SendResponse(body,len);
            len = 0;
        }
        memset(body,0,BUFFER_SIZE);
    }
    ifs.close();
}

void Worker::ProcessDeleteRequest(OpCtx* ctx) {
    Connection* conn = ctx->GetConn();
    std::string path = WORK_BASE + conn->GetPath();
    int ret = CheckDeletePath(path);
    if (ret) {
        conn->SendResponse(ret,0);
        return;
    }
    remove(path.c_str());
    conn->SendResponse(200,0);
}

int Worker::CheckPutPath(const std::string& path) {
    std::vector<int> vec;
    std::ifstream ifs;
    ifs.open(path.c_str(),std::ios::in);
    if (!ifs) {
        int ret = path.find('/');
        while (ret != -1) {
            vec.push_back(ret);
            ret = path.find('/',vec.back() + 1);
        }
        for (int i = 1; i < vec.size(); i++) {
            mkdir(path.substr(0,vec[i]).c_str(),777);
        }
    } else {
        std::cout << "file " << path << " exist" << std::endl;
        ifs.close();
        return 201;
    }
    return 0;
}

int Worker::CheckDeletePath(const std::string& path) {
    std::ifstream ifs;
    ifs.open(path.c_str(),std::ios::in);
    if (!ifs) {
        std::cout << "file " << path << " not exist" << std::endl;
        return 202;
    }
    ifs.close();
    return 0;

}
