#pragma once

#include "IVisitor.hpp"

namespace NVisitor {
    class CPrettyPrinter : IVisitor {
        void Visit(const NNonTerminal::CId *const node) const override;
    };
}

