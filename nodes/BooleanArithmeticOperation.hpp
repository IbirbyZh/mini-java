#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CBooleanArithmeticOperation : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        enum TOperation {
            T_AND,
            T_OR,
            T_LESS,
            T_BANG
        };

        CBooleanArithmeticOperation(
                const std::shared_ptr<INode> leftPart,
                TOperation operationType,
                const std::shared_ptr<INode> rightPart
        );

        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        const std::shared_ptr<INode> left, right;
        TOperation type;
    };
}