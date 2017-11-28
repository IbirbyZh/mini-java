#pragma once

#include "INode.hpp"
#include "StatementSequence.hpp"
#include <memory>
#include <string>
#include <vector>

namespace NNodes {

    class CMain : public INode {
        friend class NVisitor::CGraphvizPrinter;

    public:
        CMain(
                const char *className,
                const char *inputName,
                std::shared_ptr<CStatementSequence> mainStatements
        );

        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::vector<std::shared_ptr<const IStatement>> &GetStatements() const;
    private:
        const std::string name;
        const std::string input;
        std::vector<std::shared_ptr<const IStatement>> statements;
    };
}
