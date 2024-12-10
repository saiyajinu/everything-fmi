%{

#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include <stdbool.h> 

#include "cppparser.tab.h"
void showError();
%}

identifier          ([a-zA-Z_][a-zA-Z0-9_]*)
numbers             ([0-9])+
string_literal      (\"[^"]*\")

%%

"if"                {return IF_INSTR;}
"while"             {return WHILE_INSTR;}


"("                 {return LCBR;}
")"                 {return RCBR;}
"{"                 {return LBR;}
"}"                 {return RBR;}

"true"              {yylval.bool_val = 1; return (TRUE_LIT);}
"false"             {yylval.bool_val = 0;return (FALSE_LIT);}

"int"               {return INT_DT;}
"string"            {return STRING_DT;}
{string_literal}    {sscanf(yytext, "%s", yylval.id); return (STRING_LIT);}
{numbers}           {yylval.num = atoi(yytext); return (NUM);}
{identifier}        {sscanf(yytext, "%s", yylval.id); return (ID);}
"="                 {return EQ;}
"=="                { return EQ_OP; }
";"                 {return SEMICOLON;}
[ \t\n]+            { /* ignore whitespace */ }
.                   {showError();}

%%


void showError(){
    printf("Error");
}
int yywrap(){
    return 1;
}
