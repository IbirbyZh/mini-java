%{
    #include <stdlib.h>

    #define NICE_FORMATTING 1

    #define NF_RED  "\x1B[31m"
    #define NF_RESET "\x1B[0m"
    #define YY_USER_ACTION upgradePosition();
    int lineNumber = 1;
    int columnNumber = 1;
    long formatCounter = 0;
    void upgradePosition() {
        if( *yytext == '\n' ) {
            lineNumber += 1;
            columnNumber = 1;
        } else {
            columnNumber += strlen(yytext);
        }
        formatCounter += 1;
    }
    void print_position() {
        printf("%d:%d ", lineNumber, columnNumber);
    }
%}

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
{CLASS}                         printf( "CLASS " ); print_position();
{INT}                           printf( "INT " ); print_position();
{BOOLEAN}                       printf( "BOOLEAN " ); print_position();

{TRUE}                          printf( "TRUE " ); print_position();
{FALSE}                         printf( "FALSE " ); print_position();

{THIS}                          printf( "THIS " ); print_position();
{NEW}                           printf( "NEW " ); print_position();
{PUBLIC}                        printf( "PUBLIC " ); print_position();
{PRIVATE}                       printf( "PRIVATE " ); print_position();
{EXTENDS}                       printf( "EXTENDS " ); print_position();
{RETURN}                        printf( "RETURN " ); print_position();

{SEMI}                          printf( "SEMI " ); print_position();
{DOT}                           printf( "DOT " ); print_position();
{COMMA}                         printf( "COMMA " ); print_position();
{ASSIGN}                        printf( "ASSIGN " ); print_position();

{L_PAREN}                       printf( "L_PAREN " ); print_position();
{R_PAREN}                       printf( "R_PAREN " ); print_position();
{L_SQUARE}                      printf( "L_SQUARE " ); print_position();
{R_SQUARE}                      printf( "R_SQUARE " ); print_position();
{L_BRACE}                       printf( "L_BRACE " ); print_position();
{R_BRACE}                       printf( "R_BRACE " ); print_position();

{IF}                            printf( "IF " ); print_position();
{ELSE}                          printf( "ELSE " ); print_position();
{WHILE}                         printf( "WHILE " ); print_position();

{AND}                           printf( "AND " ); print_position();
{LESS}                          printf( "LESS " ); print_position();
{PLUS}                          printf( "PLUS " ); print_position();
{MINUS}                         printf( "MINUS " ); print_position();
{MULT}                          printf( "MULT " ); print_position();
{MOD}                           printf( "MOD " ); print_position();
{OR}                            printf( "OR " ); print_position();
{BANG}                          printf( "BANG " ); print_position();

{PRINT_LINE}                    printf( "PRINT_LINE " ); print_position();
{MAIN}                          printf( "MAIN " ); print_position();
{STRING}                        printf( "STRING " ); print_position();

{ID}                            printf( "ID(%s) ", yytext ); print_position();
{INTEGER_NUMBER}                printf( "INTEGER_NUMBER(%s) ", yytext );  print_position();

"//".*
\n                              if( NICE_FORMATTING ) {
                                    printf("\n");
                                }
[ \t\r]+
<<EOF>>                         {
                                    printf( "EOF\n" );
                                    return 0;
                                }

.	printf( NF_RED "\nFucking bullshit at %d,%d\n" NF_RESET, lineNumber, columnNumber );  print_position();
