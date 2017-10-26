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
            Node(const string& key,unsigned long long offset,unsigned int size){
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
            unsigned long long mOffset;
            unsigned int mValueSize;
            unsigned int mIndex;
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
        int Open();
        int Close();
        int FlushBitset();
        int ReloadBitset();
        int ReloadIndex();
        int Put(const string&,unsigned long long,unsigned int);
        int Flush(Node*);
        int Decode(Node*);
        int Get(const string&,unsigned long long&,unsigned int&);
        void List(vector<string>&,vector<unsigned long long>&,vector<unsigned int>&);
        bool Find(const string&);
        void Release(Node*);
    private :
        int Insert(Node*& p,Node* n);
        void List(Node*,vector<string>&,vector<unsigned long long>&,vector<unsigned int>&);
        Node* mHeader;
        string mFileName;
        FILE* mFile;
        BitSet mBitset;
};

#endif
