#include "CreateNewArray.hpp"

NNodes::CCreateNewArray::CCreateNewArray(const std::shared_ptr<INode> arraySize) : size(arraySize) {}

void NNodes::CCreateNewArray::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::shared_ptr<NNodes::INode> &NNodes::CCreateNewArray::GetSize() const {
    return size;
}
