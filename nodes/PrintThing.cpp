#include "PrintThing.hpp"

NNodes::CPrintThing::CPrintThing(const std::shared_ptr<NNodes::INode> whatObject) : object(whatObject) {

}

void NNodes::CPrintThing::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
