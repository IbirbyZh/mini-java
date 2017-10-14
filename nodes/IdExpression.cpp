#include "IdExpression.hpp"


NNodes::CIdExpression::CIdExpression(const char *const name) : id(name) {}

void NNodes::CIdExpression::Visit(NVisitor::IVisitor *const visitor) const {
    visitor->Visit(this);
}

