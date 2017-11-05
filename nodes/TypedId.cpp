#include "TypedId.hpp"

NNodes::CTypedId::CTypedId(const std::shared_ptr<NNodes::IType> objectType, const char *objectName)
        : type(objectType), name(objectName) {

}

void NNodes::CTypedId::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::shared_ptr<NNodes::IType> &NNodes::CTypedId::GetType() const {
    return type;
}

const std::string &NNodes::CTypedId::GetName() const {
    return name;
}
