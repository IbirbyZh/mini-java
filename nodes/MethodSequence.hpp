#pragma once

#include "INode.hpp"
#include "Method.hpp"
#include <memory>

namespace NNodes {

    class CMethodSequence {
    public:
        CMethodSequence(
                const std::shared_ptr<CMethodSequence> methods,
                const std::shared_ptr<CMethod> method
        );

        void ToVector(std::vector<std::shared_ptr<const CMethod>> &methods) const;

    private:
        const std::shared_ptr<CMethodSequence> firstMethods;
        const std::shared_ptr<CMethod> lastMethod;
    };
}