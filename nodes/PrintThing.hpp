#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CPrintThing : public IStatement {
        friend class NVisitor::CGraphvizPrinter;

    public:
        explicit CPrintThing(const std::shared_ptr<INode> whatObject);
        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::shared_ptr <INode> &GetObject() const;
    private:
        const std::shared_ptr<INode> object;
    };
}
