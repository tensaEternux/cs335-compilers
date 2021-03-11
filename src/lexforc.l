D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"

typedef struct node {
  int id;
  char *name;
} node;

extern node* terminal(char* s);
node* yylval;
void count();
void singlecomment();
void comment();
%}

%%
"//"      { singlecomment(); }
"/*"			{ comment(); }
"#"     {singlecomment(); }

"auto"			{ yylval = terminal(yytext); count(); return(AUTO); }
"break"			{ yylval = terminal(yytext); count(); return(BREAK); }
"case"			{ yylval = terminal(yytext); count(); return(CASE); }
"char"			{ yylval = terminal(yytext); count(); return(CHAR); }
"const"			{ yylval = terminal(yytext); count(); return(CONST); }
"continue"		{ yylval = terminal(yytext); count(); return(CONTINUE); }
"default"		{ yylval = terminal(yytext); count(); return(DEFAULT); }
"do"			{ yylval = terminal(yytext); count(); return(DO); }
"double"		{ yylval = terminal(yytext); count(); return(DOUBLE); }
"else"			{ yylval = terminal(yytext); count(); return(ELSE); }
"enum"			{ yylval = terminal(yytext); count(); return(ENUM); }
"extern"		{ yylval = terminal(yytext); count(); return(EXTERN); }
"float"			{ yylval = terminal(yytext); count(); return(FLOAT); }
"for"			{ yylval = terminal(yytext); count(); return(FOR); }
"goto"			{ yylval = terminal(yytext); count(); return(GOTO); }
"if"			{ yylval = terminal(yytext); count(); return(IF); }
"int"			{ yylval = terminal(yytext); count(); return(INT); }
"long"			{ yylval = terminal(yytext); count(); return(LONG); }
"register"		{ yylval = terminal(yytext); count(); return(REGISTER); }
"return"		{ yylval = terminal(yytext); count(); return(RETURN); }
"short"			{ yylval = terminal(yytext); count(); return(SHORT); }
"signed"		{ yylval = terminal(yytext); count(); return(SIGNED); }
"sizeof"		{ yylval = terminal(yytext); count(); return(SIZEOF); }
"static"		{ yylval = terminal(yytext); count(); return(STATIC); }
"struct"		{ yylval = terminal(yytext); count(); return(STRUCT); }
"switch"		{ yylval = terminal(yytext); count(); return(SWITCH); }
"typedef"		{ yylval = terminal(yytext); count(); return(TYPEDEF); }
"union"			{ yylval = terminal(yytext); count(); return(UNION); }
"unsigned"		{ yylval = terminal(yytext); count(); return(UNSIGNED); }
"void"			{ yylval = terminal(yytext); count(); return(VOID); }
"volatile"		{ yylval = terminal(yytext); count(); return(VOLATILE); }
"while"			{ yylval = terminal(yytext); count(); return(WHILE); }

{L}({L}|{D})*		{ yylval = terminal(yytext); count(); return(IDENTIFIER);}

0[xX]{H}+{IS}?		{ yylval = terminal(yytext); count(); return(CONSTANT); }
0{D}+{IS}?		{ yylval = terminal(yytext); count(); return(CONSTANT); }
{D}+{IS}?		{ yylval = terminal(yytext); count(); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ yylval = terminal(yytext); count(); return(CONSTANT); }

{D}+{E}{FS}?		{ yylval = terminal(yytext); count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ yylval = terminal(yytext); count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ yylval = terminal(yytext); count(); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ yylval = terminal(yytext); count(); return(STRING_LITERAL); }

"..."			{ yylval = terminal(yytext); count(); return(ELLIPSIS); }
">>="			{ yylval = terminal(yytext); count(); return(RIGHT_ASSIGN); }
"<<="			{ yylval = terminal(yytext); count(); return(LEFT_ASSIGN); }
"+="			{ yylval = terminal(yytext); count(); return(ADD_ASSIGN); }
"-="			{ yylval = terminal(yytext); count(); return(SUB_ASSIGN); }
"*="			{ yylval = terminal(yytext); count(); return(MUL_ASSIGN); }
"/="			{ yylval = terminal(yytext); count(); return(DIV_ASSIGN); }
"%="			{ yylval = terminal(yytext); count(); return(MOD_ASSIGN); }
"&="			{ yylval = terminal(yytext); count(); return(AND_ASSIGN); }
"^="			{ yylval = terminal(yytext); count(); return(XOR_ASSIGN); }
"|="			{ yylval = terminal(yytext); count(); return(OR_ASSIGN); }
">>"			{ yylval = terminal(yytext); count(); return(RIGHT_OP); }
"<<"			{ yylval = terminal(yytext); count(); return(LEFT_OP); }
"++"			{ yylval = terminal(yytext); count(); return(INC_OP); }
"--"			{ yylval = terminal(yytext); count(); return(DEC_OP); }
"->"			{ yylval = terminal(yytext); count(); return(PTR_OP); }
"&&"			{ yylval = terminal(yytext); count(); return(AND_OP); }
"||"			{ yylval = terminal(yytext); count(); return(OR_OP); }
"<="			{ yylval = terminal(yytext); count(); return(LE_OP); }
">="			{ yylval = terminal(yytext); count(); return(GE_OP); }
"=="			{ yylval = terminal(yytext); count(); return(EQ_OP); }
"!="			{ yylval = terminal(yytext); count(); return(NE_OP); }
";"			{ yylval = terminal(yytext); count(); return(';'); }
("{"|"<%")		{ yylval = terminal(yytext); count(); return('{'); }
("}"|"%>")		{ yylval = terminal(yytext); count(); return('}'); }
","			{ yylval = terminal(yytext); count(); return(','); }
":"			{ yylval = terminal(yytext); count(); return(':'); }
"="			{ yylval = terminal(yytext); count(); return('='); }
"("			{ yylval = terminal(yytext); count(); return('('); }
")"			{ yylval = terminal(yytext); count(); return(')'); }
("["|"<:")		{ yylval = terminal(yytext); count(); return('['); }
("]"|":>")		{ yylval = terminal(yytext); count(); return(']'); }
"."			{ yylval = terminal(yytext); count(); return('.'); }
"&"			{ yylval = terminal(yytext); count(); return('&'); }
"!"			{ yylval = terminal(yytext); count(); return('!'); }
"~"			{ yylval = terminal(yytext); count(); return('~'); }
"-"			{ yylval = terminal(yytext); count(); return('-'); }
"+"			{ yylval = terminal(yytext); count(); return('+'); }
"*"			{ yylval = terminal(yytext); count(); return('*'); }
"/"			{ yylval = terminal(yytext); count(); return('/'); }
"%"			{ yylval = terminal(yytext); count(); return('%'); }
"<"			{ yylval = terminal(yytext); count(); return('<'); }
">"			{ yylval = terminal(yytext); count(); return('>'); }
"^"			{ yylval = terminal(yytext); count(); return('^'); }
"|"			{ yylval = terminal(yytext); count(); return('|'); }
"?"			{ yylval = terminal(yytext); count(); return('?'); }

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
