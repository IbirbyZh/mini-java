#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CWhileDo : IStatement {
    public:
        CWhileDo(std::shared_ptr<INode> whileWhat, std::shared_ptr<INode> doWhat);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<INode> condition;
        const std::shared_ptr<INode> action;
    };
}
