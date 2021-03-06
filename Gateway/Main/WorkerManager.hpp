#ifndef WORKER_MANAGER_HPP_
#define WORKER_MANAGER_HPP_
#include "../Request/RequestReceiver.hpp"
#include "../Request/RequestManager.hpp"
#include "../Request/ResponseManager.hpp"
#include "../Manage/RWHandler.hpp"
#include "../../Common/Worker.hpp"
#include "../../Common/CommonDefine.hpp"
#include <unistd.h>

class WorkerManager : Worker {
    public :
        WorkerManager(){
            mRequestReceiver = new RequestReceiver();
            mRWHandler = new RWHandler();
            mRequestManager = new RequestManager(REQUEST_HANDLER_NUM);
            mRequestManager->Init();
            mResponseManager = new ResponseManager(RESPONSER_NUM);
            mResponseManager->Init();
        }
        ~WorkerManager(){
            delete mRequestReceiver;
            delete mRWHandler;
            delete mRequestManager;
            delete mResponseManager;
        }
        void Start() {
            mRequestReceiver->Start();
            mRWHandler->Start();
            mRequestManager->Start();
            mResponseManager->Start();
            Entry();
        }
        RequestReceiver* GetRequestReceiver() {
            return mRequestReceiver;
        } 
        RWHandler* GetRWHandler() {
            return mRWHandler;
        }

        RequestManager* GetRequestManager() {
            return mRequestManager;
        }
        ResponseManager* GetResponseManager() {
            return mResponseManager;
        }
        static WorkerManager* Instance() {
            static WorkerManager* ins = new WorkerManager();
            return ins;
        }
    private :
        void* Entry() {
            while (1) {
                usleep(10000000);
            }
        }
        RequestReceiver* mRequestReceiver;
        RequestManager* mRequestManager;
        ResponseManager* mResponseManager;
        RWHandler* mRWHandler;
};

#endif
