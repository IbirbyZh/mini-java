#include "GraphvizPrinter.hpp"

#include <iostream>
#include <sstream>

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CIdExpression *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "Id: " + node->id);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CBasicType *const node) {
    std::string stringNode = formatNode(node);

    switch (node->type) {
        case NNodes::CBasicType::BT_BOOL:
            printNode(stringNode, "bool");
            break;
        case NNodes::CBasicType::BT_INT:
            printNode(stringNode, "int");
            break;
        case NNodes::CBasicType::BT_INT_ARRAY:
            printNode(stringNode, "int[]");
            break;
    }
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CClassType *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "class" + node->name);
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

    printNodes(node->parameters, formatNode(node, "parameters"), "ololo", "cyan");
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

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CAssignment *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "<statement>ST|{" + node->lValue + " =|<rValue>RValue}");

    printEdge(formatNode(node, "rValue"), formatNode(node->rValue.get()));
    node->rValue->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CAssignmentAtPosition *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "<statement>ST|{" + node->lValue + " =|{<position>Position|<rValue>RValue}}");

    printEdge(formatNode(node, "position"), formatNode(node->position.get()));
    node->position->Visit(this);

    printEdge(formatNode(node, "rValue"), formatNode(node->rValue.get()));
    node->rValue->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CPrintThing *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "<statement>ST|<print>Print");
    if (node->object) {
        printEdge(formatNode(node, "print"), formatNode(node->object.get()));
        node->object->Visit(this);
    }
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CWhileDo *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "<statement>ST|{While|{<condition>Condition|<action>Action}}");

    printEdge(formatNode(node, "condition"), formatNode(node->condition.get()));
    node->condition->Visit(this);

    printStatements(node->actions, formatNode(node, "action"));

}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CIfDoElseDo *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "<statement>ST|{If|{<condition>Condition|<ifAction>IfAction|<elseAction>ElseAction}}");

    printEdge(formatNode(node, "condition"), formatNode(node->condition.get()));
    node->condition->Visit(this);


    printStatements(node->ifAction, formatNode(node, "ifAction"));
    printStatements(node->elseAction, formatNode(node, "elseAction"));
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CTypedId *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "<variable>VR|{<id>Id: " + node->name + "|<type>Type}");

    printEdge(formatNode(node, "type"), formatNode(node->type.get()));
    node->type->Visit(this);
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

    printVariables(node->parameters, formatNode(node, "parameters"), "blue");
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CMethod *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode,
              "<method>MT|{Method|{<signature>Signature|<variables>Variables|<actions>Actions|<result>Result}}");

    printEdge(formatNode(node, "signature"), formatNode(node->signature.get()));
    node->signature->Visit(this);

    printVariables(node->variables, formatNode(node, "variables"), "gold");

    printStatements(node->actions, formatNode(node, "actions"));

    printEdge(formatNode(node, "result"), formatNode(node->result.get()));
    node->result->Visit(this);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CClass *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "<class>Class|<variables>Variables|<methods>Methods");

    printVariables(node->variables, formatNode(node, "variables"), "gold");
    printMethods(node->methods, formatNode(node, "methods"));

}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CMain *const node) {
    std::string stringNode = formatNode(node);
    printNode(stringNode, "class: " + node->name + "\\ninput: " + node->input);

    printStatements(node->statements, stringNode);
}

void NVisitor::CGraphvizPrinter::Visit(const NNodes::CProgram *const node) {
    std::cout << "digraph G {" << std::endl;
    std::string stringNode = formatNode(node);
    printNode(stringNode, "{Program|{<main>Main|<classes>Classes}}");

    printEdge(formatNode(node, "main"), formatNode(node->main.get()));
    node->main->Visit(this);

    stringNode = formatNode(node, "classes");
    for (auto &&class_:node->classes) {
        printEdge(stringNode, formatNode(class_.get(), "class"), "", "green");
        class_->Visit(this);
        stringNode = formatNode(class_.get(), "class");
    }

    std::cout << '}' << std::endl;
}

std::string NVisitor::CGraphvizPrinter::formatNode(const NNodes::INode *node, const std::string &tag) {
    std::ostringstream address;
    address << '"' << node << '"';
    if (tag.size() > 0) {
        address << ":<" << tag << '>';
    }
    return address.str();
}

void NVisitor::CGraphvizPrinter::printNode(const std::string &node, const std::string &lable) {
    std::cout << node << "[shape=record,label=\"" << lable << "\"];" << std::endl;
}

void NVisitor::CGraphvizPrinter::printEdge(const std::string &parent, const std::string &son, const std::string &label,
                                           const std::string &color) {
    std::cout << parent << "->" << son;
    if (label.size() > 0 && color.size() == 0) {
        std::cout << "[label=\"" << label << "\"]";
    }
    if (label.size() == 0 && color.size() > 0) {
        std::cout << "[color=\"" << color << "\"]";
    }
    if (label.size() > 0 && color.size() > 0) {
        std::cout << "[label=\"" << label << ",color=\"" << color << "\"]";
    }

    std::cout << ';' << std::endl;
}


void NVisitor::CGraphvizPrinter::printStatements(
        const std::vector<std::shared_ptr<const NNodes::IStatement>> &statements,
        const std::string &node
) {
    std::string stringNode = node;
    for (auto &&statement :statements) {
        printEdge(stringNode, formatNode(statement.get(), "statement"), "", "red");
        statement->Visit(this);
        stringNode = formatNode(statement.get(), "statement");
    }
}

void NVisitor::CGraphvizPrinter::printMethods(
        const std::vector<std::shared_ptr<const NNodes::CMethod>> &methods,
        const std::string &node
) {
    std::string stringNode = node;
    for (auto &&statement :methods) {
        printEdge(stringNode, formatNode(statement.get(), "method"), "", "orange");
        statement->Visit(this);
        stringNode = formatNode(statement.get(), "method");
    }
}

void NVisitor::CGraphvizPrinter::printVariables(
        const std::vector<std::shared_ptr<const NNodes::CTypedId>> &variables,
        const std::string &node,
        const std::string &color
) {
    std::string stringNode = node;
    for (auto &&statement :variables) {
        printEdge(stringNode, formatNode(statement.get(), "variable"), "", color);
        statement->Visit(this);
        stringNode = formatNode(statement.get(), "variable");
    }
}

void NVisitor::CGraphvizPrinter::printNodes(
        const std::vector<std::shared_ptr<const NNodes::INode>> &nodes,
        const std::string &node,
        const std::string &tag,
        const std::string &color

) {
    std::string stringNode = node;
    for (auto &&statement :nodes) {
        printEdge(stringNode, formatNode(statement.get(), tag), "", color);
        statement->Visit(this);
        stringNode = formatNode(statement.get(), tag);
    }
}
