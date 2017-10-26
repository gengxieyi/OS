#include "RequestManager.hpp"
#include "RequestHandler.hpp"

int RequestManager::Init()
{
    for (int i = 0; i < mThreadCount;i++)
    {
        Worker* worker = new RequestHandler();
        mWorkerMap.insert(std::make_pair(i,worker));
    }
    return 0;
}
