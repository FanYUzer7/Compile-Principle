/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    LP = 258,
    RP = 259,
    LB = 260,
    RB = 261,
    DOTDOT = 262,
    COMMA = 263,
    COLON = 264,
    SEMI = 265,
    DOT = 266,
    PLUS = 267,
    MINUS = 268,
    MUL = 269,
    DIV_R = 270,
    LT = 271,
    LE = 272,
    NE = 273,
    GT = 274,
    GE = 275,
    ASSIGN = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    DIV = 280,
    MOD = 281,
    UNEQUAL = 282,
    EQUAL = 283,
    ARRAY = 284,
    START = 285,
    CASE = 286,
    CONST = 287,
    DO = 288,
    DOWNTO = 289,
    ELSE = 290,
    END = 291,
    FOR = 292,
    FUNCTION = 293,
    GOTO = 294,
    IF = 295,
    IN = 296,
    OF = 297,
    PACKED = 298,
    PROCEDURE = 299,
    PROGRAM = 300,
    READ = 301,
    RECORD = 302,
    REPEAT = 303,
    SET = 304,
    THEN = 305,
    TO = 306,
    TYPE = 307,
    UNTIL = 308,
    VAR = 309,
    WHILE = 310,
    WITH = 311,
    SYS_CON = 312,
    SYS_FUNCT = 313,
    SYS_PROC = 314,
    SYS_TYPE = 315,
    ID = 316,
    INTEGER = 317,
    REAL = 318,
    CHAR = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "parse.y"

    int token;
    std::string *string;
    NProgram *program;
    NProgramHead *programHead;
    NRoutine *routine;
    NRoutineHead *routineHead;
    NRoutineBody *routineBody;
    NConstPart *constPart;
    NConstExpressionList *constExpressionList;
    NConstValue *constValue;
    NTypePart *typePart;
    NTypeDefList *typeDefList;
    NTypeDefinition *typeDefinition;
    NTypeDecl *typeDecl;
    NSimpleType *simpleType;
    NArrayType *arrayType;
    NRecordType *recordType;
    NFieldDeclList *fieldDeclList;
    NFieldDecl *fieldDecl;
    NNameList *nameList;
    NVarPart *varPart;
    NVarDeclList *varDeclList;
    NVarDecl *varDecl;
    NRoutinePart *routinePart;
    NBlockDecl *blockDecl;
    NFuncDecl *funcDecl;
    NFuncHead *funcHead;
    NProcDecl *procDecl;
    NProcHead *procHead;
    NParams *params;
    NParamsDeclList *paramsDeclList;
    NParamsTypeList *paramsTypeList;
    NVarParamsList *varParamsList;
    NValParamsList *valParamsList;
    NCompStmt *compStmt;
    NStmtList *stmtList;
    NStmt *stmt;
    NNonLabStmt *nonLabStmt;
    NAssignStmt *assignStmt;
    NProcStmt *procStmt;
    NIfStmt *ifStmt;
    NRepeatStmt *repeatStmt;
    NWhileStmt *whileStmt;
    NForStmt *forStmt;
    NCaseStmt *caseStmt;
    NGotoStmt *gotoStmt;
    NExpression *expression;
    NArgsList *argsList;
    NExprList *exprList;
    NFactor *factor;
    NElseStmt *elseStmt;
    NDirection *direction;
    NCaseExprList *caseExprList;
    NCaseExpr *caseExpr;
    NExpr *expr;
    NTerm *term;
    

#line 182 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
