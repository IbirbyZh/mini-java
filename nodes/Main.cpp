#include "Main.hpp"

NNodes::CMain::CMain(const char *className, const char *inputName,
                     const std::shared_ptr<NNodes::CStatementSequence> mainStatements)
        : name(className), input(inputName), statements() {
    mainStatements->ToVector(statements);
}

void NNodes::CMain::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::vector<std::shared_ptr<const NNodes::IStatement>> &NNodes::CMain::GetStatements() const {
    return statements;
}