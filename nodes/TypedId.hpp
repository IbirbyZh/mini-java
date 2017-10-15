#pragma once

#include "INode.hpp"
#include <memory>
#include <string>


namespace NNodes {

    class CTypedId : public INode {
        friend class NVisitor::CPrettyPrinter;

    public:
        CTypedId(std::shared_ptr<IType> objectType, const char *objectName);

        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<IType> type;
        const std::string name;
    };
}