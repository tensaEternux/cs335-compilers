%{
#include "parseforc.h"

#define NULL ((void*)0)
#define YYSTYPE node* 

node *tn1, *tn2;
extern int yylex();
%}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN



%start translation_unit
%%

primary_expression
	: IDENTIFIER                  {$$=$1;}
	| CONSTANT                    {$$=$1;}
	| STRING_LITERAL              {$$=$1;}
	| '(' expression ')'          {$$=nonTerminal("primary_expression", NULL, $2, NULL);}
	;

postfix_expression
	: primary_expression                                    {$$=$1;}
	| postfix_expression '[' expression ']'                 {$$=nonTerminal("postfix_expression", NULL, $1, $3);}
	| postfix_expression '(' ')'                            {$$=$1;}
	| postfix_expression '(' argument_expression_list ')'   {$$ = nonTerminal("postfix_expression", NULL, $1, $3);}
	| postfix_expression '.' IDENTIFIER                     {
                                                            tn1 = $3;
                                                            $$ = nonTerminal("postfix_expression.IDENTIFIER",NULL, $1, tn1);
                                                          }
	| postfix_expression PTR_OP IDENTIFIER                  {
                                                            tn1 = $3;
                                                            $$ = nonTerminal($2->name,NULL, $1, tn1);
                                                          }
	| postfix_expression INC_OP                             {$$=nonTerminal($2->name, NULL,$1, NULL);}
	| postfix_expression DEC_OP                             {$$=nonTerminal($2->name,NULL, $1,NULL);}
	;

argument_expression_list
	: assignment_expression                                 {$$=$1;}
	| argument_expression_list ',' assignment_expression    {$$=nonTerminal("argument_expression_list",NULL, $1, $3);}
	;

unary_expression
	: postfix_expression                 {$$=$1;}
	| INC_OP unary_expression            {$$=nonTerminal($1->name, NULL, NULL, $2);}
	| DEC_OP unary_expression            {$$=nonTerminal($1->name, NULL, NULL, $2);}
	| unary_operator cast_expression     {$$=nonTerminal("unary_expression", NULL, $1, $2);}
	| SIZEOF unary_expression            {$$=nonTerminal($1->name, NULL, NULL, $2);}
	| SIZEOF '(' type_name ')'           {$$=nonTerminal($1->name, NULL, NULL, $3);}
	;

unary_operator
	: '&'      {$$=terminal("&");}
	| '*'      {$$=terminal("*");}
	| '+'      {$$=terminal("+");}
	| '-'      {$$=terminal("-");}
	| '~'      {$$=terminal("~");}
	| '!'      {$$=terminal("!");}
	;

cast_expression
	: unary_expression                       {$$=$1;}
	| '(' type_name ')' cast_expression      {$$=nonTerminal("cast_expression", NULL, $2, $4);}
	;

multiplicative_expression
	: cast_expression                                 {$$=$1;}
	| multiplicative_expression '*' cast_expression   {$$=nonTerminal("*",NULL,$1,$3);}
	| multiplicative_expression '/' cast_expression   {$$=nonTerminal("/",NULL,$1,$3);}
	| multiplicative_expression '%' cast_expression   {$$=nonTerminal("%",NULL,$1,$3);}
	;

additive_expression
	: multiplicative_expression                          {$$=$1;}
	| additive_expression '+' multiplicative_expression  {$$=nonTerminal("+",NULL,$1,$3);}
	| additive_expression '-' multiplicative_expression  {$$=nonTerminal("-",NULL,$1,$3);}
	;

shift_expression
	: additive_expression                              {$$=$1;}
	| shift_expression LEFT_OP additive_expression     {$$=nonTerminal2($2->name, $1,NULL, $3);}
	| shift_expression RIGHT_OP additive_expression    {$$=nonTerminal2($2->name, $1,NULL, $3);}
	;

