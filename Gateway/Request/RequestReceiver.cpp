#include "RequestReceiver.hpp"
#include "../../Common/Connection.hpp"
#include "../../Common/Common.hpp"
#include "../../Common/Request.hpp"
#include "../../Common/OpCtx.hpp"
#include "../Main/WorkerManager.hpp"

RequestReceiver::RequestReceiver() {
    mFD = SocketCreate(REQUEST_PORT);
}

void* RequestReceiver::Entry() {
    while (1) {
        Connection* conn = SocketAccept(mFD);
        if (conn != NULL) {
            OpCtx* ctx = new OpCtx(conn);
            PostConn(ctx);
        }
        usleep(SLEEP_TIME);
    }
}

void RequestReceiver::PostConn(OpCtx* ctx)
{
    WorkerManager::Instance()->GetRequestManager()->PostRequest(ctx);
}

