#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CStatementSequence : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

        friend class NVisitor::CGraphvizPrinter;

    public:
        CStatementSequence(std::shared_ptr<CStatementSequence> statements,
                           std::shared_ptr<IStatement> statement);
        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        const std::shared_ptr<CStatementSequence> firstStatements;
        const std::shared_ptr<IStatement> lastStatement;
    };
}