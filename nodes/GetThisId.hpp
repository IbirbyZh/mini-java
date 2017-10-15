#pragma once

#include "INode.hpp"

namespace NNodes {

    class CGetThisId : public INode {
    public:
        CGetThisId();
        void Visit(NVisitor::IVisitor *visitor) const override;

    };
}

