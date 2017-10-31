#include "RequestHandler.hpp"
#include "ResponseManager.hpp"
#include "../../Common/Request.hpp"
#include "../../Common/OpCtx.hpp"
#include "../../Common/Common.hpp"
#include "../Main/WorkerManager.hpp"
#include <unistd.h>

void* RequestHandler::Entry()
{
    while (1) {
        if (mQueue.Empty()) {
            usleep(SLEEP_TIME);
        } else {
            OpCtx* ctx = NULL;
            mQueue.Dequeue(ctx);
            if (ctx != NULL) {
                ProcessConn(ctx);
            }
        }
    }
    
}

void RequestHandler::ProcessConn(OpCtx* ctx)
{
    Request* req = new Request;
    int ret = ReadRequest(ctx->GetConn()->GetFD(),req);
    ctx->SetReq(req);
    if ( ret > 0 ) {
        WorkerManager::Instance()->GetRWHandler()->PostRequest(ctx);    
    } else {
        std::cout << ret << std::endl;
        ctx->SetResult(1,"FAILED");
        WorkerManager::Instance()->GetResponseManager()->PostRequest(ctx);    
    }
}

