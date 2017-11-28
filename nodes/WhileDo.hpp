#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CWhileDo : public IStatement {
        friend class NVisitor::CGraphvizPrinter;

    public:
        CWhileDo(
                const std::shared_ptr<INode> whileWhat,
                const std::shared_ptr<IStatement> doWhat
        );

        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::shared_ptr <INode> &GetCondition() const;
        const std::vector<std::shared_ptr<const IStatement>> &GetActions() const;
    private:
        const std::shared_ptr<INode> condition;
        std::vector<std::shared_ptr<const IStatement>> actions;
    };
}
