%{
    #include <stdio.h>
    #include "tokens.h"
    #include "Nodes.hpp"

    extern "C" int yylex();
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

%token T_END 0

%locations

%union {
    long intValue;
    char *strValue;
};

%type<strValue> T_ID
%type<intValue> T_INTEGER_NUMBER


%nonassoc T_AND
%nonassoc T_OR
%nonassoc T_LESS



%left T_MINUS T_PLUS
%left T_MOD
%left T_MULT

%left T_DOT
%left T_L_SQUARE
%right T_BANG


%%
goal
  : class_main T_END                                                            {printf("only main\n");}
  | class_main seq_class T_END                                                  {printf("not only main\n");}
;


main_signature
  : T_PUBLIC T_MAIN T_L_PAREN T_STRING T_L_SQUARE T_R_SQUARE T_ID T_R_PAREN
;


class_main 
  : T_CLASS T_ID T_L_BRACE
         main_signature T_L_BRACE
            seq_statement
        T_R_BRACE
    T_R_BRACE

  | T_CLASS T_ID T_L_BRACE
        main_signature T_L_BRACE
            T_R_BRACE
        T_R_BRACE
;


class
  : T_CLASS T_ID T_L_BRACE
        seq_var
        seq_method
    T_R_BRACE

  | T_CLASS T_ID T_L_BRACE
        seq_method
    T_R_BRACE

  | T_CLASS T_ID T_L_BRACE
        seq_var
    T_R_BRACE

  | T_CLASS T_ID T_L_BRACE
    T_R_BRACE

  | T_CLASS T_ID T_L_BRACE T_EXTENDS T_ID
        seq_var
        seq_method
    T_R_BRACE

  | T_CLASS T_ID T_L_BRACE T_EXTENDS T_ID
        seq_method
    T_R_BRACE

  | T_CLASS T_ID T_L_BRACE T_EXTENDS T_ID
        seq_var
    T_R_BRACE

  | T_CLASS T_ID T_L_BRACE T_EXTENDS T_ID
    T_R_BRACE
;


seq_class
  : class
  | seq_class class
;


type
  : T_INT T_L_SQUARE T_R_SQUARE                                     {/*BasicType*/}
  | T_BOOLEAN                                                       {/*BasicType*/}
  | T_INT                                                           {/*BasicType*/}
  | T_ID                                                            {/*ClassType*/}
;


var
  : type T_ID T_SEMI                                                {/*TypedId*/}
;


seq_var
  : var                                                             {/*TypedIdSequence*/}
  | seq_var var                                                     {/*TypedIdSequence*/}
;


argument
  : type T_ID                                                       {/*TypedId*/}
;


method_params
  :                                                                 {/*null*/}
  | argument                                                        {/*TypedIdSequence*/}
  | argument T_COMMA method_params                                  {/*TypedIdSequence*/}
;


method_signature
  : T_PUBLIC type T_ID T_L_PAREN method_params T_R_PAREN            {/*MethodSignature*/}
  | T_PRIVATE type T_ID T_L_PAREN method_params T_R_PAREN           {/*MethodSignature*/}


method
  : method_signature T_L_BRACE
        seq_var seq_statement T_RETURN exp T_SEMI
    T_R_BRACE                                                       {/*Method*/}

  | method_signature T_L_BRACE
        seq_statement T_RETURN exp T_SEMI
    T_R_BRACE                                                       {/*Method*/}

  | method_signature T_L_BRACE
        seq_var T_RETURN exp T_SEMI
    T_R_BRACE                                                       {/*Method*/}

  | method_signature T_L_BRACE
        T_RETURN exp T_SEMI
    T_R_BRACE                                                       {/*Method*/}
;


seq_method
  : method                                                          {/*MethodSequence*/}
  | seq_method method                                               {/*MethodSequence*/}
;


statement 
  : T_L_BRACE
        seq_statement
    T_R_BRACE                                                       {/*wrapper*/}
  | T_IF T_L_PAREN exp T_R_PAREN statement T_ELSE statement         {/*IfDoElseDo*/}
  | T_WHILE T_L_PAREN exp T_R_PAREN statement                       {/*WhileDo*/}
  | T_PRINT_LINE T_L_PAREN exp T_R_PAREN T_SEMI                     {/*PrintThing*/}
  | T_ID T_ASSIGN exp T_SEMI                                        {/*Assignment*/}
  | T_ID T_L_SQUARE exp T_R_SQUARE T_ASSIGN exp T_SEMI              {/*AssignmentAtPosition*/}
;


seq_statement
  : statement                                                       {/*StatementSequence*/}
  | seq_statement statement                                         {/*StatementSequence*/}
;


operation
  : exp T_AND exp                                                   {/*BooleanArithmeticOperation*/}
  | exp T_OR exp                                                    {/*BooleanArithmeticOperation*/}
  | exp T_LESS exp                                                  {/*BooleanArithmeticOperation*/}
  | exp T_PLUS exp                                                  {/*IntegerArithmeticOperation*/}
  | exp T_MINUS exp                                                 {/*IntegerArithmeticOperation*/}
  | exp T_MULT exp                                                  {/*IntegerArithmeticOperation*/}
  | exp T_MOD exp                                                   {/*IntegerArithmeticOperation*/}
;


exp
  : operation                                                       {/*wrapper*/}
  | exp T_L_SQUARE exp T_R_SQUARE                                   {/*GetItemAtPosition*/}
  | exp T_DOT T_LENGTH                                              {/*GetLength*/}
  | exp T_DOT T_ID T_L_PAREN run_method_params T_R_PAREN            {/*RunMethod*/}
  | T_INTEGER_NUMBER                                                {printf("%d\n", $1);/*IntegerExpression*/}
  | T_TRUE                                                          {/*BooleanExpression*/}
  | T_FALSE                                                         {/*BooleanExpression*/}
  | T_ID                                                            {/*IdExpression*/}
  | T_THIS                                                          {/*GetThisId*/}
  | T_NEW T_INT T_L_SQUARE exp T_R_SQUARE                           {/*CreateNewArray*/}
  | T_NEW T_ID T_L_PAREN T_R_PAREN                                  {/*CreateNewObject*/}
  | T_BANG exp                                                      {/*BooleanArithmeticOperation*/}
  | T_L_PAREN exp T_R_PAREN                                         {/*wrapper*/}
;


run_method_params
  :                                                                 {/*null*/}
  | exp                                                             {/*CallMethodParameters*/}
  | exp T_COMMA run_method_params                                   {/*CallMethodParameters*/}
;

%%

void yyerror(char* s) {
    printf("AGAIN %s at %d,%d:%d\n",
        s, yylloc.first_line, yylloc.first_column, yylloc.last_column);
}

int main(void) {
    yyparse();
}