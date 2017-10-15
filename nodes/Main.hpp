#pragma once

#include "INode.hpp"
#include "StatementSequence.hpp"
#include <memory>
#include <string>

namespace NNodes {

    class CMain : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

        friend class NVisitor::CGraphvizPrinter;

    public:
        CMain(const char *className, const char *inputName,
              std::shared_ptr<CStatementSequence> mainStatements);

        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const std::string name;
        const std::string input;
        const std::shared_ptr<CStatementSequence> statements;
    };
}
