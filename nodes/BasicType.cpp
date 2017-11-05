#include "BasicType.hpp"

const std::string NNodes::CBasicType::INT = "int";
const std::string NNodes::CBasicType::BOOL = "bool";
const std::string NNodes::CBasicType::INT_ARRAY = "int[]";

NNodes::CBasicType::CBasicType(NNodes::CBasicType::TType basicType) : type(basicType) {
}

void NNodes::CBasicType::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::string &NNodes::CBasicType::ToString() const {
    if (type == BT_INT) {
        return INT;
    } else if (type == BT_BOOL) {
        return BOOL;
    } else if (type == BT_INT_ARRAY) {
        return INT_ARRAY;
    }
    throw;
}
