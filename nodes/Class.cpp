#include "Class.hpp"


NNodes::CClass::CClass(const char *className, const std::shared_ptr<NNodes::CTypedIdSequence> classVariables,
                       const std::shared_ptr<NNodes::CMethodSequence> classMethods, const char *extendsClassName)
        : name(className), extendsName(extendsClassName), variables(), methods() {
    if (classVariables) {
        classVariables->ToVector(variables);
    }
    if (classMethods) {
        classMethods->ToVector(methods);
    }

}

NNodes::CClass::CClass(const char *className, std::shared_ptr<NNodes::CTypedIdSequence> classVariables,
                       std::shared_ptr<NNodes::CMethodSequence> classMethods)
        : name(className), extendsName(), variables(), methods() {
    if (classVariables) {
        classVariables->ToVector(variables);
    }
    if (classMethods) {
        classMethods->ToVector(methods);
    }

}

void NNodes::CClass::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
