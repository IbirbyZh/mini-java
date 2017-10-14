#include "BooleanArithmeticOperation.hpp"

void NNodes::CBooleanArithmeticOperation::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

NNodes::CBooleanArithmeticOperation::CBooleanArithmeticOperation(
        const std::shared_ptr<INode> leftPart,
        NNodes::CBooleanArithmeticOperation::TOperation operationType,
        const std::shared_ptr<INode> rightPart) :
        left(leftPart),
        type(operationType),
        right(rightPart) {

}
