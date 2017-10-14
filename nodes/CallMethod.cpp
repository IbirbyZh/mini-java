#include "CallMethod.hpp"

NNodes::CRunMethod::CRunMethod(const std::shared_ptr<NNodes::INode> fromObject, const char *const methodName)
        : object(fromObject), name(methodName) {}

void NNodes::CRunMethod::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
