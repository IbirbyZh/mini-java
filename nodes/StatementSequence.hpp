#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CStatementSequence : INode {
    public:
        CStatementSequence(std::shared_ptr<CStatementSequence> statements,
                           std::shared_ptr<INode> statement);
        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        const std::shared_ptr<CStatementSequence> firstStatements;
        const std::shared_ptr<INode> lastStatement;
    };
}