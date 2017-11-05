#pragma once

#include "INode.hpp"
#include <memory>
#include <string>


namespace NNodes {

    class CTypedId : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        CTypedId(
                const std::shared_ptr<IType> objectType,
                const char *objectName
        );

        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::shared_ptr<IType> &GetType() const;
        const std::string &GetName() const;
    private:
        const std::shared_ptr<IType> type;
        const std::string name;
    };
}