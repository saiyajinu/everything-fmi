%{
#include <stdio.h>

int yylex();
int yyerror(char *s);

%}

%token INT_DT STRING_DT IF_INSTR NUM STRING_LIT ID SEMICOLON EQ LCBR RCBR LBR RBR TRUE_LIT FALSE_LIT WHILE_INSTR EQ_OP AND_OP


%type <id> ID
%type <num> NUM
%type <id> STRING_LIT
%type <bool_val> TRUE_LIT FALSE_LIT
%type <bool_val> boolean expression

%union{
    char id[20];
    int num;
    int bool_val; 

}

%left EQ_OP

%%

prog:
    stmts
;

boolean:
    TRUE_LIT   { $$ = 1; } 
    | FALSE_LIT  { $$ = 0; }  
    // | expression  { $$ = $1; }

;

expression:
      NUM                       { $$ = $1; }
    | boolean                   { $$ = $1; }
    | expression EQ_OP expression
      {
        $$ = $1 == $3;
      }
    | expression AND_OP expression
    {
        $$ = $1 && $3;
    }
    ;

stmts:
	| stmts stmt SEMICOLON
    ;

stmt:
    SEMICOLON { 
        printf("SEMICOLON -> END OF INPUT");
        YYACCEPT;
    }
    |
    expression
    {
        printf("E%d\n", $1);
    }
    |
    INT_DT ID EQ NUM
    {
        printf("INT_DT %s EQ %d\n", $2, $4);
    }
    |
    STRING_DT ID EQ STRING_LIT
    {
        printf("STRING_DT %s EQ %s\n", $2, $4);
    }
    |
    IF_INSTR LCBR expression RCBR LBR stmts RBR
    {
        if ($3) {
            printf("IF_INSTR executed\n");
        } else {
            printf("IF_INSTR skipped\n");
        }
    }
    |
    WHILE_INSTR LCBR expression RCBR LBR stmts RBR
    {
        if ($3) {
            printf("WHILE_INSTR executed\n");
        }
        else { 
            printf("WHILE_INSTR skipped\n");

        }
    }
;

%%

int yyerror(char *s){
    printf("Syntax Error on line %s\n", s);
	return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        perror("ERROR - no file given");
        return 0;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("ERROR - file not found");
        return 0;
    }

    stdin = file;
    yyparse();
    return 0;
}