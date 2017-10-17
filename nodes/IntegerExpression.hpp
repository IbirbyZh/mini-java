#pragma once

#include "INode.hpp"

namespace NNodes {

    class CIntegerExpression : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        explicit CIntegerExpression(int number);
        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        int value;
    };
}

