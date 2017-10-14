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
