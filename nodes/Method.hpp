#pragma once

#include "INode.hpp"
#include "MethodSignature.hpp"
#include "TypedIdSequence.hpp"
#include "StatementSequence.hpp"
#include <memory>
#include <vector>

namespace NNodes {

    class CMethod : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        CMethod(
                const std::shared_ptr<CMethodSignature> methodSignature,
                const std::shared_ptr<CTypedIdSequence> methodVariables,
                const std::shared_ptr<CStatementSequence> methodActions,
                const std::shared_ptr<INode> methodResult
        );
        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::shared_ptr<CMethodSignature> &GetSignature() const;
        const std::vector<std::shared_ptr<const CTypedId>> &GetVariables() const;
        const std::vector<std::shared_ptr<const IStatement>> &GetActions() const;
        const std::shared_ptr<INode> &GetResult() const;
    private:
        const std::shared_ptr<CMethodSignature> signature;
        std::vector<std::shared_ptr<const CTypedId>> variables;
        std::vector<std::shared_ptr<const IStatement>> actions;
        const std::shared_ptr<INode> result;
    };
}