#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CGetLength : INode {
    public:
        explicit CGetLength(std::shared_ptr<INode> fromObject);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<INode> object;
    };
}
