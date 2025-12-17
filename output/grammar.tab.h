#include "common/trees.h"
/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 67 "grammar.y"
{
	AbstractASTNode* ast;
    char* str;
}
/* Line 1529 of yacc.c.  */
#line 122 "./output/grammar.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;
