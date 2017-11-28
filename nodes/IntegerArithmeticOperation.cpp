#include "IntegerArithmeticOperation.hpp"

void NNodes::CIntegerArithmeticOperation::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

NNodes::CIntegerArithmeticOperation::CIntegerArithmeticOperation(
        const std::shared_ptr<INode> leftPart,
        NNodes::CIntegerArithmeticOperation::TOperation operationType,
        const std::shared_ptr<INode> rightPart) : left(leftPart),
                                                  type(operationType),
                                                  right(rightPart) {

}

const std::shared_ptr<NNodes::INode> &NNodes::CIntegerArithmeticOperation::GetLeft() const {
    return left;
}

const std::shared_ptr<NNodes::INode> &NNodes::CIntegerArithmeticOperation::GetRight() const {
    return right;
}

NNodes::CIntegerArithmeticOperation::TOperation NNodes::CIntegerArithmeticOperation::GetType() const {
    return type;
}
