#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CGetItemAtPosition : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        CGetItemAtPosition(
                const std::shared_ptr<INode> fromObject,
                const std::shared_ptr<INode> atPosition
        );

        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::shared_ptr<INode> &GetObject() const;
        const std::shared_ptr<INode> &GetPosition() const;
    private:
        const std::shared_ptr<INode> object;
        const std::shared_ptr<INode> position;
    };
}