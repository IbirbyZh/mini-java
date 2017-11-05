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

const std::string &NNodes::CClass::GetName() const {
    return name;
}

const std::string &NNodes::CClass::GetExtendsName() const {
    return extendsName;
}

const std::vector<std::shared_ptr<const NNodes::CTypedId>> &NNodes::CClass::GetVariables() const {
    return variables;
}

const std::vector<std::shared_ptr<const NNodes::CMethod>> &NNodes::CClass::GetMethods() const {
    return methods;
}
