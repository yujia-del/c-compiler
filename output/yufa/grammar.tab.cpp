/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIGNOP = 258,
     OR = 259,
     AND = 260,
     SINGALAND = 261,
     RELOP = 262,
     PLUS = 263,
     MINUS = 264,
     MOD = 265,
     DIV = 266,
     STAR = 267,
     POWER = 268,
     NOT = 269,
     RB = 270,
     LB = 271,
     RP = 272,
     LP = 273,
     LOWER_THAN_ELSE = 274,
     COMMA = 275,
     SEMI = 276,
     GETMEMBER = 277,
     STRUCT = 278,
     WHILE = 279,
     ELSE = 280,
     IF = 281,
     RETURN = 282,
     ERRID = 283,
     INT = 284,
     TYPE = 285,
     ID = 286,
     FOR = 287,
     LC = 288,
     RC = 289
   };
#endif
/* Tokens.  */
#define ASSIGNOP 258
#define OR 259
#define AND 260
#define SINGALAND 261
#define RELOP 262
#define PLUS 263
#define MINUS 264
#define MOD 265
#define DIV 266
#define STAR 267
#define POWER 268
#define NOT 269
#define RB 270
#define LB 271
#define RP 272
#define LP 273
#define LOWER_THAN_ELSE 274
#define COMMA 275
#define SEMI 276
#define GETMEMBER 277
#define STRUCT 278
#define WHILE 279
#define ELSE 280
#define IF 281
#define RETURN 282
#define ERRID 283
#define INT 284
#define TYPE 285
#define ID 286
#define FOR 287
#define LC 288
#define RC 289




