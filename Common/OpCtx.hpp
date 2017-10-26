#ifndef OPCTX_HPP_
#define OPCTX_HPP_

#include <string>
#include "Connection.hpp"
#include "Request.hpp"
class OpCtx {
    private :
        Connection* mConn;
        Request* mReq;
        int mErrCode;
        std::string mErrStr;     
    public :
        OpCtx(Connection* conn) : mConn(conn) {
            mReq = NULL;
        }
        ~OpCtx()
        {
            delete mConn;
            delete mReq;
        }
        Connection* GetConn() {
            return mConn;
        }
        void SetResult(int err,std::string str) {
            mErrCode = err;
            mErrStr = str;
        }
        int GetErrCode() {
            return mErrCode;
        }
        std::string GetErrStr() {
            return mErrStr;
        }
        void SetReq(Request* req) {
            mReq = req;
        }
        Request* GetReq() {
            return mReq;
        }
};

#endif
