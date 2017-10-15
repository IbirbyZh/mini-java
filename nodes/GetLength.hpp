#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CGetLength : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

        friend class NVisitor::CGraphvizPrinter;

    public:
        explicit CGetLength(std::shared_ptr<INode> fromObject);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<INode> object;
    };
}
