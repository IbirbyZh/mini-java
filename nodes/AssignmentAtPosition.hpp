#pragma once

#include "INode.hpp"
#include <memory>
#include <string>

namespace NNodes {

    class CAssignmentAtPosition : public IStatement {
        friend class NVisitor::CGraphvizPrinter;

    public:
        CAssignmentAtPosition(
                const char *id,
                const std::shared_ptr<INode> atPosition,
                const std::shared_ptr<INode> toObject
        );

        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::string &GetLValue() const;
        const std::shared_ptr<INode> &GetRValue() const;
        const std::shared_ptr<INode> &GetPosition() const;
    private:
        const std::string lValue;
        const std::shared_ptr<INode> position;
        const std::shared_ptr<INode> rValue;
    };
}
