/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parse.y"

#include <iostream>
#include <cstring>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>
using namespace std;
#define MAX_STR_LEN 1024

int scope;
int symNumber = 0;
int funcSym=0;
int isFunc;
int blockSym=0;
int yylex(void);
void yyerror(char *s,...);
#include "typeCheck.h"
#include "nodes.h"
#include "symTable.h"


FILE *digraph;
FILE *duplicate;
node *temp,*temp1,*temp2;
char filename[1000];
string typeName="";
extern int yylineno;
string symFileName;
string funcName;
string funcType;
int structCounter=0;
string funcArguments;
string currArguments;
int tempodd;
int tempeven;

#line 109 "build/parse.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 245 "build/parse.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUILD_PARSE_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2387

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  279
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  485

#define YYUNDEFTOK  2
#define YYMAXUTOK   330


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    96,     2,     2,     2,    87,    94,     2,
      83,    84,    89,    85,    75,    86,    90,    88,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    98,    78,
      92,    95,    91,    99,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    81,     2,    82,    76,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    79,    77,    80,    97,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      93
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,   102,   103,   104,   105,   109,   119,   128,
     133,   138,   139,   143,   146,   147,   151,   152,   157,   158,
     170,   190,   238,   248,   262,   277,   291,   304,   319,   325,
     338,   339,   354,   368,   381,   386,   391,   399,   400,   401,
     402,   403,   404,   408,   409,   418,   419,   438,   458,   473,
     474,   495,   520,   521,   531,   546,   547,   563,   576,   589,
     605,   606,   617,   631,   632,   647,   648,   664,   665,   681,
     682,   690,   691,   699,   700,   720,   721,   738,   739,   742,
     745,   748,   751,   754,   757,   760,   763,   766,   772,   773,
     779,   783,   784,   785,   789,   790,   791,   792,   793,   794,
     795,   796,   797,   798,   802,   803,   807,   823,   839,   842,
     845,   848,   851,   854,   860,   864,   868,   872,   876,   880,
     884,   888,   892,   896,   900,   904,   910,   911,   914,   915,
     922,   929,   936,   946,   952,   955,   961,   962,   966,   967,
     970,   974,   975,   976,   977,   981,   982,   986,   987,   990,
     996,   999,  1002,  1005,  1009,  1016,  1017,  1021,  1022,  1026,
    1032,  1035,  1038,  1041,  1047,  1050,  1058,  1061,  1068,  1076,
    1080,  1084,  1089,  1100,  1109,  1121,  1132,  1140,  1152,  1161,
    1170,  1179,  1192,  1206,  1214,  1220,  1221,  1222,  1223,  1228,
    1229,  1234,  1239,  1243,  1244,  1248,  1259,  1260,  1264,  1267,
    1274,  1275,  1279,  1280,  1281,  1285,  1286,  1287,  1288,  1292,
    1296,  1300,  1301,  1302,  1303,  1304,  1305,  1309,  1313,  1314,
    1318,  1319,  1320,  1321,  1322,  1323,  1327,  1329,  1331,  1335,
    1348,  1349,  1371,  1387,  1394,  1395,  1399,  1400,  1407,  1415,
    1416,  1417,  1418,  1419,  1420,  1424,  1428,  1432,  1439,  1440,
    1449,  1464,  1465,  1470,  1471,  1475,  1477,  1481,  1484,  1487,
    1493,  1496,  1499,  1502,  1505,  1508,  1514,  1519,  1522,  1525,
    1528,  1536,  1537,  1542,  1543,  1547,  1556,  1567,  1579,  1580
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "CONST", "CASE", "CONTINUE",
  "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT", "FOR",
  "IF", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT", "RETURN", "SHORT",
  "SIGNED", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED",
  "VOID", "VOLATILE", "WHILE", "ALIGNAS", "ALIGNOF", "ATOMIC", "BOOL",
  "COMPLEX", "GENERIC", "IMAGINARY", "NORETURN", "STATIC_ASSERT",
  "THREAD_LOCAL", "FUNC_NAME", "AUTO", "BREAK", "GOTO", "TYPEDEF_NAME",
  "IDENTIFIER", "ENUMERATION_CONSTANT", "STRING_LITERAL", "I_CONSTANT",
  "F_CONSTANT", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN",
  "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "ELLIPSIS",
  "','", "'^'", "'|'", "';'", "'{'", "'}'", "'['", "']'", "'('", "')'",
  "'+'", "'-'", "'%'", "'/'", "'*'", "'.'", "'>'", "'<'", "SIZEOF", "'&'",
  "'='", "'!'", "'~'", "':'", "'?'", "$accept", "primary_expression",
  "constant", "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "E5", "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "E3",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "designation", "designator_list",
  "designator", "static_assert_declaration", "statement",
  "labeled_statement", "compound_statement", "E1", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "E2", "declaration_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    44,    94,   124,    59,   123,
     125,    91,    93,    40,    41,    43,    45,    37,    47,    42,
      46,    62,    60,   330,    38,    61,    33,   126,    58,    63
};
# endif

#define YYPACT_NINF (-357)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-134)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2217,  -357,  -357,  -357,   -11,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,    -2,     4,  -357,  -357,  -357,  -357,    50,  -357,  -357,
    -357,  -357,    84,  2259,  2259,  -357,     8,  -357,  -357,  2259,
    2259,  2259,  -357,  2175,  -357,  -357,    58,   132,   853,  2340,
    2004,  -357,  -357,   -26,    24,    51,  -357,   -17,   186,    23,
    -357,  -357,   148,   184,  -357,  -357,  -357,  -357,  -357,   132,
    -357,   115,    36,  -357,   137,   159,  -357,  -357,  -357,  -357,
    -357,  -357,  2023,  2023,   853,  -357,  -357,  -357,  2080,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,   -30,  -357,  2004,  -357,
     208,    67,   178,   174,   218,   155,   197,   206,   230,   -22,
    -357,   216,  2340,   187,  2340,   229,   232,   244,   238,  -357,
    -357,  -357,    24,   -26,  -357,  1716,  1566,   423,  -357,   186,
     247,  2301,    43,  2004,   -33,  -357,  2340,  2004,   853,  -357,
    -357,   427,  -357,  -357,    64,   251,   853,  -357,   293,  -357,
    -357,  2004,  1773,   298,  -357,  2004,  2004,  2004,  2004,  2004,
    2004,  2004,  2004,  2004,  2004,  2004,  2004,  2004,  2004,  2004,
    2004,  2004,  2004,  2004,  -357,  -357,   875,  1354,   227,  -357,
     257,  -357,  -357,  -357,   297,  -357,  -357,  -357,  -357,   253,
    1697,  -357,  -357,   272,  -357,    84,  -357,   663,  1566,  1111,
    -357,   276,   277,   939,  1436,  2301,   382,  -357,    86,  -357,
      44,  -357,  -357,  -357,  -357,   279,   289,   282,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  2004,
    2004,  -357,  1792,   284,  -357,   -37,  -357,    72,  -357,  -357,
    -357,  -357,  -357,   208,   208,    67,    67,   178,   178,   178,
     178,   174,   174,   218,   155,   197,   206,   230,   -44,  1111,
    -357,   288,   291,   961,  -357,    57,   287,   299,  -357,   292,
     257,  1025,  1482,   294,  2004,   327,  -357,   103,  1716,    55,
    -357,  -357,  2004,   304,   285,  1177,   306,   307,  1849,   309,
     315,   323,   329,   308,  -357,   196,  -357,  -357,  -357,  -357,
     568,  -357,  -357,  -357,  -357,  -357,  -357,  -357,   305,  1111,
    -357,  -357,  2004,  -357,   326,   332,  -357,  -357,   325,    88,
    1524,  -357,  -357,  -357,  2004,   209,  -357,   317,  -357,  -357,
     314,   337,  -357,  -357,  1697,  -357,   337,  -357,  2004,  -357,
    2004,   338,  1111,  -357,  -357,  2004,  -357,   340,  1272,  -357,
      96,  -357,  -357,  1611,  -357,  1111,  -357,   342,   343,  1047,
    -357,   344,   348,   349,  -357,  1618,  -357,  -357,  -357,  -357,
     334,  -357,  1177,   401,   758,  2004,  -357,   213,  2004,  2004,
    -357,   357,  1177,  -357,  -357,  -357,  -357,   354,   356,  -357,
    -357,  -357,   391,  -357,  -357,  -357,    87,  -357,  2004,   346,
     130,  -357,   347,   166,  -357,  -357,  -357,   358,   359,  -357,
    -357,  -357,   360,  1111,  -357,  -357,  2004,  -357,   364,  -357,
    -357,  -357,  -357,  -357,  1716,  1177,  -357,   365,  1871,  1871,
     141,  -357,   146,   156,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  2004,   314,  -357,  2004,  1640,  -357,  -357,  -357,  -357,
     367,   368,  -357,  -357,  -357,  2004,  1928,  1947,  1177,  1177,
    1177,  -357,  -357,  -357,  -357,  -357,  -357,   164,  1177,   170,
    1177,   172,   441,  -357,  -357,   374,  -357,  1177,  -357,  1177,
    1177,  -357,  -357,  -357,  -357
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   115,   160,   120,     0,   109,   119,   164,   117,   118,
     113,   161,   116,   121,   110,   134,   108,   135,   122,   114,
     162,     0,   163,   123,   124,   125,   165,     0,   111,   112,
     129,   274,     0,    95,    97,   127,   133,   128,   126,    99,
     101,   103,    93,     0,   271,   273,   154,     0,     0,     0,
       0,   170,    91,     0,   188,     0,   104,   277,   169,     0,
      94,    96,   132,     0,    98,   100,   102,     1,   272,     0,
      10,   158,     0,   155,     0,     0,    12,     2,     9,    11,
       7,     8,     0,     0,     0,    39,    40,    38,     0,    37,
      42,    41,    18,     3,     4,     6,    30,    43,     0,    45,
      49,    52,    55,    60,    63,    65,    67,    69,    71,    73,
      90,     0,   142,   201,   144,     0,     0,     0,     0,   163,
     189,   187,   186,     0,    92,     0,     0,     0,   184,   168,
       0,     0,     0,     0,     0,   150,     0,     0,     0,    31,
      32,    43,    75,    88,     0,     0,     0,    34,     0,    24,
      25,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   141,     0,     0,   203,   200,
     204,   143,   166,   159,     0,   171,   190,   185,   105,   107,
       0,   228,   106,   250,   278,     0,   276,     0,     0,     0,
     172,    38,     0,     0,     0,     0,     0,   136,     0,   140,
       0,   152,   157,   151,   156,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    77,     0,
       0,     5,     0,     0,    23,     0,    20,     0,    28,    22,
      48,    47,    46,    50,    51,    53,    54,    58,    59,    57,
      56,    61,    62,    64,    66,    68,    70,    72,     0,     0,
     206,    38,     0,     0,   222,   197,     0,   192,   193,     0,
     202,     0,     0,     0,     0,     0,   230,     0,     0,     0,
     234,   248,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,   255,     0,   253,   254,   239,   240,
       0,   251,   241,   242,   243,   244,   279,   275,     0,     0,
     173,   180,     0,   179,    38,     0,   198,   182,     0,     0,
       0,   130,   137,   138,     0,     0,   145,   149,   153,    36,
       0,     0,    76,    89,     0,    44,    35,    19,     0,    21,
       0,     0,     0,   207,   213,     0,   212,     0,     0,   195,
     203,   196,   223,     0,   205,     0,   214,    38,     0,     0,
     224,     0,     0,     0,   237,     0,   226,   229,   233,   235,
       0,   267,     0,     0,     0,     0,   269,     0,     0,     0,
     268,     0,     0,   256,   249,   252,   175,     0,     0,   176,
     178,   181,     0,   183,   131,   147,     0,   139,     0,     0,
       0,    14,     0,     0,    29,    74,   209,     0,     0,   211,
     191,   194,     0,     0,   215,   221,     0,   220,     0,   225,
     238,   236,   227,   232,     0,     0,   247,     0,     0,     0,
       0,   270,     0,     0,   266,   245,   174,   177,   199,   146,
     148,     0,     0,    13,     0,     0,    26,   208,   210,   217,
       0,     0,   218,   231,   246,     0,     0,     0,     0,     0,
       0,    17,    15,    16,    27,   216,   219,     0,     0,     0,
       0,     0,   258,   259,   260,     0,   264,     0,   262,     0,
       0,   261,   265,   263,   257
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -357,  -357,  -357,  -357,  -357,  -357,  -357,    11,  -357,  -357,
      32,  -357,   -14,   131,   144,    95,   163,   296,   286,   290,
     310,   311,  -357,   -31,   125,  -357,   -76,   -38,   -94,     9,
    -357,   333,  -357,   -45,  -357,   403,  -357,   263,  -195,   -98,
    -357,    73,  -357,   407,   -88,  -357,   -48,  -357,  -357,   -27,
     -52,  -357,   -28,  -100,  -183,  -357,   126,  -357,   -19,  -111,
    -168,  -112,   151,  -345,  -357,   203,   -96,  -251,  -357,   -86,
    -357,  -357,   188,  -356,  -357,  -357,  -357,  -357,   443,  -357,
    -357,  -357
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    92,    93,    71,    94,    95,   400,   401,    96,   237,
     141,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   142,   143,   229,   295,   111,    31,   195,
      55,    56,    33,    34,    35,    63,    36,   206,   207,   113,
     325,   326,    37,    72,    73,    38,    39,    40,    41,   118,
      58,   204,    59,   122,   266,   267,   268,   319,   402,   269,
     180,   276,   277,   278,   279,   280,    42,   297,   298,   299,
     197,   300,   301,   302,   303,   304,   305,    43,    44,    45,
     126,   198
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     114,   114,   179,   112,   112,    57,   120,   129,   144,    32,
     270,   322,   117,   192,   175,    70,   181,   110,   429,   110,
     424,   318,    51,   148,   149,   150,   121,   203,     2,   115,
     116,   230,   194,   208,   373,   209,   114,    46,   230,   112,
     196,   172,    60,    61,    11,   337,   214,   213,    64,    65,
      66,   151,    32,   152,   340,    20,    62,    53,  -107,   119,
     153,  -107,   144,    54,   114,   145,   114,   112,    47,   112,
     144,    51,   456,   457,   186,   235,   263,   173,   125,   120,
      97,    48,    97,   114,   154,   178,   112,    49,   114,   361,
     114,   112,    70,   112,   187,   212,   189,   258,   114,   309,
     424,   112,   110,   296,   306,    51,    53,   208,   208,   209,
     209,   134,   307,    54,   139,   140,   135,   215,   210,   217,
     147,   426,   214,   211,   328,   322,   123,   233,   120,   124,
      97,   435,    51,    50,    51,    51,   274,    69,   176,   230,
     348,   240,   241,   242,    51,   275,    54,   338,   231,   178,
     368,   120,   158,   159,   351,   186,   339,   114,   114,   342,
     112,   112,    52,   392,   323,    97,   367,    53,   189,    53,
      53,   359,   393,    54,   454,    54,    54,   176,   365,   348,
      70,   327,   270,   366,   324,   324,   265,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,   442,   296,   472,   473,   474,
     133,   120,   377,   265,   443,   186,   230,   476,   335,   478,
     136,   230,   208,   120,   209,   458,   482,  -133,   483,   484,
     459,   230,   162,   163,   160,   161,   363,   350,   349,   230,
     460,   445,   137,   110,   370,   230,   446,   230,   475,   168,
     191,   110,   202,   423,   477,   413,   479,   247,   248,   249,
     250,   186,   216,   131,    97,   164,   165,   127,   176,   128,
     177,   230,   114,   169,   383,   112,    54,   238,   166,   167,
     428,   265,   114,   170,   396,   112,   395,   397,   230,   243,
     244,   431,   171,   110,   186,   155,   156,   157,   129,   430,
     174,   262,   432,   433,   245,   246,    97,   120,   176,   405,
     177,   186,   453,   182,    97,   191,   183,     1,     2,   184,
     350,   399,   185,     3,   308,     4,   205,     6,   315,   251,
     252,     8,     9,   423,    11,   232,    12,    13,   271,    15,
     272,   234,    17,    18,    19,    20,   239,   273,   125,    22,
      23,    24,   281,    25,   332,   333,    97,   265,   310,   311,
     440,    30,   265,   329,   330,   186,   331,   110,   336,   327,
     343,   352,    97,   344,   353,   364,   354,   381,   362,   467,
     469,   471,   371,   372,   341,     1,     2,   386,   347,   374,
     375,     3,   378,     4,   114,     6,   358,   112,   379,     8,
       9,   380,    11,   191,    12,    13,   382,    15,   389,   391,
      17,    18,    19,    20,   390,   398,   334,    22,    23,    24,
     406,    25,   409,    27,   414,   415,   420,     2,   419,    30,
      97,   421,   425,   427,   387,   434,   436,   388,   437,   438,
     447,   448,   449,    11,   441,   444,   452,   199,   455,   465,
     466,   480,   481,   462,    20,   254,   188,    74,   119,   191,
     255,    75,   321,   404,   253,   130,    76,   407,   320,   439,
     408,    77,    78,    79,    80,    81,   132,    82,    83,   411,
     412,   256,   369,   257,   418,   403,    68,     0,   385,     0,
     191,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,     0,     0,     0,     0,   200,    84,     0,    85,    86,
       0,     0,   201,     0,     0,     0,    88,    89,     0,    90,
      91,     0,   228,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   450,     0,
       0,   451,     0,     0,     0,     0,     0,     0,     0,   191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   461,     0,     0,   463,
     191,     1,     2,   282,   283,   284,   285,     3,     0,     4,
       5,     6,   286,   287,     7,     8,     9,    10,    11,   288,
      12,    13,    14,    15,   289,    16,    17,    18,    19,    20,
     290,    21,    74,    22,    23,    24,    75,    25,    26,    27,
      28,    76,    29,   291,   292,    30,   293,    78,    79,    80,
      81,     0,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,   193,   384,     0,
       0,    84,     0,    85,    86,     0,     0,    87,     0,     0,
       0,    88,    89,     0,    90,    91,     1,     2,   282,   283,
     284,   285,     3,     0,     4,     5,     6,   286,   287,     7,
       8,     9,    10,    11,   288,    12,    13,    14,    15,   289,
      16,    17,    18,    19,    20,   290,    21,    74,    22,    23,
      24,    75,    25,    26,    27,    28,    76,    29,   291,   292,
      30,   293,    78,    79,    80,    81,     0,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,   193,     0,     0,     0,    84,     0,    85,    86,
       0,     0,    87,     0,     0,     0,    88,    89,     0,    90,
      91,     1,     2,     0,     0,     0,     0,     3,     0,     4,
       5,     6,     0,     0,     7,     8,     9,    10,    11,     0,
      12,    13,    14,    15,     0,    16,    17,    18,    19,    20,
       0,    21,    74,    22,    23,    24,    75,    25,    26,    27,
      28,    76,    29,     0,     0,    30,    77,    78,    79,    80,
      81,     0,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
       0,    84,     0,    85,    86,     0,     0,    87,     0,     0,
       0,    88,    89,     0,    90,    91,     1,     2,     0,     0,
       0,     0,     3,     0,     4,     0,     6,     0,     0,     0,
       8,     9,     0,    11,     0,    12,    13,     0,    15,     2,
       0,    17,    18,    19,    20,     0,     0,    74,    22,    23,
      24,    75,    25,     0,     0,    11,    76,     0,     0,   259,
      30,    77,    78,    79,    80,    81,    20,    82,    83,    74,
     119,     0,     0,    75,     0,     0,     0,     0,    76,     0,
       0,     0,     0,    77,    78,    79,    80,    81,     0,    82,
      83,     0,     0,     0,     0,     0,    84,     0,    85,    86,
       0,     0,    87,     2,     0,     0,    88,    89,     0,    90,
      91,     0,     0,     0,     0,     0,     0,   260,    84,    11,
      85,    86,     0,   312,   261,     2,     0,     0,    88,    89,
      20,    90,    91,    74,   119,     0,     0,    75,     0,     0,
       0,    11,    76,     0,     0,   345,     0,    77,    78,    79,
      80,    81,    20,    82,    83,    74,   119,     0,     0,    75,
       0,     0,     0,     0,    76,     0,     0,     0,     0,    77,
      78,    79,    80,    81,     0,    82,    83,     0,     0,     0,
       0,   313,    84,     0,    85,    86,     0,     0,   314,     2,
       0,     0,    88,    89,     0,    90,    91,     0,     0,     0,
       0,     0,     0,   346,    84,    11,    85,    86,     0,   355,
      87,     2,     0,     0,    88,    89,    20,    90,    91,    74,
     119,     0,     0,    75,     0,     0,     0,    11,    76,     0,
       0,   416,     0,    77,    78,    79,    80,    81,    20,    82,
      83,    74,   119,     0,     0,    75,     0,     0,     0,     0,
      76,     0,     0,     0,     0,    77,    78,    79,    80,    81,
       0,    82,    83,     0,     0,     0,     0,   356,    84,     0,
      85,    86,     0,     0,   357,     2,     0,     0,    88,    89,
       0,    90,    91,     0,     0,     0,     0,     0,     0,   417,
      84,    11,    85,    86,     0,     0,    87,     0,     0,     0,
      88,    89,    20,    90,    91,    74,   119,     0,     0,    75,
       0,     0,     0,     0,    76,     0,     0,     0,     0,    77,
      78,    79,    80,    81,     0,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,   283,   284,   285,     0,     0,     0,     0,
       0,   286,   287,     0,    84,     0,    85,    86,   288,     0,
      87,     0,     0,   289,    88,    89,     0,    90,    91,   290,
       0,    74,     0,     0,     0,    75,     0,     0,     0,     0,
      76,     0,   291,   292,     0,   293,    78,    79,    80,    81,
       0,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,   193,     0,     0,     0,
      84,     0,    85,    86,     0,     0,    87,     0,     0,     0,
      88,    89,     0,    90,    91,     1,     2,     0,     0,     0,
       0,     3,     0,     4,     5,     6,     0,     0,     7,     8,
       9,    10,    11,     0,    12,    13,    14,    15,     0,    16,
      17,    18,    19,    20,     0,    21,     0,    22,    23,    24,
       0,    25,    26,     0,    28,     0,    29,     0,     0,    30,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,     0,   348,   264,     1,     2,     0,
       0,    54,     0,     3,     0,     4,     5,     6,     0,     0,
       7,     8,     9,    10,    11,     0,    12,    13,    14,    15,
       0,    16,    17,    18,    19,    20,     0,    21,     0,    22,
      23,    24,     0,    25,    26,     0,    28,     0,    29,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,     0,   177,   264,     1,
       2,     0,     0,    54,     0,     3,     0,     4,     5,     6,
       0,     0,     7,     8,     9,    10,    11,     0,    12,    13,
      14,    15,     0,    16,    17,    18,    19,    20,     0,    21,
       0,    22,    23,    24,     0,    25,    26,     0,    28,     0,
      29,     0,     0,    30,   316,     1,     2,     0,     0,     0,
       0,     3,     0,     4,     5,     6,     0,     0,     7,     8,
       9,    10,    11,     0,    12,    13,    14,    15,     0,    16,
      17,    18,    19,    20,     0,    21,     0,    22,    23,    24,
     317,    25,    26,     0,    28,     0,    29,     1,     2,    30,
       0,     0,     0,     3,     0,     4,     0,     6,     0,     0,
       0,     8,     9,     0,    11,     0,    12,    13,     0,    15,
       0,     0,    17,    18,    19,    20,     0,     0,     0,    22,
      23,    24,     0,    25,     0,    27,   360,     0,     0,     1,
       2,    30,     0,     0,     0,     3,     0,     4,     5,     6,
       0,     0,     7,     8,     9,    10,    11,     0,    12,    13,
      14,    15,     0,    16,    17,    18,    19,    20,     0,    21,
       0,    22,    23,    24,   394,    25,    26,    27,    28,     0,
      29,     0,     0,    30,     1,     2,     0,     0,     0,     0,
       3,     0,     4,     5,     6,     0,     0,     7,     8,     9,
      10,    11,     0,    12,    13,    14,    15,     0,    16,    17,
      18,    19,    20,     0,    21,   193,    22,    23,    24,     0,
      25,    26,    74,    28,     0,    29,    75,     0,    30,     0,
       0,    76,     0,     0,     0,     0,    77,    78,    79,    80,
      81,     0,    82,    83,    74,     0,     0,     0,    75,     0,
       0,     0,     0,    76,     0,   410,     0,     0,    77,    78,
      79,    80,    81,     0,    82,    83,     0,   190,   422,   274,
       0,    84,     0,    85,    86,     0,     0,    87,   275,     0,
       0,    88,    89,     0,    90,    91,     0,     0,     0,   190,
     464,   274,     0,    84,     0,    85,    86,     0,     0,    87,
     275,    74,     0,    88,    89,    75,    90,    91,     0,     0,
      76,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      74,    82,    83,     0,    75,     0,     0,     0,     0,    76,
       0,     0,     0,     0,    77,    78,    79,    80,    81,     0,
      82,    83,     0,     0,     0,     0,   190,     0,   274,     0,
      84,     0,    85,    86,     0,     0,    87,   275,     0,     0,
      88,    89,     0,    90,    91,   190,     0,     0,     0,    84,
       0,    85,    86,     0,     0,    87,     0,    74,     0,    88,
      89,    75,    90,    91,     0,     0,    76,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    74,    82,    83,     0,
      75,     0,     0,     0,     0,    76,     0,     0,     0,     0,
      77,    78,    79,    80,    81,     0,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    84,   236,    85,    86,
       0,     0,    87,     0,     0,     0,    88,    89,     0,    90,
      91,   334,     0,     0,     0,    84,     0,    85,    86,     0,
       0,    87,     0,    74,     0,    88,    89,    75,    90,    91,
       0,     0,    76,     0,     0,     0,     0,    77,    78,    79,
      80,    81,     0,    82,    83,    74,     0,     0,     0,    75,
       0,     0,     0,     0,    76,     0,     0,     0,     0,    77,
      78,    79,    80,    81,     0,    82,    83,   376,     0,     0,
       0,     0,    84,     0,    85,    86,     0,     0,    87,     0,
       0,     0,    88,    89,     0,    90,    91,     0,     0,   294,
       0,     0,     0,     0,    84,     0,    85,    86,     0,     0,
      87,     0,    74,     0,    88,    89,    75,    90,    91,     0,
       0,    76,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    74,    82,    83,     0,    75,     0,     0,     0,     0,
      76,     0,     0,     0,     0,    77,    78,    79,    80,    81,
       0,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,    84,   468,    85,    86,     0,     0,    87,     0,     0,
       0,    88,    89,     0,    90,    91,     0,     0,     0,     0,
      84,   470,    85,    86,     0,     0,    87,     0,    74,     0,
      88,    89,    75,    90,    91,     0,     0,    76,     0,     0,
       0,     0,    77,    78,    79,    80,    81,    74,    82,    83,
       0,    75,     0,     0,     0,     0,    76,     0,     0,     0,
       0,    77,    78,    79,    80,    81,     0,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    85,
      86,     0,     0,    87,     0,     0,     0,    88,    89,     0,
      90,    91,     0,     0,     0,     0,   138,     0,    85,    86,
       0,     0,    87,     0,    74,     0,    88,    89,    75,    90,
      91,     0,     0,    76,     0,     0,     0,     0,    77,    78,
      79,    80,    81,     0,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,     0,    85,    86,     0,     0,    87,
       0,     0,     0,    88,    89,    67,    90,    91,     1,     2,
       0,     0,     0,     0,     3,     0,     4,     5,     6,     0,
       0,     7,     8,     9,    10,    11,     0,    12,    13,    14,
      15,     0,    16,    17,    18,    19,    20,     0,    21,     0,
      22,    23,    24,     0,    25,    26,    27,    28,     0,    29,
       1,     2,    30,     0,     0,     0,     3,     0,     4,     5,
       6,     0,     0,     7,     8,     9,    10,    11,     0,    12,
      13,    14,    15,     0,    16,    17,    18,    19,    20,     0,
      21,     0,    22,    23,    24,     0,    25,    26,    27,    28,
       0,    29,     1,     2,    30,     0,     0,     0,     3,     0,
       4,     5,     6,     0,     0,     7,     8,     9,    10,    11,
       0,    12,    13,    14,    15,     0,    16,    17,    18,    19,
      20,     0,    21,     0,    22,    23,    24,     0,    25,    26,
       0,    28,     0,    29,     1,     2,    30,     0,     0,     0,
       3,     0,     4,     0,     6,     0,     0,     0,     8,     9,
       0,    11,     0,    12,    13,     0,    15,     0,     0,    17,
      18,    19,    20,     0,     0,     0,    22,    23,    24,     0,
      25,     0,    27,     1,     2,     0,     0,     0,    30,     3,
       0,     4,     0,     6,     0,     0,     0,     8,     9,     0,
      11,     0,    12,    13,     0,    15,     0,     0,    17,    18,
      19,    20,     0,     0,     0,    22,    23,    24,     0,    25,
       0,     0,     0,     0,     0,     0,     0,    30
};

