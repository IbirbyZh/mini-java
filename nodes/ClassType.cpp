#include "ClassType.hpp"

NNodes::CClassType::CClassType(const char *className) : name(className) {

}

void NNodes::CClassType::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::string &NNodes::CClassType::ToString() const {
    return name;
}

const std::string &NNodes::CClassType::GetName() const {
    return name;
}
