#pragma once

#include "INode.hpp"
#include "Class.hpp"
#include <memory>

namespace NNodes {

    class CClassSequence : public INode {
    public:
        CClassSequence(std::shared_ptr<CClassSequence> classes,
                       std::shared_ptr<CClass> class_);
        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        const std::shared_ptr<CClassSequence> firstClasses;
        const std::shared_ptr<CClass> lastClass;
    };
}