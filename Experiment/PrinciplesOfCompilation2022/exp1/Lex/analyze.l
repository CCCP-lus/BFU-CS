%{
#include <stdio.h>
int lines = 0;   
%}


DIGIT              [0-9]
ALPHA              [a-zA-Z_]
KEYWORD            "if"|"else"|"for"|"return"|"while"|"int"|"short"|"float"|"double"|"long"
IDENTIFIER         {ALPHA}({ALPHA}|{DIGIT})*
OPERATOR           "+"|"-"|"*"|"/"|"="|">"|">="|"<"|"<="|"=="|"!="
SEPARATOR          ":"|";"|"."|","|"{"|"}"|"("|")"
LITERAL            [+-]?{DIGIT}+(\.{DIGIT}+)?([eE][+-]?{DIGIT}+)?
SINGLE_COMMENT     \/\/.*
MULTI_COMMENT      \/\*.*?\*\/

%%

{KEYWORD}    {fprintf(yyout, "%-8d %s\n", 1, yytext);}
{IDENTIFIER} {fprintf(yyout, "%-8d %s\n", 2, yytext);}
{OPERATOR}   {fprintf(yyout, "%-8d %s\n", 4, yytext);}
{SEPARATOR}  {fprintf(yyout, "%-8d %s\n", 5, yytext);}
{LITERAL}    {fprintf(yyout, "%-8d %s\n", 3, yytext);}
{SINGLE_COMMENT} {}
{MULTI_COMMENT}  {}
[ \t]            {}
[\n]             {lines++;}
.                {printf("Unexpected character");}

%%

int main(int argc, const char** argv) {
    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;
}