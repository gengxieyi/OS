#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include <string>
#define BUFFER_SIZE 1024

class Connection {
    private :
        int mClientSocket;
        std::string mHeader;
        int mOpType;
        bool mContinue;
        std::string mContent;
        std::string mPath;
        int mContentLength;
    public :
        Connection(int st) : mClientSocket(st) {
            mHeader = "";
        }
        ~Connection();
        std::string GetHeader();
        int ReadHeader();
        int ParseHeader();
        int SendResponse(int errno,int size);
        int SendResponse(char* buf,int len);
        int GetOpType() {
            return mOpType;
        }
        int GetLength() {
            return mContentLength;
        }
        bool GetContinue() {
            return mContinue;
        }
        std::string GetContent() {
            return mContent;
        }
        std::string GetPath() {
            return mPath;
        }
        char* GetBlock(int& len);

};

#endif
