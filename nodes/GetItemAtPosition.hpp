#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CGetItemAtPosition : public INode {
    public:
        CGetItemAtPosition(const std::shared_ptr<INode> fromObject, const std::shared_ptr<INode> atPosition);

        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<INode> object;
        const std::shared_ptr<INode> position;
    };
}