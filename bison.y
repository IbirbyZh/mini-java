%code requires {
    #include "Nodes.hpp"
    #include <memory>
    #include <string>

    using namespace NNodes;

}

%{
    #include "tokens.h"
    #include "Nodes.hpp"
    using namespace NNodes;
    #include <iostream>
    #include <memory>
    #include "GraphvizPrinter.hpp"
    #include "TypeChecker.cpp"
    NVisitor::IVisitor *prettyPrinter = new NVisitor::CTypeChecker();
    extern int yylex();
    void yyerror(char *s);
%}

%token T_CLASS
%token T_INT
%token T_BOOLEAN

%token T_TRUE
%token T_FALSE

%token T_THIS
%token T_NEW
%token T_PUBLIC
%token T_PRIVATE
%token T_EXTENDS
%token T_RETURN

%token T_SEMI
%token T_DOT
%token T_COMMA
%token T_ASSIGN

%token T_L_PAREN
%token T_R_PAREN
%token T_L_SQUARE
%token T_R_SQUARE
%token T_L_BRACE
%token T_R_BRACE

%token T_IF
%token T_ELSE
%token T_WHILE

%token T_AND
%token T_LESS
%token T_PLUS
%token T_MINUS
%token T_MULT
%token T_MOD
%token T_OR
%token T_BANG

%token T_LENGTH
%token T_PRINT_LINE
%token T_MAIN
%token T_STRING

%token T_ID
%token T_INTEGER_NUMBER

%token T_END_LINE

%token T_ERROR

%token T_END 0

%locations

%union {
    long intValue;
    char *strValue;
    char *stringValue;
    int integerValue;
    CProgram *program;
    CMain *mainClass;
    CClass *additionalClass;
    CClassSequence *additionalClasses;
    IType *type;
    CTypedId *typedId;
    CTypedIdSequence *typedIdSequence;
    CMethodSignature *methodSignature;
    CMethod *method;
    CMethodSequence *methodSequence;
    IStatement *statement;
    CStatementSequence *statementSequence;
    INode *node;
    CCallMethodParameters *callMethodParameters;
};

%type<integerValue> integer_number
%type<stringValue> main_signature id
%type<program> goal
%type<mainClass> class_main
%type<additionalClass> class
%type<additionalClasses> seq_class
%type<type> type
%type<typedId> var argument
%type<typedIdSequence> seq_var method_params
%type<methodSignature> method_signature
%type<method> method
%type<methodSequence> seq_method
%type<statement> statement
%type<statementSequence> seq_statement
%type<node> exp operation
%type<callMethodParameters> run_method_params


%nonassoc T_AND
%nonassoc T_OR
%nonassoc T_LESS



%left T_MINUS T_PLUS
%left T_MOD
%left T_MULT

%right T_BANG

%left T_DOT
%left T_L_SQUARE



%%
goal
  : class_main T_END                                                {$$ = new CProgram(std::shared_ptr<CMain>($1), nullptr); $$->AddLocation(yylloc.first_line, yylloc.first_column); $$->Visit(prettyPrinter); delete prettyPrinter;}
  | class_main seq_class T_END                                      {$$ = new CProgram(std::shared_ptr<CMain>($1), std::shared_ptr<CClassSequence>($2)); $$->AddLocation(yylloc.first_line, yylloc.first_column); $$->Visit(prettyPrinter); delete prettyPrinter;}
;


main_signature
  : T_PUBLIC T_MAIN T_L_PAREN
        T_STRING T_L_SQUARE T_R_SQUARE id
    T_R_PAREN                                                       {$$ = $7;}
;


class_main 
  : T_CLASS id T_L_BRACE
        main_signature T_L_BRACE
            seq_statement
        T_R_BRACE
    T_R_BRACE                                                       {$$ = new CMain($2, $4, std::shared_ptr<CStatementSequence>($6)); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2; delete[] $4;}

  | T_CLASS id T_L_BRACE
        main_signature T_L_BRACE

        T_R_BRACE
    T_R_BRACE                                                       {$$ = new CMain($2, $4, nullptr); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2; delete[] $4;}
;