/* Copy the first part of user declarations.  */
#line 17 "grammar.y"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "common/trees.h"
#include "common/util/InterMediate.h"
#include "common/util/AsmGenerator.h"
class AbstractASTNode; // 数据类型定义：定义语义动作使用到的数据类型
extern char *yytext; // 外部变量和全局变量定义
extern int yylex();
extern int column;
extern FILE * yyin;
extern int yylineno;
AbstractASTNode* root;
StructTable *structTable;
void yyerror(const char *str);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 67 "grammar.y"
{
	AbstractASTNode* ast;
    char* str;
}
/* Line 193 of yacc.c.  */
#line 188 "./output/yufa/grammar.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 213 "./output/yufa/grammar.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   518

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    14,    17,    21,    25,
      28,    31,    33,    37,    39,    42,    48,    50,    53,    57,
      59,    64,    69,    73,    77,    79,    82,    84,    88,    91,
      94,    95,    97,    99,   102,   105,   110,   112,   116,   119,
     125,   133,   139,   146,   154,   162,   170,   180,   189,   198,
     207,   210,   213,   216,   218,   222,   224,   228,   232,   236,
     240,   244,   248,   252,   256,   260,   264,   268,   272,   275,
     278,   281,   286,   290,   295,   297,   302,   306,   308,   311,
     314,   318
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    37,    -1,    38,    -1,    37,    38,    -1,
      40,    39,    21,    -1,    40,    21,    -1,    40,    45,    48,
      -1,    40,    45,    21,    -1,    41,    21,    -1,     1,    21,
      -1,    44,    -1,    39,    20,    44,    -1,    30,    -1,    30,
      12,    -1,    23,    31,    33,    42,    34,    -1,    43,    -1,
      42,    43,    -1,    40,    31,    21,    -1,    31,    -1,    31,
      16,    29,    15,    -1,    31,    18,    46,    17,    -1,    31,
      18,    17,    -1,    46,    20,    47,    -1,    47,    -1,    40,
      31,    -1,    40,    -1,    33,    49,    34,    -1,     1,    34,
      -1,    49,    51,    -1,    -1,    52,    -1,    55,    -1,    55,
      21,    -1,    52,    21,    -1,    23,    31,    31,    21,    -1,
      48,    -1,    27,    55,    21,    -1,    27,    21,    -1,    26,
      18,    55,    17,    51,    -1,    26,    18,    55,    17,    51,
      25,    51,    -1,    24,    18,    55,    17,    51,    -1,    32,
      18,    21,    21,    17,    51,    -1,    32,    18,    50,    21,
      21,    17,    51,    -1,    32,    18,    21,    55,    21,    17,
      51,    -1,    32,    18,    21,    21,    55,    17,    51,    -1,
      32,    18,    50,    21,    55,    21,    55,    17,    51,    -1,
      32,    18,    50,    21,    55,    21,    17,    51,    -1,    32,
      18,    50,    21,    21,    55,    17,    51,    -1,    32,    18,
      21,    55,    21,    55,    17,    51,    -1,     1,    21,    -1,
      40,    53,    -1,     1,    21,    -1,    54,    -1,    54,    20,
      53,    -1,    44,    -1,    44,     3,    55,    -1,    55,     3,
      55,    -1,    55,     5,    55,    -1,    55,     4,    55,    -1,
      55,     7,    55,    -1,    55,     8,    55,    -1,    55,     9,
      55,    -1,    55,    12,    55,    -1,    55,    11,    55,    -1,
      55,    10,    55,    -1,    55,    13,    55,    -1,    18,    55,
      17,    -1,     9,    55,    -1,    14,    55,    -1,     6,    31,
      -1,    31,    18,    56,    17,    -1,    31,    18,    17,    -1,
      55,    16,    55,    15,    -1,    31,    -1,    31,    16,    55,
      15,    -1,    31,    22,    31,    -1,    29,    -1,    12,    31,
      -1,     1,    17,    -1,    56,    20,    55,    -1,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   179,   179,   194,   197,   208,   213,   215,   221,   223,
     226,   228,   231,   238,   241,   246,   256,   259,   265,   273,
     276,   283,   286,   291,   295,   299,   304,   310,   315,   319,
     325,   331,   334,   339,   344,   349,   355,   358,   363,   366,
     369,   372,   375,   378,   381,   384,   387,   390,   393,   396,
     399,   405,   410,   413,   416,   422,   425,   433,   453,   459,
     465,   471,   477,   483,   489,   495,   501,   507,   510,   515,
     520,   526,   529,   532,   535,   538,   545,   553,   556,   562,
     564,   568
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGNOP", "OR", "AND", "SINGALAND",
  "RELOP", "PLUS", "MINUS", "MOD", "DIV", "STAR", "POWER", "NOT", "RB",
  "LB", "RP", "LP", "LOWER_THAN_ELSE", "COMMA", "SEMI", "GETMEMBER",
  "STRUCT", "WHILE", "ELSE", "IF", "RETURN", "ERRID", "INT", "TYPE", "ID",
  "FOR", "LC", "RC", "$accept", "Program", "ExtDefList", "ExtDef",
  "ExtDecList", "Specifier", "StructSpecifier", "StructDecList",
  "StructDec", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "DecFor", "Stmt", "Def", "DecList", "Dec", "Exp", "Args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    38,
      38,    39,    39,    40,    40,    41,    42,    42,    43,    44,
      44,    45,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     2,     3,     3,     2,
       2,     1,     3,     1,     2,     5,     1,     2,     3,     1,
       4,     4,     3,     3,     1,     2,     1,     3,     2,     2,
       0,     1,     1,     2,     2,     4,     1,     3,     2,     5,
       7,     5,     6,     7,     7,     7,     9,     8,     8,     8,
       2,     2,     2,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     4,     3,     4,     1,     4,     3,     1,     2,     2,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    13,     0,     0,     3,     0,     0,    10,
       0,    14,     1,     4,     6,    19,     0,    11,     0,     9,
       0,     0,     0,     0,     5,     0,     8,    30,     7,     0,
       0,    16,     0,    22,    26,     0,    24,    19,    12,    28,
       0,     0,    15,    17,    20,    25,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    74,
       0,    27,     0,    36,    29,     0,     0,    18,    23,    79,
      50,    70,     0,    68,    78,    69,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,    55,    51,    53,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    67,     0,     0,     0,    37,     0,    72,    81,
       0,    76,     0,     0,     0,    31,    32,     0,     0,    57,
      59,    58,    60,    61,    62,    65,    64,    63,    66,     0,
      35,     0,     0,    75,    71,     0,    52,     0,     0,     0,
      56,    54,    73,    41,    39,    80,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,     0,     0,     0,    40,
      45,    44,     0,    43,     0,     0,     0,    49,    48,    47,
       0,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    16,    62,     8,    30,    31,    86,
      18,    35,    36,    63,    40,   114,    64,    65,    87,    88,
      66,   110
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -95
static const yytype_int16 yypact[] =
{
       0,    -8,   -15,    10,    31,    65,   -95,    -4,    40,   -95,
      48,   -95,   -95,   -95,   -95,     2,    52,   -95,    53,   -95,
      34,    46,   -11,    38,   -95,    50,   -95,   -95,   -95,    51,
     -20,   -95,    75,   -95,    60,    19,   -95,    77,   -95,   -95,
      91,    73,   -95,   -95,   -95,   -95,   -95,    34,    -9,    70,
     261,    71,   261,   261,    76,    78,    93,   158,   -95,    88,
      94,   -95,    38,   -95,   -95,    92,   290,   -95,   -95,   -95,
      95,   -95,   102,    67,   -95,   111,   350,    97,   261,   261,
     -95,   305,   261,   168,    98,   132,   127,   -95,   112,   -95,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   -95,   -95,   114,   365,   380,   -95,   455,   -95,   483,
      36,   -95,    -6,   182,   115,   -95,   483,   261,    38,   483,
     275,   493,   502,    67,    67,    42,    42,    42,   111,   469,
     -95,   125,   125,   -95,   -95,   261,   -95,   192,   320,   206,
     483,   -95,   -95,   -95,   117,   483,   125,   395,   216,   237,
     335,   125,   -95,   125,   125,   410,   125,   425,   247,   -95,
     -95,   -95,   125,   -95,   125,   125,   440,   -95,   -95,   -95,
     125,   -95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   135,   -95,     4,   -95,   -95,   130,    -2,
     -95,   -95,   100,   147,   -95,   -95,   -94,    81,    27,   -95,
     -50,   -95
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -53
static const yytype_int16 yytable[] =
{
      73,     1,    75,    76,     7,    17,    33,    81,    69,     7,
       3,    69,    70,     9,    42,   136,    10,    14,    21,     3,
      22,    38,    11,     2,    29,    39,    34,    15,   104,   105,
       3,    12,   107,   109,    29,   116,    46,   143,   144,    47,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    34,   152,   134,    25,    99,   135,   159,   100,   160,
     161,    19,   163,   138,     3,    -2,     1,   140,   167,    37,
     168,   169,    23,    24,    26,    32,   171,    96,    97,    98,
      99,    20,    41,   100,    39,   145,    27,   147,     2,   150,
      44,    45,    48,    21,    67,     3,    78,    49,   155,   157,
      50,    71,    74,    51,    82,    52,    83,    77,   166,    53,
      84,    79,    85,    89,    54,    55,   -52,    56,    57,    69,
      58,     3,    59,    60,    27,    61,    48,   100,   103,   111,
     117,    49,   118,   112,    50,   130,   139,    51,    49,    52,
      13,    50,   151,    53,    51,   141,    52,    68,    54,    55,
      53,    56,    57,   113,    58,     3,    59,    60,    27,    72,
      43,    58,     3,    59,    49,    28,   115,    50,     0,    72,
      51,     0,    52,     0,    49,     0,    53,    50,     0,    80,
      51,     0,    52,    72,     0,   108,    53,    58,    49,    59,
       0,    50,     0,    72,    51,     0,    52,    58,    49,    59,
      53,    50,     0,   137,    51,     0,    52,    72,     0,   146,
      53,    58,    49,    59,     0,    50,     0,    72,    51,     0,
      52,    58,    49,    59,    53,    50,     0,   149,    51,     0,
      52,     0,     0,   154,    53,    58,     0,    59,    72,     0,
       0,     0,     0,    49,     0,    58,    50,    59,    72,    51,
       0,    52,     0,    49,   156,    53,    50,     0,     0,    51,
       0,    52,    72,     0,   165,    53,    58,    49,    59,     0,
      50,     0,     0,    51,     0,    52,    58,     0,    59,    53,
      92,     0,    93,    94,    95,    96,    97,    98,    99,     0,
      58,   100,    59,    90,    91,    92,     0,    93,    94,    95,
      96,    97,    98,    99,     0,     0,   100,     0,    90,    91,
      92,   101,    93,    94,    95,    96,    97,    98,    99,     0,
       0,   100,     0,    90,    91,    92,   106,    93,    94,    95,
      96,    97,    98,    99,     0,     0,   100,     0,    90,    91,
      92,   148,    93,    94,    95,    96,    97,    98,    99,     0,
       0,   100,     0,    90,    91,    92,   158,    93,    94,    95,
      96,    97,    98,    99,     0,     0,   100,   102,    90,    91,
      92,     0,    93,    94,    95,    96,    97,    98,    99,     0,
       0,   100,   131,    90,    91,    92,     0,    93,    94,    95,
      96,    97,    98,    99,     0,     0,   100,   132,    90,    91,
      92,     0,    93,    94,    95,    96,    97,    98,    99,     0,
       0,   100,   153,    90,    91,    92,     0,    93,    94,    95,
      96,    97,    98,    99,     0,     0,   100,   162,    90,    91,
      92,     0,    93,    94,    95,    96,    97,    98,    99,     0,
       0,   100,   164,    90,    91,    92,     0,    93,    94,    95,
      96,    97,    98,    99,     0,     0,   100,   170,    90,    91,
      92,     0,    93,    94,    95,    96,    97,    98,    99,     0,
     133,   100,    90,    91,    92,     0,    93,    94,    95,    96,
      97,    98,    99,     0,   142,   100,    90,    91,    92,     0,
      93,    94,    95,    96,    97,    98,    99,     0,     0,   100,
      93,    94,    95,    96,    97,    98,    99,     0,     0,   100,
      94,    95,    96,    97,    98,    99,     0,     0,   100
};

static const yytype_int16 yycheck[] =
{
      50,     1,    52,    53,     0,     7,    17,    57,    17,     5,
      30,    17,    21,    21,    34,    21,    31,    21,    16,    30,
      18,    23,    12,    23,    20,    34,    22,    31,    78,    79,
      30,     0,    82,    83,    30,    85,    17,   131,   132,    20,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    47,   146,    17,     1,    13,    20,   151,    16,   153,
     154,    21,   156,   113,    30,     0,     1,   117,   162,    31,
     164,   165,    20,    21,    21,    29,   170,    10,    11,    12,
      13,    33,    31,    16,    34,   135,    33,   137,    23,   139,
      15,    31,     1,    16,    21,    30,    18,     6,   148,   149,
       9,    31,    31,    12,    16,    14,    18,    31,   158,    18,
      22,    18,    18,    21,    23,    24,    21,    26,    27,    17,
      29,    30,    31,    32,    33,    34,     1,    16,    31,    31,
       3,     6,    20,     1,     9,    21,    21,    12,     6,    14,
       5,     9,    25,    18,    12,   118,    14,    47,    23,    24,
      18,    26,    27,    21,    29,    30,    31,    32,    33,     1,
      30,    29,    30,    31,     6,    18,    85,     9,    -1,     1,
      12,    -1,    14,    -1,     6,    -1,    18,     9,    -1,    21,
      12,    -1,    14,     1,    -1,    17,    18,    29,     6,    31,
      -1,     9,    -1,     1,    12,    -1,    14,    29,     6,    31,
      18,     9,    -1,    21,    12,    -1,    14,     1,    -1,    17,
      18,    29,     6,    31,    -1,     9,    -1,     1,    12,    -1,
      14,    29,     6,    31,    18,     9,    -1,    21,    12,    -1,
      14,    -1,    -1,    17,    18,    29,    -1,    31,     1,    -1,
      -1,    -1,    -1,     6,    -1,    29,     9,    31,     1,    12,
      -1,    14,    -1,     6,    17,    18,     9,    -1,    -1,    12,
      -1,    14,     1,    -1,    17,    18,    29,     6,    31,    -1,
       9,    -1,    -1,    12,    -1,    14,    29,    -1,    31,    18,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    -1,
      29,    16,    31,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    16,    -1,     3,     4,
       5,    21,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    16,    -1,     3,     4,     5,    21,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    16,    -1,     3,     4,
       5,    21,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    16,    -1,     3,     4,     5,    21,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    16,    17,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    16,    17,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    16,    17,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    16,    17,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    16,    17,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    16,    17,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    16,    17,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    16,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    16,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    16,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    16,
       8,     9,    10,    11,    12,    13,    -1,    -1,    16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    23,    30,    36,    37,    38,    40,    41,    21,
      31,    12,     0,    38,    21,    31,    39,    44,    45,    21,
      33,    16,    18,    20,    21,     1,    21,    33,    48,    40,
      42,    43,    29,    17,    40,    46,    47,    31,    44,    34,
      49,    31,    34,    43,    15,    31,    17,    20,     1,     6,
       9,    12,    14,    18,    23,    24,    26,    27,    29,    31,
      32,    34,    40,    48,    51,    52,    55,    21,    47,    17,
      21,    31,     1,    55,    31,    55,    55,    31,    18,    18,
      21,    55,    16,    18,    22,    18,    44,    53,    54,    21,
       3,     4,     5,     7,     8,     9,    10,    11,    12,    13,
      16,    21,    17,    31,    55,    55,    21,    55,    17,    55,
      56,    31,     1,    21,    50,    52,    55,     3,    20,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      21,    17,    17,    15,    17,    20,    21,    21,    55,    21,
      55,    53,    15,    51,    51,    55,    17,    55,    21,    21,
      55,    25,    51,    17,    17,    55,    17,    55,    21,    51,
      51,    51,    17,    51,    17,    17,    55,    51,    51,    51,
      17,    51
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 179 "grammar.y"
    {
        root = new RootASTNode();
        root->addChildNode((yyvsp[(1) - (1)].ast));
        (yyval.ast) = root;
    ;}
    break;

  case 3:
#line 194 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(1) - (1)].ast);
    ;}
    break;

  case 4:
#line 197 "grammar.y"
    {
        if ((yyvsp[(1) - (2)].ast) == NULL) {
            (yyval.ast) = (yyvsp[(2) - (2)].ast);
        } else {
            if ((yyvsp[(2) - (2)].ast) != NULL) {
                (yyvsp[(1) - (2)].ast)->getLastPeerNode()->addPeerNode((yyvsp[(2) - (2)].ast));
            }
            (yyval.ast) = (yyvsp[(1) - (2)].ast);
        }
    ;}
    break;

  case 5:
#line 208 "grammar.y"
    {
        DefVarASTNode* defVar = (DefVarASTNode*)(yyvsp[(2) - (3)].ast);
        defVar->setAllType((yyvsp[(1) - (3)].str));
        (yyval.ast) = defVar;
    ;}
    break;

  case 6:
#line 213 "grammar.y"
    {
    ;}
    break;

  case 7:
#line 215 "grammar.y"
    {
        DefFunASTNode* temp = (DefFunASTNode*)(yyvsp[(2) - (3)].ast);
        temp->setFunBody((yyvsp[(3) - (3)].ast));
        temp->setRevType((yyvsp[(1) - (3)].str));
        (yyval.ast) = temp;
    ;}
    break;

  case 8:
#line 221 "grammar.y"
    {
    ;}
    break;

  case 9:
#line 223 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(1) - (2)].ast);
    ;}
    break;

  case 10:
