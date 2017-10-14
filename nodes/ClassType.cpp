#include "ClassType.hpp"

NNodes::CClassType::CClassType(const char *className) : name(className) {

}

void NNodes::CClassType::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
