#include "BooleanExpression.hpp"

NNodes::CBooleanExpression::CBooleanExpression(bool number) : value(number) {}

void NNodes::CBooleanExpression::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

