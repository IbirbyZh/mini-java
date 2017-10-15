#pragma once

#include "INode.hpp"
#include "MethodSignature.hpp"
#include "TypedIdSequence.hpp"
#include "StatementSequence.hpp"
#include <memory>

namespace NNodes {

    class CMethod : public INode {
    public:
        CMethod(std::shared_ptr<CMethodSignature> methodSignature,
                std::shared_ptr<CTypedIdSequence> methodVariables,
                std::shared_ptr<CStatementSequence> methodActions,
                std::shared_ptr<INode> methodResult);
        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        const std::shared_ptr<CMethodSignature> signature;
        const std::shared_ptr<CTypedIdSequence> variables;
        const std::shared_ptr<CStatementSequence> actions;
        const std::shared_ptr<INode> result;
    };
}