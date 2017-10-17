#include "Method.hpp"

NNodes::CMethod::CMethod(
        const std::shared_ptr<NNodes::CMethodSignature> methodSignature,
        const std::shared_ptr<NNodes::CTypedIdSequence> methodVariables,
        const std::shared_ptr<NNodes::CStatementSequence> methodActions,
        const std::shared_ptr<NNodes::INode> methodResult)
        : signature(methodSignature), variables(), actions(), result(methodResult) {
    if (methodVariables) {
        methodVariables->ToVector(variables);
    }
    if (methodActions) {
        methodActions->ToVector(actions);
    }
}

void NNodes::CMethod::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