static const yytype_int16 yycheck[] =
{
      48,    49,   113,    48,    49,    32,    54,    59,    84,     0,
     178,   206,    50,   125,   112,    48,   114,    48,   374,    50,
     365,   204,    48,    53,    54,    55,    54,   127,     4,    48,
      49,    75,   126,   131,   285,   131,    84,    48,    75,    84,
     126,    63,    33,    34,    20,    82,   134,    80,    39,    40,
      41,    81,    43,    83,    98,    31,    48,    83,    75,    35,
      90,    78,   138,    89,   112,    84,   114,   112,    79,   114,
     146,    48,   428,   429,   122,   151,   176,    99,    95,   127,
      48,    83,    50,   131,    98,   113,   131,    83,   136,   272,
     138,   136,    48,   138,   122,   133,   123,   173,   146,   199,
     445,   146,   133,   197,   198,    48,    83,   205,   206,   205,
     206,    75,   198,    89,    82,    83,    80,   136,    75,   138,
      88,   372,   210,    80,    80,   320,    75,   146,   176,    78,
      98,   382,    48,    83,    48,    48,    81,    79,    81,    75,
      83,   155,   156,   157,    48,    90,    89,    75,    84,   177,
      95,   199,    85,    86,   265,   203,    84,   205,   206,   259,
     205,   206,    78,    75,    78,   133,   278,    83,   195,    83,
      83,   271,    84,    89,   425,    89,    89,    81,    75,    83,
      48,   208,   350,    80,    98,    98,   177,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    75,   300,   458,   459,   460,
      95,   259,   288,   204,    84,   263,    75,   468,   232,   470,
      83,    75,   320,   271,   320,    84,   477,    79,   479,   480,
      84,    75,    58,    59,    56,    57,   274,   265,   265,    75,
      84,    75,    83,   274,   282,    75,    80,    75,    84,    94,
     125,   282,   127,   365,    84,   355,    84,   162,   163,   164,
     165,   309,   137,    79,   232,    91,    92,    81,    81,    83,
      83,    75,   320,    76,    78,   320,    89,   152,    60,    61,
     374,   272,   330,    77,    75,   330,   324,    78,    75,   158,
     159,    78,    62,   324,   342,    87,    88,    89,   350,   375,
      84,   176,   378,   379,   160,   161,   274,   355,    81,   340,
      83,   359,   424,    84,   282,   190,    84,     3,     4,    75,
     348,     7,    84,     9,   199,    11,    79,    13,   203,   166,
     167,    17,    18,   445,    20,    84,    22,    23,    81,    25,
      83,    48,    28,    29,    30,    31,    48,    50,    95,    35,
      36,    37,    80,    39,   229,   230,   324,   348,    82,    82,
     398,    47,   353,    84,    75,   413,    84,   398,    84,   396,
      82,    84,   340,    82,    75,    48,    84,    48,    84,   455,
     456,   457,    78,    98,   259,     3,     4,    82,   263,    83,
      83,     9,    83,    11,   442,    13,   271,   442,    83,    17,
      18,    78,    20,   278,    22,    23,    98,    25,    82,    84,
      28,    29,    30,    31,    82,    98,    79,    35,    36,    37,
      82,    39,    82,    41,    82,    82,    78,     4,    84,    47,
     398,    82,    98,    32,   309,    78,    82,   312,    82,    48,
      82,    82,    82,    20,    98,    98,    82,    24,    83,    82,
      82,    10,    78,   442,    31,   169,   123,    34,    35,   334,
     170,    38,    80,   338,   168,    62,    43,   342,   205,   396,
     345,    48,    49,    50,    51,    52,    69,    54,    55,   353,
     355,   171,   279,   172,   359,   334,    43,    -1,   300,    -1,
     365,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,    86,
      -1,    -1,    89,    -1,    -1,    -1,    93,    94,    -1,    96,
      97,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,   444,
     445,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    -1,
      -1,    83,    -1,    85,    86,    -1,    -1,    89,    -1,    -1,
      -1,    93,    94,    -1,    96,    97,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    -1,    -1,    -1,    83,    -1,    85,    86,
      -1,    -1,    89,    -1,    -1,    -1,    93,    94,    -1,    96,
      97,     3,     4,    -1,    -1,    -1,    -1,     9,    -1,    11,
      12,    13,    -1,    -1,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    83,    -1,    85,    86,    -1,    -1,    89,    -1,    -1,
      -1,    93,    94,    -1,    96,    97,     3,     4,    -1,    -1,
      -1,    -1,     9,    -1,    11,    -1,    13,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    22,    23,    -1,    25,     4,
      -1,    28,    29,    30,    31,    -1,    -1,    34,    35,    36,
      37,    38,    39,    -1,    -1,    20,    43,    -1,    -1,    24,
      47,    48,    49,    50,    51,    52,    31,    54,    55,    34,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,
      -1,    -1,    89,     4,    -1,    -1,    93,    94,    -1,    96,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    20,
      85,    86,    -1,    24,    89,     4,    -1,    -1,    93,    94,
      31,    96,    97,    34,    35,    -1,    -1,    38,    -1,    -1,
      -1,    20,    43,    -1,    -1,    24,    -1,    48,    49,    50,
      51,    52,    31,    54,    55,    34,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    -1,    -1,    89,     4,
      -1,    -1,    93,    94,    -1,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    20,    85,    86,    -1,    24,
      89,     4,    -1,    -1,    93,    94,    31,    96,    97,    34,
      35,    -1,    -1,    38,    -1,    -1,    -1,    20,    43,    -1,
      -1,    24,    -1,    48,    49,    50,    51,    52,    31,    54,
      55,    34,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    -1,    -1,    -1,    82,    83,    -1,
      85,    86,    -1,    -1,    89,     4,    -1,    -1,    93,    94,
      -1,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    20,    85,    86,    -1,    -1,    89,    -1,    -1,    -1,
      93,    94,    31,    96,    97,    34,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    14,    15,    -1,    83,    -1,    85,    86,    21,    -1,
      89,    -1,    -1,    26,    93,    94,    -1,    96,    97,    32,
      -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    -1,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      83,    -1,    85,    86,    -1,    -1,    89,    -1,    -1,    -1,
      93,    94,    -1,    96,    97,     3,     4,    -1,    -1,    -1,
      -1,     9,    -1,    11,    12,    13,    -1,    -1,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    -1,    33,    -1,    35,    36,    37,
      -1,    39,    40,    -1,    42,    -1,    44,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    83,    84,     3,     4,    -1,
      -1,    89,    -1,     9,    -1,    11,    12,    13,    -1,    -1,
      16,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    -1,    33,    -1,    35,
      36,    37,    -1,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    83,    84,     3,
       4,    -1,    -1,    89,    -1,     9,    -1,    11,    12,    13,
      -1,    -1,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    -1,    33,
      -1,    35,    36,    37,    -1,    39,    40,    -1,    42,    -1,
      44,    -1,    -1,    47,    48,     3,     4,    -1,    -1,    -1,
      -1,     9,    -1,    11,    12,    13,    -1,    -1,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    -1,    33,    -1,    35,    36,    37,
      84,    39,    40,    -1,    42,    -1,    44,     3,     4,    47,
      -1,    -1,    -1,     9,    -1,    11,    -1,    13,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    22,    23,    -1,    25,
      -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    35,
      36,    37,    -1,    39,    -1,    41,    84,    -1,    -1,     3,
       4,    47,    -1,    -1,    -1,     9,    -1,    11,    12,    13,
      -1,    -1,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    -1,    33,
      -1,    35,    36,    37,    80,    39,    40,    41,    42,    -1,
      44,    -1,    -1,    47,     3,     4,    -1,    -1,    -1,    -1,
       9,    -1,    11,    12,    13,    -1,    -1,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    -1,    33,    79,    35,    36,    37,    -1,
      39,    40,    34,    42,    -1,    44,    38,    -1,    47,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    -1,    54,    55,    34,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    43,    -1,    74,    -1,    -1,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    79,    80,    81,
      -1,    83,    -1,    85,    86,    -1,    -1,    89,    90,    -1,
      -1,    93,    94,    -1,    96,    97,    -1,    -1,    -1,    79,
      80,    81,    -1,    83,    -1,    85,    86,    -1,    -1,    89,
      90,    34,    -1,    93,    94,    38,    96,    97,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      34,    54,    55,    -1,    38,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,    -1,    -1,    -1,    79,    -1,    81,    -1,
      83,    -1,    85,    86,    -1,    -1,    89,    90,    -1,    -1,
      93,    94,    -1,    96,    97,    79,    -1,    -1,    -1,    83,
      -1,    85,    86,    -1,    -1,    89,    -1,    34,    -1,    93,
      94,    38,    96,    97,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    34,    54,    55,    -1,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      -1,    -1,    89,    -1,    -1,    -1,    93,    94,    -1,    96,
      97,    79,    -1,    -1,    -1,    83,    -1,    85,    86,    -1,
      -1,    89,    -1,    34,    -1,    93,    94,    38,    96,    97,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    -1,    54,    55,    34,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    54,    55,    78,    -1,    -1,
      -1,    -1,    83,    -1,    85,    86,    -1,    -1,    89,    -1,
      -1,    -1,    93,    94,    -1,    96,    97,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    83,    -1,    85,    86,    -1,    -1,
      89,    -1,    34,    -1,    93,    94,    38,    96,    97,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    34,    54,    55,    -1,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    -1,    -1,    89,    -1,    -1,
      -1,    93,    94,    -1,    96,    97,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    -1,    -1,    89,    -1,    34,    -1,
      93,    94,    38,    96,    97,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    34,    54,    55,
      -1,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,
      86,    -1,    -1,    89,    -1,    -1,    -1,    93,    94,    -1,
      96,    97,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,
      -1,    -1,    89,    -1,    34,    -1,    93,    94,    38,    96,
      97,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    85,    86,    -1,    -1,    89,
      -1,    -1,    -1,    93,    94,     0,    96,    97,     3,     4,
      -1,    -1,    -1,    -1,     9,    -1,    11,    12,    13,    -1,
      -1,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    -1,    33,    -1,
      35,    36,    37,    -1,    39,    40,    41,    42,    -1,    44,
       3,     4,    47,    -1,    -1,    -1,     9,    -1,    11,    12,
      13,    -1,    -1,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    -1,
      33,    -1,    35,    36,    37,    -1,    39,    40,    41,    42,
      -1,    44,     3,     4,    47,    -1,    -1,    -1,     9,    -1,
      11,    12,    13,    -1,    -1,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    -1,    33,    -1,    35,    36,    37,    -1,    39,    40,
      -1,    42,    -1,    44,     3,     4,    47,    -1,    -1,    -1,
       9,    -1,    11,    -1,    13,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    22,    23,    -1,    25,    -1,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    35,    36,    37,    -1,
      39,    -1,    41,     3,     4,    -1,    -1,    -1,    47,     9,
      -1,    11,    -1,    13,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    22,    23,    -1,    25,    -1,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     9,    11,    12,    13,    16,    17,    18,
      19,    20,    22,    23,    24,    25,    27,    28,    29,    30,
      31,    33,    35,    36,    37,    39,    40,    41,    42,    44,
      47,   128,   129,   132,   133,   134,   136,   142,   145,   146,
     147,   148,   166,   177,   178,   179,    48,    79,    83,    83,
      83,    48,    78,    83,    89,   130,   131,   149,   150,   152,
     129,   129,    48,   135,   129,   129,   129,     0,   178,    79,
      48,   103,   143,   144,    34,    38,    43,    48,    49,    50,
      51,    52,    54,    55,    83,    85,    86,    89,    93,    94,
      96,    97,   101,   102,   104,   105,   108,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   127,   133,   139,   146,   158,   158,   127,   149,    35,
     146,   152,   153,    75,    78,    95,   180,    81,    83,   150,
     135,    79,   143,    95,    75,    80,    83,    83,    83,   110,
     110,   110,   123,   124,   126,   158,    83,   110,    53,    54,
      55,    81,    83,    90,   112,    87,    88,    89,    85,    86,
      56,    57,    58,    59,    91,    92,    60,    61,    94,    76,
      77,    62,    63,    99,    84,   139,    81,    83,   152,   159,
     160,   139,    84,    84,    75,    84,   146,   152,   131,   149,
      79,   124,   161,    79,   128,   129,   169,   170,   181,    24,
      82,    89,   124,   153,   151,    79,   137,   138,   139,   166,
      75,    80,   127,    80,   144,   158,   124,   158,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    95,   125,
      75,    84,    84,   158,    48,   126,    84,   109,   124,    48,
     112,   112,   112,   113,   113,   114,   114,   115,   115,   115,
     115,   116,   116,   117,   118,   119,   120,   121,   126,    24,
      82,    89,   124,   153,    84,   129,   154,   155,   156,   159,
     160,    81,    83,    50,    81,    90,   161,   162,   163,   164,
     165,    80,     5,     6,     7,     8,    14,    15,    21,    26,
      32,    45,    46,    48,    78,   126,   128,   167,   168,   169,
     171,   172,   173,   174,   175,   176,   128,   169,   124,   153,
      82,    82,    24,    82,    89,   124,    48,    84,   154,   157,
     137,    80,   138,    78,    98,   140,   141,   149,    80,    84,
      75,    84,   124,   124,    79,   112,    84,    82,    75,    84,
      98,   124,   153,    82,    82,    24,    82,   124,    83,   149,
     152,   159,    84,    75,    84,    24,    82,    89,   124,   153,
      84,   154,    84,   127,    48,    75,    80,   161,    95,   165,
     127,    78,    98,   167,    83,    83,    78,   126,    83,    83,
      78,    48,    98,    78,    80,   172,    82,   124,   124,    82,
      82,    84,    75,    84,    80,   127,    75,    78,    98,     7,
     106,   107,   158,   162,   124,   123,    82,   124,   124,    82,
      74,   156,   124,   153,    82,    82,    24,    82,   124,    84,
      78,    82,    80,   161,   163,    98,   167,    32,   128,   173,
     126,    78,   126,   126,    78,   167,    82,    82,    48,   141,
     127,    98,    75,    84,    98,    75,    80,    82,    82,    82,
     124,   124,    82,   161,   167,    83,   173,   173,    84,    84,
      84,   124,   107,   124,    80,    82,    82,   126,    84,   126,
      84,   126,   167,   167,   167,    84,   167,    84,   167,    84,
      10,    78,   167,   167,   167
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   101,   101,   101,   102,   102,   102,
     103,   104,   104,   105,   106,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   113,   113,   113,   114,
     114,   114,   115,   115,   115,   116,   116,   116,   116,   116,
     117,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   128,   128,   128,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     132,   132,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     134,   134,   134,   135,   136,   136,   137,   137,   138,   138,
     138,   139,   139,   139,   139,   140,   140,   141,   141,   141,
     142,   142,   142,   142,   142,   143,   143,   144,   144,   145,
     146,   146,   146,   146,   147,   147,   148,   148,   149,   149,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   151,   152,   152,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   156,   156,   157,   157,
     158,   158,   159,   159,   159,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   161,   161,   161,   162,
     162,   162,   162,   163,   164,   164,   165,   165,   166,   167,
     167,   167,   167,   167,   167,   168,   168,   168,   169,   169,
     170,   171,   171,   172,   172,   173,   173,   174,   174,   174,
     175,   175,   175,   175,   175,   175,   176,   176,   176,   176,
     176,   177,   177,   178,   178,   179,   179,   180,   181,   181
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     1,     3,     3,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     3,
       1,     2,     2,     2,     2,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     6,     2,     0,     1,     1,     1,     2,     2,     3,
       1,     2,     1,     2,     1,     1,     3,     2,     3,     1,
       4,     5,     5,     6,     2,     1,     3,     3,     1,     4,
       1,     1,     1,     1,     1,     1,     4,     4,     2,     1,
       1,     3,     3,     4,     6,     5,     5,     6,     5,     4,
       4,     5,     4,     5,     0,     3,     2,     2,     1,     1,
       2,     3,     1,     1,     3,     2,     2,     1,     1,     3,
       2,     1,     2,     1,     1,     3,     2,     3,     5,     4,
       5,     4,     3,     3,     3,     4,     6,     5,     5,     6,
       4,     4,     2,     3,     3,     4,     3,     4,     1,     2,
       1,     4,     3,     2,     1,     2,     3,     2,     7,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     3,
       1,     1,     2,     1,     1,     1,     2,     7,     5,     5,
       5,     7,     6,     7,     6,     7,     3,     2,     2,     2,
       3,     1,     2,     1,     1,     5,     4,     0,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 90 "src/parse.y"
                                  {(yyval.ptr)=terminal((yyvsp[0].str));
				    char* a = primaryExpr((yyvsp[0].str));
				    if (a) {string as(a);
                                         (yyval.ptr)->isInit = lookup((yyvsp[0].str))->is_init;
                                         (yyval.ptr)->nodeType=as;
                                         string key((yyvsp[0].str));
                                         (yyval.ptr)->exprType = 3;
                                         (yyval.ptr)->nodeKey = key;
                                    }
				    else{ yyerror("Error: %s is not declared in this scope", (yyvsp[0].str));
                                      (yyval.ptr)->nodeType = string("");}
				  }
#line 2190 "build/parse.tab.c"
    break;

  case 3:
#line 102 "src/parse.y"
                                  {(yyval.ptr)=(yyvsp[0].ptr); }
#line 2196 "build/parse.tab.c"
    break;

  case 4:
#line 103 "src/parse.y"
                                  {(yyval.ptr)=(yyvsp[0].ptr); }
#line 2202 "build/parse.tab.c"
    break;

  case 5:
#line 104 "src/parse.y"
                                  {(yyval.ptr)=(yyvsp[-1].ptr); }
#line 2208 "build/parse.tab.c"
    break;

  case 6:
#line 105 "src/parse.y"
                                  {(yyval.ptr)=(yyvsp[0].ptr); }
#line 2214 "build/parse.tab.c"
    break;

  case 7:
#line 109 "src/parse.y"
                                  { long long val = (yyvsp[0].num)->iVal;
                                   (yyval.ptr)=terminal((yyvsp[0].num)->str);
				   char * a = constant((yyvsp[0].num)->nType);
                                   (yyval.ptr)->isInit=1;
                                   string as(a);
				   (yyval.ptr)->nodeType=as;        
                                   (yyval.ptr)->rVal = -5;
                                   (yyval.ptr)->iVal = val;
                                   (yyval.ptr)->exprType=5;
				   }
#line 2229 "build/parse.tab.c"
    break;

  case 8:
#line 119 "src/parse.y"
                                  { long long val = (int) (yyvsp[0].num)->rVal;
                                   (yyval.ptr)=terminal((yyvsp[0].num)->str);
                                   char * a = constant((yyvsp[0].num)->nType);
                                   (yyval.ptr)->isInit =1;
                                   string as(a);
                                   (yyval.ptr)->nodeType=as;
                                   (yyval.ptr)->iVal = val;
                                   (yyval.ptr)->exprType=5;
                                   }
#line 2243 "build/parse.tab.c"
    break;

  case 9:
#line 128 "src/parse.y"
                                   {(yyval.ptr)=terminal((yyvsp[0].str));
                              (yyval.ptr)->isInit=1;
                             (yyval.ptr)->nodeType=string("ENUMERATION_CONSTANT");}
#line 2251 "build/parse.tab.c"
    break;

  case 10:
#line 133 "src/parse.y"
                                  {(yyval.ptr)=terminal((yyvsp[0].str));
                                  }
#line 2258 "build/parse.tab.c"
    break;

  case 11:
#line 138 "src/parse.y"
                                  {(yyval.ptr)=terminal((yyvsp[0].str)); (yyval.ptr)->nodeType = string("char*"); (yyval.ptr)->isInit =1;}
#line 2264 "build/parse.tab.c"
    break;

  case 12:
#line 139 "src/parse.y"
                                  {(yyval.ptr)=terminal((yyvsp[0].str)); (yyval.ptr)->nodeType = string(); (yyval.ptr)->isInit=1;}
#line 2270 "build/parse.tab.c"
    break;

  case 13:
#line 143 "src/parse.y"
                                                                 {temp=terminal((yyvsp[-5].str));(yyval.ptr)=nonTerminal2("generic_selection",temp,(yyvsp[-3].ptr),(yyvsp[-1].ptr));}
#line 2276 "build/parse.tab.c"
    break;

  case 14:
#line 146 "src/parse.y"
                                               {(yyval.ptr)=(yyvsp[0].ptr);}
#line 2282 "build/parse.tab.c"
    break;

  case 15:
#line 147 "src/parse.y"
                                                {(yyval.ptr)=nonTerminal2("generic_assoc_list",NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 2288 "build/parse.tab.c"
    break;

  case 16:
#line 151 "src/parse.y"
                                             {(yyval.ptr) = nonTerminal2("generic_association", (yyvsp[-2].ptr), (yyvsp[0].ptr), NULL);}
#line 2294 "build/parse.tab.c"
    break;

  case 17:
#line 152 "src/parse.y"
                                             {   temp = terminal("DEFAULT");
                                                 (yyval.ptr) = nonTerminal2("generic_association", temp, (yyvsp[0].ptr), NULL);
                                             }
#line 2302 "build/parse.tab.c"
    break;

  case 18:
#line 157 "src/parse.y"
                                             {(yyval.ptr) = (yyvsp[0].ptr);}
#line 2308 "build/parse.tab.c"
    break;

  case 19:
#line 159 "src/parse.y"
                                             {
						(yyval.ptr) = nonTerminal("postfix_expression[experssion]", NULL, (yyvsp[-3].ptr), (yyvsp[-1].ptr));
                         if((yyvsp[-3].ptr)->isInit==1 && (yyvsp[-1].ptr)->isInit==1)(yyval.ptr)->isInit=1;
						char* s = postfixExpr((yyvsp[-3].ptr)->nodeType, 1);
						if(s){string as(s);
							(yyval.ptr)->nodeType =as;
              }
						else {
						  yyerror("Error:  array indexed with more indices than its dimension ");
						}
                                             }
#line 2324 "build/parse.tab.c"
    break;

  case 20:
#line 170 "src/parse.y"
                                             {  (yyval.ptr) = (yyvsp[-2].ptr);
              (yyval.ptr)->isInit=1;

	  char* s = postfixExpr((yyvsp[-2].ptr)->nodeType, 2);
	  if(s){
		  string as(s);
		  (yyval.ptr)->nodeType =as;
                  if((yyvsp[-2].ptr)->exprType==3){
                        string funcArgs = funcArgList((yyvsp[-2].ptr)->nodeKey);
                        if(!(funcArgs==string(""))) {
                            yyerror("Error:\'%s\' function call requires arguments to be passed \n     \'%s %s\( %s \)\'",((yyvsp[-2].ptr)->nodeKey).c_str(),((yyval.ptr)->nodeType).c_str(),((yyvsp[-2].ptr)->nodeKey).c_str(),funcArgs.c_str());
                        }
                  }
	  }
	  else {
		  yyerror("Error: Invalid Function call");
	  }
          currArguments=string("");

  }
#line 2349 "build/parse.tab.c"
    break;

  case 21:
#line 190 "src/parse.y"
                                                          {(yyval.ptr) = nonTerminal("postfix_expression", NULL, (yyvsp[-3].ptr), (yyvsp[-1].ptr));
          if((yyvsp[-1].ptr)->isInit==1) (yyval.ptr)->isInit=1;
	  char* s = postfixExpr((yyvsp[-3].ptr)->nodeType, 3);
	  if(s){
		  string as(s);
		  (yyval.ptr)->nodeType =as;
                  if((yyvsp[-3].ptr)->exprType==3){
                       string funcArgs = funcArgList((yyvsp[-3].ptr)->nodeKey);
                       char* a =new char();
                       string temp1 = currArguments;
                       string temp2 = funcArgs;
                       string typeA,typeB;
                       string delim = string(",");
                       unsigned f1=1;
                       unsigned f2=1;
                       int argNo = 0;
                       while(f1!=-1 && f2!=-1){
                          f1 = temp1.find_first_of(delim);
                          f2 = temp2.find_first_of(delim);
                            argNo++;
                            if(f1==-1) typeA = temp1; else{ typeA = temp1.substr(0,f1); temp1 = temp1.substr(f1+1);}
                            if(f2==-1) typeB = temp2 ; else{ typeB = temp2.substr(0,f2); temp2 = temp2.substr(f2+1); }
                            if(typeB==string("...")) break;
                            a = validAssign(typeA,typeB);
                            if(a){
                                   if(!strcmp(a,"warning")) { yyerror("Warning: Passing argumnet %d of \'%s\' from incompatible pointer type.\n Note : expected \'%s\' but argument is of type \'%s\'\n     \'%s %s\( %s \)\'",argNo,((yyvsp[-3].ptr)->nodeKey).c_str(),typeB.c_str(),typeA.c_str(),((yyval.ptr)->nodeType).c_str(),((yyvsp[-3].ptr)->nodeKey).c_str(),funcArgs.c_str()); }
                            }
                            else{
                                  yyerror("Error: Incompatible type for argumnet %d of \'%s\' .\n Note : expected \'%s\' but argument is of type \'%s\'\n     \'%s %s\( %s \)\'",argNo,((yyvsp[-3].ptr)->nodeKey).c_str(),typeB.c_str(),typeA.c_str(),((yyval.ptr)->nodeType).c_str(),((yyvsp[-3].ptr)->nodeKey).c_str(),funcArgs.c_str());
                            }
                            if((f1!=-1)&&(f2!=-1)){
                                 continue;
                           }else if(f2!=-1){
                                 if(!(temp2==string("..."))) yyerror("Error: Too few arguments for the function \'%s\'\n    \'%s %s\( %s \)\'",((yyvsp[-3].ptr)->nodeKey).c_str(),((yyval.ptr)->nodeType).c_str(),((yyvsp[-3].ptr)->nodeKey).c_str(),funcArgs.c_str());
                                 break;
                           }else if(f1!=-1){
                                   yyerror("Error: Too many arguments for the function \'%s\'\n    \'%s %s\( %s \)\'",((yyvsp[-3].ptr)->nodeKey).c_str(),((yyval.ptr)->nodeType).c_str(),((yyvsp[-3].ptr)->nodeKey).c_str(),funcArgs.c_str());
                                   break;
                          }else{ break; }
                  }
    }

	  }
	  else {
		  yyerror("Error: Invalid Function call");
	  }
          currArguments=string("");
}
#line 2402 "build/parse.tab.c"
    break;

  case 22:
#line 238 "src/parse.y"
                                            {
                                                temp = terminal((yyvsp[0].str));
                                                (yyval.ptr) = nonTerminal("postfix_expression.IDENTIFIER",NULL, (yyvsp[-2].ptr), temp);
                                                string as((yyvsp[0].str));
                                                int k = structLookup((yyvsp[-2].ptr)->nodeType, as);
                                                if(k==1) yyerror("Error: \'.\' is an invalid operator on \'%s\'", (yyvsp[-2].ptr)->nodeKey.c_str() );
                                                else if(k==2) yyerror("Error: \'%s\' is not a member of struct \'%s\'", (yyvsp[0].str),(yyvsp[-2].ptr)->nodeKey.c_str() );
                                                else (yyval.ptr)->nodeType = structMemberType((yyvsp[-2].ptr)->nodeType, as);
                                                (yyval.ptr)->nodeKey = (yyvsp[-2].ptr)->nodeKey+ string(".") + as;
                                            }
#line 2417 "build/parse.tab.c"
    break;

  case 23:
#line 248 "src/parse.y"
                                            {
                                                temp=terminal((yyvsp[0].str));
                                                (yyval.ptr) = nonTerminal((yyvsp[-1].str),NULL, (yyvsp[-2].ptr), temp);
                                                string as((yyvsp[0].str));
                                                string as1 = ((yyvsp[-2].ptr)->nodeType).substr(0,((yyvsp[-2].ptr)->nodeType).length()-1);
                                                int k = structLookup(as1, as);
                                                cout<<k<<endl;
                                                if(k==1){ yyerror("Error: \'%s\' is an invalid operator on \'%s\'", (yyvsp[-1].str), (yyvsp[-2].ptr)->nodeKey.c_str() );
                                                }
                                                else if(k==2){ yyerror("Error: \'%s\' is not a member of struct \'%s\'", (yyvsp[0].str),(yyvsp[-2].ptr)->nodeKey.c_str() );
                                                }
                                                else (yyval.ptr)->nodeType = structMemberType(as1, as);
                                                (yyval.ptr)->nodeKey = (yyvsp[-2].ptr)->nodeKey+ string("->") + as;
                                            }
#line 2436 "build/parse.tab.c"
    break;

  case 24:
#line 262 "src/parse.y"
                                            {

                                               (yyval.ptr)=  nonTerminal((yyvsp[0].str), NULL,(yyvsp[-1].ptr), NULL);
         if((yyvsp[-1].ptr)->isInit==1) (yyval.ptr)->isInit=1;
	  char* s = postfixExpr((yyvsp[-1].ptr)->nodeType, 6);
	  if(s){
		  string as(s);
		  (yyval.ptr)->nodeType =as;
      (yyval.ptr)->iVal = (yyvsp[-1].ptr)->iVal +1;
	  }
	  else {
		  yyerror("Error: Increment not defined for this type");
	  }

                                            }
#line 2456 "build/parse.tab.c"
    break;

  case 25:
#line 277 "src/parse.y"
                                            {
	  (yyval.ptr)=  nonTerminal((yyvsp[0].str),NULL, (yyvsp[-1].ptr),NULL);
          if((yyvsp[-1].ptr)->isInit==1) (yyval.ptr)->isInit =1;
	  char* s = postfixExpr((yyvsp[-1].ptr)->nodeType, 7);
	  if(s){
		  string as(s);
		  (yyval.ptr)->nodeType =as;
      (yyval.ptr)->iVal = (yyvsp[-1].ptr)->iVal -1;
	  }
	  else {
		  yyerror("Error: Decrement not defined for this type");
	  }

  }
#line 2475 "build/parse.tab.c"
    break;

  case 26:
#line 291 "src/parse.y"
                                               {
	  (yyval.ptr)=  nonTerminal("postfix_expression", NULL, (yyvsp[-4].ptr), (yyvsp[-1].ptr));
          if((yyvsp[-1].ptr)->isInit==1) (yyval.ptr)->isInit =1;
	  char* s = postfixExpr((yyvsp[-4].ptr)->nodeType, 8);
	  if(s){
		  string as(s);
		  (yyval.ptr)->nodeType =as;
	  }
	  else {
		  yyerror("Error: typecasting error");
	  }

  }
#line 2493 "build/parse.tab.c"
    break;

  case 27:
#line 304 "src/parse.y"
                                                   {
	  (yyval.ptr)=nonTerminalFourChild("postfix_expression",(yyvsp[-5].ptr),(yyvsp[-2].ptr),NULL,NULL,(yyvsp[-1].str));
          if((yyvsp[-2].ptr)->isInit==1) (yyval.ptr)->isInit =1;
	  char* s = postfixExpr((yyvsp[-5].ptr)->nodeType, 9);
	  if(s){
		  string as(s);
		  (yyval.ptr)->nodeType =as;
	  }
	  else {
		  yyerror("Error: typecasting error");
	  }
  }
#line 2510 "build/parse.tab.c"
    break;

  case 28:
#line 320 "src/parse.y"
          {
		(yyval.ptr) = (yyvsp[0].ptr);
		if((yyvsp[0].ptr)->isInit==1)(yyval.ptr)->isInit = 1;
                currArguments = (yyvsp[0].ptr)->nodeType;
          }
#line 2520 "build/parse.tab.c"
    break;

  case 29:
#line 326 "src/parse.y"
            {
             (yyval.ptr) = nonTerminal("argument_expression_list",NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	     char* a =  argumentExpr((yyvsp[-2].ptr)->nodeType, (yyvsp[0].ptr)->nodeType, 2);
		string as(a);
		(yyval.ptr)->nodeType = as;
		if((yyvsp[-2].ptr)->isInit == 1 && (yyvsp[0].ptr)->isInit==1) (yyval.ptr)->isInit=1;
                currArguments = currArguments +string(",")+ (yyvsp[0].ptr)->nodeType;
              }
#line 2533 "build/parse.tab.c"
    break;

  case 30:
#line 338 "src/parse.y"
                                  {(yyval.ptr) = (yyvsp[0].ptr);}
#line 2539 "build/parse.tab.c"
    break;

  case 31:
#line 339 "src/parse.y"
                                  {
	  (yyval.ptr)=  nonTerminal((yyvsp[-1].str), NULL,NULL, (yyvsp[0].ptr));
	  if((yyvsp[0].ptr)->isInit == 1 ) (yyval.ptr)->isInit=1;
	  char* s = postfixExpr((yyvsp[0].ptr)->nodeType, 6);
	  if(s){
		  string as(s);
		  (yyval.ptr)->nodeType =as;
      (yyval.ptr)->iVal = (yyvsp[0].ptr)->iVal +1;
	  }
	  else {
		  yyerror("Error: Increment not defined for this type");
	  }

  }
#line 2558 "build/parse.tab.c"
    break;

  case 32:
#line 354 "src/parse.y"
                                  {
          (yyval.ptr)->iVal =(yyvsp[0].ptr)->iVal -1;
       	  (yyval.ptr)=  nonTerminal((yyvsp[-1].str), NULL,NULL, (yyvsp[0].ptr));
	  if((yyvsp[0].ptr)->isInit == 1 ) (yyval.ptr)->isInit=1;
	  char* s = postfixExpr((yyvsp[0].ptr)->nodeType, 7);
	  if(s){
		  string as(s);
		  (yyval.ptr)->nodeType =as;
	  }
	  else {
		  yyerror("Error: Decrement not defined for this type");
	  }

  }
#line 2577 "build/parse.tab.c"
    break;

  case 33:
#line 368 "src/parse.y"
                                   {
    (yyval.ptr)->iVal = (yyvsp[0].ptr)->iVal;
		(yyval.ptr) = nonTerminal("unary_expression", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));
		if( (yyvsp[0].ptr)->isInit==1) (yyval.ptr)->isInit=1;
		char* a= unaryExpr((yyvsp[-1].ptr)->name, (yyvsp[0].ptr)->nodeType, 1);
		if(a){
		    string as(a);
		    (yyval.ptr)->nodeType= as;
    }
		else{
		    yyerror("Error: Type inconsistent with operator %s", (yyvsp[-1].ptr)->name.c_str());
		}
 	}
#line 2595 "build/parse.tab.c"
    break;

  case 34:
#line 381 "src/parse.y"
                                  {
                (yyval.ptr)=  nonTerminal((yyvsp[-1].str), NULL,NULL, (yyvsp[0].ptr));
		            (yyval.ptr)->nodeType = string("int");
		            (yyval.ptr)->isInit=1;
                }
#line 2605 "build/parse.tab.c"
    break;

  case 35:
#line 386 "src/parse.y"
                               {
                (yyval.ptr)=  nonTerminal((yyvsp[-3].str), NULL,NULL, (yyvsp[-1].ptr));
		            (yyval.ptr)->nodeType = string("int");
		            (yyval.ptr)->isInit=1;
              }
#line 2615 "build/parse.tab.c"
    break;

  case 36:
#line 391 "src/parse.y"
                                {
		(yyval.ptr)=  nonTerminal((yyvsp[-3].str), NULL,NULL, (yyvsp[-1].ptr));
		(yyval.ptr)->nodeType = string("int");
		(yyval.ptr)->isInit=1;
       }
#line 2625 "build/parse.tab.c"
    break;

  case 37:
#line 399 "src/parse.y"
             { (yyval.ptr) = terminal("&");}
#line 2631 "build/parse.tab.c"
    break;

  case 38:
#line 400 "src/parse.y"
             { (yyval.ptr) = terminal("*");}
#line 2637 "build/parse.tab.c"
    break;

  case 39:
#line 401 "src/parse.y"
             { (yyval.ptr) = terminal("+");}
#line 2643 "build/parse.tab.c"
    break;

  case 40:
#line 402 "src/parse.y"
             { (yyval.ptr) = terminal("-");}
#line 2649 "build/parse.tab.c"
    break;

  case 41:
#line 403 "src/parse.y"
             { (yyval.ptr) = terminal("~");}
#line 2655 "build/parse.tab.c"
    break;

  case 42:
#line 404 "src/parse.y"
             { (yyval.ptr) = terminal("!");}
#line 2661 "build/parse.tab.c"
    break;

  case 43:
#line 408 "src/parse.y"
                                  {(yyval.ptr) = (yyvsp[0].ptr);}
#line 2667 "build/parse.tab.c"
    break;

  case 44:
#line 410 "src/parse.y"
                {
			(yyval.ptr) = nonTerminal("cast_expression", NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
			(yyval.ptr)->nodeType = (yyvsp[-2].ptr)->nodeType;
                        if((yyvsp[0].ptr)->isInit==1) (yyval.ptr)->isInit=1;
		}
#line 2677 "build/parse.tab.c"
    break;

  case 45:
#line 418 "src/parse.y"
                                                              {(yyval.ptr)=(yyvsp[0].ptr);}
#line 2683 "build/parse.tab.c"
    break;

  case 46:
#line 419 "src/parse.y"
                                                              { 
            char* a=multilplicativeExpr((yyvsp[-2].ptr)->nodeType, (yyvsp[0].ptr)->nodeType, '*');
           if(a){
               int k;
               if(strcmp(a,"int")==0){
                 (yyval.ptr)=nonTerminal("*int",NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));
                 (yyval.ptr)->nodeType = string("long long");
	       }
               else if (strcmp(a, "float")==0){
                 (yyval.ptr)=nonTerminal("*float",NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));
                 (yyval.ptr)->nodeType = string("long double");
               }
            }
            else{
                (yyval.ptr)=nonTerminal("*",NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));
		yyerror("Error: Incompatible type for * operator");
            }
	    if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==1) (yyval.ptr)->isInit=1;
        }
