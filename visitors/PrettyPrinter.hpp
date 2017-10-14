#pragma once

#include "IVisitor.hpp"

namespace NVisitor {
    class CPrettyPrinter : IVisitor {
        void Visit(const NNodes::CIdExpression *node) override;
    };
}

