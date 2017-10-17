#pragma once

#include "IVisitor.hpp"
#include <string>

namespace NVisitor {
    class CGraphvizPrinter : public IVisitor {
    public:
        void Visit(const NNodes::CIdExpression *node) override;
        void Visit(const NNodes::CBasicType *const node) override;
        void Visit(const NNodes::CClassType *const node) override;
        void Visit(const NNodes::CIntegerExpression *const node) override;
        void Visit(const NNodes::CIntegerArithmeticOperation *const node) override;
        void Visit(const NNodes::CBooleanExpression *const node) override;
        void Visit(const NNodes::CBooleanArithmeticOperation *const node) override;
        void Visit(const NNodes::CGetItemAtPosition *const node) override;
        void Visit(const NNodes::CCallMethod *const node) override;
        void Visit(const NNodes::CGetLength *const node) override;
        void Visit(const NNodes::CCreateNewObject *const node) override;
        void Visit(const NNodes::CCreateNewArray *const node) override;
        void Visit(const NNodes::CGetThisId *const node) override;
        void Visit(const NNodes::CAssignment *const node) override;
        void Visit(const NNodes::CAssignmentAtPosition *const node) override;
        void Visit(const NNodes::CPrintThing *const node) override;
        void Visit(const NNodes::CWhileDo *const node) override;
        void Visit(const NNodes::CIfDoElseDo *const node) override;
        void Visit(const NNodes::CTypedId *const node) override;
        void Visit(const NNodes::CMethodSignature *const node) override;
        void Visit(const NNodes::CMethod *const node) override;
        void Visit(const NNodes::CClass *const node) override;
        void Visit(const NNodes::CMain *const node) override;
        void Visit(const NNodes::CProgram *const node) override;
    private:
        void printStatements(
                const std::vector<std::shared_ptr<const NNodes::IStatement>> &statements,
                const std::string &node
        );

        void printMethods(
                const std::vector<std::shared_ptr<const NNodes::CMethod>> &methods,
                const std::string &node
        );

        void printVariables(
                const std::vector<std::shared_ptr<const NNodes::CTypedId>> &variables,
                const std::string &node,
                const std::string &color
        );

        void printNodes(
                const std::vector<std::shared_ptr<const NNodes::INode>> &nodes,
                const std::string &node,
                const std::string &tag,
                const std::string &color
        );

        static std::string formatNode(
                const NNodes::INode *node,
                const std::string &tag = ""
        );

        static void printNode(const std::string &node, const std::string &label);

        static void printEdge(
                const std::string &parent,
                const std::string &son,
                const std::string &label = "",
                const std::string &color = ""
        );

    };
}

