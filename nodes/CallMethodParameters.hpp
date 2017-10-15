#pragma once

#include "INode.hpp"
#include <memory>

namespace NNodes {

    class CCallMethodParameters : public INode {
        friend class NVisitor::CPrettyPrinter;

    public:
        CCallMethodParameters(std::shared_ptr<INode> callParameter,
                              std::shared_ptr<CCallMethodParameters> nextParameters);
        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        const std::shared_ptr<INode> firstParameter;
        const std::shared_ptr<CCallMethodParameters> additionalParameters;
    };
}