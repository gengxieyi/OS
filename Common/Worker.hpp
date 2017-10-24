#ifndef WORKER_HPP_
#define WORKER_HPP_

#include "SafeQueue.hpp"
class OpCtx;

class Worker {
    private :
        static void* _entry_func_(void* arg) {
            void* r = ((Worker*)arg)->Entry();
            return r;
        }
    protected :
        SafeQueue<OpCtx*> mQueue;
        virtual void* Entry() = 0;
    public :
        Worker(){}
        ~Worker(){}
        int Start();
        void PostRequest(OpCtx* ctx);
};

#endif
