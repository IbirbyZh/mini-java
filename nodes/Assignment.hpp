#pragma once

#include "INode.hpp"
#include <memory>
#include <string>

namespace NNodes {

    class CAssignment : public IStatement {
        friend class NVisitor::CPrettyPythonPrinter;

        friend class NVisitor::CGraphvizPrinter;


    public:
        CAssignment(
                const char *id,
                const std::shared_ptr<INode> toObject
        );
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::string lValue;
        const std::shared_ptr<INode> rValue;
    };
}
