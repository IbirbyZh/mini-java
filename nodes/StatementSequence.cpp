#include "StatementSequence.hpp"

NNodes::CStatementSequence::CStatementSequence
        (const std::shared_ptr<NNodes::CStatementSequence> statements,
         const std::shared_ptr<NNodes::IStatement> statement) : firstStatements(statements),
                                                                lastStatement(statement) {}

void NNodes::CStatementSequence::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

void NNodes::CStatementSequence::ToVector(std::vector<std::shared_ptr<IStatement>> &statements) const {
    if (firstStatements) {
        firstStatements->ToVector(statements);
    }
    statements.push_back(lastStatement);
}