#line 226 "grammar.y"
    { yyerrok; (yyval.ast) = NULL;;}
    break;

  case 11:
#line 228 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(1) - (1)].ast);
    ;}
    break;

  case 12:
#line 231 "grammar.y"
    {
        (yyvsp[(1) - (3)].ast)->getLastPeerNode()->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = (yyvsp[(1) - (3)].ast);
    ;}
    break;

  case 13:
#line 238 "grammar.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 14:
#line 241 "grammar.y"
    {
        (yyval.str) = (char*)("integer pointer");
    ;}
    break;

  case 15:
#line 246 "grammar.y"
    {
        if (structTable == NULL) {
            structTable = new StructTable();
        }
        structSymbol* sSymble = new structSymbol((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].ast));
        structTable->addStruct(sSymble);
        (yyval.ast) = NULL;
    ;}
    break;

  case 16:
#line 256 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(1) - (1)].ast);
    ;}
    break;

  case 17:
#line 259 "grammar.y"
    {
        (yyvsp[(1) - (2)].ast)->getLastPeerNode()->addPeerNode((yyvsp[(2) - (2)].ast));
        (yyval.ast) = (yyvsp[(1) - (2)].ast);
    ;}
    break;

  case 18:
#line 265 "grammar.y"
    {
        DefVarASTNode* var = new DefVarASTNode((yyvsp[(2) - (3)].str));
        var->setAllType((yyvsp[(1) - (3)].str));
        (yyval.ast) = var;
    ;}
    break;

  case 19:
