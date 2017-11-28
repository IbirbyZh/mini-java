#pragma once

#include "INode.hpp"
#include <string>

namespace NNodes {

    class CCreateNewObject : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        explicit CCreateNewObject(const char *className);
        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::string &GetName() const;
    private:
        const std::string name;
    };
}
