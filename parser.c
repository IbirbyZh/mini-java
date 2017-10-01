%{
    #include <stdio.h>
    #include "btree.tab.h"
    
    #define NICE_FORMATTING 1
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

PRINT_LINE                      "System.out.println"
MAIN                            static[ \t\n]+void[ \t\n]+main
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

{PRINT_LINE}                    return T_PRINT_LINE;
{MAIN}                          return T_MAIN;
{STRING}                        return T_STRING;

{ID}                            return T_ID;
{INTEGER_NUMBER}                return T_INTEGER_NUMBER;

"//".*
\n                              {
                                    lineNumber += 1;
                                    columnNumber = 1;
                                    if( NICE_FORMATTING ) {
                                        return T_END_LINE;
                                    }
                                }

[\t]+                              columnNumber += (TAB_SIZE - 1) * yyleng;

[ \r]+
<<EOF>>                         {
                                    printf( "EOF\n" );
                                    return 0;
                                }

.	printf("\nFucking bullshit at %d,%d\n", lineNumber, columnNumber );

%%