#line 273 "grammar.y"
    {
        (yyval.ast) = new DefVarASTNode((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 20:
#line 276 "grammar.y"
    {
        DefVarASTNode* var = new DefVarASTNode((yyvsp[(1) - (4)].str));
        var->setAllType((char*)("array"));
        var->setArrayLength((yyvsp[(3) - (4)].str));
        (yyval.ast) = var;
    ;}
    break;

  case 21:
#line 283 "grammar.y"
    {
        (yyval.ast) = new DefFunASTNode((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].ast), NULL);
    ;}
    break;

  case 22:
#line 286 "grammar.y"
    {
        (yyval.ast) = new DefFunASTNode((yyvsp[(1) - (3)].str), NULL, NULL);
    ;}
    break;

  case 23:
#line 291 "grammar.y"
    {
        (yyvsp[(1) - (3)].ast)->getLastPeerNode()->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = (yyvsp[(1) - (3)].ast);
    ;}
    break;

  case 24:
#line 295 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(1) - (1)].ast);
    ;}
    break;

  case 25:
#line 299 "grammar.y"
    {
        DefVarASTNode* var = new DefVarASTNode((yyvsp[(2) - (2)].str));
        var->setAllType((yyvsp[(1) - (2)].str));
        (yyval.ast) = var;
    ;}
    break;

  case 26:
#line 304 "grammar.y"
    {
    ;}
    break;

  case 27:
#line 310 "grammar.y"
    {
        AbstractASTNode* compStmt = new StmtASTNode(StmtType::compStmt);
        compStmt->addChildNode((yyvsp[(2) - (3)].ast));
        (yyval.ast) = compStmt;
    ;}
    break;

  case 28:
#line 315 "grammar.y"
    { yyerrok; ;}
    break;

  case 29:
#line 319 "grammar.y"
    {
        if ((yyvsp[(1) - (2)].ast) == NULL) (yyval.ast) = (yyvsp[(2) - (2)].ast);
        else {
            (yyvsp[(1) - (2)].ast)->getLastPeerNode()->addPeerNode((yyvsp[(2) - (2)].ast));
        }
    ;}
    break;

  case 30:
#line 325 "grammar.y"
    {
        (yyval.ast) = NULL;
    ;}
    break;

  case 31:
#line 331 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(1) - (1)].ast);
    ;}
    break;

  case 32:
