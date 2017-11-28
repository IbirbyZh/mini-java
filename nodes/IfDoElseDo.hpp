#pragma once

#include "INode.hpp"
#include <memory>
#include <vector>

namespace NNodes {

    class CIfDoElseDo : public IStatement {
        friend class NVisitor::CGraphvizPrinter;

    public:
        CIfDoElseDo(
                const std::shared_ptr<INode> ifCondition,
                const std::shared_ptr<IStatement> doWhat,
                const std::shared_ptr<IStatement> doOtherwise
        );

        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::shared_ptr<INode> &GetCondition() const;
        const std::vector<std::shared_ptr<const IStatement>> &GetIfAction() const;
        const std::vector<std::shared_ptr<const IStatement>> &GetElseAction() const;
    private:
        const std::shared_ptr<INode> condition;
        std::vector<std::shared_ptr<const IStatement>> ifAction, elseAction;
    };
}
