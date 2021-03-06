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

const std::shared_ptr<NNodes::CMethodSignature> &NNodes::CMethod::GetSignature() const {
    return signature;
}

const std::vector<std::shared_ptr<const NNodes::CTypedId>> &NNodes::CMethod::GetVariables() const {
    return variables;
}

const std::vector<std::shared_ptr<const NNodes::IStatement>> &NNodes::CMethod::GetActions() const {
    return actions;
}

const std::shared_ptr<NNodes::INode> &NNodes::CMethod::GetResult() const {
    return result;
}
