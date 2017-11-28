#pragma once

#include "INode.hpp"
#include "CallMethodParameters.hpp"
#include <memory>
#include <string>
#include <vector>

namespace NNodes {

    class CCallMethod : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        CCallMethod(
                const std::shared_ptr<INode> fromObject,
                const char *methodName,
                const std::shared_ptr<CCallMethodParameters> methodParameters
        );

        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::shared_ptr<INode> &GetObject() const;
        const std::string &GetName() const;
        const std::vector<std::shared_ptr<const INode>> &GetParameters() const;
    private:
        const std::shared_ptr<INode> object;
        const std::string name;
        std::vector<std::shared_ptr<const INode>> parameters;
    };
}
