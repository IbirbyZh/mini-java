#include "CreateNewArray.hpp"

NNodes::CCreateNewArray::CCreateNewArray(int arraySize) : size(arraySize) {}

void NNodes::CCreateNewArray::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
