#pragma once

#include "INode.hpp"
#include <memory>
#include <string>


namespace NNodes {

    class CTypedId : public INode {
    public:
        CTypedId(std::shared_ptr<IType> objectType, const char *objectName);

        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<IType> type;
        const std::string name;
    };
}