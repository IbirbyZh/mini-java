#pragma once
#define interface struct

#include <memory>
#include "IExp.h"

namespace NIRTree {

    class CConst : public IExp {
    public:
        explicit CConst(int value);

    private:
        int value;
    };

}