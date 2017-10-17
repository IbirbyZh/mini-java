#pragma once

#include "INode.hpp"
#include <memory>
#include <vector>

namespace NNodes {

    class CCallMethodParameters {
    public:
        CCallMethodParameters(
                std::shared_ptr<INode> callParameter,
                std::shared_ptr<CCallMethodParameters> nextParameters
        );

        void ToVector(std::vector<std::shared_ptr<const INode>> &parameters) const;

    private:
        const std::shared_ptr<INode> firstParameter;
        const std::shared_ptr<CCallMethodParameters> additionalParameters;
    };
}