class
  : T_CLASS id T_L_BRACE
        seq_var
        seq_method
    T_R_BRACE                                                       {$$ = new CClass($2, std::shared_ptr<CTypedIdSequence>($4), std::shared_ptr<CMethodSequence>($5)); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2;}

  | T_CLASS id T_L_BRACE
        seq_method
    T_R_BRACE                                                       {$$ = new CClass($2, nullptr, std::shared_ptr<CMethodSequence>($4)); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2;}

  | T_CLASS id T_L_BRACE
        seq_var
    T_R_BRACE                                                       {$$ = new CClass($2, std::shared_ptr<CTypedIdSequence>($4), nullptr); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2;}

  | T_CLASS id T_L_BRACE
    T_R_BRACE                                                       {$$ = new CClass($2, nullptr, nullptr); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2;}

  | T_CLASS id T_EXTENDS id T_L_BRACE
        seq_var
        seq_method
    T_R_BRACE                                                       {$$ = new CClass($2, std::shared_ptr<CTypedIdSequence>($6), std::shared_ptr<CMethodSequence>($7), $4); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2; delete[] $4;}

  | T_CLASS id T_EXTENDS id T_L_BRACE
        seq_method
    T_R_BRACE                                                       {$$ = new CClass($2, nullptr, std::shared_ptr<CMethodSequence>($6), $4); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2; delete[] $4;}

  | T_CLASS id T_EXTENDS id T_L_BRACE
        seq_var
    T_R_BRACE                                                       {$$ = new CClass($2, std::shared_ptr<CTypedIdSequence>($6), nullptr, $4); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2; delete[] $4;}

  | T_CLASS id T_EXTENDS id T_L_BRACE
    T_R_BRACE                                                       {$$ = new CClass($2, nullptr, nullptr, $4); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2; delete[] $4;}
;


seq_class
  : class                                                           {$$ = new CClassSequence(nullptr, std::shared_ptr<CClass>($1));}
  | seq_class class                                                 {$$ = new CClassSequence(std::shared_ptr<CClassSequence>($1), std::shared_ptr<CClass>($2));}
;


