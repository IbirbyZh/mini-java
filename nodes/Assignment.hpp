#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CAssignment : IStatement {
    public:
        CAssignment(std::shared_ptr<INode> id, std::shared_ptr<INode> toObject);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<INode> lValue;
        const std::shared_ptr<INode> rValue;
    };
}
