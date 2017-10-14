#include "PrettyPrinter.hpp"

#include <iostream>

void NVisitor::CPrettyPrinter::Visit(const NNodes::CIdExpression *const node) {
    std::cout << "ID" << std::endl;
}
