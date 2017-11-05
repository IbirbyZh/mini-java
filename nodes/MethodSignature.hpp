#pragma once


#include "INode.hpp"
#include "TypedIdSequence.hpp"
#include <string>
#include <memory>
#include <vector>

namespace NNodes {

    class CMethodSignature : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        CMethodSignature(
                bool isPrivate_,
                const std::shared_ptr<IType> returnType,
                const char *methodName,
                const std::shared_ptr<CTypedIdSequence> methodParameters
        );
        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::shared_ptr<IType> &GetType() const;
        const std::string &GetName() const;
        const std::vector<std::shared_ptr<const CTypedId>> &GetParameters() const;
    private:
        bool isPrivate;
        const std::shared_ptr<IType> type;
        const std::string name;
        std::vector<std::shared_ptr<const CTypedId>> parameters;
    };
}
