#pragma once

#include "INode.hpp"
#include <string>

namespace NNodes {

    class CCreateNewObject : public INode {
    public:
        explicit CCreateNewObject(const char *className);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::string name;
    };
}