relational_expression
	: shift_expression                              {$$=$1;}
	| relational_expression '<' shift_expression    {$$=nonTerminal($2->name, NULL, $1, $3);}
	| relational_expression '>' shift_expression    {$$=nonTerminal( $2->name,NULL, $1, $3);}
	| relational_expression LE_OP shift_expression  {$$=nonTerminal2($2->name, $1,NULL, $3);}
	| relational_expression GE_OP shift_expression  {$$=nonTerminal2($2->name, $1,NULL, $3);}
	;

equality_expression
	: relational_expression                             {$$=$1;}
	| equality_expression EQ_OP relational_expression   {$$=nonTerminal2($2->name, $1,NULL, $3);}
	| equality_expression NE_OP relational_expression   {$$=nonTerminal2($2->name, $1,NULL, $3);}
	;

and_expression
	: equality_expression                        {$$=$1;}
	| and_expression '&' equality_expression     {$$=nonTerminal($2->name, NULL, $1, $3);}
	;

exclusive_or_expression
	: and_expression                               {$$=$1;}
	| exclusive_or_expression '^' and_expression   {$$=nonTerminal( "^",NULL, $1, $3);}
	;

inclusive_or_expression
	: exclusive_or_expression                               {$$=$1;}
	| inclusive_or_expression '|' exclusive_or_expression   {$$=nonTerminal("|",NULL, $1, $3);}
	;

logical_and_expression
	: inclusive_or_expression                                 {$$=$1;}
	| logical_and_expression AND_OP inclusive_or_expression   {$$=nonTerminal2($2->name, $1,NULL, $3);}
	;

logical_or_expression
	: logical_and_expression                                  {$$=$1;}
	| logical_or_expression OR_OP logical_and_expression      {$$=nonTerminal2($2->name, $1,NULL, $3);}
	;

conditional_expression
	: logical_or_expression                                             {$$=$1;}
	| logical_or_expression '?' expression ':' conditional_expression   {$$=nonTerminal2("conditional_expression", $1, $3, $5);}
	;

assignment_expression
	: conditional_expression                                        {$$=$1;}
	| unary_expression assignment_operator assignment_expression    {$$=nonTerminal2("assignment_expression", $1, $2, $3);}
	;

assignment_operator
	: '='             {$$ = terminal("=");}
	| MUL_ASSIGN      {$$ = $1;}
	| DIV_ASSIGN      {$$ = ($1);}
	| MOD_ASSIGN      {$$ = ($1);}
	| ADD_ASSIGN      {$$ = ($1);}
	| SUB_ASSIGN      {$$ = ($1);}
	| LEFT_ASSIGN     {$$ = ($1);}
	| RIGHT_ASSIGN    {$$ = ($1);}
	| AND_ASSIGN      {$$ = ($1);}
	| XOR_ASSIGN      {$$ = ($1);}
	| OR_ASSIGN       {$$ = ($1);}
	;

expression
	: assignment_expression                  {$$=$1;}
	| expression ',' assignment_expression   {$$=nonTerminal("expression", NULL, $1, $3);}
	;

constant_expression
	: conditional_expression      {$$=$1;}
	;

declaration
	: declaration_specifiers ';'                         {$$=$1;}
	| declaration_specifiers init_declarator_list ';'    {$$=nonTerminal("declaration", NULL, $1, $2);}
	;

declaration_specifiers
	: storage_class_specifier                           {$$=$1;}
	| storage_class_specifier declaration_specifiers    {$$=nonTerminal("declaration_specifiers", NULL, $1, $2);}
	| type_specifier                                    {$$=$1;}
	| type_specifier declaration_specifiers             {$$=nonTerminal("declaration_specifiers", NULL, $1, $2);}
	| type_qualifier                                    {$$=$1;}
	| type_qualifier declaration_specifiers             {$$=nonTerminal("declaration_specifiers", NULL, $1, $2);}
	;

init_declarator_list
	: init_declarator                               {$$=$1;}
	| init_declarator_list ',' init_declarator      {$$=nonTerminal("init_declaration_list", NULL, $1, $3);}
	;

