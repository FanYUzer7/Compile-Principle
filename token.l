%{
#include "node.hpp"
#include "parser.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap() { return 1; }

int line_cnt = 1;
%}

INTEGER 	[0-9]+
REAL 		[0-9]+.[0-9]+
CHAR 		['][0-9a-zA-Z][']
ID 			[a-zA-Z][_a-zA-Z0-9]*
comment	(\/\/.*\n)

%%

{comment}   {line_cnt++;} 
"\n"		{ line_cnt++; }
[ \t]                 ;


"("			{ return TOKEN(LP); }
")"			{ return TOKEN(RP); }
"["			{ return TOKEN(LB); }
"]"			{ return TOKEN(RB); }
".."		{ return TOKEN(DOTDOT); }
","			{ return TOKEN(COMMA); }
":"			{ return TOKEN(COLON); }
";"			{ return TOKEN(SEMI); }

"."			{ return TOKEN(DOT); }
"+"			{ return TOKEN(PLUS); }
"-"			{ return TOKEN(MINUS); }
"*"			{ return TOKEN(MUL); }
"/"			{ return TOKEN(DIV_R); }
"<"			{ return TOKEN(LT); }
"<="		{ return TOKEN(LE); }
"="			{ return TOKEN(EQUAL); }
"<>"		{ return TOKEN(UNEQUAL); }
">"			{ return TOKEN(GT); }
">="		{ return TOKEN(GE); }
":="		{ return TOKEN(ASSIGN); }

and			{ return TOKEN(AND); }
or			{ return TOKEN(OR); }
not	     	{ return TOKEN(NOT); }
div			{ return TOKEN(DIV); }
mod			{ return TOKEN(MOD); }

array				return TOKEN(ARRAY); 
begin				return TOKEN(START); 
case				return TOKEN(CASE); 
const				return TOKEN(CONST); 
do					return TOKEN(DO); 
downto			 	return TOKEN(DOWNTO); 
else				return TOKEN(ELSE); 
end					return TOKEN(END); 
for 				return TOKEN(FOR); 
function	 		return TOKEN(FUNCTION); 
goto				return TOKEN(GOTO); 
if					return TOKEN(IF); 
in					return TOKEN(IN); 
of					return TOKEN(OF); 
packed			 	return TOKEN(PACKED); 
procedure	 		return TOKEN(PROCEDURE); 
program		 		return TOKEN(PROGRAM); 
read				return TOKEN(READ); 
record			 	return TOKEN(RECORD); 
repeat			 	return TOKEN(REPEAT); 
set					return TOKEN(SET); 
then				return TOKEN(THEN); 
to					return TOKEN(TO); 
type				return TOKEN(TYPE); 
until				return TOKEN(UNTIL); 
var					return TOKEN(VAR); 
while				return TOKEN(WHILE); 
with				return TOKEN(WITH); 

true|false|maxint { SAVE_TOKEN; return SYS_CON; }
abs|chr|odd|ord|pred|sqr|sqrt|succ { SAVE_TOKEN; return SYS_FUNCT; }
write|writeln { SAVE_TOKEN; return SYS_PROC; }
integer|boolean|char|real|string { SAVE_TOKEN; return SYS_TYPE; }

{ID}		{SAVE_TOKEN; return ID; }
{INTEGER}	{SAVE_TOKEN; return INTEGER; }
{REAL}		{SAVE_TOKEN; return REAL; }
{CHAR}      {SAVE_TOKEN; return CHAR;}
 /*{STRING}	{ return str(); }*/



.                       printf("Unknown token!n"); yyterminate();

%%

