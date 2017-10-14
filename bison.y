%{
    #include <stdio.h>
    #include "tokens.h"
    #define NICE_FORMATTING 1
    void yyerror(char *s)
    {
      fprintf(stderr, "ERROR line %d %d:%d %s\n", yylloc.first_line, yylloc.first_column, yylloc.last_column, s);
    }
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
  : T_INT T_L_SQUARE T_R_SQUARE
  | T_BOOLEAN
  | T_INT
  | T_ID
;


var
  : type T_ID T_SEMI
;


seq_var
  : var
  | seq_var var
;


seq_method_params
  : type T_ID
  | seq_method_params T_COMMA type T_ID
;


method_params
  :
  | seq_method_params
;


method_signature
  : T_PUBLIC type T_ID T_L_PAREN method_params T_R_PAREN
  | T_PRIVATE type T_ID T_L_PAREN method_params T_R_PAREN


method
  : method_signature T_L_BRACE
        seq_var seq_statement T_RETURN exp T_SEMI
    T_R_BRACE

  | method_signature T_L_BRACE
        seq_statement T_RETURN exp T_SEMI
    T_R_BRACE

  | method_signature T_L_BRACE
        seq_var T_RETURN exp T_SEMI
    T_R_BRACE

  | method_signature T_L_BRACE
        T_RETURN exp T_SEMI
    T_R_BRACE
;


seq_method
  : method
  | seq_method method
;


statement 
  : T_L_BRACE
        seq_statement
    T_R_BRACE
  | T_IF T_L_PAREN exp T_R_PAREN statement T_ELSE statement
  | T_WHILE T_L_PAREN exp T_R_PAREN statement
  | T_PRINT_LINE T_L_PAREN exp T_R_PAREN T_SEMI
  | T_ID T_ASSIGN exp T_SEMI
  | T_ID T_L_SQUARE exp T_R_SQUARE T_ASSIGN exp T_SEMI
;


seq_statement
  : statement
  | seq_statement statement
;


operation
  : exp T_AND exp
  | exp T_OR exp
  | exp T_LESS exp
  | exp T_PLUS exp
  | exp T_MINUS exp
  | exp T_MULT exp
  | exp T_MOD exp
;


exp
  : operation
  | exp T_L_SQUARE exp T_R_SQUARE
  | exp T_DOT T_LENGTH
  | exp T_DOT T_ID T_L_PAREN run_method_params T_R_PAREN
  | T_INTEGER_NUMBER
  | T_TRUE
  | T_FALSE
  | T_ID
  | T_THIS
  | T_NEW T_INT T_L_SQUARE exp T_R_SQUARE
  | T_NEW T_ID T_L_PAREN T_R_PAREN
  | T_BANG exp
  | T_L_PAREN exp T_R_PAREN
;


seq_run_method_params
  : exp
  | seq_run_method_params T_COMMA exp
;


run_method_params
  :
  | seq_run_method_params


%%