init_declarator
	: declarator                          {$$=$1;}
	| declarator '=' initializer          {$$=nonTerminal($2->name, NULL, $1, $3);}
	;

storage_class_specifier
	: TYPEDEF               {$$=$1;}
	| EXTERN                {$$=$1;}
	| STATIC                {$$=$1;}
	| AUTO                  {$$=$1;}
	| REGISTER              {$$=$1;}
	;

type_specifier
	: VOID                        {$$=$1;}
	| CHAR                        {$$=$1;}
	| SHORT                       {$$=$1;}
	| INT                         {$$=$1;}
	| LONG                        {printf("INT \n");$$=$1;}
	| FLOAT                       {$$=$1;}
	| DOUBLE                      {$$=$1;}
	| SIGNED                      {$$=$1;}
	| UNSIGNED                    {$$=$1;}
	| struct_or_union_specifier   {$$=$1;}
	| enum_specifier              {$$=$1;}
	| TYPE_NAME                   {$$=$1;}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'   {$$=nonTerminal("struct_or_union_specifier", $2->name, $1, $4);}
	| struct_or_union '{' struct_declaration_list '}'              {$$=nonTerminal("struct_or_union_specifier", NULL, $1, $3);}
	| struct_or_union IDENTIFIER                                   {$$=nonTerminal("struct_or_union_specifier", $2->name, $1 ,NULL);}
	;

struct_or_union
	: STRUCT   {$$=$1;}
	| UNION    {$$=$1;}
	;

struct_declaration_list
	: struct_declaration                           {$$=$1;}
	| struct_declaration_list struct_declaration   {$$=nonTerminal("struct_declaration_list", NULL, $1, $2);}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'  {$$=nonTerminal("struct_declaration", NULL, $1, $2);}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list   {$$=nonTerminal("specifier_qualifier_list", NULL, $1, $2);}
	| type_specifier                            {$$=$1;}
	| type_qualifier specifier_qualifier_list   {$$=nonTerminal("specifier_qualifier_list", NULL, $1, $2);}
	| type_qualifier                            {$$=$1;}
	;

struct_declarator_list
	: struct_declarator                             {$$=$1;}
	| struct_declarator_list ',' struct_declarator  {$$=nonTerminal("struct_declarator_list", NULL, $1, $3);}
	;

struct_declarator
	: ':' constant_expression             {$$=$2;}
	| declarator ':' constant_expression  {$$=nonTerminal("struct_declarator", NULL, $1, $3);}
	| declarator                          {$$=$1;}
	;

enum_specifier
	: ENUM '{' enumerator_list '}'                {$$=nonTerminal("enum_specifier", $1->name, NULL, $3);}
	| ENUM IDENTIFIER '{' enumerator_list '}'     {$$=nonTerminal3("enum_specifier", $1->name, $2->name, $4, NULL);}
	| ENUM IDENTIFIER                             {$$=nonTerminal3("enum_specifier", $1->name, $2->name, NULL, NULL);}
	;

enumerator_list
	: enumerator                        {$$=$1;}
	| enumerator_list ',' enumerator    {$$=nonTerminal("enumerator_list", NULL, $1, $3);}
	;

enumerator
	: IDENTIFIER                              {$$=$1;}
	| IDENTIFIER '=' constant_expression      {$$ = nonTerminal($2->name,NULL, $1,  $3);}
	;

type_qualifier
	: CONST         {$$ = ($1);}
	| VOLATILE      {$$ = ($1);}
	;

declarator
	: pointer direct_declarator  {$$=nonTerminal("declarator", NULL, $1, $2);}
	| direct_declarator          {$$=$1;}
	;

