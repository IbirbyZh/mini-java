#pragma once

#include "IId.hpp"

namespace NNonTerminal {
    class CId;
}

namespace NVisitor {

    class IVisitor {
    public:
        virtual ~IVisitor() {}

        virtual void Visit(const NNonTerminal::CId *const node) const = 0;
    };
}