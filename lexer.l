%x COMMENT
%{
#include "Linux/grammar.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/trees.h"

extern char *yytext;
extern int column;
extern FILE * yyin;
extern YYSTYPE yylval;
extern FILE *lex_output_file; // 词法分析输出文件指针
extern FILE *ast_output_file; // 语法分析输出文件指针
void yyerror(const char *str);
%}
%option yylineno
D   [0-9]
L   [a-zA-Z_]
E   [Ee][+-]?{D}+
delim [ \t\n]
ws    {delim}+

%%
"/*"           { BEGIN(COMMENT) ; }
<COMMENT>"*/"  { BEGIN(INITIAL); }
<COMMENT>{ws}   {fprintf(lex_output_file, "inside commenet ws\n");}
<COMMENT>([^*]|\en)+|.
<COMMENT><<EOF>>    {fprintf(lex_output_file, "Unterminated comment\n"); return 0;}
 /* C++ comment, a common extension */
"//".*\n
"int"                             { yylval.str=strdup(yytext); fprintf(lex_output_file, "%10s %15s %15s\n", "TYPE", yytext, yytext); return(TYPE); }
"void"                            { yylval.str=strdup(yytext); fprintf(lex_output_file, "%10s %15s %15s\n", "VOID", yytext, ""); return(TYPE);}
"main"                            { yylval.str=strdup(yytext); fprintf(lex_output_file, "%10s %15s %15s\n", "ID", yytext, ""); return(ID);}
"return"                          { fprintf(lex_output_file, "%10s %15s %15s\n", "RETURN", yytext, ""); return(RETURN); }
"for"                             { fprintf(lex_output_file, "%10s %15s %15s\n", "FOR", yytext, ""); return(FOR);}
"while"                           { fprintf(lex_output_file, "%10s %15s %15s\n", "WHILE", yytext, ""); return(WHILE);}
"if"                              { fprintf(lex_output_file, "%10s %15s %15s\n", "IF", yytext, ""); return(IF); }
"else"                            { fprintf(lex_output_file, "%10s %15s %15s\n", "ELSE", yytext, ""); return(ELSE);}
"struct"                          { fprintf(lex_output_file, "%10s %15s %15s\n", "STRUCT", yytext, ""); return(STRUCT);}
";"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "SEMICOLON", yytext, ""); return(SEMI); }
","                               { fprintf(lex_output_file, "%10s %15s %15s\n", "COMMA", yytext, ""); return(COMMA); }
"="                               { fprintf(lex_output_file, "%10s %15s %15s\n", "ASSIGN", yytext, ""); return(ASSIGNOP); }
(>=)|(<=)|(==)|(!=)|<|>           { yylval.str=strdup(yytext); fprintf(lex_output_file, "%10s %15s %15s\n", "RELOP", yytext, yytext); return(RELOP); }
"+"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "ADD", yytext, ""); return(PLUS); }
"-"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "MINUS", yytext, ""); return(MINUS); }
"*"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "STAR", yytext, ""); return(STAR); }
"/"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "DIV", yytext, ""); return(DIV); }
"%"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "MOD", yytext, ""); return(MOD);}
"^"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "POWER", yytext, ""); return(POWER);}
"&&"                              { fprintf(lex_output_file, "%10s %15s %15s\n", "AND", yytext, ""); return(AND); }
"&"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "SINGALAND", yytext, ""); return(SINGALAND); }
"||"                              { fprintf(lex_output_file, "%10s %15s %15s\n", "OR", yytext, ""); return(OR); }
"!"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "NOT", yytext, ""); return(NOT); }
"("                               { fprintf(lex_output_file, "%10s %15s %15s\n", "LP", yytext, ""); return(LP); }
")"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "RP", yytext, ""); return(RP); }
"["                               { fprintf(lex_output_file, "%10s %15s %15s\n", "LB", yytext, ""); return(LB); }
"]"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "RB", yytext, ""); return(RB); }
"{"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "LBRACE", yytext, ""); return(LC); }
"}"                               { fprintf(lex_output_file, "%10s %15s %15s\n", "RBRACE", yytext, ""); return(RC); }
"."                               { fprintf(lex_output_file, "%10s %15s %15s\n", "GETMEMBER", yytext, ""); return(GETMEMBER); }
{L}({D}|{L})*                     { yylval.str=strdup(yytext); fprintf(lex_output_file, "%10s %15s %15s\n", "ID", yytext, ""); return(ID); }
{D}{L}({D}|{L})*                  { fprintf(lex_output_file, "%10s %15s %15s\n", "ERRID", yytext, ""); return (ERRID); }
[ \t\v\f\r\n]                     { }
(([1-9]|-){D}*)|0                     { yylval.str=strdup(yytext); int value = atoi(yytext); fprintf(lex_output_file, "%10s %15s %15d\n", "NUMBER", yytext, value); return(INT);}
%%
int yywrap()
{return 1;}
