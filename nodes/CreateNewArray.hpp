#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CCreateNewArray : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        explicit CCreateNewArray(const std::shared_ptr<INode> arraySize);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<INode> size;
    };
}
