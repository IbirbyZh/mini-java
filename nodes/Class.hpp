#pragma once

#include "INode.hpp"
#include "TypedIdSequence.hpp"
#include "MethodSequence.hpp"
#include <memory>
#include <string>
#include <vector>

namespace NNodes {

    class CClass : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        CClass(
                const char *className,
                const std::shared_ptr<CTypedIdSequence> classVariables,
                const std::shared_ptr<CMethodSequence> classMethods,
                const char *extendsClassName
        );

        CClass(
                const char *className,
                const std::shared_ptr<CTypedIdSequence> classVariables,
                const std::shared_ptr<CMethodSequence> classMethods
        );

        void Visit(NVisitor::IVisitor *visitor) const override;

        const std::string &GetName() const;
        const std::string &GetExtendsName() const;
        const std::vector<std::shared_ptr<const CTypedId>> &GetVariables() const;
        const std::vector<std::shared_ptr<const CMethod>> &GetMethods() const;
    private:
        const std::string name;
        const std::string extendsName;
        std::vector<std::shared_ptr<const CTypedId>> variables;
        std::vector<std::shared_ptr<const CMethod>> methods;
    };
}
