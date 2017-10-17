#pragma once


namespace NNodes {
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


    class CBasicType;

    class CClassType;


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

#include "INode.hpp"

#include "IdExpression.hpp"
#include "IntegerExpression.hpp"
#include "IntegerArithmeticOperation.hpp"
#include "BooleanExpression.hpp"
#include "BooleanArithmeticOperation.hpp"
#include "GetItemAtPosition.hpp"
#include "CallMethod.hpp"
#include "GetLength.hpp"
#include "CreateNewObject.hpp"
#include "CreateNewArray.hpp"
#include "GetThisId.hpp"
#include "CallMethodParameters.hpp"


#include "BasicType.hpp"
#include "ClassType.hpp"


#include "Assignment.hpp"
#include "AssignmentAtPosition.hpp"
#include "PrintThing.hpp"
#include "WhileDo.hpp"
#include "IfDoElseDo.hpp"
#include "StatementSequence.hpp"


#include "TypedId.hpp"
#include "TypedIdSequence.hpp"
#include "MethodSignature.hpp"
#include "Method.hpp"
#include "MethodSequence.hpp"


#include "Class.hpp"
#include "ClassSequence.hpp"


#include "Main.hpp"
#include "Program.hpp"
