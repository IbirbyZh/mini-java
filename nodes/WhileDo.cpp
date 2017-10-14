#include "WhileDo.hpp"

NNodes::CWhileDo::CWhileDo(
        std::shared_ptr<NNodes::INode> whileWhat, std::shared_ptr<NNodes::INode> doWhat) : condition(whileWhat),
                                                                                           action(doWhat) {}

void NNodes::CWhileDo::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
