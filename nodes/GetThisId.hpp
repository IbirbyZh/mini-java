#pragma once

#include "INode.hpp"

namespace NNodes {

    class CGetThisId : INode {
    public:
        CGetThisId();
        void Visit(NVisitor::IVisitor *visitor) const override;

    };
}

