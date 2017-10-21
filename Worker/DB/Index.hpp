#ifndef INDEX_HPP_
#define INDEX_HPP_
#include <string>
#include <vector>
#include <sys/stat.h>  
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include "../../Common/CommonDefine.hpp"
#include "../../Common/ErrCode.hpp"
#include "../../Common/BitSet.hpp"
using namespace std;
class Index {
    class Node {
        public :
            Node() {
                mKey = "";
                mOffset = -1;
                mLeft = NULL;
                mRight = NULL;
                mValueSize = -1;
                mIndex = -1;
            }
            Node(const string& key,gxy_uint64_t offset,gxy_uint32_t size){
                mKey = key;
                mOffset = offset;
                mLeft = NULL;
                mRight = NULL;
                mValueSize = size;
                mIndex = -1;
            }
            ~Node(){}
        public :
            Node* mLeft;
            Node* mRight;
            string mKey;
            gxy_uint64_t mOffset;
            gxy_uint32_t mValueSize;
            gxy_uint32_t mIndex;
    };

    public :
        Index(const string& name):mBitset(INDEX_COUNT){
            mHeader = NULL;
            mFileName = name;
            mBitset.Reset();
        }
        ~Index() {
            Release(mHeader);
        }
        gxy_result_t Open();
        gxy_result_t Close();
        gxy_result_t FlushBitset();
        gxy_result_t ReloadBitset();
        gxy_result_t ReloadIndex();
        gxy_result_t Put(const string&,gxy_uint64_t,gxy_uint32_t);
        gxy_result_t Flush(Node*);
        gxy_result_t Decode(Node*);
        gxy_result_t Get(const string&,gxy_uint64_t&,gxy_uint32_t&);
        void List(vector<string>&,vector<gxy_uint64_t>&,vector<gxy_uint32_t>&);
        bool Find(const string&);
        void Release(Node*);
    private :
        gxy_result_t Insert(Node*& p,Node* n);
        void List(Node*,vector<string>&,vector<gxy_uint64_t>&,vector<gxy_uint32_t>&);
        Node* mHeader;
        string mFileName;
        FILE* mFile;
        BitSet mBitset;
};

#endif
