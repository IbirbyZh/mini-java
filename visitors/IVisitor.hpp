#pragma once

#include "Nodes.hpp"

namespace NNodes {
    class CIdExpression;

    class CIntegerExpression;

    class CIntegerArithmeticOperation;

    class CBooleanExpression;

    class CBooleanArithmeticOperation;

    class CGetItemAtPosition;

    class CRunMethod;

    class CGetLength;

    class CCreateNewObject;

    class CCreateNewArray;

    class CGetThisId;

    class CCallMethodParameters;

    class CStatementSequence;

    class CAssignment;

    class CAssignmentAtPosition;
}

namespace NVisitor {

    interface IVisitor {
    public:
        virtual ~IVisitor() {}

        virtual void Visit(const NNodes::CIdExpression *const node) = 0;
        virtual void Visit(const NNodes::CIntegerExpression *const node) = 0;
        virtual void Visit(const NNodes::CIntegerArithmeticOperation *const node) = 0;
        virtual void Visit(const NNodes::CBooleanExpression *const node) = 0;
        virtual void Visit(const NNodes::CBooleanArithmeticOperation *const node) = 0;
        virtual void Visit(const NNodes::CGetItemAtPosition *const node) = 0;
        virtual void Visit(const NNodes::CRunMethod *const node) = 0;
        virtual void Visit(const NNodes::CGetLength *const node) = 0;
        virtual void Visit(const NNodes::CCreateNewObject *const node) = 0;
        virtual void Visit(const NNodes::CCreateNewArray *const node) = 0;
        virtual void Visit(const NNodes::CGetThisId *const node) = 0;
        virtual void Visit(const NNodes::CCallMethodParameters *const node) = 0;
        virtual void Visit(const NNodes::CStatementSequence *const node) = 0;
        virtual void Visit(const NNodes::CAssignment *const node) = 0;
        virtual void Visit(const NNodes::CAssignmentAtPosition *const node) = 0;
    };
}