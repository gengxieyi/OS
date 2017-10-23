#ifndef LOCKER_HPP_
#define LOCKER_HPP_
#include <pthread.h>
class Locker {
    public :
        Locker(){
            pthread_mutex_init(&mMutex,NULL);
        };
        ~Locker(){
            pthread_mutex_destroy(&mMutex);
        };
        void Lock(){
            pthread_mutex_lock(&mMutex);
        }
        void Unlock(){
            pthread_mutex_unlock(&mMutex);
        }
    private :
        pthread_mutex_t mMutex;
};

#endif
