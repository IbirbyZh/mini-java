#include "PrettyPrinter.hpp"

#include <iostream>

void NVisitor::CPrettyPrinter::Visit(const NNonTerminal::CId *const node) const {
    std::cout << node->GetId() << std::endl;
}
