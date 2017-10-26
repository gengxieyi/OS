#include "Server.hpp"
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

int Server::Start() {
    for (int i = 0; i < mThreadCount; i++) {
        Worker* worker = mWorkerMap[i];
        worker->Start();
    }
    return 0;
}

int Server::PostRequest(OpCtx* ctx) {
    mWorkerMap[mIndex]->PostRequest(ctx);
    mIndex = (mIndex + 1) % mThreadCount;
    return 0;
}

