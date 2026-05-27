%option noyywrap yylineno

%{
#include "parser.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%%
"#include"  { return INCLUDE; }
"#define"   { return DEFINE; }
"int"       { return INT; }
"func"      { return FUNC; }
"return"    { return RETURN; }
"if"        { return IF; }

[0-9]+      { yylval.ival = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return ID; }

\"[^\"]*\"  { yylval.sval = strdup(yytext); return STRING; }

"("         { return '('; }
")"         { return ')'; }
"{"         { return '{'; }
"}"         { return '}'; }
";"         { return ';'; }
"="         { return '='; }
"+"         { return '+'; }
"-"         { return '-'; }
","         { return ','; }
"<"         { return '<'; }
">"         { return '>'; }
"."         { return '.'; }

[ \t\n\r]+  ; // Ignorar espacios en blanco

.           { printf("Caracter no reconocido: %s\n", yytext); }
%%