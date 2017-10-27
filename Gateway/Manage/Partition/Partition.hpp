#ifndef PARTITION_HPP_
#define PARTITION_HPP_

class Partition {
    public :
        Partition(int id,int key) {
            mID = id;
            mKey = key;
        }
        ~Partition() {
        }

        void SetPrimary(int primary) {
            mPrimary = primary;
        }
        int GetPrimary() {
            return mPrimary;
        } 
        void SetSecondary(int secondary) {
            mSecondary = secondary;
        }
        int GetSecondary() {
            return mSecondary;
        }

    private :
        int mID;
        int mKey;
        int mPrimary;
        int mSecondary;
};

#endif
