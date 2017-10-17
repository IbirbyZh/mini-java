#pragma once

#include "INode.hpp"
#include <memory>
#include <vector>

namespace NNodes {

    class CStatementSequence : public IStatement {
    public:
        CStatementSequence(
                const std::shared_ptr<CStatementSequence> statements,
                const std::shared_ptr<IStatement> statement
        );
        void Visit(NVisitor::IVisitor *visitor) const override;
        void ToVector(std::vector<std::shared_ptr<const IStatement>> &statements) const override;

    private:
        const std::shared_ptr<CStatementSequence> firstStatements;
        const std::shared_ptr<IStatement> lastStatement;
    };
}