#line 334 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(1) - (1)].ast);
    ;}
    break;

  case 33:
#line 339 "grammar.y"
    {
        AbstractASTNode* temp = new StmtASTNode(StmtType::expStmt);
        temp->addChildNode((yyvsp[(1) - (2)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 34:
#line 344 "grammar.y"
    {
        AbstractASTNode* temp = new StmtASTNode(StmtType::defStmt);
        temp->addChildNode((yyvsp[(1) - (2)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 35:
#line 349 "grammar.y"
    {
        AbstractASTNode* temp = new StmtASTNode(StmtType::defStmt);
        AbstractASTNode* structDec = new DefVarASTNode((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str));
        temp->addChildNode(structDec);
        (yyval.ast) = temp;
    ;}
    break;

  case 36:
#line 355 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(1) - (1)].ast);
    ;}
    break;

  case 37:
#line 358 "grammar.y"
    {
        AbstractASTNode* temp = new StmtASTNode(StmtType::returnStmt);
        temp->addChildNode((yyvsp[(2) - (3)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 38:
#line 363 "grammar.y"
    {
        (yyval.ast) = new StmtASTNode(StmtType::returnStmt);
    ;}
    break;

  case 39:
#line 366 "grammar.y"
    {
        (yyval.ast) = new SelectASTNode((char*)"", SelectType::_if, (yyvsp[(5) - (5)].ast), (yyvsp[(3) - (5)].ast));
    ;}
    break;

  case 40:
#line 369 "grammar.y"
    {
        (yyval.ast) = new SelectASTNode((char*)"", SelectType::_if, (yyvsp[(5) - (7)].ast), (yyvsp[(3) - (7)].ast), (yyvsp[(7) - (7)].ast));
    ;}
    break;

  case 41:
#line 372 "grammar.y"
    {
        (yyval.ast) = new LoopASTNode((char*)"", LoopType::_while, (yyvsp[(5) - (5)].ast), (yyvsp[(3) - (5)].ast));
    ;}
    break;

  case 42:
#line 375 "grammar.y"
    {
        (yyval.ast) = new LoopASTNode((char*)"", LoopType::_for, (yyvsp[(6) - (6)].ast), NULL, NULL, NULL);
    ;}
    break;

  case 43:
#line 378 "grammar.y"
    {
        (yyval.ast) = new LoopASTNode((char*)"", LoopType::_for, (yyvsp[(7) - (7)].ast), (yyvsp[(3) - (7)].ast), NULL, NULL);
    ;}
    break;

  case 44:
#line 381 "grammar.y"
    {
        (yyval.ast) = new LoopASTNode((char*)"", LoopType::_for, (yyvsp[(7) - (7)].ast), NULL, (yyvsp[(4) - (7)].ast), NULL);
    ;}
    break;

  case 45:
#line 384 "grammar.y"
    {
        (yyval.ast) = new LoopASTNode((char*)"", LoopType::_for, (yyvsp[(7) - (7)].ast), NULL, NULL, (yyvsp[(5) - (7)].ast));
    ;}
    break;

  case 46:
#line 387 "grammar.y"
    {
        (yyval.ast) = new LoopASTNode((char*)"", LoopType::_for, (yyvsp[(9) - (9)].ast), (yyvsp[(3) - (9)].ast), (yyvsp[(5) - (9)].ast), (yyvsp[(7) - (9)].ast));
    ;}
    break;

  case 47:
#line 390 "grammar.y"
    {
        (yyval.ast) = new LoopASTNode((char*)"", LoopType::_for, (yyvsp[(8) - (8)].ast), (yyvsp[(3) - (8)].ast), (yyvsp[(5) - (8)].ast), NULL);
    ;}
    break;

  case 48:
#line 393 "grammar.y"
    {
        (yyval.ast) = new LoopASTNode((char*)"", LoopType::_for, (yyvsp[(8) - (8)].ast), (yyvsp[(3) - (8)].ast), NULL, (yyvsp[(6) - (8)].ast));
    ;}
    break;

  case 49:
#line 396 "grammar.y"
    {
        (yyval.ast) = new LoopASTNode((char*)"", LoopType::_for, (yyvsp[(8) - (8)].ast), NULL, (yyvsp[(4) - (8)].ast), (yyvsp[(6) - (8)].ast));
    ;}
    break;

  case 50:
#line 399 "grammar.y"
    { yyerrok; ;}
    break;

  case 51:
#line 405 "grammar.y"
    {
        DefVarASTNode* temp = (DefVarASTNode*)(yyvsp[(2) - (2)].ast);
        temp->setAllType((yyvsp[(1) - (2)].str));
        (yyval.ast) = temp;
    ;}
    break;

  case 52:
#line 410 "grammar.y"
    { yyerrok; ;}
    break;

  case 53:
#line 413 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(1) - (1)].ast);
    ;}
    break;

  case 54:
#line 416 "grammar.y"
    {
        (yyvsp[(1) - (3)].ast)->getLastPeerNode()->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = (yyvsp[(1) - (3)].ast);
    ;}
    break;

  case 55:
#line 422 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(1) - (1)].ast);
    ;}
    break;

  case 56:
#line 425 "grammar.y"
    {
        (yyvsp[(1) - (3)].ast)->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = (yyvsp[(1) - (3)].ast);
    ;}
    break;

  case 57:
#line 433 "grammar.y"
    {
        AbstractASTNode* temp = NULL;
        if ((yyvsp[(1) - (3)].ast)->getNodeType() == ASTNodeType::op) {
            OperatorASTNode* left = (OperatorASTNode*)(yyvsp[(1) - (3)].ast);
            if (left->getType() == opType::GetArrayValue) {
                temp = new OperatorASTNode((char*)"=", opType::AssignArray);
            } else if (left->getType() == opType::GetMember) {
                temp = new OperatorASTNode((char*)"=", opType::AssignMember);
            } else {
                temp = new OperatorASTNode((char*)"=", opType::Assignop);
            }
        }
        else {
            temp = new OperatorASTNode((char*)"=", opType::Assignop);
        }
        temp->addChildNode((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyvsp[(3) - (3)].ast)->setParent(temp);
        (yyval.ast) = temp;
    ;}
    break;

  case 58:
#line 453 "grammar.y"
    {
        AbstractASTNode* temp = new OperatorASTNode((char*)"&&", opType::And);
        temp->addChildNode((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 59:
#line 459 "grammar.y"
    {
        AbstractASTNode* temp = new OperatorASTNode((char*)"||", opType::Or);
        temp->addChildNode((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 60:
#line 465 "grammar.y"
    {
        AbstractASTNode* temp = new OperatorASTNode((yyvsp[(2) - (3)].str), opType::Relop);
        temp->addChildNode((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 61:
#line 471 "grammar.y"
    {
        AbstractASTNode* temp = new OperatorASTNode((char*)"+", opType::Plus);
        temp->addChildNode((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 62:
#line 477 "grammar.y"
    {
        AbstractASTNode* temp = new OperatorASTNode((char*)"-", opType::Minus);
        temp->addChildNode((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 63:
#line 483 "grammar.y"
    {
        AbstractASTNode* temp = new OperatorASTNode((char*)"*", opType::Times);
        temp->addChildNode((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 64:
#line 489 "grammar.y"
    {
        AbstractASTNode* temp = new OperatorASTNode((char*)"/", opType::Div);
        temp->addChildNode((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 65:
#line 495 "grammar.y"
    {
        AbstractASTNode* temp = new OperatorASTNode((char*)"%", opType::Mod);
        temp->addChildNode((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 66:
#line 501 "grammar.y"
    {
        AbstractASTNode* temp = new OperatorASTNode((char*)"^", opType::Power);
        temp->addChildNode((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 67:
#line 507 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(2) - (3)].ast);
    ;}
    break;

  case 68:
#line 510 "grammar.y"
    {
        AbstractASTNode* temp = new OperatorASTNode((char*)"-", opType::Negative);
        temp->addChildNode((yyvsp[(2) - (2)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 69:
#line 515 "grammar.y"
    {
        AbstractASTNode* temp = new OperatorASTNode((char*)"!", opType::Not);
        temp->addChildNode((yyvsp[(2) - (2)].ast));
        (yyval.ast) = temp;
    ;}
    break;

  case 70:
#line 520 "grammar.y"
    {
        AbstractASTNode* op = new OperatorASTNode((char*)"&", opType::SingalAnd);
        AbstractASTNode* var = new VarASTNode((char*)(yyvsp[(2) - (2)].str));
        op->addChildNode(var);
        (yyval.ast) = op;
    ;}
    break;

  case 71:
#line 526 "grammar.y"
    {
        (yyval.ast) = new CallFunASTNode((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 72:
#line 529 "grammar.y"
    {
        (yyval.ast) = new CallFunASTNode((yyvsp[(1) - (3)].str), NULL);
    ;}
    break;

  case 73:
#line 532 "grammar.y"
    {
        (yyval.ast) = NULL;
    ;}
    break;

  case 74:
#line 535 "grammar.y"
    {
        (yyval.ast) = new VarASTNode((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 75:
#line 538 "grammar.y"
    {
        AbstractASTNode* op = new OperatorASTNode((char*)"[]", opType::GetArrayValue);
        AbstractASTNode* var = new VarASTNode((char*)(yyvsp[(1) - (4)].str));
        op->addChildNode(var);
        var->addPeerNode((yyvsp[(3) - (4)].ast));
        (yyval.ast) = op;
    ;}
    break;

  case 76:
#line 545 "grammar.y"
    {
        AbstractASTNode* op = new OperatorASTNode((char*)".", opType::GetMember);
        VarASTNode* var1 = new VarASTNode((yyvsp[(1) - (3)].str));
        VarASTNode* var2 = new VarASTNode((yyvsp[(3) - (3)].str));
        op->addChildNode(var1);
        var1->addPeerNode(var2);
        (yyval.ast) = op;
    ;}
    break;

  case 77:
#line 553 "grammar.y"
    {
        (yyval.ast) = new LiteralASTNode((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 78:
#line 556 "grammar.y"
    {
        AbstractASTNode* op = new OperatorASTNode((char*)"*", opType::GetValue);
        AbstractASTNode* var = new VarASTNode((char*)(yyvsp[(2) - (2)].str));
        op->addChildNode(var);
        (yyval.ast) = op;
    ;}
    break;

  case 79:
#line 562 "grammar.y"
    { yyerrok; ;}
    break;

  case 80:
#line 564 "grammar.y"
    {
        (yyvsp[(1) - (3)].ast)->getLastPeerNode()->addPeerNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = (yyvsp[(1) - (3)].ast);
    ;}
    break;

  case 81:
#line 568 "grammar.y"
    {
        (yyval.ast) = (yyvsp[(1) - (1)].ast);
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2306 "./output/yufa/grammar.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 573 "grammar.y"


/* 
YACC源程序的程序部分包括：
主程序 main()
错误信息执行程序 yyerror(s)
词法分析程序yylex(),可以与LEX进行整合
用户在语义动作中用到的子程序
YACC约定：
传递词法分析程序token属性值的全程变量名：yylval
生成的语法分析程序名为：yyparse();
 */

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: At line %d. %s\n", yylineno, s);
	exit(1);
}

std::string replaceExtName(char* fileName) {
    int dotIndex = 0;
    int nameLength = strlen(fileName);
    for (int i = nameLength - 1; i >= 0; i--) {
        if (fileName[i] == '.') {
            dotIndex = i;
            break;
        }
    }
    char* buf = new char[dotIndex];
    strncpy(buf, fileName, dotIndex);
    std::string rev(buf);
    rev += ".asm";
    return rev;
}

// 全局输出文件指针
FILE *lex_output_file = stdout;
FILE *ast_output_file = stdout;

int main(int argc,char* argv[])
{
    InterMediate* im;
    bool flag_print_ast = false;
    bool flag_print_ir = false;
    bool flag_print_asm = false;
    char* filename = NULL;
    if (argc == 1) {
        printf("Error! Please input file name!\n");
        printf("Usage: parser [-t] [-i] [-a] [-d]\n");
        printf("  -t  print the abstract syntax tree (AST)\n");
        printf("  -i  print IR code\n");
        printf("  -a  print asm code\n");
        printf("  -d  debug mode print all\n");
        return -1;
    } else if (argc >= 2) {
        for (int i=1; i<argc; i++) {
            if (*argv[i] != '-') {
                if (filename == NULL) filename = argv[i];
            }
            else if (strcmp(argv[i], "-t") == 0) flag_print_ast = true;
            else if (strcmp(argv[i], "-i") == 0) flag_print_ir = true;
            else if (strcmp(argv[i], "-a") == 0) flag_print_asm = true;
            else if (strcmp(argv[i], "-d") == 0) {
                flag_print_ast = true;
                flag_print_ir = true;
                flag_print_asm = true;
            }
            else printf("Invalid parameter \"%s\"\n", argv[i]);
        }
    }
    FILE* file = fopen(filename, "r");
    yyin = file;
    do {
		yyparse();
	} while(!feof(yyin));
    if (flag_print_ast) {
        root->printTree();
    }
    
    // 将语法树写入到文件
    std::string astFileName(filename);
    size_t pos = astFileName.rfind('.');
    if (pos != std::string::npos) {
        astFileName = astFileName.substr(0, pos) + ".ast";
    } else {
        astFileName += ".ast";
    }
    FILE *ast_file = fopen(astFileName.c_str(), "w");
    if (ast_file != NULL) {
        FILE *old_ast_output = ast_output_file;
        ast_output_file = ast_file;
        root->printTree();
        ast_output_file = old_ast_output;
        fclose(ast_file);
        printf("AST written to file: %s\n", astFileName.c_str());
    } else {
        printf("Error: Cannot open AST file %s for writing\n", astFileName.c_str());
    }
    im = new InterMediate((RootASTNode *)root, structTable);
    im->Generate(im->getRoot(), im->getTable());
    if (flag_print_ir) {
        im->printQuads();
    }
    // 将四元式写入到文件
    std::string irFileName(filename);
    size_t irPos = irFileName.rfind('.');
    if (irPos != std::string::npos) {
        irFileName = irFileName.substr(0, irPos) + ".ir";
    } else {
        irFileName += ".ir";
    }
    im->writeQuadsToFile(irFileName);
    
    AsmGenerator* asmgenerator = new AsmGenerator(im->getQuads(), im->getTempVars(), im->getTable(), im->getFuncTable());
    asmgenerator->generate();
    if (flag_print_asm) {
        std::cout << asmgenerator->getAsmCode();
    }

    std::string outFileName = replaceExtName(filename);
    std::ofstream outasm(outFileName);
    outasm << asmgenerator->getAsmCode();
    return 0;
}

