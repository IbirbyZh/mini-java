#pragma once

#include "INode.hpp"

namespace NNodes {

    class CGetThisId : public INode {
        friend class NVisitor::CPrettyPrinter;

    public:
        CGetThisId();
        void Visit(NVisitor::IVisitor *visitor) const override;

    };
}

