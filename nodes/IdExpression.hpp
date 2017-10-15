#pragma once

#include "INode.hpp"
#include <string>

namespace NNodes {

    class CIdExpression : public INode {
    public:
        explicit CIdExpression(const char *name);
        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        const std::string id;
    };
}

