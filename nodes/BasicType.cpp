
#include "BasicType.hpp"

NNodes::CBasicType::CBasicType(NNodes::CBasicType::TType basicType) : type(basicType) {
}

void NNodes::CBasicType::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
