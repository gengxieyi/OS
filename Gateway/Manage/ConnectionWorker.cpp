#include "ConnectionWorker.hpp"
#include "../../Common/Connection.hpp"
#include "../../Common/Common.hpp"
#include "../../Common/Request.hpp"
#include "../../Common/CommonDefine.hpp"

ConnWorker::ConnWorker() {
    mFD = SocketCreate(MANAGE_PORT);
}

void* ConnWorker::Entry() {
    while (1) {
        Connection* conn = SocketAccept(mFD);
        if (conn != NULL) {
            std::cout << "get a conn" << std::endl;
            std::cout << "ip : " << conn->GetIP() << std::endl;
            std::cout << "port : " << conn->GetPort() << std::endl;
            mLocker.Lock();
            mConnMap.insert(std::make_pair(conn->GetFD(),conn));
            mLocker.Unlock();
        }

        mLocker.Lock();
        for (std::map<int,Connection*>::iterator iter = mConnMap.begin();
                iter != mConnMap.end();) {
        }
        mLocker.Unlock();
        usleep(SLEEP_TIME);
    }
}