direct_declarator
	: IDENTIFIER                                     {$$=$1;}
	| '(' declarator ')'                             {$$=$2;}
	| direct_declarator '[' constant_expression ']'  {$$=nonTerminalFourChild("direct_declarator", $1, NULL, $3, NULL, NULL);}
	| direct_declarator '[' ']'                      {$$=nonTerminalSquareB("direct_declarator", $1);}
	| direct_declarator '(' parameter_type_list ')'  {$$=nonTerminal("direct_declarator", NULL, $1, $3);}
	| direct_declarator '(' identifier_list ')'      {$$=nonTerminal("direct_declarator", NULL, $1, $3);}
	| direct_declarator '(' ')'                      {$$=nonTerminalRoundB("direct_declarator", $1);}
	;

pointer
	: '*'                                {$$=$1;}
	| '*' type_qualifier_list            {$$=nonTerminal($1->name,NULL,$2,NULL);}
	| '*' pointer                        {$$=nonTerminal($1->name,NULL,$2,NULL);}
	| '*' type_qualifier_list pointer    {$$=nonTerminal($1->name,NULL,$2,$3);}
	;

type_qualifier_list
	: type_qualifier                        {$$=$1;}
	| type_qualifier_list type_qualifier    {$$=nonTerminal("type_qualifier_list",NULL,$1,$2);}
	;


parameter_type_list
	: parameter_list                  {$$=$1;}
	| parameter_list ',' ELLIPSIS     {
                                      tn1 = $3;
                                      $$=nonTerminal("parameter_type_list",NULL,$1,tn1);
                                    }
	;

parameter_list
	: parameter_declaration                     {$$=$1;}
	| parameter_list ',' parameter_declaration  {$$=nonTerminal("parameter_list",NULL,$1,$3);}
	;

parameter_declaration
	: declaration_specifiers declarator            {$$=nonTerminal("parameter_declaration",NULL,$1,$2);}
	| declaration_specifiers abstract_declarator   {$$=nonTerminal("parameter_declaration",NULL,$1,$2);}
	| declaration_specifiers                       {$$=$1;}
	;

identifier_list
	: IDENTIFIER                        {$$=$1;}
	| identifier_list ',' IDENTIFIER    {
                                        tn1 = $3;
                                        $$=nonTerminal("identifier_list",NULL,$1,tn1);
                                      }
	;

type_name
	: specifier_qualifier_list abstract_declarator  {$$=nonTerminal("type_name",NULL,$1,$2);}
	| specifier_qualifier_list                      {$$=$1;}
	;

abstract_declarator
	: pointer direct_abstract_declarator {$$=nonTerminal("abstract_declarator",NULL,$1,$2);}
	| pointer {$$=$1;}
	| direct_abstract_declarator {$$=$1;}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'                                {$$=$2;}
	| '[' ']'                                                    {$$ = terminal("[ ]");}
	| '[' constant_expression ']'                                {$$ = terminal("[ * ]");}
	| direct_abstract_declarator '[' ']'                         {$$ = nonTerminal("direct_abstract_declarator","[ ]",$1,NULL);}
	| direct_abstract_declarator '[' constant_expression ']'     {$$ = nonTerminal("direct_abstract_declarator", "[ * ]", $1, NULL);}
	| '(' ')'                                                    {$$ = terminal("( )");}
	| '(' parameter_type_list ')'                                {$$=$2;}
	| direct_abstract_declarator '(' ')'                         {$$ = nonTerminal("direct_abstract_declarator","( )",$1,NULL);}
	| direct_abstract_declarator '(' parameter_type_list ')'     {$$ = nonTerminal("direct_abstract_declarator", NULL, $1, $3);}
	;

initializer
	: '{' initializer_list '}'       {$$ = $2;}
	| '{' initializer_list ',' '}'   {$$ = nonTerminal("initializer", ",", $2 ,NULL);}
	| assignment_expression          {$$ = $1;}
	;

initializer_list
	: initializer                        {$$=$1;}
	| initializer_list ',' initializer   {$$ = nonTerminal("initializer_list", NULL, $1 ,$2);}
	;

