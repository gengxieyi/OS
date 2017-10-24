#ifndef WORKER_MANAGER_HPP_
#define WORKER_MANAGER_HPP_
#include "ConnectionWorker.hpp"

class WorkerManager {
    public :
        WorkerManager(){
            mConnWorker = new ConnWorker();
        }
        ~WorkerManager(){
            delete mConnWorker;
        }
        void Start() {
            mConnWorker->Start();
        }
        ConnWorker* GetConnWorker() {
            return mConnWorker;
        }
        static WorkerManager* Instance() {
            static WorkerManager* ins = new WorkerManager();
            return ins;
        }
    private :
        ConnWorker* mConnWorker;
};

#endif
