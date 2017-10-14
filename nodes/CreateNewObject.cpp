#include "CreateNewObject.hpp"

NNodes::CCreateNewObject::CCreateNewObject(const char *className) : name(className) {}

void NNodes::CCreateNewObject::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
