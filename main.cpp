#include "tokens.h"
#include "Nodes.hpp"
#include "GraphvizPrinter.hpp"
#include "TypeChecker.cpp"

int main() {
    NNodes::CProgram *syntaxTree = nullptr;
    yyparse(&syntaxTree);

    if (syntaxTree != nullptr) {
        NVisitor::IVisitor *prettyPrinter = new NVisitor::CTypeChecker();
        syntaxTree->Visit(prettyPrinter);
        delete prettyPrinter;
    } else {
        std::cout << "Failed with parse" << std::endl;
    }

}