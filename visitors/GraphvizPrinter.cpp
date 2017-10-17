#include "GraphvizPrinter.hpp"

#include <iostream>
#include <string>
#include <sstream>

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CIdExpression *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{Id|" + node->id + "}");
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CBasicType *const node) {
    std::string stringNode = formatNode(node);

    switch (node->type) {
        case NNodes::CBasicType::BT_BOOL:
            printNode(stringNode, "{Type|bool}");
            break;
        case NNodes::CBasicType::BT_INT:
            printNode(stringNode, "{Type|int}");
            break;
        case NNodes::CBasicType::BT_INT_ARRAY:
            printNode(stringNode, "{Type|int[]}");
            break;
    }
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CClassType *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{Type|" + node->name + '}');
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CIntegerExpression *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, std::to_string(node->value));
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CIntegerArithmeticOperation *const node) {
    std::string stringNode = formatNode(node);
    printEdge(formatNode(node, "left"), formatNode(node->left.get()));
    node->left->Visit(this);
    switch (node->type) {
        case NNodes::CIntegerArithmeticOperation::T_PLUS:
            printNode(stringNode, "{IntegerArithmetic|{<left>Left|PLUS|<right>right}}");
            break;
        case NNodes::CIntegerArithmeticOperation::T_MINUS:
            printNode(stringNode, "{IntegerArithmetic|{<left>Left|MINUS|<right>right}}");
            break;
        case NNodes::CIntegerArithmeticOperation::T_MULT:
            printNode(stringNode, "{IntegerArithmetic|{<left>Left|MULT|<right>right}}");
            break;
        case NNodes::CIntegerArithmeticOperation::T_MOD:
            printNode(stringNode, "{IntegerArithmetic|{<left>Left|MOD|<right>right}}");
            break;
    }
    printEdge(formatNode(node, "right"), formatNode(node->right.get()));
    node->right->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CBooleanExpression *const node) {
    std::string stringNode = formatNode(node);
    if (node->value) {
        printNode(stringNode, "True");
    } else {
        printNode(stringNode, "False");
    }
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CBooleanArithmeticOperation *const node) {
    std::string stringNode = formatNode(node);

    if (node->type != NNodes::CBooleanArithmeticOperation::T_BANG) {
        printEdge(formatNode(node, "left"), formatNode(node->left.get()));
        node->left->Visit(this);
    }
    switch (node->type) {
        case NNodes::CBooleanArithmeticOperation::T_AND:
            printNode(stringNode, "{BooleanArithmetic|{<left>Left|AND|<right>right}}");
            break;
        case NNodes::CBooleanArithmeticOperation::T_OR:
            printNode(stringNode, "{BooleanArithmetic|{<left>Left|OR|<right>right}}");
            break;
        case NNodes::CBooleanArithmeticOperation::T_LESS:
            printNode(stringNode, "{BooleanArithmetic|{<left>Left|LESS|<right>right}}");
            break;
        case NNodes::CBooleanArithmeticOperation::T_BANG:
            printNode(stringNode, "{BooleanArithmetic|{NOT|<right>right}}");
            break;
    }
    printEdge(formatNode(node, "right"), formatNode(node->right.get()));
    node->right->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CGetItemAtPosition *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{GetItem|{<object>Object|<position>Position}}");

    printEdge(formatNode(node, "object"), formatNode(node->object.get()));
    node->object->Visit(this);

    printEdge(formatNode(node, "position"), formatNode(node->position.get()));
    node->position->Visit(this);

}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CCallMethod *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{CallMethod " + node->name + "|{<object>Object|<parameters>Parameters}}");

    printEdge(formatNode(node, "object"), formatNode(node->object.get()));
    node->object->Visit(this);
    if (node->parameters) {
        printEdge(formatNode(node, "parameters"), formatNode(node->parameters.get()));
        node->parameters->Visit(this);
    }
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CGetLength *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{GetLength|<object>Object}");

    printEdge(formatNode(node, "object"), formatNode(node->object.get()));
    node->object->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CCreateNewObject *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "CreateNewObject\\n" + node->name);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CCreateNewArray *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{CreateNewArray|<size>Size}");

    printEdge(formatNode(node, "size"), formatNode(node->size.get()));
    node->size->Visit(this);

}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CGetThisId *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "This");
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CCallMethodParameters *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "CallMethodParameters");
    if (node->firstParameter) {
        printEdge(stringNode, formatNode(node->firstParameter.get()));
        node->firstParameter->Visit(this);
    }
    if (node->additionalParameters) {
        printEdge(stringNode, formatNode(node->additionalParameters.get()));
        node->additionalParameters->Visit(this);
    }

}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CAssignment *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{" + node->lValue + " =|{<rValue>RValue}}");

    printEdge(formatNode(node, "rValue"), formatNode(node->rValue.get()));
    node->rValue->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CAssignmentAtPosition *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{" + node->lValue + " =|{<position>Position|<rValue>RValue}}");

    printEdge(formatNode(node, "position"), formatNode(node->position.get()));
    node->position->Visit(this);

    printEdge(formatNode(node, "rValue"), formatNode(node->rValue.get()));
    node->rValue->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CPrintThing *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "Print");
    if (node->object) {
        printEdge(stringNode, formatNode(node->object.get()));
        node->object->Visit(this);
    }
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CWhileDo *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{While|{<condition>Condition|<action>Action|}}");

    printEdge(formatNode(node, "condition"), formatNode(node->condition.get()));
    node->condition->Visit(this);

    printEdge(formatNode(node, "action"), formatNode(node->action.get()));
    node->action->Visit(this);

}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CIfDoElseDo *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{If|{<condition>Condition|<ifAction>IfAction|<elseAction>ElseAction}}");

    printEdge(formatNode(node, "condition"), formatNode(node->condition.get()));
    node->condition->Visit(this);

    printEdge(formatNode(node, "ifAction"), formatNode(node->ifAction.get()));
    node->ifAction->Visit(this);

    printEdge(formatNode(node, "elseAction"), formatNode(node->elseAction.get()));
    node->elseAction->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CStatementSequence *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "StatementSequence");
    if (node->firstStatements) {
        printEdge(stringNode, formatNode(node->firstStatements.get()));
        node->firstStatements->Visit(this);
    }
    if (node->lastStatement) {
        printEdge(stringNode, formatNode(node->lastStatement.get()));
        node->lastStatement->Visit(this);
    }
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CTypedId *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "Id: " + node->name);
    printEdge(stringNode, formatNode(node->type.get()));
    node->type->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CTypedIdSequence *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "TypedIdSequence");
    if (node->firstTypedIds) {
        printEdge(stringNode, formatNode(node->firstTypedIds.get()));
        node->firstTypedIds->Visit(this);
    }
    if (node->lastTypedId) {
        printEdge(stringNode, formatNode(node->lastTypedId.get()));
        node->lastTypedId->Visit(this);
    }
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CMethodSignature *const node) {
    std::string stringNode = formatNode(node);

    if (node->isPrivate) {
        printNode(stringNode, "{Private " + node->name + "|{<type>Type|<parameters>Parameters}}");
    } else {
        printNode(stringNode, "{Public " + node->name + "|{<type>Type|<parameters>Parameters}}");
    }
    printEdge(formatNode(node, "type"), formatNode(node->type.get()));
    node->type->Visit(this);
    if (node->parameters) {
        printEdge(formatNode(node, "parameters"), formatNode(node->parameters.get()));
        node->parameters->Visit(this);
    }
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CMethod *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{Method|{<signature>Signature|<variables>Variables|<actions>Actions|<result>Result}}");

    printEdge(formatNode(node, "signature"), formatNode(node->signature.get()));
    node->signature->Visit(this);
    if (node->variables) {
        printEdge(formatNode(node, "variables"), formatNode(node->variables.get()));
        node->variables->Visit(this);
    }
    if (node->actions) {
        printEdge(formatNode(node, "actions"), formatNode(node->actions.get()));
        node->actions->Visit(this);
    }
    printEdge(formatNode(node, "result"), formatNode(node->result.get()));
    node->result->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CMethodSequence *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "MethodSequence");
    if (node->firstMethods) {
        printEdge(stringNode, formatNode(node->firstMethods.get()));
        node->firstMethods->Visit(this);
    }
    if (node->lastMethod) {
        printEdge(stringNode, formatNode(node->lastMethod.get()));
        node->lastMethod->Visit(this);
    }
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CClass *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{Class|{<variables>Variables|<methods>Methods}}");
    if (node->variables) {
        printEdge(formatNode(node, "variables"), formatNode(node->variables.get()));
        node->variables->Visit(this);
    }
    if (node->methods) {
        printEdge(formatNode(node, "methods"), formatNode(node->methods.get()));
        node->methods->Visit(this);
    }

}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CClassSequence *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "ClassSequence");
    if (node->firstClasses) {
        printEdge(stringNode, formatNode(node->firstClasses.get()));
        node->firstClasses->Visit(this);
    }
    if (node->lastClass) {
        printEdge(stringNode, formatNode(node->lastClass.get()));
        node->lastClass->Visit(this);
    }
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CMain *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "class: " + node->name + "\\ninput: " + node->input);
    printEdge(stringNode, formatNode(node->statements.get()));
    node->statements->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CProgram *const node) {
    std::cout << "digraph G {" << std::endl;
    std::string stringNode = formatNode(node);
    printNode(stringNode, "Program");

    printEdge(stringNode, formatNode(node->main.get()));
    node->main->Visit(this);
    if (node->classes) {
        printEdge(stringNode, formatNode(node->classes.get()));
        node->classes->Visit(this);
    }

    std::cout << '}' << std::endl;
}

std::string NVisitor::CGraphvizPrinter::formatNode(const NNodes::INode *node, const std::string tag) {
    std::ostringstream address;
    address << '"' << node << '"';
    if (tag.size() > 0) {
        address << ":<" << tag << '>';
    }
    return address.str();
}

void NVisitor::CGraphvizPrinter::printNode(const std::string node, const std::string lable) {
    std::cout << node << "[shape=record,label=\"" << lable << "\"];" << std::endl;
}

void NVisitor::CGraphvizPrinter::printEdge(const std::string parent, const std::string son, const std::string label) {
    std::cout << parent << "->" << son;
    if (label.size() > 0) {
        std::cout << "[label=\"" << label << "\"]";
    }
    std::cout << ';' << std::endl;
}


