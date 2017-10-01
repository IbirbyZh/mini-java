%{
    #include <stdio.h>
    #include "btree.tab.h"
    void yyerror(char *s)
    {
      fprintf(stderr, "ERROR line %d: %s\n", yylloc.first_line, s);
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

%token T_PRINT_LINE
%token T_MAIN
%token T_STRING

%token T_ID
%token T_INTEGER_NUMBER

%token T_END_LINE

%locations

%%
input
    :TOKEN
    |TOKEN input
;

TOKEN
    :T_CLASS {printf("CLASS %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_INT {printf("INT %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_BOOLEAN {printf("BOOLEAN %d:%d ", yylloc.first_line, yylloc.first_column);}

    |T_TRUE {printf("TRUE %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_FALSE {printf("FALSE %d:%d ", yylloc.first_line, yylloc.first_column);}

    |T_THIS {printf("THIS %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_NEW {printf("NEW %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_PUBLIC {printf("PUBLIC %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_PRIVATE {printf("PRIVATE %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_EXTENDS {printf("EXTENDS %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_RETURN {printf("RETURN %d:%d ", yylloc.first_line, yylloc.first_column);}

    |T_SEMI {printf("SEMI %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_DOT {printf("DOT %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_COMMA {printf("COMMA %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_ASSIGN {printf("ASSIGN %d:%d ", yylloc.first_line, yylloc.first_column);}

    |T_L_PAREN {printf("L_PAREN %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_R_PAREN {printf("R_PAREN %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_L_SQUARE {printf("L_SQUARE %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_R_SQUARE {printf("R_SQUARE %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_L_BRACE {printf("L_BRACE %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_R_BRACE {printf("R_BRACE %d:%d ", yylloc.first_line, yylloc.first_column);}

    |T_IF {printf("IF %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_ELSE {printf("ELSE %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_WHILE {printf("WHILE %d:%d ", yylloc.first_line, yylloc.first_column);}

    |T_AND {printf("AND %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_LESS {printf("LESS %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_PLUS {printf("PLUS %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_MINUS {printf("MINUS %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_MULT {printf("MULT %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_MOD {printf("MOD %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_OR {printf("OR %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_BANG {printf("BANG %d:%d ", yylloc.first_line, yylloc.first_column);}

    |T_PRINT_LINE {printf("PRINT_LINE %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_MAIN {printf("MAIN %d:%d ", yylloc.first_line, yylloc.first_column);}

    |T_STRING {printf("STRING %d:%d ", yylloc.first_line, yylloc.first_column);}

    |T_ID {printf("ID %d:%d ", yylloc.first_line, yylloc.first_column);}
    |T_INTEGER_NUMBER {printf("INTEGER_NUMBER %d:%d ", yylloc.first_line, yylloc.first_column);}

    |T_END_LINE {printf("\n");}
;
%%