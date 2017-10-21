#ifndef OPCTX_HPP_
#define OPCTX_HPP_

#include "Connection.hpp"
class OpCtx {
    private :
        Connection* mConn;
        int mOpType;
    public :
        OpCtx(Connection* conn) : mConn(conn) {
        }
        void SetType(int type);
        int GetType();
        Connection* GetConn();
};

#endif
