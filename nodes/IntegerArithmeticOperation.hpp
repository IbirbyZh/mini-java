#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CIntegerArithmeticOperation : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

        friend class NVisitor::CGraphvizPrinter;

    public:
        enum TOperation {
            T_PLUS,
            T_MINUS,
            T_MULT,
            T_MOD
        };
        CIntegerArithmeticOperation(const std::shared_ptr<INode> leftPart, TOperation operationType,
                                    const std::shared_ptr<INode> rightPart);
        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        const std::shared_ptr<INode> left, right;
        TOperation type;
    };
}