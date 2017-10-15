#include "PrettyPrinter.hpp"

#include <iostream>
#include <string>

void NVisitor::CPrettyPrinter::printIndent() const {
    std::cout << std::string(indent, ' ');
}

void NVisitor::CPrettyPrinter::increaseIndent() {
    indent += 4;
}

void NVisitor::CPrettyPrinter::dicreaseIndent() {
    indent -= 4;
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CIdExpression *const node) {
    std::cout << node->id;
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CBasicType *const node) {
    switch (node->type) {
        case NNodes::CBasicType::BT_BOOL:
            std::cout << "bool";
            break;
        case NNodes::CBasicType::BT_INT:
            std::cout << "int";
            break;
        case NNodes::CBasicType::BT_INT_ARRAY:
            std::cout << "int[]";
            break;
    }
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CClassType *const node) {
    std::cout << node->name;
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CIntegerExpression *const node) {
    std::cout << node->value;
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CIntegerArithmeticOperation *const node) {
    std::cout << '(';
    node->left->Visit(this);
    switch (node->type) {
        case NNodes::CIntegerArithmeticOperation::T_PLUS:
            std::cout << " + ";
            break;
        case NNodes::CIntegerArithmeticOperation::T_MINUS:
            std::cout << " - ";
            break;
        case NNodes::CIntegerArithmeticOperation::T_MULT:
            std::cout << " * ";
            break;
        case NNodes::CIntegerArithmeticOperation::T_MOD:
            std::cout << " % ";
            break;
    }
    node->right->Visit(this);
    std::cout << ')';
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CBooleanExpression *const node) {
    if (node->value) {
        std::cout << "True";
    } else {
        std::cout << "False";
    }
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CBooleanArithmeticOperation *const node) {
    std::cout << '(';
    if (node->type != NNodes::CBooleanArithmeticOperation::T_BANG) {
        node->left->Visit(this);
    }
    switch (node->type) {
        case NNodes::CBooleanArithmeticOperation::T_AND:
            std::cout << " and ";
            break;
        case NNodes::CBooleanArithmeticOperation::T_OR:
            std::cout << " or ";
            break;
        case NNodes::CBooleanArithmeticOperation::T_LESS:
            std::cout << " < ";
            break;
        case NNodes::CBooleanArithmeticOperation::T_BANG:
            std::cout << "not ";
            break;
    }
    node->right->Visit(this);
    std::cout << ')';
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CGetItemAtPosition *const node) {
    node->object->Visit(this);
    std::cout << '[';
    node->position->Visit(this);
    std::cout << ']';
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CCallMethod *const node) {
    node->object->Visit(this);
    std::cout << '.' << node->name << '(';
    if (node->parameters) {
        node->parameters->Visit(this);
    }
    std::cout << ')';
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CGetLength *const node) {
    node->object->Visit(this);
    std::cout << ".length";
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CCreateNewObject *const node) {
    std::cout << "new " << node->name << "()";
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CCreateNewArray *const node) {
    std::cout << "new int[";
    node->size->Visit(this);
    std::cout<< ']';
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CGetThisId *const node) {
    std::cout << "this";
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CCallMethodParameters *const node) {
    if (node->firstParameter) {
        node->firstParameter->Visit(this);
    }
    if (node->additionalParameters) {
        std::cout << ", ";
        node->additionalParameters->Visit(this);
    }

}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CAssignment *const node) {
    printIndent();
    std::cout << node->lValue << " = ";
    node->rValue->Visit(this);
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CAssignmentAtPosition *const node) {
    printIndent();
    std::cout << node->lValue << '[';
    node->position->Visit(this);
    std::cout << "] = ";
    node->rValue->Visit(this);
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CPrintThing *const node) {
    printIndent();
    std::cout << "print ";
    if (node->object) {
        node->object->Visit(this);
    }
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CWhileDo *const node) {
    printIndent();
    std::cout << "while ";
    node->condition->Visit(this);
    std::cout << ':' << std::endl;
    increaseIndent();
    node->action->Visit(this);
    dicreaseIndent();
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CIfDoElseDo *const node) {
    printIndent();
    std::cout << "if ";
    node->condition->Visit(this);
    std::cout << ':' << std::endl;
    increaseIndent();
    node->ifAction->Visit(this);
    dicreaseIndent();
    std::cout << std::endl;
    printIndent();
    std::cout << "else:" << std::endl;
    increaseIndent();
    node->elseAction->Visit(this);
    dicreaseIndent();
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CStatementSequence *const node) {
    if (node->firstStatements) {
        node->firstStatements->Visit(this);
    }
    if (node->lastStatement) {
        node->lastStatement->Visit(this);
        std::cout << std::endl;
    }
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CTypedId *const node) {
    node->type->Visit(this);
    std::cout << ' ' << node->name;
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CTypedIdSequence *const node) {
    if (node->firstTypedIds) {
        node->firstTypedIds->Visit(this);
        std::cout << ", ";
    }
    if (node->lastTypedId) {
        node->lastTypedId->Visit(this);
    }
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CMethodSignature *const node) {
    if (node->isPrivate) {
        std::cout << "private ";
    } else {
        std::cout << "public ";
    }
    node->type->Visit(this);
    std::cout << ' ' << node->name << '(';
    if (node->parameters) {
        node->parameters->Visit(this);
    }
    std::cout << ')';
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CMethod *const node) {
    printIndent();
    node->signature->Visit(this);
    std::cout << ':' << std::endl;
    increaseIndent();
    if (node->variables) {
        printIndent();
        node->variables->Visit(this);
        std::cout << std::endl;
    }
    if (node->actions) {
        node->actions->Visit(this);
    }
    printIndent();
    std::cout << "return ";
    node->result->Visit(this);
    std::cout << std::endl;
    dicreaseIndent();
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CMethodSequence *const node) {
    if (node->firstMethods) {
        node->firstMethods->Visit(this);
        std::cout << std::endl;
    }
    if (node->lastMethod) {
        node->lastMethod->Visit(this);
    }
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CClass *const node) {
    printIndent();
    std::cout << "class " << node->name << '(' << node->extendsName << "):" << std::endl;
    increaseIndent();
    printIndent();
    if (node->variables) {
        node->variables->Visit(this);
        std::cout << std::endl;
        std::cout << std::endl;
    }
    if (node->methods) {
        node->methods->Visit(this);
    }
    dicreaseIndent();
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CClassSequence *const node) {
    if (node->firstClasses) {
        node->firstClasses->Visit(this);
        std::cout << std::endl << std::endl;
    }
    if (node->lastClass) {
        node->lastClass->Visit(this);
    }
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CMain *const node) {
    printIndent();
    std::cout << "class " << node->name << "():" << std::endl;
    increaseIndent();
    printIndent();
    std::cout << "def main(" << node->input << "):" << std::endl;
    increaseIndent();
    node->statements->Visit(this);
    dicreaseIndent();
    dicreaseIndent();
}

void NVisitor::CPrettyPrinter::Visit(const NNodes::CProgram *const node) {
    node->main->Visit(this);
    if (node->classes) {
        std::cout << std::endl << std::endl;
        node->classes->Visit(this);
    }
}