#line 2707 "build/parse.tab.c"
    break;

  case 47:
#line 438 "src/parse.y"
                                                              {
            if ((yyvsp[0].ptr)->iVal != 0)
                (yyval.ptr)->iVal = (yyvsp[-2].ptr)->iVal/ (yyvsp[0].ptr)->iVal;
            char* a=multilplicativeExpr((yyvsp[-2].ptr)->nodeType, (yyvsp[0].ptr)->nodeType, '/');
           if(a){int k;
                if(!strcmp(a,"int")){
                  (yyval.ptr)=nonTerminal("/int",NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));
                  (yyval.ptr)->nodeType = string("long long");
	        }
	        else if (!strcmp(a,"float")){
                  (yyval.ptr)=nonTerminal("/float",NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));
                  (yyval.ptr)->nodeType = string("long double");
                }
            }
            else{
               (yyval.ptr)=nonTerminal("/",NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));
		yyerror("Error: Incompatible type for / operator");
            }
	    if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==1) (yyval.ptr)->isInit=1;
}
#line 2732 "build/parse.tab.c"
    break;

  case 48:
#line 458 "src/parse.y"
                                                              {
           if((yyvsp[0].ptr)->iVal != 0) (yyval.ptr)->iVal = (yyvsp[-2].ptr)->iVal % (yyvsp[0].ptr)->iVal;
            (yyval.ptr)=nonTerminal("%",NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));
            char* a=multilplicativeExpr((yyvsp[-2].ptr)->nodeType, (yyvsp[0].ptr)->nodeType, '/');
            if(!strcmp(a,"int")){
		(yyval.ptr)->nodeType= string("long long");
	    }
	    else {
		yyerror("Error: Incompatible type for % operator");
            }
	    if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==1) (yyval.ptr)->isInit=1;
           }
