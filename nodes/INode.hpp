#pragma once
#define interface struct

namespace NVisitor {
    class IVisitor;
}

namespace NNodes {

    interface INode {
        virtual ~INode() = default;

        virtual void Visit(NVisitor::IVisitor *visitor) const = 0;
    };
}

#include "IVisitor.hpp"
