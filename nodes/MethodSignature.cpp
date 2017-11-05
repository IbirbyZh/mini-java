#include "MethodSignature.hpp"
#include <iostream>
#include <algorithm>

NNodes::CMethodSignature::CMethodSignature(
        bool isPrivate_, const std::shared_ptr<NNodes::IType> returnType, const char *methodName,
        const std::shared_ptr<NNodes::CTypedIdSequence> methodParameters)
        : isPrivate(isPrivate_), type(returnType), name(methodName), parameters() {
    if (methodParameters) {
        methodParameters->ToVector(parameters);
        std::reverse(parameters.begin(), parameters.end());
    }
}

void NNodes::CMethodSignature::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::shared_ptr<NNodes::IType> &NNodes::CMethodSignature::GetType() const {
    return type;
}

const std::string &NNodes::CMethodSignature::GetName() const {
    return name;
}

const std::vector<std::shared_ptr<const NNodes::CTypedId>> &NNodes::CMethodSignature::GetParameters() const {
    return parameters;
}
