#include "Responser.hpp"
#include "../../Common/Common.hpp"
#include "../../Common/OpCtx.hpp"
#include "../../Common/Request.hpp"
#include "../../Common/Connection.hpp"
#include <unistd.h>

void* Responser::Entry()
{
    while (1) {
        if (mQueue.Empty()) {
            usleep(1000);
        } else {
            OpCtx* ctx = NULL;
            mQueue.Dequeue(ctx);
            if (ctx != NULL) {
                ProcessResponse(ctx);
            }
        }
    }
    
}

void Responser::ProcessResponse(OpCtx* ctx)
{
    int ret = SendResponse(ctx->GetConn()->GetFD(),ctx);
    delete ctx;
}
