#pragma once
#define interface struct

#include "IExp.h"

namespace NIRTree {

    class CTemp : public IExp {
    public:
        explicit CTemp(int localId);

    private:
        int localId;
    };

}