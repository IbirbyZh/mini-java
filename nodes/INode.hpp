#pragma once
#define interface struct

namespace NVisitor {
    class IVisitor;

    class CPrettyPythonPrinter;

    class CGraphvizPrinter;
}

namespace NNodes {

    interface INode {
        virtual ~INode() = default;

        virtual void Visit(NVisitor::IVisitor *visitor) const = 0;
    };

    typedef INode IType;
    typedef INode IStatement;
}

#include "IVisitor.hpp"
