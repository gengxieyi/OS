#include "ConnectionWorker.hpp"
#include "../Common/Connection.hpp"
#include "../Common/Common.hpp"
#include "../Common/Request.hpp"

ConnWorker::ConnWorker() {
    mFD = SocketCreate(LISTEN_PORT);
}

void* ConnWorker::Entry() {
    while (1) {
        Connection* conn = SocketAccept(mFD);
        if (conn != NULL) {
            std::cout << "get a conn" << std::endl;
            std::cout << "ip : " << conn->GetIP() << std::endl;
            std::cout << "port : " << conn->GetPort() << std::endl;
            conn->SetFree();
            mLocker.Lock();
            mConnMap.insert(std::make_pair(conn->GetFD(),conn));
            mLocker.Unlock();
        }

        mLocker.Lock();
        for (std::map<gxy_int32_t,Connection*>::iterator iter = mConnMap.begin();
                iter != mConnMap.end();) {
            if (iter->second->Using()) {
                iter++;
            } else {
                int op = 0;
                Request* req = NULL;
                gxy_int32_t ret = ReadRequest(iter->first,req);
                if (ret == 0) {
                    std::cout << "close " << iter->first << std::endl;
                    close(iter->first);
                    delete iter->second;
                    mConnMap.erase(iter++);
                } else if (ret < 0) {
                    std::cout << "no data : " << iter->second->GetIP() << std::endl;
                    iter++;
                } else {
                    if (req != NULL) {
                        std::cout << req->mKey << ":" << req->mValue << std::endl;
                    }
                    iter++;
                }
            }
        }
        mLocker.Unlock();
        usleep(3000000);
    }
}

void ConnWorker::SetFree(gxy_int32_t fd) {
    mLocker.Lock();
    std::map<gxy_int32_t,Connection*>::iterator iter =
        mConnMap.find(fd);
    if (iter != mConnMap.end()) {
        iter->second->SetFree();
    }
    mLocker.Unlock();
}
