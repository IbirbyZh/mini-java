#pragma once

#include "INode.hpp"
#include "Class.hpp"
#include <memory>
#include <vector>

namespace NNodes {

    class CClassSequence {
    public:
        CClassSequence(
                const std::shared_ptr<CClassSequence> classes,
                const std::shared_ptr<CClass> class_
        );

        void ToVector(std::vector<std::shared_ptr<const CClass>> &classes) const;

    private:
        const std::shared_ptr<CClassSequence> firstClasses;
        const std::shared_ptr<CClass> lastClass;
    };
}