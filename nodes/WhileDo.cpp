#include "WhileDo.hpp"

NNodes::CWhileDo::CWhileDo(std::shared_ptr<NNodes::INode> whileWhat, std::shared_ptr<NNodes::IStatement> doWhat)
        : condition(whileWhat),
          actions() {
    doWhat->ToVector(actions);
}

void NNodes::CWhileDo::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
