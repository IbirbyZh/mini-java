#include "TypeChecker.hpp"
#include "StringInternist.hpp"
#include <set>
#include <iostream>

void NVisitor::CTypeChecker::Visit(const NNodes::CBasicType *const node) {
    switch (node->GetType()) {
        case NNodes::CBasicType::BT_BOOL:
            expressionType = boolType;
            break;
        case NNodes::CBasicType::BT_INT:
            expressionType = intType;
            break;
        case NNodes::CBasicType::BT_INT_ARRAY:
            expressionType = intArrayType;
            break;
    }
}

void NVisitor::CTypeChecker::Visit(const NNodes::CClassType *const node) {
    auto &&classInfo = table->GetClassInfo(node->GetName());
    if (classInfo == nullptr) {
        std::cout << "ERROR: Wrong Type";
        printPosition(node);
        expressionType = nullptr;
    } else {
        expressionType = classInfo->GetName();
    }

}

void NVisitor::CTypeChecker::Visit(const NNodes::CIdExpression *const node) {
    auto &&variableInfo = table->FindNameInScope(node->GetId());
    if (variableInfo == nullptr) {
        std::cout << "ERROR: Undefined variable";
        printPosition(node);
        expressionType = nullptr;
    } else {
        expressionType = variableInfo->GetType();
    }
}

void NVisitor::CTypeChecker::Visit(const NNodes::CIntegerExpression *const node) {
    expressionType = intType;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CIntegerArithmeticOperation *const node) {

    node->GetLeft()->Visit(this);
    if (expressionType != intType) {
        std::cout << "ERROR: Wrong left operand " << expressionType->ToString();
        printPosition(node);
    }
    expressionType = nullptr;

    node->GetRight()->Visit(this);
    if (expressionType != intType) {
        std::cout << "ERROR: Wrong right operand " << expressionType->ToString();
        printPosition(node);
    }
    expressionType = intType;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CBooleanExpression *const node) {
    expressionType = boolType;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CBooleanArithmeticOperation *const node) {
    switch (node->GetType()) {
        case NNodes::CBooleanArithmeticOperation::T_AND:
        case NNodes::CBooleanArithmeticOperation::T_OR:
            node->GetLeft()->Visit(this);
            if (expressionType != boolType) {
                std::cout << "ERROR: Wrong left operand " << expressionType->ToString();
                printPosition(node);
            }
            expressionType = nullptr;
        case NNodes::CBooleanArithmeticOperation::T_BANG:
            node->GetRight()->Visit(this);
            if (expressionType != boolType) {
                std::cout << "ERROR: Wrong right operand " << expressionType->ToString();
                printPosition(node);
            }
            break;
        case NNodes::CBooleanArithmeticOperation::T_LESS:
            node->GetLeft()->Visit(this);
            if (expressionType != intType) {
                std::cout << "ERROR: Wrong left operand " << expressionType->ToString();
                printPosition(node);
            }
            expressionType = nullptr;
            node->GetRight()->Visit(this);
            if (expressionType != intType) {
                std::cout << "ERROR: Wrong right operand " << expressionType->ToString();
                printPosition(node);
            }
            break;

    }
    expressionType = boolType;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CGetItemAtPosition *const node) {
    node->GetObject()->Visit(this);
    if (expressionType != intArrayType) {
        std::cout << "ERROR: No item getter";
        printPosition(node);
    }
    node->GetPosition()->Visit(this);
    if (expressionType != intType) {
        std::cout << "ERROR: Array index not int";
        printPosition(node);
    }
    expressionType = intType;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CCallMethod *const node) {
    node->GetObject()->Visit(this);
    const NTable::CSymbol *objectType = expressionType;

    auto &&classInfo = table->GetClassInfo(objectType);
    if (classInfo == nullptr) {
        std::cout << "ERROR: Call method of wrong class";
        printPosition(node);
        expressionType = nullptr;
        return;
    }

    auto &&methodInfo = table->GetMethodInfo(
            classInfo->GetName(),
            NTable::CStringInternist::GetInstance().Intern(node->GetName())
    );
    if (methodInfo == nullptr) {
        std::cout << "ERROR: Unknown method name";
        printPosition(node);
        expressionType = nullptr;
        return;
    }

    if (node->GetParameters().size() != methodInfo->GetPositionParameters().size()) {
        std::cout << "ERROR: Wrong parameters number";
        printPosition(node);
        expressionType = nullptr;
        return;
    } else {
        for (int i = 0; i < methodInfo->GetPositionParameters().size(); ++i) {
            node->GetParameters()[i]->Visit(this);
            if (expressionType != methodInfo->GetPositionParameters()[i]) {
                std::cout << "ERROR: Wrong parameter type " << expressionType->ToString();
                printPosition(node);
            }
        }
    }
    expressionType = methodInfo->GetType();
}

void NVisitor::CTypeChecker::Visit(const NNodes::CGetLength *const node) {
    node->GetObject()->Visit(this);
    if (expressionType != intArrayType) {
        std::cout << "ERROR: No length attribute";
        printPosition(node);
    }
    expressionType = intType;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CCreateNewObject *const node) {
    const NTable::CSymbol *objectType = NTable::CStringInternist::GetInstance().Intern(node->GetName());
    auto &&classInfo = table->GetClassInfo(node->GetName());
    if (objectType != boolType and objectType != intType and objectType != intArrayType
        and classInfo == nullptr) {
        std::cout << "ERROR: Wrong type";
        printPosition(node);
    }
    expressionType = objectType;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CCreateNewArray *const node) {
    node->GetSize()->Visit(this);
    if (expressionType != intType) {
        std::cout << "ERROR: Size of array not int";
        printPosition(node);
    }
    expressionType = intArrayType;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CGetThisId *const node) {
    expressionType = table->GetCurrentClass();
}

