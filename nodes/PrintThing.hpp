#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CPrintThing : public IStatement {
        friend class NVisitor::CPrettyPythonPrinter;

        friend class NVisitor::CGraphvizPrinter;

    public:
        explicit CPrintThing(const std::shared_ptr<INode> whatObject);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<INode> object;
    };
}
