#pragma once

#include "INode.hpp"
#include "Class.hpp"
#include <memory>
#include <vector>

namespace NNodes {

    class CClassSequence : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

        friend class NVisitor::CGraphvizPrinter;

    public:
        CClassSequence(std::shared_ptr<CClassSequence> classes,
                       std::shared_ptr<CClass> class_);
        void Visit(NVisitor::IVisitor *visitor) const override;
        void ToVector(std::vector<std::shared_ptr<CClass>> classes) const;

    private:
        const std::shared_ptr<CClassSequence> firstClasses;
        const std::shared_ptr<CClass> lastClass;
    };
}