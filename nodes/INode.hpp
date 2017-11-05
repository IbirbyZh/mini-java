#pragma once
#define interface struct

#include <memory>
#include <vector>
#include <string>

namespace NVisitor {

    class IVisitor;

    class CGraphvizPrinter;
}

namespace NNodes {

    interface INode {
        virtual ~INode() = default;

        virtual void Visit(NVisitor::IVisitor *visitor) const = 0;

        void AddLocation(int line, int column);
        int startColumn, startLine;
    };

    class IType : public INode {
    public:
        virtual const std::string &ToString() const = 0;
    };

    class IStatement : public INode, public std::enable_shared_from_this<IStatement> {
    public:
        virtual ~IStatement() = default;

        virtual void Visit(NVisitor::IVisitor *visitor) const override;

        virtual void ToVector(std::vector<std::shared_ptr<const IStatement>> &actions) const;
    };
}

#include "IVisitor.hpp"
