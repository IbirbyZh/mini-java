#pragma once

#include "INode.hpp"
#include <string>

namespace NNodes {

    class CClassType : public IType {
    public:
        explicit CClassType(const char *className);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::string name;
    };
}