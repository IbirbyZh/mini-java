#pragma once

#include "INode.hpp"
#include "Method.hpp"
#include <memory>

namespace NNodes {

    class CMethodSequence : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

        friend class NVisitor::CGraphvizPrinter;

    public:
        CMethodSequence(std::shared_ptr<CMethodSequence> methods,
                        std::shared_ptr<CMethod> method);
        void Visit(NVisitor::IVisitor *visitor) const override;
        void ToVector(std::vector<std::shared_ptr<CMethod>> &methods) const;

    private:
        const std::shared_ptr<CMethodSequence> firstMethods;
        const std::shared_ptr<CMethod> lastMethod;
    };
}