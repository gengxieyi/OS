#include "ResponseManager.hpp"
#include "Responser.hpp"

int ResponseManager::Init()
{
    for (int i = 0; i < mThreadCount;i++)
    {
        Worker* worker = new Responser();
        mWorkerMap.insert(std::make_pair(i,worker));
    }
    return 0;
}
