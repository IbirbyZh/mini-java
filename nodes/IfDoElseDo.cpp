#include "IfDoElseDo.hpp"

NNodes::CIfDoElseDo::CIfDoElseDo(
        const std::shared_ptr<NNodes::INode> ifCondition, const std::shared_ptr<NNodes::INode> doWhat,
        const std::shared_ptr<NNodes::INode> doOtherwise) : condition(ifCondition), ifAction(doWhat),
                                                            elseAction(doOtherwise) {}

void NNodes::CIfDoElseDo::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
