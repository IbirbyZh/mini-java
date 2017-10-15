#include "Assignment.hpp"

NNodes::CAssignment::CAssignment(const char *id,
                                 const std::shared_ptr<NNodes::INode> toObject) : lValue(id), rValue(toObject) {

}

void NNodes::CAssignment::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
