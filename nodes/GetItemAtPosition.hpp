#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CGetItemAtPosition : INode {
    public:
        CGetItemAtPosition(const std::shared_ptr<INode> fromObject, int atPosition);

        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<INode> object;
        int position;
    };
}