#ifndef RESPONSER_HPP_
#define RESPONSER_HPP_

#include "../../Common/Worker.hpp"

class OpCtx;
class Responser : public Worker{
    public :
        Responser(){};
        ~Responser(){};

    private :
        void* Entry();
        void ProcessResponse(OpCtx* ctx);
};
#endif
