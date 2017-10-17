#include "MethodSequence.hpp"

NNodes::CMethodSequence::CMethodSequence
        (const std::shared_ptr<NNodes::CMethodSequence> methods,
         const std::shared_ptr<NNodes::CMethod> method) : firstMethods(methods),
                                                          lastMethod(method) {}

void NNodes::CMethodSequence::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

void NNodes::CMethodSequence::ToVector(std::vector<std::shared_ptr<CMethod>> &methods) const {
    if (firstMethods) {
        firstMethods->ToVector(methods);
    }
    methods.push_back(lastMethod);
}
