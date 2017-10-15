#pragma once


#include "INode.hpp"
#include "TypedIdSequence.hpp"
#include <string>
#include <memory>

namespace NNodes {

    class CMethodSignature : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

    public:
        CMethodSignature(bool isPrivate_, std::shared_ptr<IType> returnType,
                         const char * methodName,
                         std::shared_ptr<CTypedIdSequence> methodParameters);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        bool isPrivate;
        const std::shared_ptr<IType> type;
        const std::string name;
        const std::shared_ptr<CTypedIdSequence> parameters;
    };
}
