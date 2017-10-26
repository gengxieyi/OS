#ifndef BITSET_HPP_
#define BITSET_HPP_
#include <memory.h>
class BitSet {
    public :
        BitSet(int n) {
            mSize = n / 8;
            buf = new unsigned char[mSize];
        }
        ~BitSet() {
            delete[] buf;
        }
        
        void Set(int n) {
            unsigned char* p = buf + n/8;
            int offset = n % 8;
            *p = *p | (128 >> offset);
        }

        void Reset() {
            memset(buf,0,mSize);
        }

        void Reset(int n) {
            unsigned char* p = buf + n/8;
            int offset = n % 8;
            *p = *p & (255 - (128 >> offset));
        }

        bool Test(int n) {
            unsigned char* p = buf + n / 8;
            int offset = n % 8;
            return *p & (128 >> offset);
        }

        int FindFirst() {
            int offset = 0;
            int i = 0;
            for (;i < mSize ; i++) {
                if (*(buf + i) != 255) {
                    for (;offset < 8;offset++) {
                        if (*(buf + i) & (128 >> offset)) {
                            continue;
                        } else {
                            break;
                        }
                    }
                    break;
                }
            }
            return i * 8 + offset;
        }

        unsigned char* GetChar(int n) {
            return buf + n;
        }
        int GetSize() {
            return mSize * 8;
        }
    private :
        unsigned char* buf;
        int mSize;
};

#endif
