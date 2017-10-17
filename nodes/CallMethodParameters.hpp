#pragma once

#include "INode.hpp"
#include <memory>
#include <vector>

namespace NNodes {

    class CCallMethodParameters : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

        friend class NVisitor::CGraphvizPrinter;

    public:
        CCallMethodParameters(std::shared_ptr<INode> callParameter,
                              std::shared_ptr<CCallMethodParameters> nextParameters);
        void Visit(NVisitor::IVisitor *visitor) const override;
        void ToVector(std::vector<std::shared_ptr<INode>> &parameters) const;

    private:
        const std::shared_ptr<INode> firstParameter;
        const std::shared_ptr<CCallMethodParameters> additionalParameters;
    };
}