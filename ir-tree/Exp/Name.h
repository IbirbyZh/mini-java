#pragma once
#define interface struct

#include <memory>
#include "IExp.h"
#include "LabelHandler.h"

namespace NIRTree {

    class CName : public IExp {
    public:
        explicit CName(const std::shared_ptr<const CLabel> label);

    private:
        const std::shared_ptr<const CLabel> label;
    };

}