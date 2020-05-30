/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

        #include "node.h"
        #include <iostream>
        #define DEBUG 1
        NProgram *top; 
        extern int yylex();
        extern int line_cnt;
        extern char *yytext;
        void yyerror(const char *s) { printf("ERROR: %s at line %d: %s\n", s, line_cnt, yytext); }

#line 77 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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
#line 12 "parser.y" /* yacc.c:355  */

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

#line 241 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  259

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   144,   147,   150,   153,   156,   157,   160,
     161,   164,   165,   166,   167,   170,   171,   174,   175,   178,
     182,   183,   184,   187,   188,   189,   190,   191,   192,   193,
     196,   199,   202,   203,   205,   208,   209,   212,   213,   216,
     217,   220,   222,   223,   224,   225,   226,   228,   230,   232,
     234,   236,   237,   239,   240,   242,   243,   245,   247,   249,
     251,   253,   254,   256,   257,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   269,   270,   271,   273,   274,   275,
     276,   277,   279,   280,   281,   283,   285,   287,   289,   290,
     292,   294,   295,   297,   298,   300,   302,   303,   305,   306,
     307,   308,   309,   310,   311,   313,   314,   315,   316,   318,
     319,   320,   321,   322,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   335,   336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LP", "RP", "LB", "RB", "DOTDOT",
  "COMMA", "COLON", "SEMI", "DOT", "PLUS", "MINUS", "MUL", "DIV_R", "LT",
  "LE", "NE", "GT", "GE", "ASSIGN", "AND", "OR", "NOT", "DIV", "MOD",
  "UNEQUAL", "EQUAL", "ARRAY", "START", "CASE", "CONST", "DO", "DOWNTO",
  "ELSE", "END", "FOR", "FUNCTION", "GOTO", "IF", "IN", "OF", "PACKED",
  "PROCEDURE", "PROGRAM", "READ", "RECORD", "REPEAT", "SET", "THEN", "TO",
  "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "SYS_CON", "SYS_FUNCT",
  "SYS_PROC", "SYS_TYPE", "ID", "INTEGER", "REAL", "CHAR", "$accept",
  "program", "program_head", "routine", "sub_routine", "routine_head",
  "const_part", "const_expr_list", "const_value", "type_part",
  "type_decl_list", "type_definition", "type_decl", "simple_type_decl",
  "array_type_decl", "record_type_decl", "field_decl_list", "field_decl",
  "name_list", "var_part", "var_decl_list", "var_decl", "routine_part",
  "function_decl", "function_head", "procedure_decl", "procedure_head",
  "parameters", "para_decl_list", "para_type_list", "var_para_list",
  "val_para_list", "routine_body", "compound_stmt", "stmt_list", "stmt",
  "non_label_stmt", "assign_stmt", "proc_stmt", "if_stmt", "else_clause",
  "repeat_stmt", "while_stmt", "for_stmt", "direction", "case_stmt",
  "case_expr_list", "case_expr", "goto_stmt", "expression_list",
  "expression", "expr", "term", "factor", "args_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,   -35,    33,     8,    46,  -136,   -18,    66,    31,    40,
    -136,    84,    48,  -136,  -136,  -136,  -136,    56,    68,    57,
     104,   151,   109,    56,  -136,    79,   -14,  -136,  -136,  -136,
    -136,   136,    57,   110,  -136,    88,    96,   110,   148,  -136,
     110,   157,    26,   154,  -136,   160,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,    19,  -136,  -136,    60,    79,
    -136,   117,   118,   -14,  -136,   173,  -136,   175,  -136,   176,
     110,   110,   110,   186,    82,  -136,    25,   103,    24,  -136,
     171,  -136,    83,   110,   178,   283,   110,   110,   110,   132,
     110,   216,  -136,    79,    57,   191,    79,  -136,   194,   200,
     201,  -136,  -136,  -136,   155,    19,  -136,   217,   217,  -136,
    -136,     8,     8,  -136,   241,  -136,  -136,   110,   110,   110,
     158,   110,   110,   110,   110,   110,   110,   141,   110,   110,
     110,   110,   110,   110,   110,   110,   204,   219,   110,   204,
      87,   313,   313,   120,   264,   206,   313,  -136,   131,   218,
      81,   -26,  -136,    89,   167,    57,  -136,  -136,   222,   -36,
     220,  -136,   226,    31,   228,  -136,   153,   161,   270,  -136,
     103,   103,   103,   103,   103,   103,   233,   239,    91,  -136,
      24,    24,    24,  -136,  -136,  -136,  -136,     0,   214,  -136,
     313,  -136,  -136,   110,  -136,   110,   230,   110,  -136,     1,
     248,  -136,  -136,    19,  -136,  -136,  -136,    79,   259,    50,
    -136,   263,   265,    81,  -136,  -136,  -136,  -136,  -136,  -136,
     204,   204,  -136,  -136,  -136,  -136,   110,   204,  -136,   313,
     313,   110,   313,    57,  -136,   231,   268,   259,  -136,   -36,
      81,    81,  -136,   269,   272,   298,  -136,   313,  -136,    19,
    -136,  -136,  -136,  -136,  -136,  -136,   204,  -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     8,     0,     1,     0,     0,     0,    16,
       3,     0,     7,     2,    62,     4,    59,     0,    38,     0,
       0,     0,     0,    15,    18,     0,    46,    14,    11,    12,
      13,     0,     0,     0,    60,     0,     0,     0,     0,    62,
       0,    79,    77,     0,    67,     0,    64,    65,    66,    68,
      69,    70,    71,    72,    73,     0,    17,    36,     0,    37,
      40,     0,     0,     6,    44,     0,    45,     0,    10,     0,
       0,     0,     0,   116,   114,   118,     0,   104,   108,   113,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,    23,    24,     0,
       0,    20,    21,    22,     0,     0,    39,    52,    52,    42,
      43,     8,     8,     9,     0,   121,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,   125,     0,     0,     0,    74,    63,     0,     0,
       0,     0,    33,     0,     0,     0,    19,    35,     0,     0,
       0,    50,     0,     0,     0,   119,     0,     0,     0,   123,
     101,   100,    99,    98,   103,   102,     0,     0,     0,    92,
     105,   106,   107,   109,   112,   110,   111,     0,    84,    81,
      85,    86,    80,     0,    78,     0,     0,     0,    25,     0,
       0,    31,    32,     0,    29,    26,    41,     0,    58,     0,
      54,     0,     0,     0,    47,     5,    49,   117,   115,   122,
       0,     0,    90,    91,    89,    88,     0,     0,    82,    96,
     124,     0,    76,     0,    27,     0,     0,    57,    51,     0,
       0,     0,    48,     0,     0,     0,    83,    75,    28,     0,
      34,    53,    55,    56,    94,    93,     0,    30,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,   181,   282,  -136,  -136,   -19,  -136,
    -136,   271,  -102,  -135,  -136,  -136,  -136,   137,   -89,  -136,
    -136,   236,  -136,   238,  -136,   249,  -136,   188,  -136,    74,
    -136,  -136,   156,    -7,   281,  -131,   232,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,   143,  -136,  -136,
     -31,   183,    47,   -60,    12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,   162,   163,     9,    12,    75,    18,
      23,    24,   100,   101,   102,   103,   151,   152,    58,    26,
      59,    60,    63,    64,    65,    66,    67,   160,   209,   210,
     211,   212,    15,    44,    21,    45,    46,    47,    48,    49,
     228,    50,    51,    52,   226,    53,   178,   179,    54,   140,
     142,    77,    78,    79,   143
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      31,    16,    76,   158,   148,   188,    82,   153,   191,    85,
     201,   115,   116,    69,   233,   200,   121,   122,   207,   123,
     124,     1,    93,   137,    61,    57,     4,   125,   126,    87,
      62,    88,    94,     5,   224,    57,    99,    89,   131,   114,
       6,   121,   122,    11,   123,   124,   132,    90,    95,   133,
     134,   225,   125,   126,   238,   141,    10,   144,    27,   146,
     239,    14,   153,    28,    29,    30,    96,   127,   104,   105,
     208,   183,   184,   185,   186,   149,    27,    13,   242,    97,
      98,    28,    29,    30,    93,   118,    99,   119,   168,   243,
     244,   192,    17,   120,    94,   193,   246,   104,   203,   121,
     122,   236,   123,   124,   187,   252,   253,   190,   177,    20,
     125,   126,    19,    70,    27,   128,   129,    22,   237,    28,
      29,    30,    25,    71,   194,   258,   130,   222,   195,   166,
     167,    99,    32,   136,    72,   198,   205,    55,    27,   104,
      57,    97,    98,    28,    29,    30,    68,   257,    27,    80,
     208,    83,   176,    28,    29,    30,    16,   217,    81,   177,
      86,   195,   229,    91,   230,   218,   232,    27,    73,   195,
      92,    74,    28,    29,    30,   180,   181,   182,   107,   108,
     234,    14,    33,   111,    99,   112,   113,    34,    35,   117,
      36,    37,   135,   145,    99,   245,   150,    38,    27,    39,
     247,   154,   176,    28,    29,    30,    40,   155,    14,    33,
      41,   156,    42,    43,   248,    35,   157,    36,    37,   169,
     159,    99,    99,   189,    38,   199,    39,   197,   204,   213,
      99,   138,   206,    40,    14,    33,   214,    41,   216,    42,
      43,    35,   220,    36,    37,   165,    14,    33,   221,   227,
      38,   231,    39,    35,   235,    36,    37,   121,   122,    40,
     123,   124,    38,    41,    39,    42,    43,   104,   125,   126,
     196,    40,   240,   249,   241,    41,   219,    42,   250,   254,
     121,   122,   255,   123,   124,     8,   121,   122,   202,   123,
     124,   125,   126,   164,    56,   106,   161,   125,   126,   121,
     122,   109,   123,   124,   170,   171,   172,   173,   174,   175,
     125,   126,   110,   251,   121,   122,   139,   123,   124,   215,
      84,   223,     0,   147,     0,   125,   126,     0,     0,   121,
     122,   256,   123,   124,     0,     0,     0,     0,     0,     0,
     125,   126
};

