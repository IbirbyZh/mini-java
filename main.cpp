#include "tokens.h"
#include "Nodes.hpp"
#include "TypeChecker.cpp"
#include "Table.hpp"
#include "MiniJavaFrame.hpp"

int main() {
    NNodes::CProgram *syntaxTree = nullptr;
    yyparse(&syntaxTree);

    if (syntaxTree != nullptr) {
        auto typeChecker = new NVisitor::CTypeChecker();
        syntaxTree->Visit(typeChecker);
        bool hasError = typeChecker->IsHasError();
        delete typeChecker;
        if (hasError) {
            return 0;
        }
    } else {
        std::cout << "Failed with parse" << std::endl;
        return 0;
    }
    std::shared_ptr<NTable::CTable> table = std::make_shared<NTable::CTable>(syntaxTree);
    for (auto &&item: table->GetClassesInfo()) {
        for (auto &&method: item.second->GetMethods()) {
            std::cout << method.second->GetName()->ToString() << std::endl;
            std::shared_ptr<const NIRTree::CMiniJavaFrame> a = NIRTree::CMiniJavaFrame::BuildFrame(method.second);
            for (auto &&variable: method.second->GetVariables()) {
                std::cout << variable.first->ToString() << ':' << a->FindLocalOrFormal(variable.first)->GetPointer() << std::endl;
            }
            for (auto &&parameter: method.second->GetPositionParameters()) {
                std::cout << parameter->ToString() << ':' << a->FindLocalOrFormal(parameter)->GetPointer() << std::endl;
            }
            std::cout << std::endl;
        }
    }


}