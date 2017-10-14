#include "GetThisId.hpp"

NNodes::CGetThisId::CGetThisId() {}

void NNodes::CGetThisId::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
