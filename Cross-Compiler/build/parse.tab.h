/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_BUILD_PARSE_TAB_H_INCLUDED
# define YY_YY_BUILD_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CHAR = 258,
    CONST = 259,
    CASE = 260,
    CONTINUE = 261,
    DEFAULT = 262,
    DO = 263,
    DOUBLE = 264,
    ELSE = 265,
    ENUM = 266,
    EXTERN = 267,
    FLOAT = 268,
    FOR = 269,
    IF = 270,
    INLINE = 271,
    INT = 272,
    LONG = 273,
    REGISTER = 274,
    RESTRICT = 275,
    RETURN = 276,
    SHORT = 277,
    SIGNED = 278,
    STATIC = 279,
    STRUCT = 280,
    SWITCH = 281,
    TYPEDEF = 282,
    UNION = 283,
    UNSIGNED = 284,
    VOID = 285,
    VOLATILE = 286,
    WHILE = 287,
    ALIGNAS = 288,
    ALIGNOF = 289,
    ATOMIC = 290,
    BOOL = 291,
    COMPLEX = 292,
    GENERIC = 293,
    IMAGINARY = 294,
    NORETURN = 295,
    STATIC_ASSERT = 296,
    THREAD_LOCAL = 297,
    FUNC_NAME = 298,
    AUTO = 299,
    BREAK = 300,
    GOTO = 301,
    TYPEDEF_NAME = 302,
    IDENTIFIER = 303,
    ENUMERATION_CONSTANT = 304,
    STRING_LITERAL = 305,
    I_CONSTANT = 306,
    F_CONSTANT = 307,
    PTR_OP = 308,
    INC_OP = 309,
    DEC_OP = 310,
    LEFT_OP = 311,
    RIGHT_OP = 312,
    LE_OP = 313,
    GE_OP = 314,
    EQ_OP = 315,
    NE_OP = 316,
    AND_OP = 317,
    OR_OP = 318,
    MUL_ASSIGN = 319,
    DIV_ASSIGN = 320,
    MOD_ASSIGN = 321,
    ADD_ASSIGN = 322,
    SUB_ASSIGN = 323,
    LEFT_ASSIGN = 324,
    RIGHT_ASSIGN = 325,
    AND_ASSIGN = 326,
    XOR_ASSIGN = 327,
    OR_ASSIGN = 328,
    ELLIPSIS = 329,
    SIZEOF = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "src/parse.y"

  int number;     /*integer value*/
  char *str;
  node *ptr;     /*node pointer */
  exprNode *expr;
  numb * num;

#line 141 "build/parse.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUILD_PARSE_TAB_H_INCLUDED  */
