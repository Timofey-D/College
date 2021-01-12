%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}

%%

if					                    return IF;
while					                return WHILE;
for					                    return FOR;
else					                return ELSE;
void                                    return VOID;
return                                  return RETURN;


int					                    return INT;
float					                return FLOAT;
String					                return STRING;
char					                return CHAR;

[0-9]+	                                return INTEGER_VAL;
[0-9]*\.?[0-9]+	                        return FLOAT_VAL;
[\'][a-zA-Z0-9][\']			            return CHAR_VAL;

[a-zA-Z][_a-zA-Z0-9]*(\[[0-9]+\])+	    return ARRAY;
[a-zA-Z]+[_a-zA-Z0-9]*[_a-zA-Z0-9]*     return IDENTIFIER;

\"(\\.|[^"])*\"		                    return STRING_VAL;

"="                                     return ASSIGN;
"+"                                     return PLUS;
"-"                                     return MINUS;
"/"                                     return DIVISION;
"*"                                     return MULTIPLY;

"<"                                     return LESS;
">"                                     return BIGGER;
">="                                    return BOE;
"<="                                    return LOE;
"=="                                    return EQUALS;
"!="                                    return NOE;
"&&"                                    return AND;
"||"                                    return OR;
"^"					                    return XOR;

";"					                    return SEMICOLON;
"'"					                    return QUOTE;
","					                    return COMMA;

"("					                    return BRACKET_OPEN;
")"					                    return BRACKET_CLOSE;

"{"					                    return BRACE_OPEN;
"}"					                    return BRACE_CLOSE;

"["					                    return ARRAY_BRACKET_OPEN;
"]"					                    return ARRAY_BRACKET_CLOSE;

[ \t]					                ;

.					                    return yytext[0]; 

%%
