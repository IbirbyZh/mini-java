#include "GetItemAtPosition.hpp"

NNodes::CGetItemAtPosition::CGetItemAtPosition(const std::shared_ptr<NNodes::INode> fromObject, int atPosition)
        : object(fromObject), position(atPosition) {}

void NNodes::CGetItemAtPosition::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
