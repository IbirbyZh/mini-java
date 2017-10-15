#pragma once

#include "IVisitor.hpp"

namespace NVisitor {
    class CPrettyPrinter : public IVisitor {
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
        void Visit(const NNodes::CCallMethodParameters *const node) override;
        void Visit(const NNodes::CAssignment *const node) override;
        void Visit(const NNodes::CAssignmentAtPosition *const node) override;
        void Visit(const NNodes::CPrintThing *const node) override;
        void Visit(const NNodes::CWhileDo *const node) override;
        void Visit(const NNodes::CIfDoElseDo *const node) override;
        void Visit(const NNodes::CStatementSequence *const node) override;
        void Visit(const NNodes::CTypedId *const node) override;
        void Visit(const NNodes::CTypedIdSequence *const node) override;
        void Visit(const NNodes::CMethodSignature *const node) override;
        void Visit(const NNodes::CMethod *const node) override;
        void Visit(const NNodes::CMethodSequence *const node) override;
        void Visit(const NNodes::CClass *const node) override;
        void Visit(const NNodes::CClassSequence *const node) override;
        void Visit(const NNodes::CMain *const node) override;
        void Visit(const NNodes::CProgram *const node) override;
    private:
        int indent;
        void printIndent() const;
        void increaseIndent();
        void dicreaseIndent();
    };
}