#line 2749 "build/parse.tab.c"
    break;

  case 49:
#line 473 "src/parse.y"
                                                              {(yyval.ptr)=(yyvsp[0].ptr);}
#line 2755 "build/parse.tab.c"
    break;

  case 50:
#line 474 "src/parse.y"
                                                              {
                (yyval.ptr)->iVal = (yyvsp[-2].ptr)->iVal + (yyvsp[0].ptr)->iVal;
                char *a = additiveExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType,'+');
                 char *q=new char();
                 string p;
                 if(a){string as(a);
                 p = string("+")+as;
                 strcpy(q,p.c_str());}
                 else q = "+";
                 (yyval.ptr)=nonTerminal(q,NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));
                 if(a){ string as(a);
                   if(!strcmp(a,"int")) (yyval.ptr)->nodeType=string("long long");
                   else if(!strcmp(a,"real")) (yyval.ptr)->nodeType=string("long double");
                   else (yyval.ptr)->nodeType=as; // for imaginary and complex returns
                 }
                 else {
                       yyerror("Error: Incompatible type for + operator");
                      }
		 if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==1) (yyval.ptr)->isInit=1;

                 }
#line 2781 "build/parse.tab.c"
    break;

  case 51:
#line 495 "src/parse.y"
                                                              {
                 (yyval.ptr)->iVal = (yyvsp[-2].ptr)->iVal - (yyvsp[0].ptr)->iVal;
                 char *a = additiveExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType,'-');
		 char *q = new char();
                 string p;
		 if(a){ string as(a);
                         p =string("-")+as;
                         strcpy(q,p.c_str());
                      }
		  (yyval.ptr)=nonTerminal(q,NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));
	          if(a){ string as(a);
                   if(!strcmp(a,"int")) (yyval.ptr)->nodeType=string("long long");
                   else if(!strcmp(a,"real")) (yyval.ptr)->nodeType=string("long double");
	           else (yyval.ptr)->nodeType=as;   // for imaginary and complex returns
                 }
		 else {
			 yyerror("Error: Incompatible type for - operator");
		 }
		 if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==1) (yyval.ptr)->isInit=1;

	}
