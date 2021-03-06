#ifndef SAFE_QUEUE_HPP_
#define SAFE_QUEUE_HPP_

#include "Locker.hpp"
#include <vector>

template<class T>
class SafeQueue {
    public :
        SafeQueue() {}
        ~SafeQueue() {}
        void Enqueue(T t) {
            mLocker.Lock();
            mData.push_back(t);
            mLocker.Unlock();
        }
        void Dequeue(T& t) {
            if (mData.size() != 0) {
                mLocker.Lock();
                t = mData.back();
                mData.pop_back();
                mLocker.Unlock();
            }
        }
        void Dequeue(std::vector<T>& vec) {
            mLocker.Lock();
            for (int i = 0;i < mData.size();i++) {
                vec.push_back(mData[i]);
            }
            mData.Clear();
            mLocker.Unlock();
        }
        bool Empty() {
            return mData.size() == 0;
        }
    private :
        Locker mLocker;
        std::vector<T> mData;
};


#endif
