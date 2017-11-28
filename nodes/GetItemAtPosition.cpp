#include "GetItemAtPosition.hpp"

NNodes::CGetItemAtPosition::CGetItemAtPosition(const std::shared_ptr<NNodes::INode> fromObject,
                                               const std::shared_ptr<INode> atPosition)
        : object(fromObject), position(atPosition) {}

void NNodes::CGetItemAtPosition::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::shared_ptr<NNodes::INode> &NNodes::CGetItemAtPosition::GetObject() const {
    return object;
}

const std::shared_ptr<NNodes::INode> &NNodes::CGetItemAtPosition::GetPosition() const {
    return position;
}