#line 2807 "build/parse.tab.c"
    break;

  case 52:
#line 520 "src/parse.y"
                            {(yyval.ptr) = (yyvsp[0].ptr);}
#line 2813 "build/parse.tab.c"
    break;

  case 53:
#line 521 "src/parse.y"
                                                 {
                          (yyval.ptr) = nonTerminal2("<<", (yyvsp[-2].ptr),NULL, (yyvsp[0].ptr));
                          char* a = shiftExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);                        if(a){
                            (yyval.ptr)->nodeType = (yyvsp[-2].ptr)->nodeType;
                           }
                       else{
                          yyerror("Error: Invalid operands to binary <<");
                           }
		       if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==1) (yyval.ptr)->isInit=1;
                     }
#line 2828 "build/parse.tab.c"
    break;

  case 54:
#line 531 "src/parse.y"
                                                  {
                              (yyval.ptr) = nonTerminal2(">>", (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));
                       char* a = shiftExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);
                          if(a){
                                (yyval.ptr)->nodeType = (yyvsp[-2].ptr)->nodeType;
                               }
                        else{
                          yyerror("Error: Invalid operands to binary <<");
                            }

			if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==1) (yyval.ptr)->isInit=1;
                       }
#line 2845 "build/parse.tab.c"
    break;

  case 55:
#line 546 "src/parse.y"
                         {(yyval.ptr) = (yyvsp[0].ptr);}
#line 2851 "build/parse.tab.c"
    break;

  case 56:
#line 548 "src/parse.y"
      {                (yyval.ptr) = nonTerminal("<", NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                    char* a=relationalExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType,"<");
                 if(a) { 

                         if(!strcmp(a,"bool")) (yyval.ptr)->nodeType = string("bool");
                        else if(!strcmp(a,"Bool")){
                        (yyval.ptr)->nodeType = string("bool");
                       yyerror("Warning: comparison between pointer and integer");}
                    }
                  else {
                         yyerror("Error: invalid operands to binary <");
                    }
                  if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==3) (yyval.ptr)->isInit=1;

      }
#line 2871 "build/parse.tab.c"
    break;

  case 57:
#line 564 "src/parse.y"
 {                (yyval.ptr) = nonTerminal(">", NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                  char* a=relationalExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType,">");
                   if(a){ if(!strcmp(a,"bool")) (yyval.ptr)->nodeType = string("bool");
                          else if(!strcmp(a,"Bool")){
                           (yyval.ptr)->nodeType = string("bool");
                          yyerror("Warning: comparison between pointer and integer");}
                    } else {
                         yyerror("Error: invalid operands to binary >");
                    }
                  if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==3) (yyval.ptr)->isInit=1;

  }
#line 2888 "build/parse.tab.c"
    break;

  case 58:
#line 577 "src/parse.y"
   {
                                  (yyval.ptr) = nonTerminal2("<=", (yyvsp[-2].ptr),NULL, (yyvsp[0].ptr));
                    char* a=relationalExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType,"<=");
                    if(a){if(!strcmp(a,"bool")) (yyval.ptr)->nodeType = string("bool");
                       else if(!strcmp(a,"Bool")){
                        (yyval.ptr)->nodeType = string("bool");
                        yyerror("Warning: comparison between pointer and integer");}
                    }else {
                         yyerror("Error: invalid operands to binary <=");
                    }
                  if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==3) (yyval.ptr)->isInit=1;
      }
#line 2905 "build/parse.tab.c"
    break;

  case 59:
#line 590 "src/parse.y"
    {
                       (yyval.ptr) = nonTerminal2(">=", (yyvsp[-2].ptr),NULL, (yyvsp[0].ptr));
                  char* a=relationalExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType,">=");
              if(a){  if(!strcmp(a,"bool")) (yyval.ptr)->nodeType = string("bool");
                      else if(!strcmp(a,"Bool")){
                        (yyval.ptr)->nodeType = string("bool");
                         yyerror("Warning: comparison between pointer and integer");}
                    }else {
                         yyerror("Error: invalid operands to binary >=");
                    }
                  if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==3) (yyval.ptr)->isInit=1;
      }
#line 2922 "build/parse.tab.c"
    break;

  case 60:
#line 605 "src/parse.y"
                            {(yyval.ptr) = (yyvsp[0].ptr);}
#line 2928 "build/parse.tab.c"
    break;

  case 61:
#line 606 "src/parse.y"
                                                    {
                                                    (yyval.ptr) = nonTerminal2("==", (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));
                    char* a = equalityExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);
                    if(a){ if(!strcmp(a,"true")){
                            yyerror("Warning: Comparision between pointer and Integer");
                            }
                            (yyval.ptr)->nodeType = "bool";
                    }
                   else{ yyerror("Error:Invalid operands to binary =="); }
                 if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==3) (yyval.ptr)->isInit=1;
                                                  }
#line 2944 "build/parse.tab.c"
    break;

  case 62:
#line 617 "src/parse.y"
                                                    {
                      (yyval.ptr) = nonTerminal2("!=", (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));
                      char* a = equalityExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);
                    if(a){   if(!strcmp(a,"true")){
                            yyerror("Warning: Comparision between pointer and Integer");
                            }
                            (yyval.ptr)->nodeType = "bool";
                    }
                   else{ yyerror("Error:Invalid operands to binary !="); }
                 if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==3) (yyval.ptr)->isInit=1;
                                                  }
#line 2960 "build/parse.tab.c"
    break;

  case 63:
#line 631 "src/parse.y"
                         { (yyval.ptr) = (yyvsp[0].ptr);}
#line 2966 "build/parse.tab.c"
    break;

  case 64:
#line 632 "src/parse.y"
                                            {
               (yyval.ptr) = nonTerminal("&",NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
               char* a = bitwiseExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);
               if(a){
                  if(!strcmp(a,"true")) { (yyval.ptr)->nodeType = string("bool"); }
                  else{   (yyval.ptr)->nodeType = string("long long");}
               }
               else {
                 yyerror("Error:Invalid operands to the binary &");
               }
                 if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==3) (yyval.ptr)->isInit=1;
          }
#line 2983 "build/parse.tab.c"
    break;

  case 65:
#line 647 "src/parse.y"
                     { (yyval.ptr) = (yyvsp[0].ptr);}
#line 2989 "build/parse.tab.c"
    break;

  case 66:
#line 648 "src/parse.y"
                                                {
           (yyval.ptr) = nonTerminal("^", NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
               char* a = bitwiseExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);
               if(a){
                  if(!strcmp(a,"true")) { (yyval.ptr)->nodeType = string("bool"); }
                  else{   (yyval.ptr)->nodeType = string("long long");}
               }
               else {
                 yyerror("Error:Invalid operands to the binary ^");
               }
                 if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==3) (yyval.ptr)->isInit=1;

        }
#line 3007 "build/parse.tab.c"
    break;

  case 67:
#line 664 "src/parse.y"
                               { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3013 "build/parse.tab.c"
    break;

  case 68:
#line 665 "src/parse.y"
                                                         {
            (yyval.ptr) = nonTerminal("|", NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
               char* a = bitwiseExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);
               if(a){
                  if(!strcmp(a,"true")) { (yyval.ptr)->nodeType = string("bool"); }
                  else{   (yyval.ptr)->nodeType = string("long long");}
               }
               else {
                 yyerror("Error:Invalid operands to the binary |");
               }
                 if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==3) (yyval.ptr)->isInit=1;

      }
#line 3031 "build/parse.tab.c"
    break;

  case 69:
#line 681 "src/parse.y"
                            { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3037 "build/parse.tab.c"
    break;

  case 70:
#line 682 "src/parse.y"
                                                            {
                          (yyval.ptr) = nonTerminal2("&&", (yyvsp[-2].ptr),NULL, (yyvsp[0].ptr));
                        (yyval.ptr)->nodeType == string("bool");
                 if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==3) (yyval.ptr)->isInit=1;
                  }
#line 3047 "build/parse.tab.c"
    break;

  case 71:
