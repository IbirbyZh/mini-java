#include "Class.hpp"


NNodes::CClass::CClass(const char *className, const std::shared_ptr<NNodes::CTypedIdSequence> classVariables,
                       const std::shared_ptr<NNodes::CMethodSequence> classMethods, const char *extendsClassName)
        : name(className), extendsName(extendsClassName), variables(classVariables), methods(classMethods) {

}

NNodes::CClass::CClass(const char *className, std::shared_ptr<NNodes::CTypedIdSequence> classVariables,
                       std::shared_ptr<NNodes::CMethodSequence> classMethods)
        : name(className), extendsName(), variables(classVariables), methods(classMethods) {

}

void NNodes::CClass::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
