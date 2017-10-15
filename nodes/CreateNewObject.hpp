#pragma once

#include "INode.hpp"
#include <string>

namespace NNodes {

    class CCreateNewObject : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

    public:
        explicit CCreateNewObject(const char * className);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::string name;
    };
}
