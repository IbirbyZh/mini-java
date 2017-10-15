#pragma once

#define interface struct


namespace NNodes {
    class CBasicType;

    class CClassType;


    class CIdExpression;

    class CIntegerExpression;

    class CIntegerArithmeticOperation;

    class CBooleanExpression;

    class CBooleanArithmeticOperation;

    class CGetItemAtPosition;

    class CCallMethod;

    class CGetLength;

    class CCreateNewObject;

    class CCreateNewArray;

    class CGetThisId;

    class CCallMethodParameters;


    class CAssignment;

    class CAssignmentAtPosition;

    class CPrintThing;

    class CWhileDo;

    class CIfDoElseDo;

    class CStatementSequence;


    class CTypedId;

    class CTypedIdSequence;

    class CMethodSignature;

    class CMethod;

    class CMethodSequence;


    class CClass;

    class CClassSequence;


    class CMain;

    class CProgram;
}

#include "Nodes.hpp"

namespace NVisitor {

    interface IVisitor {
    public:
        virtual ~IVisitor() {}

        virtual void Visit(const NNodes::CBasicType *const node) = 0;
        virtual void Visit(const NNodes::CClassType *const node) = 0;

        virtual void Visit(const NNodes::CIdExpression *const node) = 0;
        virtual void Visit(const NNodes::CIntegerExpression *const node) = 0;
        virtual void Visit(const NNodes::CIntegerArithmeticOperation *const node) = 0;
        virtual void Visit(const NNodes::CBooleanExpression *const node) = 0;
        virtual void Visit(const NNodes::CBooleanArithmeticOperation *const node) = 0;
        virtual void Visit(const NNodes::CGetItemAtPosition *const node) = 0;
        virtual void Visit(const NNodes::CCallMethod *const node) = 0;
        virtual void Visit(const NNodes::CGetLength *const node) = 0;
        virtual void Visit(const NNodes::CCreateNewObject *const node) = 0;
        virtual void Visit(const NNodes::CCreateNewArray *const node) = 0;
        virtual void Visit(const NNodes::CGetThisId *const node) = 0;
        virtual void Visit(const NNodes::CCallMethodParameters *const node) = 0;

        virtual void Visit(const NNodes::CAssignment *const node) = 0;
        virtual void Visit(const NNodes::CAssignmentAtPosition *const node) = 0;
        virtual void Visit(const NNodes::CPrintThing *const node) = 0;
        virtual void Visit(const NNodes::CWhileDo *const node) = 0;
        virtual void Visit(const NNodes::CIfDoElseDo *const node) = 0;
        virtual void Visit(const NNodes::CStatementSequence *const node) = 0;

        virtual void Visit(const NNodes::CTypedId *const node) = 0;
        virtual void Visit(const NNodes::CTypedIdSequence *const node) = 0;
        virtual void Visit(const NNodes::CMethodSignature *const node) = 0;
        virtual void Visit(const NNodes::CMethod *const node) = 0;
        virtual void Visit(const NNodes::CMethodSequence *const node) = 0;

        virtual void Visit(const NNodes::CClass *const node) = 0;
        virtual void Visit(const NNodes::CClassSequence *const node) = 0;

        virtual void Visit(const NNodes::CMain *const node) = 0;
        virtual void Visit(const NNodes::CProgram *const node) = 0;

    };
}

