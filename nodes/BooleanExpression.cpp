#include "BooleanExpression.hpp"

NNodes::CBooleanExpression::CBooleanExpression(bool isTrue) : value(isTrue) {}

void NNodes::CBooleanExpression::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

