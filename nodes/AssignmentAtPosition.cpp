#include "AssignmentAtPosition.hpp"

NNodes::CAssignmentAtPosition::CAssignmentAtPosition(
        const char *id,
        const std::shared_ptr<INode> atPosition,
        const std::shared_ptr<NNodes::INode> toObject) : lValue(id),
                                                         position(atPosition),
                                                         rValue(toObject) {

}

void NNodes::CAssignmentAtPosition::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::string &NNodes::CAssignmentAtPosition::GetLValue() const {
    return lValue;
}

const std::shared_ptr<NNodes::INode> &NNodes::CAssignmentAtPosition::GetRValue() const {
    return rValue;
}

const std::shared_ptr<NNodes::INode> &NNodes::CAssignmentAtPosition::GetPosition() const {
    return position;
}
