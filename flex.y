%{
    #include "Nodes.hpp"
    using namespace NNodes;
    #include "tokens.h"

    #include <stdio.h>
    #include <stdlib.h>


    int TAB_SIZE = 4;

    int lineNumber = 1;
    int columnNumber = 1;
    void print_position() {
        printf("%d %d ", lineNumber, columnNumber - yyleng);
    }

    void DoBeforeEverything();
    #define YY_USER_ACTION DoBeforeEverything();
    void DoBeforeEverything(){
        yylloc.first_line = yylloc.last_line = yylineno;
        yylloc.first_column = columnNumber;
        columnNumber += yyleng;
        yylloc.last_column = columnNumber;
    }
    
    
%}

%option yylineno
%option noyywrap

SPACE                           [ \t\n]+
LETTER                          [A-Za-z_]
POSITIVE                        [1-9]
ZERO                            0
DIGIT                           {ZERO}|{POSITIVE}

CLASS                           class
INT                             int
BOOLEAN                         boolean

TRUE                            true
FALSE                           false

THIS                            this
NEW                             new
PUBLIC                          public
PRIVATE                         private
EXTENDS                         extends
RETURN                          return

SEMI                            ";"
DOT                             "."
COMMA                           ","
ASSIGN                          "="

L_PAREN                         "("
R_PAREN                         ")"
L_SQUARE                        "["
R_SQUARE                        "]"
L_BRACE                         "{"
R_BRACE                         "}"

IF                              if
ELSE                            else
WHILE                           while

AND                             "&&"
LESS                            "<"
PLUS                            "+"
MINUS                           "-"
MULT                            "*"
MOD                             "%"
OR                              "||"
BANG                            "!"

LENGTH                          "length"
PRINT_LINE                      "System.out.println"
MAIN                            static[ \t]+void[ \t]+main
STRING                          String

ID                              {LETTER}({LETTER}|{DIGIT})*
INTEGER_NUMBER                  {POSITIVE}({DIGIT})*|{ZERO}


%%
{CLASS}                         return T_CLASS;
{INT}                           return T_INT;
{BOOLEAN}                       return T_BOOLEAN;

{TRUE}                          return T_TRUE;
{FALSE}                         return T_FALSE;

{THIS}                          return T_THIS;
{NEW}                           return T_NEW;
{PUBLIC}                        return T_PUBLIC;
{PRIVATE}                       return T_PRIVATE;
{EXTENDS}                       return T_EXTENDS;
{RETURN}                        return T_RETURN;

{SEMI}                          return T_SEMI;
{DOT}                           return T_DOT;
{COMMA}                         return T_COMMA;
{ASSIGN}                        return T_ASSIGN;

{L_PAREN}                       return T_L_PAREN;
{R_PAREN}                       return T_R_PAREN;
{L_SQUARE}                      return T_L_SQUARE;
{R_SQUARE}                      return T_R_SQUARE;
{L_BRACE}                       return T_L_BRACE;
{R_BRACE}                       return T_R_BRACE;

{IF}                            return T_IF;
{ELSE}                          return T_ELSE;
{WHILE}                         return T_WHILE;

{AND}                           return T_AND;
{LESS}                          return T_LESS;
{PLUS}                          return T_PLUS;
{MINUS}                         return T_MINUS;
{MULT}                          return T_MULT;
{MOD}                           return T_MOD;
{OR}                            return T_OR;
{BANG}                          return T_BANG;

{LENGTH}                        return T_LENGTH;
{PRINT_LINE}                    return T_PRINT_LINE;
{MAIN}                          return T_MAIN;
{STRING}                        return T_STRING;

{ID}                            yylval.strValue=yytext; return T_ID;
{INTEGER_NUMBER}                yylval.intValue=atoi(yytext); return T_INTEGER_NUMBER;



"//".*
\n                              {
                                    lineNumber += 1;
                                    columnNumber = 1;
                                }

[\t]+                              columnNumber += (TAB_SIZE - 1) * yyleng;

[ \r]+
<<EOF>>                         {
                                    return 0;
                                }

.	{printf("Unexpected token: %s\n", yytext); return T_ERROR;}

%%
