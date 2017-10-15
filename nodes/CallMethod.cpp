#include "CallMethod.hpp"

NNodes::CCallMethod::CCallMethod(const std::shared_ptr<NNodes::INode> fromObject, const char *methodName,
                                 const std::shared_ptr<CCallMethodParameters> methodParameters)
        : object(fromObject), name(methodName), parameters(methodParameters) {}

void NNodes::CCallMethod::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
