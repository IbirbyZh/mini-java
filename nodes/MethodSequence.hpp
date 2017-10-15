#pragma once

#include "INode.hpp"
#include "Method.hpp"
#include <memory>

namespace NNodes {

    class CMethodSequence : INode {
    public:
        CMethodSequence(std::shared_ptr<CMethodSequence> methods,
                           std::shared_ptr<CMethod> method);
        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        const std::shared_ptr<CMethodSequence> firstMethods;
        const std::shared_ptr<CMethod> lastMethod;
    };
}