#pragma once

#include "INode.hpp"
#include <memory>
#include <string>

namespace NNodes {

    class CRunMethod : INode {
    public:
        CRunMethod(const std::shared_ptr<INode> fromObject, const char *methodName);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<INode> object;
        const std::string name;
    };
}
