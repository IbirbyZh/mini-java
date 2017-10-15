#pragma once

#include "INode.hpp"

namespace NNodes {

    class CGetThisId : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

        friend class NVisitor::CGraphvizPrinter;

    public:
        CGetThisId();
        void Visit(NVisitor::IVisitor *visitor) const override;

    };
}

