#include "MethodSequence.hpp"

NNodes::CMethodSequence::CMethodSequence
        (const std::shared_ptr<NNodes::CMethodSequence> methods,
         const std::shared_ptr<NNodes::INode> method) : firstMethods(methods),
                                                  lastMethod(method) {}

void NNodes::CMethodSequence::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
