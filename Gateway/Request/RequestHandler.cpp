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
            usleep(1000);
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
        ProcessRequest(ctx);
    } else {
        std::cout << ret << std::endl;
        ctx->SetResult(1,"FAILED");
    }
    WorkerManager::Instance()->GetResponseManager()->PostRequest(ctx);    
}

void RequestHandler::ProcessRequest(OpCtx* ctx)
{
    Request* req = ctx->GetReq();
    int ret = 0;
    switch (req->mOpType) {
        case ePut :
            ret = Write(req);
            break;
        case eGet :
            ret = Read(req);
            break;
        case eDelete :
            Delete(req);
            break;
        default :
            break;
    }
    if (ret) {
        ctx->SetResult(ret,"failed");
    } else {
        ctx->SetResult(ret,"success");
    }
}

int RequestHandler::Write(Request* req)
{

    int ret = mDB.Write(req->mKey,req->mValue);
    if (ret == 0) {
        return 0;
    } else {
        std::cout << "write failed : " << ret << std::endl;
        return 1;
    }
}

int RequestHandler::Read(Request* req)
{
    req->mValue = mDB.Read(req->mKey);
    if (req->mValue != "") {
        return 0;
    } else {
        std::cout << "read failed" << std::endl;
        return 1;
    }
}

int RequestHandler::Delete(Request* req)
{
    return 0;
}
