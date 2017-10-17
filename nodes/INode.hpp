#pragma once
#define interface struct

#include <memory>
#include <vector>

namespace NVisitor {

    class IVisitor;

    class CGraphvizPrinter;
}

namespace NNodes {

    interface INode {
        virtual ~INode() = default;

        virtual void Visit(NVisitor::IVisitor *visitor) const = 0;
    };

    typedef INode IType;

    class IStatement : public INode, public std::enable_shared_from_this<IStatement> {
    public:
        virtual ~IStatement() = default;

        virtual void Visit(NVisitor::IVisitor *visitor) const override;

        virtual void ToVector(std::vector<std::shared_ptr<const IStatement>> &actions) const;
    };
}

#include "IVisitor.hpp"
