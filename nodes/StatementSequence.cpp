#include "StatementSequence.hpp"

NNodes::CStatementSequence::CStatementSequence
        (std::shared_ptr<NNodes::CStatementSequence> statements,
         std::shared_ptr<NNodes::INode> statement) : firstStatements(statements),
                                                     lastStatement(statement) {}

void NNodes::CStatementSequence::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
