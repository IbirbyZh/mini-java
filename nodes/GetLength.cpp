#include "GetLength.hpp"

NNodes::CGetLength::CGetLength(const std::shared_ptr<NNodes::INode> fromObject)
        : object(fromObject) {}

void NNodes::CGetLength::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
