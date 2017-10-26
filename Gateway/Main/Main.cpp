#include <iostream>
#include "WorkerManager.hpp"
int main(int argc,char *argv[])
{
    WorkerManager::Instance()->Start();
    return 0;
};

