#include "CallMethod.hpp"

NNodes::CCallMethod::CCallMethod(const std::shared_ptr<NNodes::INode> fromObject, const char *methodName,
                                 const std::shared_ptr<CCallMethodParameters> methodParameters)
        : object(fromObject), name(methodName), parameters() {
    if (methodParameters) {
        methodParameters->ToVector(parameters);
    }
}

void NNodes::CCallMethod::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::shared_ptr<NNodes::INode> &NNodes::CCallMethod::GetObject() const {
    return object;
}

const std::string &NNodes::CCallMethod::GetName() const {
    return name;
}

const std::vector<std::shared_ptr<const NNodes::INode>> &NNodes::CCallMethod::GetParameters() const {
    return parameters;
}