#line 690 "src/parse.y"
                            { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3053 "build/parse.tab.c"
    break;

  case 72:
#line 691 "src/parse.y"
                                                        {
                                (yyval.ptr) = nonTerminal2("||", (yyvsp[-2].ptr),NULL, (yyvsp[0].ptr));
                                if((yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==3) (yyval.ptr)->isInit=1;
                                (yyval.ptr)->nodeType == string("bool");
                     }
#line 3063 "build/parse.tab.c"
    break;

  case 73:
#line 699 "src/parse.y"
                           { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3069 "build/parse.tab.c"
    break;

  case 74:
#line 700 "src/parse.y"
                                                                      {

            (yyval.ptr) = nonTerminal2("conditional_expression", (yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr));
            (yyval.ptr)->rVal = -11;
            char* a = conditionalExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);
            if(a){
                 string as(a);
                 (yyval.ptr)->nodeType = string("int");
                 }
            else
                {
                 yyerror("Error:Type mismatch in conditional expression");
                }
           if((yyvsp[-4].ptr)->isInit==1 && (yyvsp[-2].ptr)->isInit==1 && (yyvsp[0].ptr)->isInit==1) (yyval.ptr)->isInit=1;

          }
#line 3090 "build/parse.tab.c"
    break;

  case 75:
#line 720 "src/parse.y"
                            { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3096 "build/parse.tab.c"
    break;

  case 76:
#line 722 "src/parse.y"
             { (yyval.ptr) = nonTerminal2((yyvsp[-1].str), (yyvsp[-2].ptr),NULL, (yyvsp[0].ptr));
               
               char* a = assignmentExpr((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType,(yyvsp[-1].str));
               if(a){
                    if(!strcmp(a,"true")){ (yyval.ptr)->nodeType = (yyvsp[-2].ptr)->nodeType;
                      }
                    if(!strcmp(a,"warning")){ (yyval.ptr)->nodeType = (yyvsp[-2].ptr)->nodeType;
                         yyerror("Warning: Assignment with incompatible pointer type");
                         }
                    }
                else{ yyerror("Error: Incompatible types when assigning type \'%s\' to \'%s\' ",((yyvsp[-2].ptr)->nodeType).c_str(),((yyvsp[0].ptr)->nodeType).c_str()); }
     if((yyvsp[-2].ptr)->exprType==3){ if((yyvsp[0].ptr)->isInit==1) update_isInit((yyvsp[-2].ptr)->nodeKey); }
             }
#line 3114 "build/parse.tab.c"
    break;

  case 77:
#line 738 "src/parse.y"
           { (yyval.str) = "=";}
#line 3120 "build/parse.tab.c"
    break;

  case 78:
#line 739 "src/parse.y"
                {
                  (yyval.str) = "*=";
                }
#line 3128 "build/parse.tab.c"
    break;

  case 79:
#line 742 "src/parse.y"
                {
                  (yyval.str) = "/=";
                }
#line 3136 "build/parse.tab.c"
    break;

  case 80:
#line 745 "src/parse.y"
                {
                  (yyval.str) = "%=";
                }
#line 3144 "build/parse.tab.c"
    break;

  case 81:
#line 748 "src/parse.y"
                {
                  (yyval.str) = "+=";
                }
#line 3152 "build/parse.tab.c"
    break;

  case 82:
#line 751 "src/parse.y"
                {
                  (yyval.str) = "-=";
                }
#line 3160 "build/parse.tab.c"
    break;

  case 83:
#line 754 "src/parse.y"
                {
                  (yyval.str) = "<<=";
                }
#line 3168 "build/parse.tab.c"
    break;

  case 84:
#line 757 "src/parse.y"
                  {
                  (yyval.str) = ">>=";
                }
#line 3176 "build/parse.tab.c"
    break;

  case 85:
#line 760 "src/parse.y"
                {
                  (yyval.str) = "&=";
                }
#line 3184 "build/parse.tab.c"
    break;

  case 86:
#line 763 "src/parse.y"
                {
                  (yyval.str) = "^=";
                }
#line 3192 "build/parse.tab.c"
    break;

  case 87:
#line 766 "src/parse.y"
                 {
                  (yyval.str) = "|=";
                }
#line 3200 "build/parse.tab.c"
    break;

  case 88:
#line 772 "src/parse.y"
                             { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3206 "build/parse.tab.c"
    break;

  case 89:
#line 773 "src/parse.y"
                                           {
                 (yyval.ptr) = nonTerminal("expression",NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr)); (yyval.ptr)->nodeType = string("void");
                 }
#line 3214 "build/parse.tab.c"
    break;

  case 90:
#line 779 "src/parse.y"
                            { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3220 "build/parse.tab.c"
    break;

  case 91:
#line 783 "src/parse.y"
                                { typeName=string("");}
#line 3226 "build/parse.tab.c"
    break;

  case 92:
#line 784 "src/parse.y"
                                                     { typeName=string(""); (yyval.ptr) = nonTerminal("declaration", NULL, (yyvsp[-2].ptr), (yyvsp[-1].ptr));}
#line 3232 "build/parse.tab.c"
    break;

  case 93:
#line 785 "src/parse.y"
                                { typeName=string("");(yyval.ptr) = (yyvsp[0].ptr);}
#line 3238 "build/parse.tab.c"
    break;

  case 94:
#line 789 "src/parse.y"
                                                   { (yyval.ptr) = nonTerminal("declaration_specifiers", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));}
#line 3244 "build/parse.tab.c"
    break;

  case 95:
#line 790 "src/parse.y"
                                 { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3250 "build/parse.tab.c"
    break;

  case 96:
#line 791 "src/parse.y"
                                            { (yyval.ptr) = nonTerminal("declaration_specifiers", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));}
#line 3256 "build/parse.tab.c"
    break;

  case 97:
#line 792 "src/parse.y"
                                { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3262 "build/parse.tab.c"
    break;

  case 98:
#line 793 "src/parse.y"
                                           { (yyval.ptr) = nonTerminal("declaration_specifiers", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));}
#line 3268 "build/parse.tab.c"
    break;

  case 99:
#line 794 "src/parse.y"
                           { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3274 "build/parse.tab.c"
    break;

  case 100:
#line 795 "src/parse.y"
                                                { (yyval.ptr) = nonTerminal("declaration_specifiers", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));}
#line 3280 "build/parse.tab.c"
    break;

  case 101:
#line 796 "src/parse.y"
                        { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3286 "build/parse.tab.c"
    break;

  case 102:
#line 797 "src/parse.y"
                                               { (yyval.ptr) = nonTerminal("declaration_specifiers", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));}
#line 3292 "build/parse.tab.c"
    break;

  case 103:
#line 798 "src/parse.y"
                         { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3298 "build/parse.tab.c"
    break;

  case 104:
#line 802 "src/parse.y"
                       { (yyval.ptr) = (yyvsp[0].ptr);}
#line 3304 "build/parse.tab.c"
    break;

  case 105:
#line 803 "src/parse.y"
                                              { (yyval.ptr) = nonTerminal("init_declaration_list",NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));}
#line 3310 "build/parse.tab.c"
    break;

  case 106:
#line 807 "src/parse.y"
                                {
                (yyval.ptr) = nonTerminal("=", NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                    if((yyvsp[-2].ptr)->exprType==1||(yyvsp[-2].ptr)->exprType==15){ char *t=new char();
                      strcpy(t,((yyvsp[-2].ptr)->nodeType).c_str());
                      char *key =new char();
                      strcpy(key,((yyvsp[-2].ptr)->nodeKey).c_str());
                if(scopeLookup((yyvsp[-2].ptr)->nodeKey)){
                     yyerror("Error: Redeclaration of \'%s\'",key);
                }else if((yyvsp[-2].ptr)->nodeType==string("void")){
                     yyerror("Error: Variable or field \'%s\' declared void",key);
                }
                else { if((yyval.ptr)->exprType==15) { insertSymbol(*curr,key,t,((yyvsp[0].ptr)->exprType*(yyvsp[-2].ptr)->iVal),0,1); }
                        insertSymbol(*curr,key,t,(yyvsp[-2].ptr)->size,0,1);
                     }
                }
               }
#line 3331 "build/parse.tab.c"
    break;

  case 107:
#line 823 "src/parse.y"
                   {
                     (yyval.ptr)= (yyvsp[0].ptr);
                     if((yyvsp[0].ptr)->exprType==1){ char *t=new char();
                     strcpy(t,((yyvsp[0].ptr)->nodeType).c_str());
                     char *key =new char();
                     strcpy(key,((yyvsp[0].ptr)->nodeKey).c_str());
                  if(scopeLookup((yyvsp[0].ptr)->nodeKey)){
                        yyerror("Error: redeclaration of \'%s\'",key);
                  }else if((yyvsp[0].ptr)->nodeType==string("void")){
                     yyerror("Error: Variable or field \'%s\' declared void",key);
                  }else {  insertSymbol(*curr,key,t,(yyvsp[0].ptr)->size,0,0);}
                     }
               }
#line 3349 "build/parse.tab.c"
    break;

  case 108:
#line 839 "src/parse.y"
              {   
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3357 "build/parse.tab.c"
    break;

  case 109:
#line 842 "src/parse.y"
              {   
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3365 "build/parse.tab.c"
    break;

  case 110:
#line 845 "src/parse.y"
              {    
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3373 "build/parse.tab.c"
    break;

  case 111:
#line 848 "src/parse.y"
                 { 
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3381 "build/parse.tab.c"
    break;

  case 112:
#line 851 "src/parse.y"
              {    
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3389 "build/parse.tab.c"
    break;

  case 113:
#line 854 "src/parse.y"
              {   
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3397 "build/parse.tab.c"
    break;

  case 114:
#line 860 "src/parse.y"
             {     if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3406 "build/parse.tab.c"
    break;

  case 115:
#line 864 "src/parse.y"
             {     if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3415 "build/parse.tab.c"
    break;

  case 116:
#line 868 "src/parse.y"
              {   if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3424 "build/parse.tab.c"
    break;

  case 117:
#line 872 "src/parse.y"
              {   if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3433 "build/parse.tab.c"
    break;

  case 118:
#line 876 "src/parse.y"
              {    if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3442 "build/parse.tab.c"
    break;

  case 119:
#line 880 "src/parse.y"
              {   if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3451 "build/parse.tab.c"
    break;

  case 120:
#line 884 "src/parse.y"
              {    if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3460 "build/parse.tab.c"
    break;

  case 121:
#line 888 "src/parse.y"
              {    if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3469 "build/parse.tab.c"
    break;

  case 122:
#line 892 "src/parse.y"
              {   if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3478 "build/parse.tab.c"
    break;

  case 123:
#line 896 "src/parse.y"
              {   if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3487 "build/parse.tab.c"
    break;

  case 124:
#line 900 "src/parse.y"
              {   if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3496 "build/parse.tab.c"
    break;

  case 125:
#line 904 "src/parse.y"
              {   if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3505 "build/parse.tab.c"
    break;

  case 126:
#line 910 "src/parse.y"
                           {(yyval.ptr) = (yyvsp[0].ptr);yyerror("Error : Not implemented atomic_type_specifier");}
#line 3511 "build/parse.tab.c"
    break;

  case 127:
#line 911 "src/parse.y"
                               {(yyval.ptr) = (yyvsp[0].ptr); if(typeName==string(""))typeName =  (yyval.ptr)->nodeType;
                                         else typeName = typeName +string("")+ (yyval.ptr)->nodeType;
                                    }
#line 3519 "build/parse.tab.c"
    break;

  case 128:
#line 914 "src/parse.y"
                    {(yyval.ptr) =(yyvsp[0].ptr);yyerror("Error : not implemented Enum specifier");}
#line 3525 "build/parse.tab.c"
    break;

  case 129:
#line 915 "src/parse.y"
                    {  if(typeName==string(""))typeName = string((yyvsp[0].str));
                   else typeName = typeName+string(" ")+string((yyvsp[0].str));
                  (yyval.ptr) = terminal((yyvsp[0].str));
              }
#line 3534 "build/parse.tab.c"
    break;

  case 130:
#line 922 "src/parse.y"
                                                       {(yyval.ptr) = nonTerminal("struct_or_union_specifier", NULL, (yyvsp[-4].ptr), (yyvsp[-1].ptr));
                                                                  structCounter++;
                                                                  string as = to_string(structCounter);
                                                                  if(endStructTable(as)){
                                                                  (yyval.ptr)->nodeType = string("STRUCT_")+as; }
                                                                  else yyerror("Error: struct \'%s\' is already defined\n", (yyvsp[-3].str));
                                                    }
#line 3546 "build/parse.tab.c"
    break;

  case 131:
#line 929 "src/parse.y"
                                                                    {
                                                                  string as((yyvsp[-4].str));
                                                                  (yyval.ptr) = nonTerminal("struct_or_union_specifier", (yyvsp[-4].str), (yyvsp[-5].ptr), (yyvsp[-1].ptr));
                                                                  if(endStructTable(as)){
                                                                  (yyval.ptr)->nodeType = string("STRUCT_")+as; }
                                                                  else yyerror("Error: struct \'%s\' is already defined\n", (yyvsp[-4].str));
                                                                }
#line 3558 "build/parse.tab.c"
    break;

  case 132:
#line 936 "src/parse.y"
                                 {
                                    (yyval.ptr) = nonTerminal("struct_or_union_specifier", (yyvsp[0].str),(yyvsp[-1].ptr), NULL);
                                    string as((yyvsp[0].str));
                                    as = "STRUCT_" + as;
                                    if(isStruct(as)) (yyval.ptr)->nodeType = as;
                                    else yyerror("Error: No struct \'%s\' is defined",(yyvsp[0].str));
                                  }
#line 3570 "build/parse.tab.c"
    break;

  case 133:
#line 946 "src/parse.y"
          {
           makeStructTable();
  }
#line 3578 "build/parse.tab.c"
    break;

  case 134:
#line 952 "src/parse.y"
             {
              (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3586 "build/parse.tab.c"
    break;

  case 135:
#line 955 "src/parse.y"
              {
                (yyval.ptr)=terminal((yyvsp[0].str));
              }
#line 3594 "build/parse.tab.c"
    break;

  case 136:
#line 961 "src/parse.y"
                         {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3600 "build/parse.tab.c"
    break;

  case 137:
#line 962 "src/parse.y"
                                                {(yyval.ptr) = nonTerminal("struct_declaration_list", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));}
#line 3606 "build/parse.tab.c"
    break;

  case 138:
#line 966 "src/parse.y"
                                  {(yyval.ptr) = (yyvsp[-1].ptr); typeName = string(""); }
#line 3612 "build/parse.tab.c"
    break;

  case 139:
#line 967 "src/parse.y"
                                                        {(yyval.ptr) = nonTerminal("struct_declaration", NULL, (yyvsp[-2].ptr), (yyvsp[-1].ptr));
                                                          typeName = string("");
                                                        }
#line 3620 "build/parse.tab.c"
    break;

  case 140:
#line 970 "src/parse.y"
                               {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3626 "build/parse.tab.c"
    break;

  case 141:
#line 974 "src/parse.y"
                                                  {(yyval.ptr) = nonTerminal("specifier_qualifier_list", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));}
#line 3632 "build/parse.tab.c"
    break;

  case 142:
#line 975 "src/parse.y"
                          {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3638 "build/parse.tab.c"
    break;

  case 143:
#line 976 "src/parse.y"
                                                   {(yyval.ptr) = nonTerminal("specifier_qualifier_list", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));}
#line 3644 "build/parse.tab.c"
    break;

  case 144:
#line 977 "src/parse.y"
                          {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3650 "build/parse.tab.c"
    break;

  case 145:
#line 981 "src/parse.y"
                             {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3656 "build/parse.tab.c"
    break;

  case 146:
#line 982 "src/parse.y"
                                                        {(yyval.ptr) = nonTerminal("struct_declarator_list",NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));}
#line 3662 "build/parse.tab.c"
    break;

  case 147:
#line 986 "src/parse.y"
                                  {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3668 "build/parse.tab.c"
    break;

  case 148:
#line 987 "src/parse.y"
                                              {(yyval.ptr) = nonTerminal("struct_declarator", NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                                               if(!insertStructSymbol((yyvsp[-2].ptr)->nodeKey, (yyvsp[-2].ptr)->nodeType, (yyvsp[-2].ptr)->size, 0, 1)) yyerror("Error: \'%s\' is already declared in the same struct", (yyvsp[-2].ptr)->nodeKey.c_str());
                                              }
#line 3676 "build/parse.tab.c"
    break;

  case 149:
#line 990 "src/parse.y"
                     {(yyval.ptr) = (yyvsp[0].ptr);
                                               if(!insertStructSymbol((yyvsp[0].ptr)->nodeKey, (yyvsp[0].ptr)->nodeType, (yyvsp[0].ptr)->size, 0, 0)) yyerror("Error: \'%s\' is already declared in the same struct", (yyvsp[0].ptr)->nodeKey.c_str());
                     }
#line 3684 "build/parse.tab.c"
    break;

  case 150:
#line 996 "src/parse.y"
                                       {
                                       	  (yyval.ptr) = nonTerminal("enum_specifier", (yyvsp[-3].str), NULL, (yyvsp[-1].ptr));
                                       }
#line 3692 "build/parse.tab.c"
    break;

  case 151:
#line 999 "src/parse.y"
                                           {
						(yyval.ptr) = nonTerminal1("enum_specifier", (yyvsp[-4].str), (yyvsp[-2].ptr),(yyvsp[-1].str));
					   }
#line 3700 "build/parse.tab.c"
    break;

  case 152:
#line 1002 "src/parse.y"
                                                   {
						    (yyval.ptr) = nonTerminal3("enum_specifier", (yyvsp[-4].str),(yyvsp[-3].str), (yyvsp[-1].ptr),NULL);
                                                   }
#line 3708 "build/parse.tab.c"
    break;

  case 153:
#line 1005 "src/parse.y"
                                                      {
							(yyval.ptr) = nonTerminal3("enum_specifier",(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-2].ptr),(yyvsp[-1].str));
                                                   }
#line 3716 "build/parse.tab.c"
    break;

  case 154:
#line 1009 "src/parse.y"
                                                   {
							(yyval.ptr) = nonTerminal3("enum_specifier",(yyvsp[-1].str), (yyvsp[0].str),NULL, NULL);
                                                   }
#line 3724 "build/parse.tab.c"
    break;

  case 155:
#line 1016 "src/parse.y"
                      {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3730 "build/parse.tab.c"
    break;

  case 156:
#line 1017 "src/parse.y"
                                         {(yyval.ptr) = nonTerminal("enumerator_list", NULL, (yyvsp[-2].ptr),  (yyvsp[0].ptr));}
#line 3736 "build/parse.tab.c"
    break;

  case 157:
#line 1021 "src/parse.y"
                                                       {(yyval.ptr) = nonTerminal("=",NULL, (yyvsp[-2].ptr),  (yyvsp[0].ptr));}
#line 3742 "build/parse.tab.c"
    break;

  case 158:
#line 1022 "src/parse.y"
                               {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3748 "build/parse.tab.c"
    break;

  case 159:
#line 1026 "src/parse.y"
                                   {
					(yyval.ptr) = nonTerminal("atomic_type_specifier", (yyvsp[-3].str), NULL, (yyvsp[-1].ptr));
				   }
#line 3756 "build/parse.tab.c"
    break;

  case 160:
#line 1032 "src/parse.y"
                {    // typeName = typeName+string(" ")+string($1);
                     (yyval.ptr) = terminal((yyvsp[0].str));
                }
#line 3764 "build/parse.tab.c"
    break;

  case 161:
#line 1035 "src/parse.y"
                   {   //typeName = typeName+string(" ")+string($1);
                     (yyval.ptr) = terminal((yyvsp[0].str));
                   }
#line 3772 "build/parse.tab.c"
    break;

  case 162:
#line 1038 "src/parse.y"
                   {  //typeName = typeName+string(" ")+string($1);
                     (yyval.ptr) = terminal((yyvsp[0].str));
                   }
#line 3780 "build/parse.tab.c"
    break;

  case 163:
#line 1041 "src/parse.y"
                 {   // typeName = typeName+string(" ")+string($1);
                     (yyval.ptr) = terminal((yyvsp[0].str));
                 }
#line 3788 "build/parse.tab.c"
    break;

  case 164:
#line 1047 "src/parse.y"
                {    //typeName = typeName+string(" ")+string($1);
                     (yyval.ptr) = terminal((yyvsp[0].str));
                }
#line 3796 "build/parse.tab.c"
    break;

  case 165:
#line 1050 "src/parse.y"
                  {    //typeName = typeName+string(" ")+string($1);
                     (yyval.ptr) = terminal((yyvsp[0].str));
                }
#line 3804 "build/parse.tab.c"
    break;

  case 166:
#line 1058 "src/parse.y"
                                   {yyerror("Error : alignment specifier not implemented");
				     (yyval.ptr) = nonTerminal("alignment_specifier", (yyvsp[-3].str),NULL, (yyvsp[-1].ptr));
				   }
#line 3812 "build/parse.tab.c"
    break;

  case 167:
#line 1061 "src/parse.y"
                                             { yyerror("Error : alignment specifier not implemented");

					     (yyval.ptr) = nonTerminal("alignment_specifier",(yyvsp[-3].str), NULL, (yyvsp[-1].ptr));
					   }
#line 3821 "build/parse.tab.c"
    break;

  case 168:
#line 1068 "src/parse.y"
                                    {(yyval.ptr) = nonTerminal("declarator", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));
               if((yyvsp[0].ptr)->exprType==1){(yyval.ptr)->nodeType=(yyvsp[0].ptr)->nodeType+(yyvsp[-1].ptr)->nodeType;
               (yyval.ptr)->nodeKey = (yyvsp[0].ptr)->nodeKey;
               (yyval.ptr)->exprType=1;}
               if((yyvsp[0].ptr)->exprType==2){ funcName = (yyvsp[0].ptr)->nodeKey; funcType = (yyvsp[0].ptr)->nodeType; }
                char* a = new char();
                strcpy(a,((yyval.ptr)->nodeType).c_str());(yyval.ptr)->size = getSize(a);
         }
#line 3834 "build/parse.tab.c"
    break;

  case 169:
#line 1076 "src/parse.y"
                            {(yyval.ptr) = (yyvsp[0].ptr);if((yyvsp[0].ptr)->exprType==2){ funcName=(yyvsp[0].ptr)->nodeKey; funcType = (yyvsp[0].ptr)->nodeType;}}
#line 3840 "build/parse.tab.c"
    break;

  case 170:
#line 1080 "src/parse.y"
                    {
                    (yyval.ptr)=terminal((yyvsp[0].str));(yyval.ptr)->exprType=1;(yyval.ptr)->nodeKey=string((yyvsp[0].str));(yyval.ptr)->nodeType=typeName; char* a =new char();
                strcpy(a,typeName.c_str()); (yyval.ptr)->size = getSize(a);
			   }
#line 3849 "build/parse.tab.c"
    break;

  case 171:
#line 1084 "src/parse.y"
                             {(yyval.ptr) = (yyvsp[-1].ptr);
                           if((yyvsp[-1].ptr)->exprType==1){ (yyval.ptr)->exprType=1;
                                          (yyval.ptr)->nodeKey=(yyvsp[-1].ptr)->nodeKey;
                                          (yyval.ptr)->nodeType=(yyvsp[-1].ptr)->nodeType;}
                           }
#line 3859 "build/parse.tab.c"
    break;

  case 172:
#line 1089 "src/parse.y"
                                    {(yyval.ptr) = nonTerminalSquareB("direct_declarator", (yyvsp[-2].ptr));
                      if((yyvsp[-2].ptr)->exprType==1){ (yyval.ptr)->exprType=1;
                                          (yyval.ptr)->nodeKey=(yyvsp[-2].ptr)->nodeKey;
                                          (yyval.ptr)->nodeType=(yyvsp[-2].ptr)->nodeType+string("*");}
                          char* a = new char();
                          strcpy(a,((yyval.ptr)->nodeType).c_str());
                          (yyval.ptr)->size = getSize(a);
                          strcpy(a,((yyvsp[-2].ptr)->nodeType).c_str());
                          (yyval.ptr)->exprType=15;
                          (yyval.ptr)->iVal=getSize(a);
                               }
#line 3875 "build/parse.tab.c"
    break;

  case 173:
#line 1100 "src/parse.y"
                                        {(yyval.ptr) = nonTerminalFourChild("direct_declarator", (yyvsp[-3].ptr), NULL, NULL, NULL, (yyvsp[-1].str));
          if((yyvsp[-3].ptr)->exprType==1){ (yyval.ptr)->exprType=1;
                                          (yyval.ptr)->nodeKey=(yyvsp[-3].ptr)->nodeKey;
                                          (yyval.ptr)->nodeType=(yyvsp[-3].ptr)->nodeType+string("*");}

                          char* a = new char();
                          strcpy(a,((yyval.ptr)->nodeType).c_str());
                          (yyval.ptr)->size = getSize(a);
                            }
#line 3889 "build/parse.tab.c"
    break;

  case 174:
#line 1109 "src/parse.y"
                                                                                    {
				temp = terminal((yyvsp[-3].str));
				(yyval.ptr) = nonTerminalFourChild("direct_declarator", (yyvsp[-5].ptr), temp, (yyvsp[-2].ptr), (yyvsp[-1].ptr), NULL);
           if((yyvsp[-5].ptr)->exprType==1){ (yyval.ptr)->exprType=1;
                                          (yyval.ptr)->nodeKey=(yyvsp[-5].ptr)->nodeKey;
                                          (yyval.ptr)->nodeType=(yyvsp[-5].ptr)->nodeType+string("*");}

                 if((yyvsp[-1].ptr)->iVal){ (yyval.ptr)->size =  (yyvsp[-5].ptr)->size*(yyvsp[-1].ptr)->iVal; }
                 else { char* a = new char();
                        strcpy(a,((yyval.ptr)->nodeType).c_str());
                        (yyval.ptr)->size = getSize(a); }
                          }
#line 3906 "build/parse.tab.c"
    break;

  case 175:
#line 1121 "src/parse.y"
                                                                 {
				temp = terminal((yyvsp[-2].str));
				(yyval.ptr) = nonTerminalFourChild("direct_declarator", (yyvsp[-4].ptr), temp, (yyvsp[-1].ptr), NULL, NULL);
        if((yyvsp[-4].ptr)->exprType==1){ (yyval.ptr)->exprType=1;
                                          (yyval.ptr)->nodeKey=(yyvsp[-4].ptr)->nodeKey;
                                          (yyval.ptr)->nodeType=(yyvsp[-4].ptr)->nodeType+string("*");}
                 if((yyvsp[-1].ptr)->iVal){ (yyval.ptr)->size = (yyvsp[-4].ptr)->size *(yyvsp[-1].ptr)->iVal; }
                 else { char* a = new char();
                        strcpy(a,((yyval.ptr)->nodeType).c_str());
                        (yyval.ptr)->size = getSize(a); }
                          }
#line 3922 "build/parse.tab.c"
    break;

  case 176:
#line 1132 "src/parse.y"
                                                            {(yyval.ptr) = nonTerminalFourChild("direct_declarator", (yyvsp[-4].ptr), (yyvsp[-2].ptr), NULL, NULL, (yyvsp[-1].str));
          if((yyvsp[-4].ptr)->exprType==1){ (yyval.ptr)->exprType=1;
                                          (yyval.ptr)->nodeKey=(yyvsp[-4].ptr)->nodeKey;
                                          (yyval.ptr)->nodeType=(yyvsp[-4].ptr)->nodeType+string("*");}
                          char* a = new char();
                          strcpy(a,((yyval.ptr)->nodeType).c_str());
                          (yyval.ptr)->size = getSize(a);
         }
#line 3935 "build/parse.tab.c"
    break;

  case 177:
#line 1140 "src/parse.y"
                                                                                     {

                          temp = terminal((yyvsp[-2].str));
				(yyval.ptr) = nonTerminalFourChild("direct_declarator", (yyvsp[-5].ptr), (yyvsp[-3].ptr), temp, (yyvsp[-1].ptr), NULL);
          if((yyvsp[-5].ptr)->exprType==1){ (yyval.ptr)->exprType=1;
                                          (yyval.ptr)->nodeKey=(yyvsp[-5].ptr)->nodeKey;
                                          (yyval.ptr)->nodeType=(yyvsp[-5].ptr)->nodeType+string("*");}
                 if((yyvsp[-1].ptr)->iVal){ (yyval.ptr)->size = (yyvsp[-5].ptr)->size * (yyvsp[-1].ptr)->iVal; }
                 else { char* a = new char();
                        strcpy(a,((yyval.ptr)->nodeType).c_str());
                        (yyval.ptr)->size = getSize(a); }
}
#line 3952 "build/parse.tab.c"
    break;

  case 178:
#line 1152 "src/parse.y"
                                                                             {(yyval.ptr) = nonTerminalFourChild("direct_declarator", (yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[-1].ptr), NULL, NULL);
          if((yyvsp[-4].ptr)->exprType==1){ (yyval.ptr)->exprType=1;
                                          (yyval.ptr)->nodeKey=(yyvsp[-4].ptr)->nodeKey;
                                          (yyval.ptr)->nodeType=(yyvsp[-4].ptr)->nodeType+string("*");}
                 if((yyvsp[-1].ptr)->iVal){ (yyval.ptr)->size = (yyvsp[-4].ptr)->size *(yyvsp[-1].ptr)->iVal; }
                 else { char* a = new char();
                        strcpy(a,((yyval.ptr)->nodeType).c_str());
                        (yyval.ptr)->size = getSize(a); }
}
#line 3966 "build/parse.tab.c"
    break;

  case 179:
#line 1161 "src/parse.y"
                                                        {(yyval.ptr) = nonTerminal("direct_declarator", NULL, (yyvsp[-3].ptr), (yyvsp[-1].ptr));
          if((yyvsp[-3].ptr)->exprType==1){ (yyval.ptr)->exprType=1;
                               (yyval.ptr)->nodeKey=(yyvsp[-3].ptr)->nodeKey;
                                (yyval.ptr)->nodeType=(yyvsp[-3].ptr)->nodeType+string("*");
                         char* a = new char();
                        strcpy(a,((yyval.ptr)->nodeType).c_str());
                        (yyval.ptr)->size = getSize(a);
           }
         }
#line 3980 "build/parse.tab.c"
    break;

  case 180:
#line 1170 "src/parse.y"
                                                          {(yyval.ptr) = nonTerminal("direct_declarator", NULL, (yyvsp[-3].ptr), (yyvsp[-1].ptr));
         if((yyvsp[-3].ptr)->exprType==1){ (yyval.ptr)->exprType=1;
                            (yyval.ptr)->nodeKey=(yyvsp[-3].ptr)->nodeKey;
                            (yyval.ptr)->nodeType=(yyvsp[-3].ptr)->nodeType+string("*");}
                 if((yyvsp[-1].ptr)->iVal){ (yyval.ptr)->size = (yyvsp[-3].ptr)->size * (yyvsp[-1].ptr)->iVal; }
                 else { char* a = new char();
                        strcpy(a,((yyval.ptr)->nodeType).c_str());
                        (yyval.ptr)->size = getSize(a); }
        }
#line 3994 "build/parse.tab.c"
    break;

  case 181:
#line 1180 "src/parse.y"
         {
         (yyval.ptr) = nonTerminal("direct_declarator", NULL, (yyvsp[-4].ptr), (yyvsp[-1].ptr));
          if((yyvsp[-4].ptr)->exprType==1){ (yyval.ptr)->nodeKey=(yyvsp[-4].ptr)->nodeKey;
                           (yyval.ptr)->exprType=2;
                           (yyval.ptr)->nodeType=(yyvsp[-4].ptr)->nodeType;
                           insertFuncArguments((yyvsp[-4].ptr)->nodeKey,funcArguments);
                           funcArguments=string("");
                         char* a = new char();
                        strcpy(a,((yyval.ptr)->nodeType).c_str());
                        (yyval.ptr)->size = getSize(a);
                           }
               }
#line 4011 "build/parse.tab.c"
    break;

  case 182:
#line 1193 "src/parse.y"
         {
          (yyval.ptr) = nonTerminalRoundB("direct_declarator", (yyvsp[-3].ptr));
          if((yyvsp[-3].ptr)->exprType==1){
                          (yyval.ptr)->nodeKey=(yyvsp[-3].ptr)->nodeKey;
                          insertFuncArguments((yyvsp[-3].ptr)->nodeKey,string(""));
                          (yyval.ptr)->exprType=2;
                          funcArguments = string("");
                          }
                       (yyval.ptr)->nodeType=(yyvsp[-3].ptr)->nodeType;
                         char* a = new char();
                        strcpy(a,((yyval.ptr)->nodeType).c_str());
                        (yyval.ptr)->size = getSize(a);
                     }
#line 4029 "build/parse.tab.c"
    break;

  case 183:
#line 1206 "src/parse.y"
                                                       {(yyval.ptr) = nonTerminal("direct_declarator", NULL, (yyvsp[-4].ptr), (yyvsp[-1].ptr));
                         char* a = new char();
                        strcpy(a,((yyval.ptr)->nodeType).c_str());
                        (yyval.ptr)->size = getSize(a);
          }
#line 4039 "build/parse.tab.c"
    break;

  case 184:
#line 1214 "src/parse.y"
                            {   typeName =string("");
                          funcArguments = string("");
                           paramTable();  }
#line 4047 "build/parse.tab.c"
    break;

  case 185:
#line 1220 "src/parse.y"
                                          {(yyval.ptr)=nonTerminal("*",NULL,(yyvsp[-1].ptr),(yyvsp[0].ptr));(yyval.ptr)->nodeType=string("*")+(yyvsp[0].ptr)->nodeType;}
#line 4053 "build/parse.tab.c"
    break;

  case 186:
#line 1221 "src/parse.y"
                                   {(yyval.ptr)=nonTerminal("*",NULL,(yyvsp[0].ptr),NULL);(yyval.ptr)->nodeType=string("*");}
#line 4059 "build/parse.tab.c"
    break;

  case 187:
#line 1222 "src/parse.y"
                        {(yyval.ptr)=nonTerminal("*",NULL,(yyvsp[0].ptr),NULL);(yyval.ptr)->nodeType=string("*")+(yyvsp[0].ptr)->nodeType;}
#line 4065 "build/parse.tab.c"
    break;

  case 188:
#line 1223 "src/parse.y"
                       {(yyval.ptr)=terminal("*");(yyval.ptr)->nodeType=string("*");}
#line 4071 "build/parse.tab.c"
    break;

  case 189:
#line 1228 "src/parse.y"
                         {(yyval.ptr)=(yyvsp[0].ptr);}
#line 4077 "build/parse.tab.c"
    break;

  case 190:
#line 1229 "src/parse.y"
                                             {(yyval.ptr)=nonTerminal("type_qualifier_list",NULL,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 4083 "build/parse.tab.c"
    break;

  case 191:
#line 1234 "src/parse.y"
                                      {
                                        funcArguments = funcArguments+string(",...");
					temp = terminal((yyvsp[0].str));
					(yyval.ptr)=nonTerminal("parameter_type_list",NULL,(yyvsp[-2].ptr),temp);
				      }
#line 4093 "build/parse.tab.c"
    break;

  case 192:
#line 1239 "src/parse.y"
                         {(yyval.ptr)=(yyvsp[0].ptr);}
#line 4099 "build/parse.tab.c"
    break;

  case 193:
#line 1243 "src/parse.y"
                                {(yyval.ptr)=(yyvsp[0].ptr);}
#line 4105 "build/parse.tab.c"
    break;

  case 194:
#line 1244 "src/parse.y"
                                                    {(yyval.ptr)=nonTerminal("parameter_list",NULL,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 4111 "build/parse.tab.c"
    break;

  case 195:
#line 1248 "src/parse.y"
                                            {typeName=string("");
         if((yyvsp[0].ptr)->exprType==1){ char *t=new char();
                     strcpy(t,((yyvsp[0].ptr)->nodeType).c_str());
                     char *key =new char();
                     strcpy(key,((yyvsp[0].ptr)->nodeKey).c_str());
                  if(scopeLookup((yyvsp[0].ptr)->nodeKey)){ yyerror("Error: redeclaration of %s",key);}
                   else {  insertSymbol(*curr,key,t,(yyvsp[0].ptr)->size,0,1);}
                if(funcArguments==string(""))funcArguments=((yyvsp[0].ptr)->nodeType);
               else funcArguments= funcArguments+string(",")+((yyvsp[0].ptr)->nodeType);
                     }
         (yyval.ptr)=nonTerminal("parameter_declaration",NULL,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 4127 "build/parse.tab.c"
    break;

  case 196:
#line 1259 "src/parse.y"
                                                     {typeName=string("");(yyval.ptr)=nonTerminal("parameter_declaration",NULL,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 4133 "build/parse.tab.c"
    break;

  case 197:
#line 1260 "src/parse.y"
                                 {typeName=string("");(yyval.ptr)=(yyvsp[0].ptr);}
#line 4139 "build/parse.tab.c"
    break;

  case 198:
#line 1264 "src/parse.y"
                                      {
					(yyval.ptr)=terminal((yyvsp[0].str));
				      }
#line 4147 "build/parse.tab.c"
    break;

  case 199:
#line 1267 "src/parse.y"
                                         {
					temp = terminal((yyvsp[0].str));
					(yyval.ptr)=nonTerminal("identifier_list",NULL,(yyvsp[-2].ptr),temp);
				      }
#line 4156 "build/parse.tab.c"
    break;

  case 200:
#line 1274 "src/parse.y"
                                                       {(yyval.ptr)=nonTerminal("type_name",NULL,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 4162 "build/parse.tab.c"
    break;

  case 201:
#line 1275 "src/parse.y"
                                   {(yyval.ptr)=(yyvsp[0].ptr);}
#line 4168 "build/parse.tab.c"
    break;

  case 202:
#line 1279 "src/parse.y"
                                             {(yyval.ptr)=nonTerminal("abstract_declarator",NULL,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 4174 "build/parse.tab.c"
    break;

  case 203:
#line 1280 "src/parse.y"
                  {(yyval.ptr)=(yyvsp[0].ptr);}
#line 4180 "build/parse.tab.c"
    break;

  case 204:
#line 1281 "src/parse.y"
                                     {(yyval.ptr)=(yyvsp[0].ptr);}
#line 4186 "build/parse.tab.c"
    break;

  case 205:
#line 1285 "src/parse.y"
                                       {(yyval.ptr) = (yyvsp[-1].ptr);}
#line 4192 "build/parse.tab.c"
    break;

  case 206:
#line 1286 "src/parse.y"
                   {(yyval.ptr) = terminal("[ ]");}
#line 4198 "build/parse.tab.c"
    break;

  case 207:
#line 1287 "src/parse.y"
                      {(yyval.ptr) = terminal("[ * ]");}
#line 4204 "build/parse.tab.c"
    break;

  case 208:
#line 1288 "src/parse.y"
                                                                   {
							             temp = terminal((yyvsp[-3].str));
								     (yyval.ptr) = nonTerminal2("direct_abstract_declarator", temp, (yyvsp[-2].ptr), (yyvsp[-1].ptr));
								   }
#line 4213 "build/parse.tab.c"
    break;

  case 209:
#line 1292 "src/parse.y"
                                                                   {
							             temp = terminal((yyvsp[-2].str));
								     (yyval.ptr) = nonTerminal2("direct_abstract_declarator", temp, (yyvsp[-1].ptr), NULL);
								   }
#line 4222 "build/parse.tab.c"
    break;

  case 210:
#line 1296 "src/parse.y"
                                                                  {
							             temp = terminal((yyvsp[-2].str));
								     (yyval.ptr) = nonTerminal2("direct_abstract_declarator", (yyvsp[-3].ptr), temp, (yyvsp[-1].ptr));
								   }
#line 4231 "build/parse.tab.c"
    break;

  case 211:
#line 1300 "src/parse.y"
                                                            {(yyval.ptr) = nonTerminal("direct_abstract_declarator", NULL, (yyvsp[-2].ptr), (yyvsp[-1].ptr));}
#line 4237 "build/parse.tab.c"
    break;

  case 212:
#line 1301 "src/parse.y"
                                      {(yyval.ptr) = (yyvsp[-1].ptr);}
#line 4243 "build/parse.tab.c"
    break;

  case 213:
#line 1302 "src/parse.y"
                                       {(yyval.ptr) = (yyvsp[-1].ptr);}
#line 4249 "build/parse.tab.c"
    break;

  case 214:
#line 1303 "src/parse.y"
                                             {(yyval.ptr) = nonTerminal("direct_abstract_declarator" , "[ ]", (yyvsp[-2].ptr),NULL);}
#line 4255 "build/parse.tab.c"
    break;

  case 215:
#line 1304 "src/parse.y"
                                                 {(yyval.ptr) = nonTerminal("direct_abstract_declarator", "\[ \* \]", (yyvsp[-3].ptr), NULL);}
#line 4261 "build/parse.tab.c"
    break;

  case 216:
#line 1305 "src/parse.y"
                                                                                             {
				temp = terminal((yyvsp[-3].str));
				(yyval.ptr) = nonTerminalFourChild("direct_abstract_declarator", (yyvsp[-5].ptr), temp, (yyvsp[-2].ptr), (yyvsp[-1].ptr), NULL);
                          }
#line 4270 "build/parse.tab.c"
    break;

  case 217:
#line 1309 "src/parse.y"
                                                                         {
				temp = terminal((yyvsp[-2].str));
				(yyval.ptr) = nonTerminalFourChild("direct_abstract_declarator", (yyvsp[-4].ptr), temp, (yyvsp[-1].ptr), NULL, NULL);
                          }
#line 4279 "build/parse.tab.c"
    break;

  case 218:
#line 1313 "src/parse.y"
                                                                                       {(yyval.ptr) = nonTerminal2("direct_abstract_declarator", (yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[-1].ptr));}
#line 4285 "build/parse.tab.c"
    break;

  case 219:
#line 1314 "src/parse.y"
                                                                                             {
				temp = terminal((yyvsp[-2].str));
				(yyval.ptr) = nonTerminalFourChild("direct_abstract_declarator", (yyvsp[-5].ptr), (yyvsp[-3].ptr), temp,  (yyvsp[-1].ptr), NULL);
                          }
#line 4294 "build/parse.tab.c"
    break;

  case 220:
#line 1318 "src/parse.y"
                                                                 {(yyval.ptr) = nonTerminal("direct_abstract_declarator",NULL, (yyvsp[-3].ptr), (yyvsp[-1].ptr));}
#line 4300 "build/parse.tab.c"
    break;

  case 221:
#line 1319 "src/parse.y"
                                                                   {(yyval.ptr) = nonTerminal("direct_abstract_declarator",NULL, (yyvsp[-3].ptr), (yyvsp[-1].ptr));}
#line 4306 "build/parse.tab.c"
    break;

  case 222:
#line 1320 "src/parse.y"
                   {(yyval.ptr) = terminal("( )");}
#line 4312 "build/parse.tab.c"
    break;

  case 223:
#line 1321 "src/parse.y"
                                      {(yyval.ptr) = (yyvsp[-1].ptr);}
#line 4318 "build/parse.tab.c"
    break;

  case 224:
#line 1322 "src/parse.y"
                                            {(yyval.ptr) = nonTerminal("direct_abstract_declarator","( )", (yyvsp[-2].ptr),NULL);}
#line 4324 "build/parse.tab.c"
    break;

  case 225:
#line 1323 "src/parse.y"
                                                                 {(yyval.ptr) = nonTerminal("direct_abstract_declarator", NULL, (yyvsp[-3].ptr), (yyvsp[-1].ptr));}
#line 4330 "build/parse.tab.c"
    break;

  case 226:
#line 1327 "src/parse.y"
                                   {(yyval.ptr) = (yyvsp[-1].ptr); (yyval.ptr)->nodeType = (yyvsp[-1].ptr)->nodeType+string("*");
                                   }
#line 4337 "build/parse.tab.c"
    break;

  case 227:
#line 1329 "src/parse.y"
                                       {(yyval.ptr) = nonTerminal("initializer", (yyvsp[-1].str), (yyvsp[-2].ptr) ,NULL); (yyval.ptr)->nodeType = (yyvsp[-2].ptr)->nodeType+string("*");
                                  (yyval.ptr)->exprType =(yyvsp[-2].ptr)->exprType;}
#line 4344 "build/parse.tab.c"
    break;

  case 228:
#line 1331 "src/parse.y"
                                {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4350 "build/parse.tab.c"
    break;

  case 229:
#line 1335 "src/parse.y"
                                  {
           (yyval.ptr) = nonTerminal("initializer_list", NULL, (yyvsp[-1].ptr) ,(yyvsp[0].ptr));
           (yyval.ptr)->nodeType = (yyvsp[0].ptr)->nodeType;
           char* a =validAssign((yyvsp[-1].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);
               if(a){
                    if(!strcmp(a,"true")){ ; }
                    if(!strcmp(a,"warning")){
                         yyerror("Warning: Assignment with incompatible pointer type");
                         }
                    }
                else{ yyerror("Error: Incompatible types when assigning type \'%s\' to \'%s\' ",((yyvsp[-1].ptr)->nodeType).c_str(),((yyvsp[0].ptr)->nodeType).c_str()); }
           (yyval.ptr)->exprType = 1;
        }
#line 4368 "build/parse.tab.c"
    break;

  case 230:
#line 1348 "src/parse.y"
                      {(yyval.ptr) = (yyvsp[0].ptr);(yyval.ptr)->exprType=1;}
#line 4374 "build/parse.tab.c"
    break;

  case 231:
#line 1349 "src/parse.y"
                                                       {
          (yyval.ptr) = nonTerminal2("initializer_list", (yyvsp[-3].ptr), (yyvsp[-1].ptr) ,(yyvsp[0].ptr));
          (yyval.ptr)->nodeType = (yyvsp[-3].ptr)->nodeType;
           char* a =validAssign((yyvsp[-1].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);
               if(a){
                    if(!strcmp(a,"true")){ ; }
                    if(!strcmp(a,"warning")){ ;
                         yyerror("Warning: Assignment with incompatible pointer type");
                         }
                     }
                else{ yyerror("Error: Incompatible types when assigning type \'%s\' to \'%s\' ",((yyvsp[-1].ptr)->nodeType).c_str(),((yyvsp[0].ptr)->nodeType).c_str()); }
            a =validAssign((yyvsp[-3].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);
               if(a){
                    if(!strcmp(a,"true")){ ; }
                    if(!strcmp(a,"warning")){ ;
                         yyerror("Warning: Assignment with incompatible pointer type");
                         }
                     }
                else{ yyerror("Error: Incompatible types when initializing type \'%s\' to \'%s\' ",((yyvsp[-3].ptr)->nodeType).c_str(),((yyvsp[0].ptr)->nodeType).c_str()); }

            (yyval.ptr)->exprType =(yyvsp[-3].ptr)->exprType+1;
          }
#line 4401 "build/parse.tab.c"
    break;

  case 232:
#line 1371 "src/parse.y"
                                           {
          (yyval.ptr) = nonTerminal("initializer_list", NULL, (yyvsp[-2].ptr) ,(yyvsp[0].ptr));
          (yyval.ptr)->nodeType = (yyvsp[-2].ptr)->nodeType;
           char* a =validAssign((yyvsp[-2].ptr)->nodeType,(yyvsp[0].ptr)->nodeType);
               if(a){
                    if(!strcmp(a,"true")){ ; }
                    if(!strcmp(a,"warning")){ ;
                         yyerror("Warning: Assignment with incompatible pointer type");
                         }
                     }
                else{ yyerror("Error: Incompatible types when initializing type \'%s\' to \'%s\' ",((yyvsp[-2].ptr)->nodeType).c_str(),((yyvsp[0].ptr)->nodeType).c_str()); }
           (yyval.ptr)->exprType = (yyvsp[-2].ptr)->exprType+1;
        }
#line 4419 "build/parse.tab.c"
    break;

  case 233:
#line 1387 "src/parse.y"
                               {
           (yyval.ptr) = nonTerminal("designation", "=", (yyvsp[-1].ptr) ,NULL);
           (yyval.ptr)->nodeType = (yyvsp[-1].ptr)->nodeType=1;
           }
#line 4428 "build/parse.tab.c"
    break;

  case 234:
#line 1394 "src/parse.y"
                      {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4434 "build/parse.tab.c"
    break;

  case 235:
#line 1395 "src/parse.y"
                                      {(yyval.ptr) = nonTerminal("designator_list", NULL, (yyvsp[-1].ptr) ,(yyvsp[0].ptr)); (yyval.ptr)->nodeType = (yyvsp[0].ptr)->nodeType;}
#line 4440 "build/parse.tab.c"
    break;

  case 236:
#line 1399 "src/parse.y"
                                       {(yyval.ptr) = (yyvsp[-1].ptr);}
#line 4446 "build/parse.tab.c"
    break;

  case 237:
#line 1400 "src/parse.y"
                           {
				temp = terminal((yyvsp[0].str));
				(yyval.ptr) = nonTerminal("designator", (yyvsp[-1].str), NULL, temp);
			   }
#line 4455 "build/parse.tab.c"
    break;

  case 238:
#line 1407 "src/parse.y"
                                                                           {
				temp = terminal((yyvsp[-6].str));
				temp1 = terminal((yyvsp[-2].str));
				(yyval.ptr) = nonTerminal2("static_assert_declaration", temp, (yyvsp[-4].ptr), temp1);
			   }
#line 4465 "build/parse.tab.c"
    break;

  case 239:
#line 1415 "src/parse.y"
                             {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4471 "build/parse.tab.c"
    break;

  case 240:
#line 1416 "src/parse.y"
                              {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4477 "build/parse.tab.c"
    break;

  case 241:
#line 1417 "src/parse.y"
                                {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4483 "build/parse.tab.c"
    break;

  case 242:
#line 1418 "src/parse.y"
                               {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4489 "build/parse.tab.c"
    break;

  case 243:
#line 1419 "src/parse.y"
                               {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4495 "build/parse.tab.c"
    break;

  case 244:
#line 1420 "src/parse.y"
                          {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4501 "build/parse.tab.c"
    break;

  case 245:
#line 1424 "src/parse.y"
                                   {
                                temp = terminal((yyvsp[-2].str));
                                (yyval.ptr) = nonTerminal("labeled_statement", NULL, temp, (yyvsp[0].ptr));
                           }
#line 4510 "build/parse.tab.c"
    break;

  case 246:
#line 1428 "src/parse.y"
                                                 {
                                temp = terminal("case");
                                (yyval.ptr) = nonTerminal2("labeled_statement", temp, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                           }
#line 4519 "build/parse.tab.c"
    break;

  case 247:
#line 1432 "src/parse.y"
                                {
                                temp = terminal((yyvsp[-2].str));
                                (yyval.ptr) = nonTerminal("labeled_statement", NULL, temp, (yyvsp[0].ptr));
                           }
#line 4528 "build/parse.tab.c"
    break;

  case 248:
#line 1439 "src/parse.y"
                    {isFunc=0;(yyval.ptr) = terminal("{ }"); (yyval.ptr)->rVal = -5;}
#line 4534 "build/parse.tab.c"
    break;

  case 249:
#line 1440 "src/parse.y"
                                   {if(blockSym){ string s((yyvsp[-2].str));
                                    s=s+string(".csv");
                                    string u((yyvsp[-2].str));
                                    //printSymTables(curr,s);
                                    //updateSymTable(u); blockSym--;
                                 } (yyval.ptr) = (yyvsp[-1].ptr);
                               }
#line 4546 "build/parse.tab.c"
    break;

  case 250:
#line 1449 "src/parse.y"
                 { if(isFunc==0) {symNumber++;
                        symFileName = /*string("symTableFunc")+to_string(funcSym)*/funcName+string("Block")+to_string(symNumber);
                        //scope=S_BLOCK;
                        //makeSymTable(symFileName,scope,string("12345"));
                        char * y=new char();
                        strcpy(y,symFileName.c_str());
                        (yyval.str) = y;
                        //blockSym++;
                        }
                       isFunc=0;
              }
#line 4562 "build/parse.tab.c"
    break;

  case 251:
#line 1464 "src/parse.y"
                      {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4568 "build/parse.tab.c"
    break;

  case 252:
#line 1465 "src/parse.y"
                                      {(yyval.ptr) = nonTerminal("block_item_list", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));
                                      }
#line 4575 "build/parse.tab.c"
    break;

  case 253:
#line 1470 "src/parse.y"
                      {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4581 "build/parse.tab.c"
    break;

  case 254:
#line 1471 "src/parse.y"
                    {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4587 "build/parse.tab.c"
    break;

  case 255:
#line 1475 "src/parse.y"
              {(yyval.ptr) = terminal(";");}
#line 4593 "build/parse.tab.c"
    break;

  case 256:
#line 1477 "src/parse.y"
                         {(yyval.ptr) =  (yyvsp[-1].ptr) ;}
#line 4599 "build/parse.tab.c"
    break;

  case 257:
#line 1481 "src/parse.y"
                                                          {
                                                           (yyval.ptr) = nonTerminal2("IF (expr) stmt ELSE stmt", (yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr));
                                                         }
#line 4607 "build/parse.tab.c"
    break;

  case 258:
#line 1484 "src/parse.y"
                                          {
                                           (yyval.ptr) = nonTerminal2("IF (expr) stmt", NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                                         }
#line 4615 "build/parse.tab.c"
    break;

  case 259:
#line 1487 "src/parse.y"
                                             {
                                           (yyval.ptr) = nonTerminal2("SWITCH (expr) stmt", NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                                         }
#line 4623 "build/parse.tab.c"
    break;

  case 260:
#line 1493 "src/parse.y"
                                             {
                                           (yyval.ptr) = nonTerminal2("WHILE (expr) stmt", NULL, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                                         }
#line 4631 "build/parse.tab.c"
    break;

  case 261:
#line 1496 "src/parse.y"
                                                    {
                                                     (yyval.ptr) = nonTerminal2("DO stmt WHILE (expr)", NULL, (yyvsp[-5].ptr), (yyvsp[-2].ptr));
                                                   }
#line 4639 "build/parse.tab.c"
    break;

  case 262:
#line 1499 "src/parse.y"
                                                                          {
                                           (yyval.ptr) = nonTerminal2("FOR (expr_stmt expr_stmt) stmt", (yyvsp[-3].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr));
                                         }
#line 4647 "build/parse.tab.c"
    break;

  case 263:
#line 1502 "src/parse.y"
                                                                                     {
                                           (yyval.ptr) = nonTerminalFiveChild("FOR (expr_stmt expr_stmt expr) stmt", NULL, (yyvsp[-4].ptr), (yyvsp[-3].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr));
                                         }
#line 4655 "build/parse.tab.c"
    break;

  case 264:
#line 1505 "src/parse.y"
                                                                 {
                                           (yyval.ptr) = nonTerminal2("FOR ( decl expr_stm ) stmt", (yyvsp[-3].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr));
                                         }
#line 4663 "build/parse.tab.c"
    break;

  case 265:
#line 1508 "src/parse.y"
                                                                             {
                                           (yyval.ptr) = nonTerminalFiveChild("FOR ( decl expr_stmt expr ) stmt", NULL, (yyvsp[-4].ptr), (yyvsp[-3].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr));
                                         }
#line 4671 "build/parse.tab.c"
    break;

  case 266:
#line 1514 "src/parse.y"
                              {
                                temp = terminal((yyvsp[-2].str));
                                temp1 = terminal((yyvsp[-1].str));
                                (yyval.ptr) = nonTerminal("jump_statement", NULL, temp, temp1);
                              }
#line 4681 "build/parse.tab.c"
    break;

  case 267:
#line 1519 "src/parse.y"
                              {
                                (yyval.ptr) = terminal("continue");
                              }
#line 4689 "build/parse.tab.c"
    break;

  case 268:
#line 1522 "src/parse.y"
                              {
                                (yyval.ptr) = terminal("break");
                              }
#line 4697 "build/parse.tab.c"
    break;

  case 269:
#line 1525 "src/parse.y"
                              {
                                (yyval.ptr) = terminal("return");
                              }
#line 4705 "build/parse.tab.c"
    break;

  case 270:
#line 1528 "src/parse.y"
                                {
                                  temp = terminal("return");
                                    (yyval.ptr) = nonTerminal("jump_statement", NULL, temp, (yyvsp[-1].ptr));
                                }
#line 4714 "build/parse.tab.c"
    break;

  case 271:
#line 1536 "src/parse.y"
                                {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4720 "build/parse.tab.c"
    break;

  case 272:
#line 1537 "src/parse.y"
                                                 {(yyval.ptr) = nonTerminal("translation_unit", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));
                                                   }
#line 4727 "build/parse.tab.c"
    break;

  case 273:
#line 1542 "src/parse.y"
                               {typeName=string("");(yyval.ptr) = (yyvsp[0].ptr);}
#line 4733 "build/parse.tab.c"
    break;

  case 274:
#line 1543 "src/parse.y"
                       {typeName=string("");(yyval.ptr) = (yyvsp[0].ptr);}
#line 4739 "build/parse.tab.c"
    break;

  case 275:
#line 1548 "src/parse.y"
         {      typeName=string("");
                string s((yyvsp[-2].str));
                string u = s+string(".csv");
                printSymTables(curr,u);
                symNumber=0;
               updateSymTable(s);
                (yyval.ptr) = nonTerminalFourChild("function_definition", (yyvsp[-4].ptr), (yyvsp[-3].ptr), (yyvsp[-1].ptr), (yyvsp[0].ptr), NULL);
         }
#line 4752 "build/parse.tab.c"
    break;

  case 276:
#line 1556 "src/parse.y"
                                                                   {
              typeName=string("");
              string s((yyvsp[-1].str));string u =s+string(".csv");
              printSymTables(curr,u);
              symNumber=0;
              updateSymTable(s);
              (yyval.ptr) = nonTerminal2("function_definition", (yyvsp[-3].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr));
             }
#line 4765 "build/parse.tab.c"
    break;

  case 277:
#line 1567 "src/parse.y"
                            { typeName=string("");scope = S_FUNC;
                                         isFunc = 1;
                                         funcSym++;
                                         symFileName = funcName;//string("symTableFunc")+to_string(funcSym);
                                         makeSymTable(symFileName,scope,funcType);
                                         char* y= new char();
                                         strcpy(y,symFileName.c_str());
                                         (yyval.str) = y;
       }
#line 4779 "build/parse.tab.c"
    break;

  case 278:
#line 1579 "src/parse.y"
                      {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4785 "build/parse.tab.c"
    break;

  case 279:
#line 1580 "src/parse.y"
                                       {(yyval.ptr) = nonTerminal("declaration_list", NULL, (yyvsp[-1].ptr), (yyvsp[0].ptr));
          }
#line 4792 "build/parse.tab.c"
    break;


#line 4796 "build/parse.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1584 "src/parse.y"


void helpMessage(){
  printf("Specify an input file with -i flag\n");
  printf("Specify an output file with -o flag\n");
  return;
}

extern FILE *yyin;

int main(int argc,char **argv){
  if(argc==1){
    helpMessage();
    return 0;
  }
  tempodd =0;
  tempeven =0; 
  yyin=NULL;
  int fileflag = 0;
  // command line options
  int argCount;
  for(argc--, argv++; argc>0; argc-=argCount, argv += argCount){
    argCount = 1;
    if(!strcmp(*argv, "-h")){
      helpMessage();
      return 0;
    }
    else if(!strcmp(*argv, "-o")){
      if (argc > 1){
        digraph =fopen(*(argv+1),"w");
        fileflag = 1;
      }
      else {
        helpMessage();
        return 0;
      }
    }
    else if(!strcmp(*argv, "-i")){
      if (argc > 1){
        yyin =fopen(*(argv+1),"r");
        strncpy(filename,*(argv+1),1024);
      }
      else {
        helpMessage();
        return 0;
      }
    }

}
  if(yyin == NULL) {
    helpMessage();
    return 0;
  }
  char ch;
  funcName = string("GST");
  duplicate = fopen("inputused.txt","w");
  while( ( ch = fgetc(yyin) ) != EOF ){
        fputc(ch, duplicate);
  }
  fclose(duplicate);
  fclose(yyin);
  yyin=fopen(filename,"r");
  // default output file
  if(fileflag == 0)
  digraph =fopen("digraph.gv","w");
  currArguments = string("");
  stInitialize();
  graphInitialization();
  yyparse();
  graphEnd();
  symFileName = "GST.csv";
  printSymTables(curr,symFileName);
  printFuncArguments();
  return 0;
}
void yyerror(char *s,...){
  va_list args;
  char buffer[MAX_STR_LEN];

va_start(args,s);
  vsnprintf(buffer,MAX_STR_LEN-1,s,args);
  va_end(args);


int count = 1;
  if(s=="syntax error") count = 2;
  fprintf(stderr,"%s : %d :: %s\n",filename,yylineno,buffer);
  duplicate=fopen("inputused.txt","r");
  if ( duplicate != NULL )
  {
    char line[256]; /* or other suitable maximum line size */
    while (fgets(line, sizeof line, duplicate) != NULL) /* read a line */
    {
        if (count == yylineno)
        {
            fprintf(stderr,"\t%s\n",line);
            break;
        }
        else
        {
            count++;
        }
    }
    fclose(duplicate);
}
else
{
    //file doesn't exist
}

}