static const yytype_int16 yycheck[] =
{
      19,     8,    33,   105,    93,   136,    37,    96,   139,    40,
      36,    71,    72,    32,    13,   150,    16,    17,    54,    19,
      20,    45,     3,    83,    38,    61,    61,    27,    28,     3,
      44,     5,    13,     0,    34,    61,    55,    11,    14,    70,
      32,    16,    17,    61,    19,    20,    22,    21,    29,    25,
      26,    51,    27,    28,     4,    86,    10,    88,    57,    90,
      10,    30,   151,    62,    63,    64,    47,    42,     8,     9,
     159,   131,   132,   133,   134,    94,    57,    11,   213,    60,
      61,    62,    63,    64,     3,     3,   105,     5,   119,   220,
     221,     4,    52,    11,    13,     8,   227,     8,     9,    16,
      17,   203,    19,    20,   135,   240,   241,   138,   127,    61,
      27,    28,    28,     3,    57,    12,    13,    61,   207,    62,
      63,    64,    54,    13,     4,   256,    23,    36,     8,   117,
     118,   150,    28,    50,    24,     4,   155,    28,    57,     8,
      61,    60,    61,    62,    63,    64,    10,   249,    57,    61,
     239,     3,    61,    62,    63,    64,   163,     4,    62,   178,
       3,     8,   193,     9,   195,     4,   197,    57,    58,     8,
      10,    61,    62,    63,    64,   128,   129,   130,    61,    61,
     199,    30,    31,    10,   203,    10,    10,    36,    37,     3,
      39,    40,    21,    61,   213,   226,     5,    46,    57,    48,
     231,     7,    61,    62,    63,    64,    55,     7,    30,    31,
      59,    10,    61,    62,   233,    37,    61,    39,    40,    61,
       3,   240,   241,     4,    46,     7,    48,    21,    61,     9,
     249,    53,    10,    55,    30,    31,    10,    59,    10,    61,
      62,    37,     9,    39,    40,     4,    30,    31,     9,    35,
      46,    21,    48,    37,     6,    39,    40,    16,    17,    55,
      19,    20,    46,    59,    48,    61,    62,     8,    27,    28,
       6,    55,     9,    42,     9,    59,     6,    61,    10,    10,
      16,    17,    10,    19,    20,     3,    16,    17,   151,    19,
      20,    27,    28,   112,    23,    59,   108,    27,    28,    16,
      17,    63,    19,    20,   121,   122,   123,   124,   125,   126,
      27,    28,    63,   239,    16,    17,    33,    19,    20,   163,
      39,   178,    -1,    91,    -1,    27,    28,    -1,    -1,    16,
      17,    33,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    66,    67,    61,     0,    32,    68,    70,    71,
      10,    61,    72,    11,    30,    97,    98,    52,    74,    28,
      61,    99,    61,    75,    76,    54,    84,    57,    62,    63,
      64,    73,    28,    31,    36,    37,    39,    40,    46,    48,
      55,    59,    61,    62,    98,   100,   101,   102,   103,   104,
     106,   107,   108,   110,   113,    28,    76,    61,    83,    85,
      86,    38,    44,    87,    88,    89,    90,    91,    10,    73,
       3,    13,    24,    58,    61,    73,   115,   116,   117,   118,
      61,    62,   115,     3,    99,   115,     3,     3,     5,    11,
      21,     9,    10,     3,    13,    29,    47,    60,    61,    73,
      77,    78,    79,    80,     8,     9,    86,    61,    61,    88,
      90,    10,    10,    10,   115,   118,   118,     3,     3,     5,
      11,    16,    17,    19,    20,    27,    28,    42,    12,    13,
      23,    14,    22,    25,    26,    21,    50,   118,    53,    33,
     114,   115,   115,   119,   115,    61,   115,   101,    83,    73,
       5,    81,    82,    83,     7,     7,    10,    61,    77,     3,
      92,    92,    69,    70,    69,     4,   119,   119,   115,    61,
     116,   116,   116,   116,   116,   116,    61,    73,   111,   112,
     117,   117,   117,   118,   118,   118,   118,   115,   100,     4,
     115,   100,     4,     8,     4,     8,     6,    21,     4,     7,
      78,    36,    82,     9,    61,    73,    10,    54,    83,    93,
      94,    95,    96,     9,    10,    97,    10,     4,     4,     6,
       9,     9,    36,   112,    34,    51,   109,    35,   105,   115,
     115,    21,   115,    13,    73,     6,    77,    83,     4,    10,
       9,     9,    78,   100,   100,   115,   100,   115,    73,    42,
      10,    94,    78,    78,    10,    10,    33,    77,   100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    68,    69,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    74,    74,    75,    75,    76,
      77,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      79,    80,    81,    81,    82,    83,    83,    84,    84,    85,
      85,    86,    87,    87,    87,    87,    87,    88,    89,    90,
      91,    92,    92,    93,    93,    94,    94,    95,    96,    97,
      98,    99,    99,   100,   100,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   102,   102,   103,   103,   103,
     103,   103,   104,   105,   105,   106,   107,   108,   109,   109,
     110,   111,   111,   112,   112,   113,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   116,   116,   116,   116,   117,
     117,   117,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     4,     2,     0,     5,
       4,     1,     1,     1,     1,     2,     0,     2,     1,     4,
       1,     1,     1,     1,     1,     3,     3,     4,     5,     3,
       6,     3,     2,     1,     4,     3,     1,     2,     0,     2,
       1,     4,     2,     2,     1,     1,     0,     4,     5,     4,
       3,     3,     0,     3,     1,     3,     3,     2,     1,     1,
       3,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     6,     5,     1,     4,     1,
       4,     4,     5,     2,     0,     4,     4,     8,     1,     1,
       5,     2,     1,     4,     4,     2,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     1,     4,     1,     4,     1,     3,
       2,     2,     4,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 141 "parser.y" /* yacc.c:1646  */
    { top = new NProgram((yyvsp[-2].programHead), (yyvsp[-1].routine)); if(DEBUG) std::cout << "program" << std::endl;}
#line 1542 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 144 "parser.y" /* yacc.c:1646  */
    {(yyval.programHead) = new NProgramHead(*(yyvsp[-1].string)); if(DEBUG) std::cout << "program_head" << std::endl;}
#line 1548 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.routine) = new NRoutine((yyvsp[-1].routineHead),(yyvsp[0].routineBody)); if(DEBUG) std::cout << "routine" << std::endl; }
#line 1554 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.routine) = new NRoutine((yyvsp[-1].routineHead),(yyvsp[0].routineBody)); if(DEBUG) std::cout << "sub_routine" << std::endl; }
#line 1560 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.routineHead) = new NRoutineHead((yyvsp[-3].constPart),(yyvsp[-2].typePart),(yyvsp[-1].varPart),(yyvsp[0].routinePart)); if(DEBUG) std::cout << "routine_head" << std::endl;}
#line 1566 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.constPart) = new NConstPart((yyvsp[0].constExpressionList)); if(DEBUG) std::cout << "const_part(1)" << std::endl;}
#line 1572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 157 "parser.y" /* yacc.c:1646  */
    {(yyval.constPart) = new NConstPart();if(DEBUG) std::cout << "const_part(2)" << std::endl;}//my
#line 1578 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-4].constExpressionList)->constList.push_back(new NConst(*(yyvsp[-3].string), (yyvsp[-1].constValue))); if(DEBUG) std::cout << "const_expr_list(1)" << std::endl; std::cout <<(yyvsp[-4].constExpressionList)->constList.size() << std::endl;}
#line 1584 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.constExpressionList) = new NConstExpressionList();  (yyval.constExpressionList)->constList.push_back(new NConst(*(yyvsp[-3].string), (yyvsp[-1].constValue))); if(DEBUG) std::cout << "const_expr_list(2)" << std::endl; std::cout <<(yyvsp[-4].constExpressionList)->constList.size() << std::endl;}
#line 1590 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.constValue) = new NConstValue(0, std::stoi(*(yyvsp[0].string))); if(DEBUG) std::cout << "const_value(1)" << std::endl;}
#line 1596 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.constValue) = new NConstValue(1, std::stod(*(yyvsp[0].string))); if(DEBUG) std::cout << "const_value(2)" << std::endl;}
#line 1602 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.constValue) = new NConstValue(2, (yyvsp[0].string)->at(0)); if(DEBUG) std::cout << "const_value(3)" << std::endl;}
#line 1608 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.constValue) = new NConstValue(3, (*(yyvsp[0].string)=="false")?0:(*(yyvsp[0].string)=="maxint")?1:2); if(DEBUG) std::cout << "const_value(4)" << std::endl;}
#line 1614 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.typePart) = new NTypePart((yyvsp[0].typeDefList)); if(DEBUG) std::cout << "type_part(1)" << std::endl;}
#line 1620 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.typePart) = new NTypePart(); if(DEBUG) std::cout << "type_part(2)" << std::endl;} //my
#line 1626 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].typeDefList)->typeDefList.push_back((yyvsp[0].typeDefinition)); if(DEBUG) std::cout << "type_decl_list(1)" << std::endl;}
#line 1632 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 175 "parser.y" /* yacc.c:1646  */
    {  (yyval.typeDefList) = new NTypeDefList(); (yyval.typeDefList)->typeDefList.push_back((yyvsp[0].typeDefinition)); if(DEBUG) std::cout << "type_decl_list(2)" << std::endl;}
#line 1638 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 178 "parser.y" /* yacc.c:1646  */
    {  (yyval.typeDefinition) = new NTypeDefinition(*(yyvsp[-3].string),(yyvsp[-1].typeDecl)); if(DEBUG) std::cout << "type_definition" << std::endl;}
#line 1644 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 182 "parser.y" /* yacc.c:1646  */
    {(yyval.typeDecl) = new NTypeDecl(0, (yyvsp[0].simpleType)); if(DEBUG) std::cout << "type_decl(1)" << std::endl;}
#line 1650 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.typeDecl) = new NTypeDecl(1, (yyvsp[0].arrayType)); if(DEBUG) std::cout << "type_decl(2)" << std::endl;}
#line 1656 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.typeDecl) = new NTypeDecl(2, (yyvsp[0].recordType)); if(DEBUG) std::cout << "type_decl(3)" << std::endl;}
#line 1662 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 187 "parser.y" /* yacc.c:1646  */
    {(yyval.simpleType) = new NSimpleType(0, (*(yyvsp[0].string)=="boolean")?0:(*(yyvsp[0].string)=="char")?1:(*(yyvsp[0].string)=="integer")?2:3); if(DEBUG) std::cout << "simple_type_decl(1)" << std::endl;}
#line 1668 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.simpleType) = new NSimpleType(1, *(yyvsp[0].string)); if(DEBUG) std::cout << "simple_type_decl(2)" << std::endl;}
#line 1674 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.simpleType) = new NSimpleType(2, (yyvsp[-1].nameList)); if(DEBUG) std::cout << "simple_type_decl(3)" << std::endl;}
#line 1680 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 190 "parser.y" /* yacc.c:1646  */
    {(yyval.simpleType) = new NSimpleType(3, (yyvsp[-2].constValue), (yyvsp[0].constValue)); if(DEBUG) std::cout << "simple_type_decl(4)" << std::endl;}
#line 1686 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 191 "parser.y" /* yacc.c:1646  */
    {(yyval.simpleType) = new NSimpleType(4, (yyvsp[-2].constValue), (yyvsp[0].constValue)); if(DEBUG) std::cout << "simple_type_decl(5)" << std::endl;}
#line 1692 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.simpleType) = new NSimpleType(5, (yyvsp[-3].constValue), (yyvsp[0].constValue)); if(DEBUG) std::cout << "simple_type_decl(6)" << std::endl;}
#line 1698 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 193 "parser.y" /* yacc.c:1646  */
    {(yyval.simpleType) = new NSimpleType(6, *(yyvsp[-2].string), *(yyvsp[0].string)); if(DEBUG) std::cout << "simple_type_decl(7)" << std::endl;}
#line 1704 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 196 "parser.y" /* yacc.c:1646  */
    {(yyval.arrayType) = new NArrayType((yyvsp[-3].simpleType), (yyvsp[0].typeDecl)); if(DEBUG) std::cout << "array_type_decl" << std::endl;}
#line 1710 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.recordType) = new NRecordType((yyvsp[-1].fieldDeclList)); if(DEBUG) std::cout << "record_type_decl" << std::endl;}
#line 1716 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].fieldDeclList)->fieldDecls.push_back((yyvsp[0].fieldDecl)); if(DEBUG) std::cout << "field_decl_list(1)" << std::endl;}
#line 1722 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.fieldDeclList) = new NFieldDeclList(); (yyval.fieldDeclList)->fieldDecls.push_back((yyvsp[0].fieldDecl)); if(DEBUG) std::cout << "field_decl_list(2)" << std::endl;}
#line 1728 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval.fieldDecl) = new NFieldDecl((yyvsp[-3].nameList), (yyvsp[-1].typeDecl)); if(DEBUG) std::cout << "field_decl" << std::endl;}
#line 1734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].nameList)->IDs.push_back(*(yyvsp[0].string)); if(DEBUG) std::cout << "name_list(1)" << std::endl;}
#line 1740 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.nameList) = new NNameList(); (yyval.nameList)->IDs.push_back(*(yyvsp[0].string)); if(DEBUG) std::cout << "name_list(2)" << std::endl;}
#line 1746 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.varPart) = new NVarPart((yyvsp[0].varDeclList)); if(DEBUG) std::cout << "var_part(1)" << std::endl;}
#line 1752 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.varPart) = new NVarPart(); if(DEBUG) std::cout << "var_part(2)" << std::endl;} //my
#line 1758 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].varDeclList)->varDecls.push_back((yyvsp[0].varDecl)); if(DEBUG) std::cout << "var_decl_list(1)" << std::endl;}
#line 1764 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.varDeclList) = new NVarDeclList();(yyval.varDeclList)->varDecls.push_back((yyvsp[0].varDecl)); if(DEBUG) std::cout << "var_decl_list(2)" << std::endl;}
#line 1770 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.varDecl) = new NVarDecl((yyvsp[-3].nameList), (yyvsp[-1].typeDecl)); if(DEBUG) std::cout << "var_decl" << std::endl;}
#line 1776 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 222 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].routinePart)->blockDecls.push_back((yyvsp[0].funcDecl)); if(DEBUG) std::cout << "routine_part(1)" << std::endl;}
#line 1782 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 223 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].routinePart)->blockDecls.push_back((yyvsp[0].procDecl)); if(DEBUG) std::cout << "routine_part(2)" << std::endl;}
#line 1788 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 224 "parser.y" /* yacc.c:1646  */
    {(yyval.routinePart) = new NRoutinePart(); (yyval.routinePart)->blockDecls.push_back((yyvsp[0].funcDecl)); if(DEBUG) std::cout << "routine_part(3)" << std::endl;}
#line 1794 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval.routinePart) = new NRoutinePart(); (yyval.routinePart)->blockDecls.push_back((yyvsp[0].procDecl)); if(DEBUG) std::cout << "routine_part(4)" << std::endl;}
#line 1800 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 226 "parser.y" /* yacc.c:1646  */
    {(yyval.routinePart) = new NRoutinePart(); if(DEBUG) std::cout << "routine_part(5)" << std::endl;}//my
#line 1806 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 228 "parser.y" /* yacc.c:1646  */
    {(yyval.funcDecl) = new NFuncDecl((yyvsp[-3].funcHead), (yyvsp[-1].routine)); if(DEBUG) std::cout << "function_decl" << std::endl;}
#line 1812 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 230 "parser.y" /* yacc.c:1646  */
    {(yyval.funcHead) = new NFuncHead(*(yyvsp[-3].string), (yyvsp[-2].params), (yyvsp[0].simpleType)); if(DEBUG) std::cout << "function_head" << std::endl;}
#line 1818 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 232 "parser.y" /* yacc.c:1646  */
    {(yyval.procDecl) = new NProcDecl((yyvsp[-3].procHead), (yyvsp[-1].routine)); if(DEBUG) std::cout << "procedure_decl" << std::endl;}
#line 1824 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 234 "parser.y" /* yacc.c:1646  */
    {(yyval.procHead) = new NProcHead(*(yyvsp[-1].string), (yyvsp[0].params)); if(DEBUG) std::cout << "procedure_head" << std::endl;}
#line 1830 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 236 "parser.y" /* yacc.c:1646  */
    {(yyval.params) = new NParams((yyvsp[-1].paramsDeclList)); if(DEBUG) std::cout << "parameters(1)" << std::endl;}
#line 1836 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 237 "parser.y" /* yacc.c:1646  */
    {if(DEBUG) std::cout << "parameters(2)" << std::endl;}
#line 1842 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 239 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].paramsDeclList)->paramsTypes.push_back((yyvsp[0].paramsTypeList)); if(DEBUG) std::cout << "para_decl_list(1)" << std::endl;}
#line 1848 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 240 "parser.y" /* yacc.c:1646  */
    {(yyval.paramsDeclList) = new NParamsDeclList(); (yyval.paramsDeclList)->paramsTypes.push_back((yyvsp[0].paramsTypeList)); if(DEBUG) std::cout << "para_decl_list(2)" << std::endl;}
#line 1854 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 242 "parser.y" /* yacc.c:1646  */
    {(yyval.paramsTypeList) = new NParamsTypeList(0, (yyvsp[-2].varParamsList), (yyvsp[0].simpleType)); if(DEBUG) std::cout << "para_type_list(1)" << std::endl;}
#line 1860 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.paramsTypeList) = new NParamsTypeList(1, (yyvsp[-2].valParamsList), (yyvsp[0].simpleType)); if(DEBUG) std::cout << "para_type_list(2)" << std::endl;}
#line 1866 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 245 "parser.y" /* yacc.c:1646  */
    {(yyval.varParamsList) = new NVarParamsList((yyvsp[0].nameList)); if(DEBUG) std::cout << "var_para_list" << std::endl;}
#line 1872 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval.valParamsList) = new NValParamsList((yyvsp[0].nameList)); if(DEBUG) std::cout << "val_para_list" << std::endl;}
#line 1878 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 249 "parser.y" /* yacc.c:1646  */
    {(yyval.routineBody) = new NRoutineBody((yyvsp[0].compStmt)); if(DEBUG) std::cout << "routine_body" << std::endl;}
#line 1884 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 251 "parser.y" /* yacc.c:1646  */
    {(yyval.compStmt) = new NCompStmt((yyvsp[-1].stmtList)); if(DEBUG) std::cout << "compound_stmt" << std::endl;}
#line 1890 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].stmtList)->stmts.push_back((yyvsp[-1].stmt)); if(DEBUG) std::cout << "stmt_list(1)" << std::endl;}
#line 1896 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 254 "parser.y" /* yacc.c:1646  */
    {(yyval.stmtList) = new NStmtList(); if(DEBUG) std::cout << "stmt_list(2)" << std::endl;}
#line 1902 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 256 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt) = new NStmt(0, std::stoi(*(yyvsp[-2].string)), (yyvsp[0].nonLabStmt)); if(DEBUG) std::cout << "stmt(1)" << std::endl;}
#line 1908 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt) = new NStmt(1, (yyvsp[0].nonLabStmt)); if(DEBUG) std::cout << "stmt(2)" << std::endl;}
#line 1914 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 259 "parser.y" /* yacc.c:1646  */
    {(yyval.nonLabStmt) = new NNonLabStmt(0, (yyvsp[0].assignStmt)); if(DEBUG) std::cout << "non_label_stmt(1)" << std::endl;}
#line 1920 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.nonLabStmt) = new NNonLabStmt(1, (yyvsp[0].procStmt)); if(DEBUG) std::cout << "non_label_stmt(2)" << std::endl;}
#line 1926 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 261 "parser.y" /* yacc.c:1646  */
    {(yyval.nonLabStmt) = new NNonLabStmt(2, (yyvsp[0].compStmt)); if(DEBUG) std::cout << "non_label_stmt(3)" << std::endl;}
#line 1932 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyval.nonLabStmt) = new NNonLabStmt(3, (yyvsp[0].ifStmt)); if(DEBUG) std::cout << "non_label_stmt(4)" << std::endl;}
#line 1938 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 263 "parser.y" /* yacc.c:1646  */
    {(yyval.nonLabStmt) = new NNonLabStmt(4, (yyvsp[0].repeatStmt)); if(DEBUG) std::cout << "non_label_stmt(5)" << std::endl;}
#line 1944 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 264 "parser.y" /* yacc.c:1646  */
    {(yyval.nonLabStmt) = new NNonLabStmt(5, (yyvsp[0].whileStmt)); if(DEBUG) std::cout << "non_label_stmt(6)" << std::endl;}
#line 1950 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.nonLabStmt) = new NNonLabStmt(6, (yyvsp[0].forStmt)); if(DEBUG) std::cout << "non_label_stmt(7)" << std::endl;}
#line 1956 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 266 "parser.y" /* yacc.c:1646  */
    {(yyval.nonLabStmt) = new NNonLabStmt(7, (yyvsp[0].caseStmt)); if(DEBUG) std::cout << "non_label_stmt(8)" << std::endl;}
#line 1962 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 267 "parser.y" /* yacc.c:1646  */
    {(yyval.nonLabStmt) = new NNonLabStmt(8, (yyvsp[0].gotoStmt)); if(DEBUG) std::cout << "non_label_stmt(9)" << std::endl;}
#line 1968 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 269 "parser.y" /* yacc.c:1646  */
    {(yyval.assignStmt) = new NAssignStmt(0, *(yyvsp[-2].string), (yyvsp[0].expression)); if(DEBUG) std::cout << "assign_stmt(1)" << std::endl;}
#line 1974 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.assignStmt) = new NAssignStmt(1, *(yyvsp[-5].string), (yyvsp[-3].expression), (yyvsp[0].expression)); if(DEBUG) std::cout << "assign_stmt(2)" << std::endl;}
#line 1980 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 271 "parser.y" /* yacc.c:1646  */
    {(yyval.assignStmt) = new NAssignStmt(0, *(yyvsp[-4].string), *(yyvsp[-2].string), (yyvsp[0].expression)); if(DEBUG) std::cout << "assign_stmt(3)" << std::endl;}
#line 1986 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.procStmt) = new NProcStmt(0, *(yyvsp[0].string)); if(DEBUG) std::cout << "proc_stmt(1)" << std::endl;}
#line 1992 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.procStmt) = new NProcStmt(1, *(yyvsp[-3].string), (yyvsp[-1].argsList)); if(DEBUG) std::cout << "proc_stmt(2)" << std::endl;}
#line 1998 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.procStmt) = new NProcStmt(2, (*(yyvsp[0].string)=="write")?0:1); if(DEBUG) std::cout << "proc_stmt(3)" << std::endl;}
#line 2004 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.procStmt) = new NProcStmt(3, (*(yyvsp[-3].string)=="write")?0:1, (yyvsp[-1].exprList)); if(DEBUG) std::cout << "proc_stmt(4)" << std::endl;}
#line 2010 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.procStmt) = new NProcStmt(4, (yyvsp[-1].factor)); if(DEBUG) std::cout << "proc_stmt(5)" << std::endl;}
#line 2016 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 279 "parser.y" /* yacc.c:1646  */
    {(yyval.ifStmt) = new NIfStmt((yyvsp[-3].expression), (yyvsp[-1].stmt), (yyvsp[0].elseStmt)); if(DEBUG) std::cout << "if_stmt" << std::endl;}
#line 2022 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 280 "parser.y" /* yacc.c:1646  */
    {(yyval.elseStmt) = new NElseStmt((yyvsp[0].stmt)); if(DEBUG) std::cout << "else_clause(1)" << std::endl;}
#line 2028 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 281 "parser.y" /* yacc.c:1646  */
    {if(DEBUG) std::cout << "else_clause(2)" << std::endl;}
#line 2034 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyval.repeatStmt) = new NRepeatStmt((yyvsp[-2].stmtList), (yyvsp[0].expression)); if(DEBUG) std::cout << "repeat_stmt" << std::endl;}
#line 2040 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 285 "parser.y" /* yacc.c:1646  */
    {(yyval.whileStmt) = new NWhileStmt((yyvsp[-2].expression), (yyvsp[0].stmt)); if(DEBUG) std::cout << "while_stmt" << std::endl;}
#line 2046 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 287 "parser.y" /* yacc.c:1646  */
    {(yyval.forStmt) = new NForStmt(*(yyvsp[-6].string), (yyvsp[-4].expression), (yyvsp[-3].direction), (yyvsp[-2].expression), (yyvsp[0].stmt)); if(DEBUG) std::cout << "for_stmt" << std::endl;}
#line 2052 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 289 "parser.y" /* yacc.c:1646  */
    {(yyval.direction) = new NDirection(0); if(DEBUG) std::cout << "direction(1)" << std::endl;}
#line 2058 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 290 "parser.y" /* yacc.c:1646  */
    {(yyval.direction) = new NDirection(1); if(DEBUG) std::cout << "direction(2)" << std::endl;}
#line 2064 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.caseStmt) = new NCaseStmt((yyvsp[-3].expression), (yyvsp[-1].caseExprList)); if(DEBUG) std::cout << "case_stmt" << std::endl;}
#line 2070 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 294 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].caseExprList)->caseExprs.push_back((yyvsp[0].caseExpr)); if(DEBUG) std::cout << "case_expr_list(1)" << std::endl;}
#line 2076 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 295 "parser.y" /* yacc.c:1646  */
    {(yyval.caseExprList) = new NCaseExprList(); (yyval.caseExprList)->caseExprs.push_back((yyvsp[0].caseExpr)); if(DEBUG) std::cout << "case_expr_list(2)" << std::endl;}
#line 2082 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.caseExpr) = new NCaseExpr(0, (yyvsp[-3].constValue), (yyvsp[-1].stmt)); if(DEBUG) std::cout << "case_expr(1)" << std::endl;}
#line 2088 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.caseExpr) = new NCaseExpr(1, *(yyvsp[-3].string), (yyvsp[-1].stmt)); if(DEBUG) std::cout << "case_expr(2)" << std::endl;}
#line 2094 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 300 "parser.y" /* yacc.c:1646  */
    {(yyval.gotoStmt) = new NGotoStmt(std::stoi(*(yyvsp[0].string))); if(DEBUG) std::cout << "goto_stmt" << std::endl;}
#line 2100 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 302 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].exprList)->expressions.push_back((yyvsp[0].expression)); if(DEBUG) std::cout << "expression_list(1)" << std::endl;}
#line 2106 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 303 "parser.y" /* yacc.c:1646  */
    {(yyval.exprList) = new NExprList(); (yyval.exprList)->expressions.push_back((yyvsp[0].expression)); if(DEBUG) std::cout << "expression_list(2)" << std::endl;}
#line 2112 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 305 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(0); if(DEBUG) std::cout << "expression(1)" << std::endl;}
#line 2118 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 306 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(1); if(DEBUG) std::cout << "expression(2)" << std::endl;}
#line 2124 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 307 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(2); if(DEBUG) std::cout << "expression(3)" << std::endl;}
#line 2130 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 308 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(3); if(DEBUG) std::cout << "expression(4)" << std::endl;}
#line 2136 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(4); if(DEBUG) std::cout << "expression(5)" << std::endl;}
#line 2142 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 310 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(5); if(DEBUG) std::cout << "expression(6)" << std::endl;}
#line 2148 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 311 "parser.y" /* yacc.c:1646  */
    {(yyval.expression) = new NExpression(); (yyval.expression)->exprs.push_back((yyvsp[0].expr)); (yyval.expression)->types.push_back(6); if(DEBUG) std::cout << "expression(7)" << std::endl;}
#line 2154 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 313 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].expr)->terms.push_back((yyvsp[0].term)); (yyvsp[-2].expr)->types.push_back(0); if(DEBUG) std::cout << "expr(1)" << std::endl;}
#line 2160 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 314 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].expr)->terms.push_back((yyvsp[0].term)); (yyvsp[-2].expr)->types.push_back(1); if(DEBUG) std::cout << "expr(2)" << std::endl;}
#line 2166 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 315 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].expr)->terms.push_back((yyvsp[0].term)); (yyvsp[-2].expr)->types.push_back(2); if(DEBUG) std::cout << "expr(3)" << std::endl;}
#line 2172 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 316 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new NExpr(); (yyval.expr)->terms.push_back((yyvsp[0].term)); (yyval.expr)->types.push_back(3); if(DEBUG) std::cout << "expr(4)" << std::endl;}
#line 2178 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 318 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].term)->factors.push_back((yyvsp[0].factor)); (yyvsp[-2].term)->types.push_back(0); if(DEBUG) std::cout << "term(1)" << std::endl;}
#line 2184 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 319 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].term)->factors.push_back((yyvsp[0].factor)); (yyvsp[-2].term)->types.push_back(1); if(DEBUG) std::cout << "term(2)" << std::endl;}
#line 2190 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 320 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].term)->factors.push_back((yyvsp[0].factor)); (yyvsp[-2].term)->types.push_back(2); if(DEBUG) std::cout << "term(3)" << std::endl;}
#line 2196 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 321 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].term)->factors.push_back((yyvsp[0].factor)); (yyvsp[-2].term)->types.push_back(3); if(DEBUG) std::cout << "term(4)" << std::endl;}
#line 2202 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 322 "parser.y" /* yacc.c:1646  */
    {(yyval.term) = new NTerm(); (yyval.term)->factors.push_back((yyvsp[0].factor)); (yyval.term)->types.push_back(4); if(DEBUG) std::cout << "term(5)" << std::endl;}
#line 2208 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 324 "parser.y" /* yacc.c:1646  */
    {(yyval.factor) = new NFactor(0, *(yyvsp[0].string)); if(DEBUG) std::cout << "factor(1)" << std::endl;}
#line 2214 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 325 "parser.y" /* yacc.c:1646  */
    {(yyval.factor) = new NFactor(1, *(yyvsp[-3].string), (yyvsp[-1].argsList)); if(DEBUG) std::cout << "factor(2)" << std::endl;}
#line 2220 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 326 "parser.y" /* yacc.c:1646  */
    {(yyval.factor) = new NFactor(2, (*(yyvsp[0].string))=="abs"?0:(*(yyvsp[0].string))=="chr"?1:(*(yyvsp[0].string))=="odd"?2:(*(yyvsp[0].string))=="ord"?3:(*(yyvsp[0].string))=="pred"?4:(*(yyvsp[0].string))=="sqr"?5:(*(yyvsp[0].string))=="sqrt"?6:7); if(DEBUG) std::cout << "factor(3)" << std::endl;}
#line 2226 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 327 "parser.y" /* yacc.c:1646  */
    {(yyval.factor) = new NFactor(3, (*(yyvsp[-3].string))=="abs"?0:(*(yyvsp[-3].string))=="chr"?1:(*(yyvsp[-3].string))=="odd"?2:(*(yyvsp[-3].string))=="ord"?3:(*(yyvsp[-3].string))=="pred"?4:(*(yyvsp[-3].string))=="sqr"?5:(*(yyvsp[-3].string))=="sqrt"?6:7, (yyvsp[-1].argsList)); if(DEBUG) std::cout << "factor(4)" << std::endl;}
#line 2232 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 328 "parser.y" /* yacc.c:1646  */
    {(yyval.factor) = new NFactor(4, (yyvsp[0].constValue)); if(DEBUG) std::cout << "factor(5)" << std::endl;}
#line 2238 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 329 "parser.y" /* yacc.c:1646  */
    {(yyval.factor) = new NFactor(5, (yyvsp[-1].expression)); if(DEBUG) std::cout << "factor(6)" << std::endl;}
#line 2244 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 330 "parser.y" /* yacc.c:1646  */
    {(yyval.factor) = new NFactor(6, (yyvsp[0].factor)); if(DEBUG) std::cout << "factor(7)" << std::endl;}
#line 2250 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 331 "parser.y" /* yacc.c:1646  */
    {(yyval.factor) = new NFactor(7, (yyvsp[0].factor)); if(DEBUG) std::cout << "factor(8)" << std::endl;}
#line 2256 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 332 "parser.y" /* yacc.c:1646  */
    {(yyval.factor) = new NFactor(8, *(yyvsp[-3].string), (yyvsp[-1].expression)); if(DEBUG) std::cout << "factor(9)" << std::endl;}
#line 2262 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 333 "parser.y" /* yacc.c:1646  */
    {(yyval.factor) = new NFactor(9, *(yyvsp[-2].string), *(yyvsp[0].string)); if(DEBUG) std::cout << "factor(10)" << std::endl;}
#line 2268 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 335 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].argsList)->expressions.push_back((yyvsp[0].expression)); if(DEBUG) std::cout << "args_list(1)" << std::endl;}
#line 2274 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 336 "parser.y" /* yacc.c:1646  */
    {(yyval.argsList) = new NArgsList(); (yyval.argsList)->expressions.push_back((yyvsp[0].expression)); if(DEBUG) std::cout << "args_list(2)" << std::endl;}
#line 2280 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2284 "parser.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 339 "parser.y" /* yacc.c:1906  */



