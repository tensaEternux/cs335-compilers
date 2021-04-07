D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"

void count();
void singlecomment();
void comment();
%}

%%
"//"      		{ singlecomment(); }
"/*"			{ comment(); }
"#"     		{singlecomment(); }

"auto"			{ yylval.val = yytext; count(); return(AUTO); }
"break"			{ yylval.val = yytext; count(); return(BREAK); }
"case"			{ yylval.val = yytext; count(); return(CASE); }
"char"			{ yylval.val = yytext; count(); return(CHAR); }
"const"			{ yylval.val = yytext; count(); return(CONST); }
"continue"		{ yylval.val = yytext; count(); return(CONTINUE); }
"default"		{ yylval.val = yytext; count(); return(DEFAULT); }
"do"			{ yylval.val = yytext; count(); return(DO); }
"double"		{ yylval.val = yytext; count(); return(DOUBLE); }
"else"			{ yylval.val = yytext; count(); return(ELSE); }
"enum"			{ yylval.val = yytext; count(); return(ENUM); }
"extern"		{ yylval.val = yytext; count(); return(EXTERN); }
"float"			{ yylval.val = yytext; count(); return(FLOAT); }
"for"			{ yylval.val = yytext; count(); return(FOR); }
"goto"			{ yylval.val = yytext; count(); return(GOTO); }
"if"			{ yylval.val = yytext; count(); return(IF); }
"int"			{ yylval.val = yytext; count(); return(INT); }
"long"			{ yylval.val = yytext; count(); return(LONG); }
"register"		{ yylval.val = yytext; count(); return(REGISTER); }
"return"		{ yylval.val = yytext; count(); return(RETURN); }
"short"			{ yylval.val = yytext; count(); return(SHORT); }
"signed"		{ yylval.val = yytext; count(); return(SIGNED); }
"sizeof"		{ yylval.val = yytext; count(); return(SIZEOF); }
"static"		{ yylval.val = yytext; count(); return(STATIC); }
"struct"		{ yylval.val = yytext; count(); return(STRUCT); }
"switch"		{ yylval.val = yytext; count(); return(SWITCH); }
"typedef"		{ yylval.val = yytext; count(); return(TYPEDEF); }
"union"			{ yylval.val = yytext; count(); return(UNION); }
"unsigned"		{ yylval.val = yytext; count(); return(UNSIGNED); }
"void"			{ yylval.val = yytext; count(); return(VOID); }
"volatile"		{ yylval.val = yytext; count(); return(VOLATILE); }
"while"			{ yylval.val = yytext; count(); return(WHILE); }

{L}({L}|{D})*		{ yylval.val = yytext; count(); return(IDENTIFIER);}

0[xX]{H}+{IS}?		{ yylval.val = yytext; count(); return(CONSTANT); }
0{D}+{IS}?		{ yylval.val = yytext; count(); return(CONSTANT); }
{D}+{IS}?		{ yylval.val = yytext; count(); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ yylval.val = yytext; count(); return(CONSTANT); }

{D}+{E}{FS}?		{ yylval.val = yytext; count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ yylval.val = yytext; count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ yylval.val = yytext; count(); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ yylval.val = yytext; count(); return(STRING_LITERAL); }

"..."			{ yylval.val = yytext; count(); return(ELLIPSIS); }
">>="			{ yylval.val = yytext; count(); return(RIGHT_ASSIGN); }
"<<="			{ yylval.val = yytext; count(); return(LEFT_ASSIGN); }
"+="			{ yylval.val = yytext; count(); return(ADD_ASSIGN); }
"-="			{ yylval.val = yytext; count(); return(SUB_ASSIGN); }
"*="			{ yylval.val = yytext; count(); return(MUL_ASSIGN); }
"/="			{ yylval.val = yytext; count(); return(DIV_ASSIGN); }
"%="			{ yylval.val = yytext; count(); return(MOD_ASSIGN); }
"&="			{ yylval.val = yytext; count(); return(AND_ASSIGN); }
"^="			{ yylval.val = yytext; count(); return(XOR_ASSIGN); }
"|="			{ yylval.val = yytext; count(); return(OR_ASSIGN); }
">>"			{ yylval.val = yytext; count(); return(RIGHT_OP); }
"<<"			{ yylval.val = yytext; count(); return(LEFT_OP); }
"++"			{ yylval.val = yytext; count(); return(INC_OP); }
"--"			{ yylval.val = yytext; count(); return(DEC_OP); }
"->"			{ yylval.val = yytext; count(); return(PTR_OP); }
"&&"			{ yylval.val = yytext; count(); return(AND_OP); }
"||"			{ yylval.val = yytext; count(); return(OR_OP); }
"<="			{ yylval.val = yytext; count(); return(LE_OP); }
">="			{ yylval.val = yytext; count(); return(GE_OP); }
"=="			{ yylval.val = yytext; count(); return(EQ_OP); }
"!="			{ yylval.val = yytext; count(); return(NE_OP); }
";"			{ yylval.val = yytext; count(); return(';'); }
("{"|"<%")		{ yylval.val = yytext; count(); return('{'); }
("}"|"%>")		{ yylval.val = yytext; count(); return('}'); }
","			{ yylval.val = yytext; count(); return(','); }
":"			{ yylval.val = yytext; count(); return(':'); }
"="			{ yylval.val = yytext; count(); return('='); }
"("			{ yylval.val = yytext; count(); return('('); }
")"			{ yylval.val = yytext; count(); return(')'); }
("["|"<:")		{ yylval.val = yytext; count(); return('['); }
("]"|":>")		{ yylval.val = yytext; count(); return(']'); }
"."			{ yylval.val = yytext; count(); return('.'); }
"&"			{ yylval.val = yytext; count(); return('&'); }
"!"			{ yylval.val = yytext; count(); return('!'); }
"~"			{ yylval.val = yytext; count(); return('~'); }
"-"			{ yylval.val = yytext; count(); return('-'); }
"+"			{ yylval.val = yytext; count(); return('+'); }
"*"			{ yylval.val = yytext; count(); return('*'); }
"/"			{ yylval.val = yytext; count(); return('/'); }
"%"			{ yylval.val = yytext; count(); return('%'); }
"<"			{ yylval.val = yytext; count(); return('<'); }
">"			{ yylval.val = yytext; count(); return('>'); }
"^"			{ yylval.val = yytext; count(); return('^'); }
"|"			{ yylval.val = yytext; count(); return('|'); }
"?"			{ yylval.val = yytext; count(); return('?'); }

[ \t\v\n\f]		{ count(); }
.			{ count(); /* ignore bad characters */ }

%%

int yywrap()
{
	return(1);
}

void singlecomment() {
  char c;
  while ((c = input()) != '\n' && c != 0);
  unput(c);
}

void comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0) {
    if (c == '\n') yylineno++;
  }

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0);
}


int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n') {
			column = 0;
      yylineno++;
    } else if (yytext[i] == '\t')
			column += 4 - (column % 4);
		else
			column++;
/*
	ECHO;
*/
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/

	return(IDENTIFIER);
}