statement
	: labeled_statement      {$$=$1;}
	| compound_statement     {$$=$1;}
	| expression_statement   {$$=$1;}
	| selection_statement    {$$=$1;}
	| iteration_statement    {$$=$1;}
	| jump_statement         {$$=$1;}
	;

labeled_statement
	: IDENTIFIER ':' statement                  {
                                                tn1 = $1;
                                                $$ = nonTerminal("labeled_statement", NULL, tn1, $3);
                                              }
	| CASE constant_expression ':' statement    {
                                                tn1 = $1;
                                                $$ = nonTerminal2("labeled_statement", tn1, $2, $4);
                                              }
	| DEFAULT ':' statement                     {
                                                tn1 = $1;
                                                $$ = nonTerminal("labeled_statement", NULL, tn1, $3);
                                              }
	;

compound_statement
	: '{' '}'                   {$$ = terminal("{ }");} 
	| '{'  block_item_list '}'  {$$ = $2;}
	;

block_item_list
	: block_item                   {$$ = $1;}
	| block_item_list block_item   {$$ = nonTerminal("block_item_list", NULL, $1, $2);}
	;

block_item
	: declaration                   {$$ = $1;}
	| statement                     {$$ = $1;}
	;

expression_statement
	: ';'                 {$$ = terminal(";");}
	| expression ';'      {$$=$1;}
	;

selection_statement
	: IF '(' expression ')' statement                   {$$ = nonTerminalFiveChild("IF (expr) stmt", NULL, $3, $5, NULL, NULL);}
	| IF '(' expression ')' statement ELSE statement    {$$ = nonTerminalFiveChild("IF (expr) stmt ELSE stmt", NULL, $3, $5, NULL, $7);}
	| SWITCH '(' expression ')' statement               {$$ = nonTerminalFiveChild("SWITCH (expr) stmt", NULL, $3, $5, NULL, NULL);}
	;

iteration_statement
	: WHILE '(' expression ')' statement                                             {$$ = nonTerminalFiveChild("WHILE (expr) stmt", NULL, $3, $5, NULL, NULL);}
	| DO statement WHILE '(' expression ')' ';'                                      {$$ = nonTerminalFiveChild("DO stmt WHILE (expr)", NULL, $2, NULL, $5, NULL);}
	| FOR '(' expression_statement expression_statement ')' statement                {$$ = nonTerminalFiveChild("FOR (expr_stmt expr_stmt) stmt", NULL, $3, $4, $6, NULL);}
	| FOR '(' expression_statement expression_statement expression ')' statement     {$$ = nonTerminalFiveChild("FOR (expr_stmt expr_stmt expr) stmt", NULL, $3, $4, $5, $7);}
	;

jump_statement
	: GOTO IDENTIFIER ';'   {  
                            tn1 = $1;
                            tn2 = $2;
                            $$ = nonTerminal("jump_statement", NULL, tn1, tn2);
                          }
	| CONTINUE ';'	        {$$ = $1;}
	| BREAK ';' 	          {$$ = $1;}
	| RETURN ';' 	          {$$ = $1;}
	| RETURN expression ';' {
                            tn1 = $1;
                            $$ = nonTerminal("jump_statement", NULL, tn1, $2);
                          }
	;

translation_unit
	: external_declaration                     {$$=$1;}
	| translation_unit external_declaration    {$$ = nonTerminal("translation_unit", NULL, $1, $2);}
	;

external_declaration
	: function_definition    {$$=$1;}
	| declaration            {$$=$1;}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement   {$$ = nonTerminalFourChild("function_definition", $1, $2, $3, $4, NULL);}
	| declaration_specifiers declarator compound_statement                    {$$ = nonTerminal2("function_definition", $1, $2, $3);}
	;

declaration_list
	: declaration                   {$$ = $1;}
	| declaration_list declaration  {$$ = nonTerminal("declaration_list", NULL, $1, $2);}
	;

%%
#include <stdio.h>

extern char yytext[];
extern int column;

void yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}