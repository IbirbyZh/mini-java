#pragma once

#include "INode.hpp"
#include "Main.hpp"
#include "ClassSequence.hpp"
#include <memory>

namespace NNodes {

    class CProgram : INode {
    public:
        CProgram(std::shared_ptr<CMain> mainClass,
                  std::shared_ptr<CClassSequence> additionalClasses);

        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::shared_ptr<CMain> main;
        const std::shared_ptr<CClassSequence> classes;
    };
}
