#include "IfDoElseDo.hpp"

NNodes::CIfDoElseDo::CIfDoElseDo(
        const std::shared_ptr<NNodes::INode> ifCondition,
        const std::shared_ptr<NNodes::IStatement> doWhat,
        const std::shared_ptr<NNodes::IStatement> doOtherwise)
        : condition(ifCondition), ifAction(), elseAction() {
    if (doWhat) {
        doWhat->ToVector(ifAction);
    }
    if (doOtherwise) {
        doOtherwise->ToVector(elseAction);
    }
}

void NNodes::CIfDoElseDo::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::shared_ptr<NNodes::INode> &NNodes::CIfDoElseDo::GetCondition() const {
    return condition;
}

const std::vector<std::shared_ptr<const NNodes::IStatement>> &NNodes::CIfDoElseDo::GetIfAction() const {
    return ifAction;
}

const std::vector<std::shared_ptr<const NNodes::IStatement>> &NNodes::CIfDoElseDo::GetElseAction() const {
    return elseAction;
}
