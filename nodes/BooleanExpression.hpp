#pragma once

#include "INode.hpp"

namespace NNodes {

    class CBooleanExpression : INode {
    public:
        explicit CBooleanExpression(bool number);

        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        bool value;
    };
}

