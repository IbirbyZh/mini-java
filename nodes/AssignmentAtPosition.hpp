#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CAssignmentAtPosition : INode {
    public:
        CAssignmentAtPosition(std::shared_ptr<INode> id, int atPosition, std::shared_ptr<INode> toObject);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        int position;
        const std::shared_ptr<INode> lValue;
        const std::shared_ptr<INode> rValue;
    };
}