type
  : T_INT T_L_SQUARE T_R_SQUARE                                     {$$ = new CBasicType(CBasicType::BT_INT_ARRAY); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | T_BOOLEAN                                                       {$$ = new CBasicType(CBasicType::BT_BOOL); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | T_INT                                                           {$$ = new CBasicType(CBasicType::BT_INT); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | id                                                              {$$ = new CClassType($1); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $1;}
;


var
  : type id T_SEMI                                                  {$$ = new CTypedId(std::shared_ptr<IType>($1), $2); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2;}
;


seq_var
  : var                                                             {$$ = new CTypedIdSequence(nullptr, std::shared_ptr<CTypedId>($1));}
  | seq_var var                                                     {$$ = new CTypedIdSequence(std::shared_ptr<CTypedIdSequence>($1), std::shared_ptr<CTypedId>($2));}
;


argument
  : type id                                                         {$$ = new CTypedId(std::shared_ptr<IType>($1), $2); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2;}
;


method_params
  :                                                                 {$$ = nullptr;}
  | argument                                                        {$$ = new CTypedIdSequence(nullptr, std::shared_ptr<CTypedId>($1));}
  | argument T_COMMA method_params                                  {$$ = new CTypedIdSequence(std::shared_ptr<CTypedIdSequence>($3), std::shared_ptr<CTypedId>($1));}
;


method_signature
  : T_PUBLIC type id T_L_PAREN method_params T_R_PAREN              {$$ = new CMethodSignature(false, std::shared_ptr<IType>($2), $3, std::shared_ptr<CTypedIdSequence>($5)); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $3;}
  | T_PRIVATE type id T_L_PAREN method_params T_R_PAREN             {$$ = new CMethodSignature(true, std::shared_ptr<IType>($2), $3, std::shared_ptr<CTypedIdSequence>($5)); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $3;}


method
  : method_signature T_L_BRACE
        seq_var seq_statement T_RETURN exp T_SEMI
    T_R_BRACE                                                       {$$ = new CMethod(std::shared_ptr<CMethodSignature>($1), std::shared_ptr<CTypedIdSequence>($3), std::shared_ptr<CStatementSequence>($4), std::shared_ptr<INode>($6)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}

  | method_signature T_L_BRACE
        seq_statement T_RETURN exp T_SEMI
    T_R_BRACE                                                       {$$ = new CMethod(std::shared_ptr<CMethodSignature>($1), nullptr, std::shared_ptr<CStatementSequence>($3), std::shared_ptr<INode>($5)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}

  | method_signature T_L_BRACE
        seq_var T_RETURN exp T_SEMI
    T_R_BRACE                                                       {$$ = new CMethod(std::shared_ptr<CMethodSignature>($1), std::shared_ptr<CTypedIdSequence>($3), nullptr, std::shared_ptr<INode>($5)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}

  | method_signature T_L_BRACE
        T_RETURN exp T_SEMI
    T_R_BRACE                                                       {$$ = new CMethod(std::shared_ptr<CMethodSignature>($1), nullptr, nullptr, std::shared_ptr<INode>($4)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
;


seq_method
  : method                                                          {$$ = new CMethodSequence(nullptr, std::shared_ptr<CMethod>($1));}
  | seq_method method                                               {$$ = new CMethodSequence(std::shared_ptr<CMethodSequence>($1), std::shared_ptr<CMethod>($2));}
;


statement 
  : T_L_BRACE
        seq_statement
    T_R_BRACE                                                       {$$ = $2;}
  | T_IF T_L_PAREN exp T_R_PAREN statement T_ELSE statement         {$$ = new CIfDoElseDo(std::shared_ptr<INode>($3), std::shared_ptr<IStatement>($5), std::shared_ptr<IStatement>($7)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | T_WHILE T_L_PAREN exp T_R_PAREN statement                       {$$ = new CWhileDo(std::shared_ptr<INode>($3), std::shared_ptr<IStatement>($5)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | T_PRINT_LINE T_L_PAREN exp T_R_PAREN T_SEMI                     {$$ = new CPrintThing(std::shared_ptr<INode>($3)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | id T_ASSIGN exp T_SEMI                                          {$$ = new CAssignment($1, std::shared_ptr<INode>($3)); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $1;}
  | id T_L_SQUARE exp T_R_SQUARE T_ASSIGN exp T_SEMI                {$$ = new CAssignmentAtPosition($1, std::shared_ptr<INode>($3), std::shared_ptr<INode>($6)); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $1;}
;


seq_statement
  : statement                                                       {$$ = new CStatementSequence(nullptr, std::shared_ptr<IStatement>($1)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | seq_statement statement                                         {$$ = new CStatementSequence(std::shared_ptr<CStatementSequence>($1), std::shared_ptr<IStatement>($2)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
;


operation
  : exp T_AND exp                                                   {$$ = new CBooleanArithmeticOperation(std::shared_ptr<INode>($1), CBooleanArithmeticOperation::T_AND, std::shared_ptr<INode>($3)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | exp T_OR exp                                                    {$$ = new CBooleanArithmeticOperation(std::shared_ptr<INode>($1), CBooleanArithmeticOperation::T_OR, std::shared_ptr<INode>($3)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | exp T_LESS exp                                                  {$$ = new CBooleanArithmeticOperation(std::shared_ptr<INode>($1), CBooleanArithmeticOperation::T_LESS, std::shared_ptr<INode>($3)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | exp T_PLUS exp                                                  {$$ = new CIntegerArithmeticOperation(std::shared_ptr<INode>($1), CIntegerArithmeticOperation::T_PLUS, std::shared_ptr<INode>($3)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | exp T_MINUS exp                                                 {$$ = new CIntegerArithmeticOperation(std::shared_ptr<INode>($1), CIntegerArithmeticOperation::T_MINUS, std::shared_ptr<INode>($3)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | exp T_MULT exp                                                  {$$ = new CIntegerArithmeticOperation(std::shared_ptr<INode>($1), CIntegerArithmeticOperation::T_MULT, std::shared_ptr<INode>($3)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | exp T_MOD exp                                                   {$$ = new CIntegerArithmeticOperation(std::shared_ptr<INode>($1), CIntegerArithmeticOperation::T_MOD, std::shared_ptr<INode>($3)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
;


exp
  : operation                                                       {$$ = $1;}
  | exp T_L_SQUARE exp T_R_SQUARE                                   {$$ = new CGetItemAtPosition(std::shared_ptr<INode>($1), std::shared_ptr<INode>($3)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | exp T_DOT T_LENGTH                                              {$$ = new CGetLength(std::shared_ptr<INode>($1)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | exp T_DOT id T_L_PAREN run_method_params T_R_PAREN              {$$ = new CCallMethod(std::shared_ptr<INode>($1), $3, std::shared_ptr<CCallMethodParameters>($5)); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $3;}
  | integer_number                                                  {$$ = new CIntegerExpression($1); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | T_TRUE                                                          {$$ = new CBooleanExpression(true); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | T_FALSE                                                         {$$ = new CBooleanExpression(false); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | id                                                              {$$ = new CIdExpression($1); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $1;}
  | T_THIS                                                          {$$ = new CGetThisId(); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | T_NEW T_INT T_L_SQUARE exp T_R_SQUARE                           {$$ = new CCreateNewArray(std::shared_ptr<INode>($4)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | T_NEW id T_L_PAREN T_R_PAREN                                    {$$ = new CCreateNewObject($2); $$->AddLocation(yylloc.first_line, yylloc.first_column); delete[] $2;}
  | T_BANG exp                                                      {$$ = new CBooleanArithmeticOperation(nullptr, CBooleanArithmeticOperation::T_BANG, std::shared_ptr<INode>($2)); $$->AddLocation(yylloc.first_line, yylloc.first_column);}
  | T_L_PAREN exp T_R_PAREN                                         {$$ = $2;}
;


run_method_params
  :                                                                 {$$ = nullptr;}
  | exp                                                             {$$ = new CCallMethodParameters(std::shared_ptr<INode>($1), nullptr);}
  | exp T_COMMA run_method_params                                   {$$ = new CCallMethodParameters(std::shared_ptr<INode>($1), std::shared_ptr<CCallMethodParameters>($3));}
;


id
  : T_ID                                                            {$$ = new char[strlen(yylval.strValue)]; strcpy($$, yylval.strValue);}
;


integer_number
  : T_INTEGER_NUMBER                                                {$$ = yylval.intValue;}
;
%%



void yyerror(char* s) {
    printf("ERROR: Grammar error (%s) at %d,%d:%d\n",
        s, yylloc.first_line, yylloc.first_column, yylloc.last_column);
}

int main(void) {
    yyparse();
}