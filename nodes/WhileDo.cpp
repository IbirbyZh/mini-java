#include "WhileDo.hpp"

NNodes::CWhileDo::CWhileDo(std::shared_ptr<NNodes::INode> whileWhat, std::shared_ptr<NNodes::IStatement> doWhat)
        : condition(whileWhat),
          actions() {
    doWhat->ToVector(actions);
}

void NNodes::CWhileDo::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::shared_ptr<NNodes::INode> &NNodes::CWhileDo::GetCondition() const {
    return condition;
}

const std::vector<std::shared_ptr<const NNodes::IStatement>> &NNodes::CWhileDo::GetActions() const {
    return actions;
}
