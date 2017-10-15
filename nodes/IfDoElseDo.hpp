#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CIfDoElseDo : public IStatement {
    public:
        CIfDoElseDo(std::shared_ptr<INode> ifCondition, std::shared_ptr<INode> doWhat,
                    std::shared_ptr<INode> doOtherwise);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<INode> condition;
        const std::shared_ptr<INode> ifAction, elseAction;
    };
}
