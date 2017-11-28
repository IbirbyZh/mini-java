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

const std::shared_ptr<NNodes::INode> &NNodes::CBooleanArithmeticOperation::GetLeft() const {
    return left;
}

const std::shared_ptr<NNodes::INode> &NNodes::CBooleanArithmeticOperation::GetRight() const {
    return right;
}

NNodes::CBooleanArithmeticOperation::TOperation NNodes::CBooleanArithmeticOperation::GetType() const {
    return type;
}