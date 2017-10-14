#include "IntegerExpression.hpp"

NNodes::CIntegerExpression::CIntegerExpression(int number) : value(number) {}

void NNodes::CIntegerExpression::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