void NVisitor::CTypeChecker::Visit(const NNodes::CAssignment *const node) {
    node->GetRValue()->Visit(this);
    auto &&variableInfo = table->FindNameInScope(node->GetLValue());
    if (variableInfo == nullptr) {
        std::cout << "ERROR: No variable in scope";
        printPosition(node);
    } else if (variableInfo->GetType() != expressionType) {
        std::cout << "ERROR: Different types";
        printPosition(node);
    }
    expressionType = nullptr;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CAssignmentAtPosition *const node) {
    auto &&variableInfo = table->FindNameInScope(node->GetLValue());
    if (variableInfo == nullptr) {
        std::cout << "ERROR: No variable in scope";
        printPosition(node);
    } else if (variableInfo->GetType() != intArrayType) {
        std::cout << "ERROR: No item getter";
        printPosition(node);
    }

    node->GetPosition()->Visit(this);
    if (expressionType != intType) {
        std::cout << "ERROR: Assignment in non int index";
        printPosition(node);
    }
    node->GetRValue()->Visit(this);
    if (expressionType != intType) {
        std::cout << "ERROR: Assignment non int to int[]";
        printPosition(node);
    }
    expressionType = nullptr;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CPrintThing *const node) {
    node->GetObject()->Visit(this);
    if (expressionType != boolType and expressionType != intType and expressionType != intArrayType) {
        std::cout << "ERROR: Can't print custom class";
        printPosition(node);
    }
    expressionType = nullptr;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CWhileDo *const node) {
    node->GetCondition()->Visit(this);
    if (expressionType != boolType) {
        std::cout << "ERROR: Wrong condition type";
        printPosition(node);
    }
    expressionType = nullptr;
    for (auto &&item:node->GetActions()) {
        item->Visit(this);
    }
    expressionType = nullptr;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CIfDoElseDo *const node) {
    node->GetCondition()->Visit(this);
    if (expressionType != boolType) {
        std::cout << "ERROR: Wrong condition type";
        printPosition(node);
    }
    expressionType = nullptr;
    for (auto &&item:node->GetIfAction()) {
        item->Visit(this);
    }
    expressionType = nullptr;
    for (auto &&item:node->GetElseAction()) {
        item->Visit(this);
    }
    expressionType = nullptr;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CTypedId *const node) {
    node->GetType()->Visit(this);
}

void NVisitor::CTypeChecker::Visit(const NNodes::CMethodSignature *const node) {
    node->GetType()->Visit(this);
    std::set<const NTable::CSymbol *> parameters;
    for (auto &&item:node->GetParameters()) {
        item->Visit(this);
        const NTable::CSymbol *name = NTable::CStringInternist::GetInstance().Intern(item->GetName());
        if (parameters.find(name) != parameters.end()) {
            std::cout << "ERROR: Copy parameter name";
            printPosition(node);
        }
        parameters.insert(name);
    }
    expressionType = NTable::CStringInternist::GetInstance().Intern(node->GetType()->ToString());
}

void NVisitor::CTypeChecker::Visit(const NNodes::CMethod *const node) {
    node->GetSignature()->Visit(this);
    const NTable::CSymbol *resultType = expressionType;
    for (auto &&item:node->GetVariables()) {
        item->Visit(this);
    }

    table->AddScope(currentClass, NTable::CStringInternist::GetInstance().Intern(node->GetSignature()->GetName()));
    for (auto &&item:node->GetActions()) {
        item->Visit(this);
    }

    node->GetResult()->Visit(this);
    if (expressionType != resultType) {
        std::cout << "ERROR: Wrong result type";
        printPosition(node);
    }

    table->PopScope();
    expressionType = nullptr;
}

void NVisitor::CTypeChecker::Visit(const NNodes::CClass *const node) {
    currentClass = NTable::CStringInternist::GetInstance().Intern(node->GetName());
    if (!table->IsValidParentClasses(currentClass)) {
        std::cout << "ERROR: Problem in class inheritance";
        printPosition(node);
        return;
    }

    for (auto &&item: node->GetMethods()) {
        item->Visit(this);
    }
    currentClass = nullptr;
    expressionType = nullptr;

}

void NVisitor::CTypeChecker::Visit(const NNodes::CMain *const node) {
    for (auto &&item:node->GetStatements()) {
        item->Visit(this);
    }
}

void NVisitor::CTypeChecker::Visit(const NNodes::CProgram *const node) {
    table = std::make_shared<NTable::CTable>(node);
    node->GetMain()->Visit(this);
    for (auto &&_class: node->GetClasses()) {
        _class->Visit(this);
    }
}

NVisitor::CTypeChecker::CTypeChecker()
        : table(nullptr),
          currentClass(nullptr),
          expressionType(nullptr),
          boolType(NTable::CStringInternist::GetInstance().Intern("bool")),
          intType(NTable::CStringInternist::GetInstance().Intern("int")),
          intArrayType(NTable::CStringInternist::GetInstance().Intern("int[]")) {
}

void NVisitor::CTypeChecker::printPosition(const NNodes::INode *const node) const {
    std::cout << ' ' << node->startLine << ':' << node->startColumn << std::endl;
}
