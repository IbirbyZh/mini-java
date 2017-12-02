#include "tokens.h"
#include "Nodes.hpp"
#include "TypeChecker.cpp"

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

}