#pragma once

#include "INode.hpp"
#include "Main.hpp"
#include "ClassSequence.hpp"
#include <memory>

namespace NNodes {

    class CProgram : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        CProgram(
                const std::shared_ptr<CMain> mainClass,
                const std::shared_ptr<CClassSequence> additionalClasses
        );
        const std::vector<std::shared_ptr<const CClass>> &GetClasses() const;
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<CMain> main;
        std::vector<std::shared_ptr<const CClass>> classes;
    };
}
