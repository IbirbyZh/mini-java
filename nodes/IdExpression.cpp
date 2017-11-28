#include "IdExpression.hpp"


NNodes::CIdExpression::CIdExpression(const char *name) : id(name) {}

void NNodes::CIdExpression::Visit(NVisitor::IVisitor *const visitor) const {
    visitor->Visit(this);
}

const std::string &NNodes::CIdExpression::GetId() const {
    return id;
}

