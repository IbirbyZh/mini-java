#pragma once

#include "INode.hpp"

namespace NNodes {

    class CBooleanExpression : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

    public:
        explicit CBooleanExpression(bool isTrue);

        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        bool value;
    };
}

