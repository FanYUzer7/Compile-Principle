/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parse.y"

        #include "node.hpp"
        #include <iostream>
        #include <fstream>
        #define MAXBLOCKS 50
        #define DEBUG 1
        NProgram *top; 
        extern int yylex();
        //extern int line_cnt;
        extern char *yytext;
        extern int lastblock;
        extern int blocknumber;       	/* Number of current block being compiled */
        extern int contblock[MAXBLOCKS];  /* Containing block for each block (the outer block of this block)        */
        std::ofstream treeNode("struct.txt");
        void yyerror(const char *s) { printf("ERROR: %s at line %d: %s\n", s, line_cnt, yytext); }

#line 87 "parser.cpp"

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
    

#line 255 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   333

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260

#define YYUNDEFTOK  2
#define YYMAXUTOK   319

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
       0,   144,   144,   146,   148,   150,   152,   154,   155,   157,
     158,   160,   161,   162,   163,   165,   166,   168,   169,   171,
     173,   174,   175,   177,   178,   179,   180,   181,   182,   183,
     185,   187,   189,   190,   192,   194,   195,   197,   198,   200,
     201,   203,   205,   206,   207,   208,   209,   211,   213,   215,
     217,   219,   220,   222,   223,   225,   226,   228,   230,   232,
     234,   236,   238,   239,   241,   242,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   254,   255,   256,   258,   259,
     260,   261,   262,   264,   266,   267,   269,   271,   273,   275,
     276,   278,   280,   281,   283,   284,   286,   288,   289,   291,
     292,   293,   294,   295,   296,   297,   299,   300,   301,   302,
     304,   305,   306,   307,   308,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   321,   322
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
  "val_para_list", "routine_body", "compound_stmt", "NULLPART",
  "stmt_list", "stmt", "non_label_stmt", "assign_stmt", "proc_stmt",
  "if_stmt", "else_clause", "repeat_stmt", "while_stmt", "for_stmt",
  "direction", "case_stmt", "case_expr_list", "case_expr", "goto_stmt",
  "expression_list", "expression", "expr", "term", "factor", "args_list", YY_NULLPTR
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

#define YYPACT_NINF -147

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-147)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,   -49,    27,     7,    37,  -147,   -11,    44,    30,     5,
    -147,    34,     6,  -147,  -147,  -147,  -147,     9,    25,   262,
      56,  -147,    59,     9,  -147,    46,    61,  -147,  -147,  -147,
    -147,   108,   262,   110,    11,  -147,  -147,    93,    46,  -147,
      50,    60,    61,  -147,   117,  -147,   132,  -147,   134,    19,
    -147,    73,    92,    19,   161,  -147,    19,   164,   140,   169,
    -147,   174,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,    46,   262,   187,    46,  -147,   194,   196,   203,  -147,
    -147,  -147,   133,    11,  -147,   214,   214,  -147,  -147,     7,
       7,  -147,    19,    19,    19,   217,    43,  -147,    14,    13,
     186,  -147,   201,  -147,   103,    19,   143,   256,    19,    19,
      19,   170,    19,   184,  -147,    96,   226,    75,   -17,  -147,
     220,   183,   262,  -147,  -147,   239,   -38,   237,  -147,   244,
      30,   250,   231,  -147,  -147,    19,    19,    19,   200,    19,
      19,    19,    19,    19,    19,   254,    19,    19,    19,    19,
      19,    19,    19,    19,   179,   258,    19,   179,   120,   286,
     286,   125,   236,   245,   286,  -147,  -147,    53,   259,  -147,
    -147,    11,  -147,  -147,  -147,    46,   261,    87,  -147,   265,
     268,    75,  -147,  -147,  -147,  -147,   151,   189,   251,  -147,
      13,    13,    13,    13,    13,    13,   272,   273,   124,  -147,
     186,   186,   186,  -147,  -147,  -147,  -147,     1,   266,  -147,
     286,  -147,  -147,    19,  -147,    19,   264,    19,   262,  -147,
     238,   276,   261,  -147,   -38,    75,    75,  -147,  -147,  -147,
    -147,   179,   179,  -147,  -147,  -147,  -147,    19,   179,  -147,
     286,   286,    19,   286,  -147,    11,  -147,  -147,  -147,  -147,
     290,   297,   271,  -147,   286,  -147,  -147,  -147,   179,  -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     8,     0,     1,     0,     0,     0,    16,
       3,     0,     7,     2,    61,     4,    59,     0,    38,     0,
       0,    63,     0,    15,    18,     0,    46,    14,    11,    12,
      13,     0,     0,     0,     0,    17,    36,     0,    37,    40,
       0,     0,     6,    44,     0,    45,     0,    10,     0,     0,
      60,     0,     0,     0,     0,    63,     0,    80,    78,     0,
      68,     0,    65,    66,    67,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,    23,    24,     0,     0,    20,
      21,    22,     0,     0,    39,    52,    52,    42,    43,     8,
       8,     9,     0,     0,     0,   117,   115,   119,     0,   105,
     109,   114,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,    33,
       0,     0,     0,    19,    35,     0,     0,     0,    50,     0,
       0,     0,     0,   122,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
     126,     0,     0,     0,    75,    64,    25,     0,     0,    31,
      32,     0,    29,    26,    41,     0,    58,     0,    54,     0,
       0,     0,    47,     5,    49,   120,     0,     0,     0,   124,
     102,   101,   100,    99,   104,   103,     0,     0,     0,    93,
     106,   107,   108,   110,   113,   111,   112,     0,    85,    82,
      86,    87,    81,     0,    79,     0,     0,     0,     0,    27,
       0,     0,    57,    51,     0,     0,     0,    48,   118,   116,
     123,     0,     0,    91,    92,    90,    89,     0,     0,    83,
      97,   125,     0,    77,    28,     0,    34,    53,    55,    56,
       0,     0,     0,    84,    76,    30,    95,    94,     0,    88
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,  -147,   218,   306,  -147,  -147,   -19,  -147,
    -147,   287,   -82,  -112,  -147,  -147,  -147,   202,   -67,  -147,
    -147,   274,  -147,   279,  -147,   280,  -147,   241,  -147,    99,
    -147,  -147,   198,    -5,  -147,   275,  -146,   216,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,   135,  -147,
    -147,   -47,   153,    29,   -56,   101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,   129,   130,     9,    12,    97,    18,
      23,    24,    78,    79,    80,    81,   118,   119,    37,    26,
      38,    39,    42,    43,    44,    45,    46,   127,   177,   178,
     179,   180,    15,    60,    21,    33,    61,    62,    63,    64,
      65,   239,    66,    67,    68,   237,    69,   198,   199,    70,
     158,   160,    99,   100,   101,   161
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      31,   125,    98,    16,   115,   168,   104,   120,   208,   107,
       1,   211,     4,    48,    71,    77,   175,   139,   140,   169,
     141,   142,    92,    36,    72,   146,   147,     5,   143,   144,
     139,   140,    93,   141,   142,   235,   148,   133,   134,     6,
      73,   143,   144,    94,    36,   132,   136,    10,   137,   155,
      11,   120,   236,   116,   138,    13,   145,    17,    74,   176,
      14,   159,    19,   162,    77,   164,   218,    20,    27,   227,
      22,    75,    76,    28,    29,    30,    27,    95,    71,    25,
      96,    28,    29,    30,    32,   250,   251,    34,    72,   221,
     188,   223,   253,   203,   204,   205,   206,   224,    77,    40,
     166,    82,    83,   173,    82,    41,   207,    36,   222,   210,
      27,    85,   259,   248,   249,    28,    29,    30,    47,   139,
     140,    86,   141,   142,   212,    16,   197,    89,   213,   214,
     143,   144,    27,   215,   102,    75,    76,    28,    29,    30,
      14,    49,    90,   109,    91,   110,    50,    51,   219,    52,
      53,   111,    77,   154,   103,   228,    54,   176,    55,   215,
     233,   112,    77,   255,   105,    56,   240,   108,   241,    57,
     243,    58,    59,    14,    49,   200,   201,   202,   113,   197,
      51,    27,    52,    53,   114,   196,    28,    29,    30,    54,
     252,    55,   117,   229,   124,   254,   156,   215,    56,   244,
     149,   121,    57,   122,    58,    59,    77,    77,   150,    14,
      49,   151,   152,   123,    14,    49,    51,   126,    52,    53,
     135,    51,   153,    52,    53,    54,    77,    55,    82,   171,
      54,   163,    55,   167,    56,   185,   186,   187,    57,    56,
      58,    59,   216,    57,   172,    58,   181,   139,   140,   174,
     141,   142,   139,   140,   182,   141,   142,   230,   143,   144,
     184,   189,   209,   143,   144,   220,   217,   139,   140,    82,
     141,   142,   139,   140,   225,   141,   142,   226,   143,   144,
     245,   231,   232,   143,   144,   242,   246,   139,   140,   157,
     141,   142,   190,   191,   192,   193,   194,   195,   143,   144,
     256,   238,   139,   140,   258,   141,   142,   257,   131,     8,
      35,    27,    84,   143,   144,   196,    28,    29,    30,    27,
     170,    87,    88,   247,    28,    29,    30,   128,   183,   165,
     106,     0,     0,   234
};

static const yytype_int16 yycheck[] =
{
      19,    83,    49,     8,    71,   117,    53,    74,   154,    56,
      45,   157,    61,    32,     3,    34,    54,    16,    17,    36,
      19,    20,     3,    61,    13,    12,    13,     0,    27,    28,
      16,    17,    13,    19,    20,    34,    23,    93,    94,    32,
      29,    27,    28,    24,    61,    92,     3,    10,     5,   105,
      61,   118,    51,    72,    11,    11,    42,    52,    47,   126,
      30,   108,    28,   110,    83,   112,    13,    61,    57,   181,
      61,    60,    61,    62,    63,    64,    57,    58,     3,    54,
      61,    62,    63,    64,    28,   231,   232,    28,    13,   171,
     137,     4,   238,   149,   150,   151,   152,    10,   117,    38,
       4,     8,     9,   122,     8,    44,   153,    61,   175,   156,
      57,    61,   258,   225,   226,    62,    63,    64,    10,    16,
      17,    61,    19,    20,     4,   130,   145,    10,     8,     4,
      27,    28,    57,     8,    61,    60,    61,    62,    63,    64,
      30,    31,    10,     3,    10,     5,    36,    37,   167,    39,
      40,    11,   171,    50,    62,     4,    46,   224,    48,     8,
      36,    21,   181,   245,     3,    55,   213,     3,   215,    59,
     217,    61,    62,    30,    31,   146,   147,   148,     9,   198,
      37,    57,    39,    40,    10,    61,    62,    63,    64,    46,
     237,    48,     5,     4,    61,   242,    53,     8,    55,   218,
      14,     7,    59,     7,    61,    62,   225,   226,    22,    30,
      31,    25,    26,    10,    30,    31,    37,     3,    39,    40,
       3,    37,    21,    39,    40,    46,   245,    48,     8,     9,
      46,    61,    48,     7,    55,     4,   135,   136,    59,    55,
      61,    62,     6,    59,    61,    61,     9,    16,    17,    10,
      19,    20,    16,    17,    10,    19,    20,     6,    27,    28,
      10,    61,     4,    27,    28,     6,    21,    16,    17,     8,
      19,    20,    16,    17,     9,    19,    20,     9,    27,    28,
      42,     9,     9,    27,    28,    21,    10,    16,    17,    33,
      19,    20,   139,   140,   141,   142,   143,   144,    27,    28,
      10,    35,    16,    17,    33,    19,    20,    10,    90,     3,
      23,    57,    38,    27,    28,    61,    62,    63,    64,    57,
     118,    42,    42,   224,    62,    63,    64,    86,   130,   113,
      55,    -1,    -1,   198
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    66,    67,    61,     0,    32,    68,    70,    71,
      10,    61,    72,    11,    30,    97,    98,    52,    74,    28,
      61,    99,    61,    75,    76,    54,    84,    57,    62,    63,
      64,    73,    28,   100,    28,    76,    61,    83,    85,    86,
      38,    44,    87,    88,    89,    90,    91,    10,    73,    31,
      36,    37,    39,    40,    46,    48,    55,    59,    61,    62,
      98,   101,   102,   103,   104,   105,   107,   108,   109,   111,
     114,     3,    13,    29,    47,    60,    61,    73,    77,    78,
      79,    80,     8,     9,    86,    61,    61,    88,    90,    10,
      10,    10,     3,    13,    24,    58,    61,    73,   116,   117,
     118,   119,    61,    62,   116,     3,   100,   116,     3,     3,
       5,    11,    21,     9,    10,    83,    73,     5,    81,    82,
      83,     7,     7,    10,    61,    77,     3,    92,    92,    69,
      70,    69,   116,   119,   119,     3,     3,     5,    11,    16,
      17,    19,    20,    27,    28,    42,    12,    13,    23,    14,
      22,    25,    26,    21,    50,   119,    53,    33,   115,   116,
     116,   120,   116,    61,   116,   102,     4,     7,    78,    36,
      82,     9,    61,    73,    10,    54,    83,    93,    94,    95,
      96,     9,    10,    97,    10,     4,   120,   120,   116,    61,
     117,   117,   117,   117,   117,   117,    61,    73,   112,   113,
     118,   118,   118,   119,   119,   119,   119,   116,   101,     4,
     116,   101,     4,     8,     4,     8,     6,    21,    13,    73,
       6,    77,    83,     4,    10,     9,     9,    78,     4,     4,
       6,     9,     9,    36,   113,    34,    51,   110,    35,   106,
     116,   116,    21,   116,    73,    42,    10,    94,    78,    78,
     101,   101,   116,   101,   116,    77,    10,    10,    33,   101
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
      98,    99,   100,   100,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   103,   103,   103,   104,   104,
     104,   104,   104,   105,   106,   106,   107,   108,   109,   110,
     110,   111,   112,   112,   113,   113,   114,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   117,   117,   117,   117,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   120,   120
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
       4,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     6,     5,     1,     4,
       1,     4,     4,     5,     2,     0,     4,     4,     8,     1,
       1,     5,     2,     1,     4,     4,     2,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     1,     4,     1,     4,     1,
       3,     2,     2,     4,     3,     3,     1
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
  YYUSE (yytype);
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
  unsigned long yylno = yyrline[yyrule];
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

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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
#line 144 "parse.y"
    {if(DEBUG) treeNode << "program" << std::endl; top = new NProgram((yyvsp[-2].programHead),(yyvsp[-1].routine));}
#line 1553 "parser.cpp"
    break;

  case 3:
#line 146 "parse.y"
    {if(DEBUG) treeNode << "program_head" << std::endl; (yyval.programHead) = new NProgramHead(*(yyvsp[-1].string));}
#line 1559 "parser.cpp"
    break;

  case 4:
#line 148 "parse.y"
    { if(DEBUG) treeNode << "routine" << std::endl; (yyval.routine) = new NRoutine((yyvsp[-1].routineHead),(yyvsp[0].routineBody));}
#line 1565 "parser.cpp"
    break;

  case 5:
#line 150 "parse.y"
    {if(DEBUG) treeNode << "sub_routine" << std::endl; (yyval.routine) = new NRoutine((yyvsp[-1].routineHead),(yyvsp[0].routineBody)); }
#line 1571 "parser.cpp"
    break;

  case 6:
#line 152 "parse.y"
    {if(DEBUG) treeNode << "routine_head" << std::endl; (yyval.routineHead) = new NRoutineHead((yyvsp[-3].constPart),(yyvsp[-2].typePart),(yyvsp[-1].varPart),(yyvsp[0].routinePart)); }
#line 1577 "parser.cpp"
    break;

  case 7:
#line 154 "parse.y"
    {if(DEBUG) treeNode << "const_part(1)" << std::endl; (yyval.constPart) = new NConstPart((yyvsp[0].constExpressionList));}
#line 1583 "parser.cpp"
    break;

  case 8:
#line 155 "parse.y"
    {if(DEBUG) treeNode << "const_part(2)" << std::endl; (yyval.constPart) = new NConstPart();}
#line 1589 "parser.cpp"
    break;

  case 9:
#line 157 "parse.y"
    {if(DEBUG) treeNode << "const_expr_list(1)" << std::endl; (yyvsp[-4].constExpressionList)->constList.push_back(new NConst(*(yyvsp[-3].string), (yyvsp[-1].constValue))); }
#line 1595 "parser.cpp"
    break;

  case 10:
#line 158 "parse.y"
    {if(DEBUG) treeNode << "const_expr_list(2)" << std::endl; (yyval.constExpressionList) = new NConstExpressionList();  (yyval.constExpressionList)->constList.push_back(new NConst(*(yyvsp[-3].string), (yyvsp[-1].constValue))); }
#line 1601 "parser.cpp"
    break;

  case 11:
#line 160 "parse.y"
    {if(DEBUG) treeNode << "const_value(1)" << std::endl; (yyval.constValue) = new NConstValue(0, std::stoi(*(yyvsp[0].string))); }
#line 1607 "parser.cpp"
    break;

  case 12:
#line 161 "parse.y"
    {if(DEBUG) treeNode << "const_value(2)" << std::endl; (yyval.constValue) = new NConstValue(1, std::stod(*(yyvsp[0].string))); }
#line 1613 "parser.cpp"
    break;

  case 13:
#line 162 "parse.y"
    {if(DEBUG) treeNode << "const_value(3)" << std::endl; (yyval.constValue) = new NConstValue(2, (yyvsp[0].string)->at(0)); }
#line 1619 "parser.cpp"
    break;

  case 14:
#line 163 "parse.y"
    {if(DEBUG) treeNode << "const_value(4)" << std::endl; (yyval.constValue) = new NConstValue(3, (*(yyvsp[0].string)=="false")?0:(*(yyvsp[0].string)=="maxint")?1:2); }
#line 1625 "parser.cpp"
    break;

  case 15:
#line 165 "parse.y"
    {if(DEBUG) treeNode << "type_part(1)" << std::endl; (yyval.typePart) = new NTypePart((yyvsp[0].typeDefList)); }
#line 1631 "parser.cpp"
    break;

  case 16:
#line 166 "parse.y"
    {if(DEBUG) treeNode << "type_part(2)" << std::endl; (yyval.typePart) = new NTypePart();}
#line 1637 "parser.cpp"
    break;

  case 17:
#line 168 "parse.y"
    {if(DEBUG) treeNode << "type_decl_list(1)" << std::endl; (yyvsp[-1].typeDefList)->typeDefList.push_back((yyvsp[0].typeDefinition)); }
#line 1643 "parser.cpp"
    break;

  case 18:
#line 169 "parse.y"
    { if(DEBUG) treeNode << "type_decl_list(2)" << std::endl; (yyval.typeDefList) = new NTypeDefList(); (yyval.typeDefList)->typeDefList.push_back((yyvsp[0].typeDefinition)); }
#line 1649 "parser.cpp"
    break;

  case 19:
#line 171 "parse.y"
    {if(DEBUG) treeNode << "type_definition" << std::endl; (yyval.typeDefinition) = new NTypeDefinition(*(yyvsp[-3].string),(yyvsp[-1].typeDecl));}
#line 1655 "parser.cpp"
    break;

  case 20:
#line 173 "parse.y"
    {if(DEBUG) treeNode << "type_decl(1)" << std::endl; (yyval.typeDecl) = new NTypeDecl(0, (yyvsp[0].simpleType)); }
#line 1661 "parser.cpp"
    break;

  case 21:
#line 174 "parse.y"
    {if(DEBUG) treeNode << "type_decl(2)" << std::endl; (yyval.typeDecl) = new NTypeDecl(1, (yyvsp[0].arrayType)); }
#line 1667 "parser.cpp"
    break;

  case 22:
#line 175 "parse.y"
    {if(DEBUG) treeNode << "type_decl(3)" << std::endl; (yyval.typeDecl) = new NTypeDecl(2, (yyvsp[0].recordType)); }
#line 1673 "parser.cpp"
    break;

  case 23:
#line 177 "parse.y"
    {if(DEBUG) treeNode << "simple_type_decl(1)" << std::endl; (yyval.simpleType) = new NSimpleType(0, (*(yyvsp[0].string)=="boolean")?0:(*(yyvsp[0].string)=="char")?1:(*(yyvsp[0].string)=="integer")?2:3); }
#line 1679 "parser.cpp"
    break;

  case 24:
#line 178 "parse.y"
    {if(DEBUG) treeNode << "simple_type_decl(2)" << std::endl; (yyval.simpleType) = new NSimpleType(1, *(yyvsp[0].string)); }
#line 1685 "parser.cpp"
    break;

  case 25:
#line 179 "parse.y"
    {if(DEBUG) treeNode << "simple_type_decl(3)" << std::endl; (yyval.simpleType) = new NSimpleType(2, (yyvsp[-1].nameList)); }
#line 1691 "parser.cpp"
    break;

  case 26:
#line 180 "parse.y"
    {if(DEBUG) treeNode << "simple_type_decl(4)" << std::endl; (yyval.simpleType) = new NSimpleType(3, (yyvsp[-2].constValue), (yyvsp[0].constValue)); }
#line 1697 "parser.cpp"
    break;

  case 27:
#line 181 "parse.y"
    {if(DEBUG) treeNode << "simple_type_decl(5)" << std::endl; (yyval.simpleType) = new NSimpleType(4, (yyvsp[-2].constValue), (yyvsp[0].constValue)); }
#line 1703 "parser.cpp"
    break;

  case 28:
#line 182 "parse.y"
    {if(DEBUG) treeNode << "simple_type_decl(6)" << std::endl; (yyval.simpleType) = new NSimpleType(5, (yyvsp[-3].constValue), (yyvsp[0].constValue)); }
#line 1709 "parser.cpp"
    break;

  case 29:
#line 183 "parse.y"
    {if(DEBUG) treeNode << "simple_type_decl(7)" << std::endl; (yyval.simpleType) = new NSimpleType(6, *(yyvsp[-2].string), *(yyvsp[0].string)); }
#line 1715 "parser.cpp"
    break;

  case 30:
#line 185 "parse.y"
    {if(DEBUG) treeNode << "array_type_decl" << std::endl; (yyval.arrayType) = new NArrayType((yyvsp[-3].simpleType), (yyvsp[0].typeDecl)); }
#line 1721 "parser.cpp"
    break;

  case 31:
#line 187 "parse.y"
    {if(DEBUG) treeNode << "record_type_decl" << std::endl; (yyval.recordType) = new NRecordType((yyvsp[-1].fieldDeclList)); }
#line 1727 "parser.cpp"
    break;

  case 32:
#line 189 "parse.y"
    {if(DEBUG) treeNode << "field_decl_list(1)" << std::endl; (yyvsp[-1].fieldDeclList)->fieldDecls.push_back((yyvsp[0].fieldDecl)); }
#line 1733 "parser.cpp"
    break;

  case 33:
#line 190 "parse.y"
    {if(DEBUG) treeNode << "field_decl_list(2)" << std::endl; (yyval.fieldDeclList) = new NFieldDeclList(); (yyval.fieldDeclList)->fieldDecls.push_back((yyvsp[0].fieldDecl)); }
#line 1739 "parser.cpp"
    break;

  case 34:
#line 192 "parse.y"
    {if(DEBUG) treeNode << "field_decl" << std::endl; (yyval.fieldDecl) = new NFieldDecl((yyvsp[-3].nameList), (yyvsp[-1].typeDecl)); }
#line 1745 "parser.cpp"
    break;

  case 35:
#line 194 "parse.y"
    {if(DEBUG) treeNode << "name_list(1)" << std::endl; (yyvsp[-2].nameList)->IDs.push_back(*(yyvsp[0].string)); }
#line 1751 "parser.cpp"
    break;

  case 36:
#line 195 "parse.y"
    {if(DEBUG) treeNode << "name_list(2)" << std::endl; (yyval.nameList) = new NNameList(); (yyval.nameList)->IDs.push_back(*(yyvsp[0].string)); }
#line 1757 "parser.cpp"
    break;

  case 37:
#line 197 "parse.y"
    {if(DEBUG) treeNode << "var_part(1)" << std::endl; (yyval.varPart) = new NVarPart((yyvsp[0].varDeclList)); }
#line 1763 "parser.cpp"
    break;

  case 38:
#line 198 "parse.y"
    {if(DEBUG) treeNode << "var_part(2)" << std::endl; (yyval.varPart) = new NVarPart();}
#line 1769 "parser.cpp"
    break;

  case 39:
#line 200 "parse.y"
    {if(DEBUG) treeNode << "var_decl_list(1)" << std::endl; (yyvsp[-1].varDeclList)->varDecls.push_back((yyvsp[0].varDecl)); }
#line 1775 "parser.cpp"
    break;

  case 40:
#line 201 "parse.y"
    {if(DEBUG) treeNode << "var_decl_list(2)" << std::endl; (yyval.varDeclList) = new NVarDeclList();(yyval.varDeclList)->varDecls.push_back((yyvsp[0].varDecl)); }
#line 1781 "parser.cpp"
    break;

  case 41:
#line 203 "parse.y"
    {if(DEBUG) treeNode << "var_decl" << std::endl; (yyval.varDecl) = new NVarDecl((yyvsp[-3].nameList), (yyvsp[-1].typeDecl));}
#line 1787 "parser.cpp"
    break;

  case 42:
#line 205 "parse.y"
    {if(DEBUG) treeNode << "routine_part(1)" << std::endl; (yyvsp[-1].routinePart)->blockDecls.push_back((yyvsp[0].funcDecl));}
#line 1793 "parser.cpp"
    break;

  case 43:
#line 206 "parse.y"
    {if(DEBUG) treeNode << "routine_part(2)" << std::endl; (yyvsp[-1].routinePart)->blockDecls.push_back((yyvsp[0].procDecl)); }
#line 1799 "parser.cpp"
    break;

  case 44:
#line 207 "parse.y"
    {if(DEBUG) treeNode << "routine_part(3)" << std::endl; (yyval.routinePart) = new NRoutinePart(); (yyval.routinePart)->blockDecls.push_back((yyvsp[0].funcDecl));}
#line 1805 "parser.cpp"
    break;

  case 45:
#line 208 "parse.y"
    {if(DEBUG) treeNode << "routine_part(4)" << std::endl; (yyval.routinePart) = new NRoutinePart(); (yyval.routinePart)->blockDecls.push_back((yyvsp[0].procDecl)); }
#line 1811 "parser.cpp"
    break;

  case 46:
#line 209 "parse.y"
    {if(DEBUG) treeNode << "routine_part(5)" << std::endl; (yyval.routinePart) = new NRoutinePart();}
#line 1817 "parser.cpp"
    break;

  case 47:
#line 211 "parse.y"
    {if(DEBUG) treeNode << "function_decl" << std::endl; (yyval.funcDecl) = new NFuncDecl((yyvsp[-3].funcHead), (yyvsp[-1].routine)); }
#line 1823 "parser.cpp"
    break;

  case 48:
#line 213 "parse.y"
    {if(DEBUG) treeNode << "function_head" << std::endl; (yyval.funcHead) = new NFuncHead(*(yyvsp[-3].string), (yyvsp[-2].params), (yyvsp[0].simpleType)); }
#line 1829 "parser.cpp"
    break;

  case 49:
#line 215 "parse.y"
    {if(DEBUG) treeNode << "procedure_decl" << std::endl; (yyval.procDecl) = new NProcDecl((yyvsp[-3].procHead), (yyvsp[-1].routine)); }
#line 1835 "parser.cpp"
    break;

  case 50:
#line 217 "parse.y"
    {if(DEBUG) treeNode << "procedure_head" << std::endl; (yyval.procHead) = new NProcHead(*(yyvsp[-1].string), (yyvsp[0].params)); }
#line 1841 "parser.cpp"
    break;

  case 51:
#line 219 "parse.y"
    {if(DEBUG) treeNode << "parameters(1)" << std::endl; (yyval.params) = new NParams((yyvsp[-1].paramsDeclList)); }
#line 1847 "parser.cpp"
    break;

  case 52:
#line 220 "parse.y"
    {if(DEBUG) treeNode << "parameters(2)" << std::endl; (yyval.params) = new NParams();}
#line 1853 "parser.cpp"
    break;

  case 53:
#line 222 "parse.y"
    {if(DEBUG) treeNode << "para_decl_list(1)" << std::endl; (yyvsp[-2].paramsDeclList)->paramsTypes.push_back((yyvsp[0].paramsTypeList)); }
#line 1859 "parser.cpp"
    break;

  case 54:
#line 223 "parse.y"
    {if(DEBUG) treeNode << "para_decl_list(2)" << std::endl; (yyval.paramsDeclList) = new NParamsDeclList(); (yyval.paramsDeclList)->paramsTypes.push_back((yyvsp[0].paramsTypeList)); }
#line 1865 "parser.cpp"
    break;

  case 55:
#line 225 "parse.y"
    {if(DEBUG) treeNode << "para_type_list(1)" << std::endl; (yyval.paramsTypeList) = new NParamsTypeList(0, (yyvsp[-2].varParamsList), (yyvsp[0].simpleType)); }
#line 1871 "parser.cpp"
    break;

  case 56:
#line 226 "parse.y"
    {if(DEBUG) treeNode << "para_type_list(2)" << std::endl; (yyval.paramsTypeList) = new NParamsTypeList(1, (yyvsp[-2].valParamsList), (yyvsp[0].simpleType)); }
#line 1877 "parser.cpp"
    break;

  case 57:
#line 228 "parse.y"
    {if(DEBUG) treeNode << "var_para_list" << std::endl; (yyval.varParamsList) = new NVarParamsList((yyvsp[0].nameList)); }
#line 1883 "parser.cpp"
    break;

  case 58:
#line 230 "parse.y"
    {if(DEBUG) treeNode << "val_para_list" << std::endl; (yyval.valParamsList) = new NValParamsList((yyvsp[0].nameList)); }
#line 1889 "parser.cpp"
    break;

  case 59:
#line 232 "parse.y"
    {if(DEBUG) treeNode << "routine_body" << std::endl; (yyval.routineBody) = new NRoutineBody((yyvsp[0].compStmt)); }
#line 1895 "parser.cpp"
    break;

  case 60:
#line 234 "parse.y"
    {if(DEBUG) treeNode << "compound_stmt" << std::endl; (yyval.compStmt) = new NCompStmt((yyvsp[-1].stmtList)); lastblock=contblock[blocknumber]; }
#line 1901 "parser.cpp"
    break;

  case 61:
#line 236 "parse.y"
    {blocknumber++; contblock[blocknumber]=lastblock; lastblock=blocknumber;}
#line 1907 "parser.cpp"
    break;

  case 62:
#line 238 "parse.y"
    {if(DEBUG) treeNode << "stmt_list(1)" << std::endl; (yyvsp[-2].stmtList)->stmts.push_back((yyvsp[-1].stmt)); }
#line 1913 "parser.cpp"
    break;

  case 63:
#line 239 "parse.y"
    {if(DEBUG) treeNode << "stmt_list(2)" << std::endl; (yyval.stmtList) = new NStmtList(); }
#line 1919 "parser.cpp"
    break;

  case 64:
#line 241 "parse.y"
    {if(DEBUG) treeNode << "stmt(1)" << std::endl; (yyval.stmt) = new NStmt(0, std::stoi(*(yyvsp[-2].string)), (yyvsp[0].nonLabStmt)); }
#line 1925 "parser.cpp"
    break;

  case 65:
#line 242 "parse.y"
    {if(DEBUG) treeNode << "stmt(2)" << std::endl; (yyval.stmt) = new NStmt(1, (yyvsp[0].nonLabStmt)); }
#line 1931 "parser.cpp"
    break;

  case 66:
#line 244 "parse.y"
    {if(DEBUG) treeNode << "non_label_stmt(1)" << std::endl; (yyval.nonLabStmt) = new NNonLabStmt(0, (yyvsp[0].assignStmt)); }
#line 1937 "parser.cpp"
    break;

  case 67:
#line 245 "parse.y"
    {if(DEBUG) treeNode << "non_label_stmt(2)" << std::endl; (yyval.nonLabStmt) = new NNonLabStmt(1, (yyvsp[0].procStmt)); }
#line 1943 "parser.cpp"
    break;

  case 68:
#line 246 "parse.y"
    {if(DEBUG) treeNode << "non_label_stmt(3)" << std::endl; (yyval.nonLabStmt) = new NNonLabStmt(2, (yyvsp[0].compStmt)); }
#line 1949 "parser.cpp"
    break;

  case 69:
#line 247 "parse.y"
    {if(DEBUG) treeNode << "non_label_stmt(4)" << std::endl; (yyval.nonLabStmt) = new NNonLabStmt(3, (yyvsp[0].ifStmt)); }
#line 1955 "parser.cpp"
    break;

  case 70:
#line 248 "parse.y"
    {if(DEBUG) treeNode << "non_label_stmt(5)" << std::endl; (yyval.nonLabStmt) = new NNonLabStmt(4, (yyvsp[0].repeatStmt)); }
#line 1961 "parser.cpp"
    break;

  case 71:
#line 249 "parse.y"
    {if(DEBUG) treeNode << "non_label_stmt(6)" << std::endl; (yyval.nonLabStmt) = new NNonLabStmt(5, (yyvsp[0].whileStmt)); }
#line 1967 "parser.cpp"
    break;

  case 72:
#line 250 "parse.y"
    {if(DEBUG) treeNode << "non_label_stmt(7)" << std::endl; (yyval.nonLabStmt) = new NNonLabStmt(6, (yyvsp[0].forStmt)); }
#line 1973 "parser.cpp"
    break;

  case 73:
#line 251 "parse.y"
    {if(DEBUG) treeNode << "non_label_stmt(8)" << std::endl; (yyval.nonLabStmt) = new NNonLabStmt(7, (yyvsp[0].caseStmt)); }
#line 1979 "parser.cpp"
    break;

  case 74:
#line 252 "parse.y"
    {if(DEBUG) treeNode << "non_label_stmt(9)" << std::endl; (yyval.nonLabStmt) = new NNonLabStmt(8, (yyvsp[0].gotoStmt)); }
#line 1985 "parser.cpp"
    break;

  case 75:
#line 254 "parse.y"
    {if(DEBUG) treeNode << "assign_stmt(1)" << std::endl; (yyval.assignStmt) = new NAssignStmt(0, *(yyvsp[-2].string), (yyvsp[0].expression)); }
#line 1991 "parser.cpp"
    break;

  case 76:
#line 255 "parse.y"
    {if(DEBUG) treeNode << "assign_stmt(2)" << std::endl; (yyval.assignStmt) = new NAssignStmt(1, *(yyvsp[-5].string), (yyvsp[-3].expression), (yyvsp[0].expression)); }
#line 1997 "parser.cpp"
    break;

  case 77:
#line 256 "parse.y"
    {if(DEBUG) treeNode << "assign_stmt(3)" << std::endl; (yyval.assignStmt) = new NAssignStmt(0, *(yyvsp[-4].string), *(yyvsp[-2].string), (yyvsp[0].expression)); }
#line 2003 "parser.cpp"
    break;

  case 78:
#line 258 "parse.y"
    {if(DEBUG) treeNode << "proc_stmt(1)" << std::endl; (yyval.procStmt) = new NProcStmt(0, *(yyvsp[0].string)); }
#line 2009 "parser.cpp"
    break;

  case 79:
#line 259 "parse.y"
    {if(DEBUG) treeNode << "proc_stmt(2)" << std::endl; (yyval.procStmt) = new NProcStmt(1, *(yyvsp[-3].string), (yyvsp[-1].argsList)); }
#line 2015 "parser.cpp"
    break;

  case 80:
#line 260 "parse.y"
    {if(DEBUG) treeNode << "proc_stmt(3)" << std::endl; (yyval.procStmt) = new NProcStmt(2, (*(yyvsp[0].string)=="write")?0:1); }
#line 2021 "parser.cpp"
    break;

  case 81:
#line 261 "parse.y"
    {if(DEBUG) treeNode << "proc_stmt(4)" << std::endl; (yyval.procStmt) = new NProcStmt(3, (*(yyvsp[-3].string)=="write")?0:1, (yyvsp[-1].exprList)); }
#line 2027 "parser.cpp"
    break;

  case 82:
#line 262 "parse.y"
    {if(DEBUG) treeNode << "proc_stmt(5)" << std::endl; (yyval.procStmt) = new NProcStmt(4, (yyvsp[-1].factor)); }
#line 2033 "parser.cpp"
    break;

  case 83:
#line 264 "parse.y"
    {if(DEBUG) treeNode << "if_stmt" << std::endl; (yyval.ifStmt) = new NIfStmt((yyvsp[-3].expression), (yyvsp[-1].stmt), (yyvsp[0].elseStmt)); }
#line 2039 "parser.cpp"
    break;

  case 84:
#line 266 "parse.y"
    {if(DEBUG) treeNode << "else_clause(1)" << std::endl; (yyval.elseStmt) = new NElseStmt((yyvsp[0].stmt)); }
#line 2045 "parser.cpp"
    break;

  case 85:
#line 267 "parse.y"
    {if(DEBUG) treeNode << "else_clause(2)" << std::endl; (yyval.elseStmt) = new NElseStmt();}
#line 2051 "parser.cpp"
    break;

  case 86:
#line 269 "parse.y"
    {if(DEBUG) treeNode << "repeat_stmt" << std::endl; (yyval.repeatStmt) = new NRepeatStmt((yyvsp[-2].stmtList), (yyvsp[0].expression)); }
#line 2057 "parser.cpp"
    break;

  case 87:
#line 271 "parse.y"
    {if(DEBUG) treeNode << "while_stmt" << std::endl; (yyval.whileStmt) = new NWhileStmt((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2063 "parser.cpp"
    break;

  case 88:
#line 273 "parse.y"
    {if(DEBUG) treeNode << "for_stmt" << std::endl; (yyval.forStmt) = new NForStmt(*(yyvsp[-6].string), (yyvsp[-4].expression), (yyvsp[-3].direction), (yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2069 "parser.cpp"
    break;

  case 89:
#line 275 "parse.y"
    {if(DEBUG) treeNode << "direction(1)" << std::endl; (yyval.direction) = new NDirection(0); }
#line 2075 "parser.cpp"
    break;

  case 90:
#line 276 "parse.y"
    {if(DEBUG) treeNode << "direction(2)" << std::endl; (yyval.direction) = new NDirection(1); }
#line 2081 "parser.cpp"
    break;

  case 91:
#line 278 "parse.y"
    {if(DEBUG) treeNode << "case_stmt" << std::endl; (yyval.caseStmt) = new NCaseStmt((yyvsp[-3].expression), (yyvsp[-1].caseExprList)); }
#line 2087 "parser.cpp"
    break;

  case 92:
#line 280 "parse.y"
    {if(DEBUG) treeNode << "case_expr_list(1)" << std::endl; (yyvsp[-1].caseExprList)->caseExprs.push_back((yyvsp[0].caseExpr)); }
#line 2093 "parser.cpp"
    break;

  case 93:
#line 281 "parse.y"
    {if(DEBUG) treeNode << "case_expr_list(2)" << std::endl; (yyval.caseExprList) = new NCaseExprList(); (yyval.caseExprList)->caseExprs.push_back((yyvsp[0].caseExpr)); }
#line 2099 "parser.cpp"
    break;

  case 94:
#line 283 "parse.y"
    {if(DEBUG) treeNode << "case_expr(1)" << std::endl; (yyval.caseExpr) = new NCaseExpr(0, (yyvsp[-3].constValue), (yyvsp[-1].stmt)); }
#line 2105 "parser.cpp"
    break;

  case 95:
#line 284 "parse.y"
    {if(DEBUG) treeNode << "case_expr(2)" << std::endl; (yyval.caseExpr) = new NCaseExpr(1, *(yyvsp[-3].string), (yyvsp[-1].stmt)); }
#line 2111 "parser.cpp"
    break;

  case 96:
#line 286 "parse.y"
    {if(DEBUG) treeNode << "goto_stmt" << std::endl; (yyval.gotoStmt) = new NGotoStmt(std::stoi(*(yyvsp[0].string))); }
#line 2117 "parser.cpp"
    break;

  case 97:
#line 288 "parse.y"
    {if(DEBUG) treeNode << "expression_list(1)" << std::endl; (yyvsp[-2].exprList)->expressions.push_back((yyvsp[0].expression)); }
#line 2123 "parser.cpp"
    break;

  case 98:
#line 289 "parse.y"
    {if(DEBUG) treeNode << "expression_list(2)" << std::endl; (yyval.exprList) = new NExprList(); (yyval.exprList)->expressions.push_back((yyvsp[0].expression)); }
#line 2129 "parser.cpp"
    break;

  case 99:
#line 291 "parse.y"
    {if(DEBUG) treeNode << "expression(1)" << std::endl; (yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(0); }
#line 2135 "parser.cpp"
    break;

  case 100:
#line 292 "parse.y"
    {if(DEBUG) treeNode << "expression(2)" << std::endl; (yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(1); }
#line 2141 "parser.cpp"
    break;

  case 101:
#line 293 "parse.y"
    {if(DEBUG) treeNode << "expression(3)" << std::endl; (yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(2); }
#line 2147 "parser.cpp"
    break;

  case 102:
#line 294 "parse.y"
    {if(DEBUG) treeNode << "expression(4)" << std::endl; (yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(3); }
#line 2153 "parser.cpp"
    break;

  case 103:
#line 295 "parse.y"
    {if(DEBUG) treeNode << "expression(5)" << std::endl; (yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(4); }
#line 2159 "parser.cpp"
    break;

  case 104:
#line 296 "parse.y"
    {if(DEBUG) treeNode << "expression(6)" << std::endl; (yyvsp[-2].expression)->exprs.push_back((yyvsp[0].expr)); (yyvsp[-2].expression)->types.push_back(5); }
#line 2165 "parser.cpp"
    break;

  case 105:
#line 297 "parse.y"
    {if(DEBUG) treeNode << "expression(7)" << std::endl; (yyval.expression) = new NExpression(); (yyval.expression)->exprs.push_back((yyvsp[0].expr)); (yyval.expression)->types.push_back(6); }
#line 2171 "parser.cpp"
    break;

  case 106:
#line 299 "parse.y"
    {if(DEBUG) treeNode << "expr(1)" << std::endl; (yyvsp[-2].expr)->terms.push_back((yyvsp[0].term)); (yyvsp[-2].expr)->types.push_back(0); }
#line 2177 "parser.cpp"
    break;

  case 107:
#line 300 "parse.y"
    {if(DEBUG) treeNode << "expr(2)" << std::endl; (yyvsp[-2].expr)->terms.push_back((yyvsp[0].term)); (yyvsp[-2].expr)->types.push_back(1); }
#line 2183 "parser.cpp"
    break;

  case 108:
#line 301 "parse.y"
    {if(DEBUG) treeNode << "expr(3)" << std::endl; (yyvsp[-2].expr)->terms.push_back((yyvsp[0].term)); (yyvsp[-2].expr)->types.push_back(2); }
#line 2189 "parser.cpp"
    break;

  case 109:
#line 302 "parse.y"
    {if(DEBUG) treeNode << "expr(4)" << std::endl; (yyval.expr) = new NExpr(); (yyval.expr)->terms.push_back((yyvsp[0].term)); (yyval.expr)->types.push_back(3); }
#line 2195 "parser.cpp"
    break;

  case 110:
#line 304 "parse.y"
    {if(DEBUG) treeNode << "term(1)" << std::endl; (yyvsp[-2].term)->factors.push_back((yyvsp[0].factor)); (yyvsp[-2].term)->types.push_back(0); }
#line 2201 "parser.cpp"
    break;

  case 111:
#line 305 "parse.y"
    {if(DEBUG) treeNode << "term(2)" << std::endl; (yyvsp[-2].term)->factors.push_back((yyvsp[0].factor)); (yyvsp[-2].term)->types.push_back(1); }
#line 2207 "parser.cpp"
    break;

  case 112:
#line 306 "parse.y"
    {if(DEBUG) treeNode << "term(3)" << std::endl; (yyvsp[-2].term)->factors.push_back((yyvsp[0].factor)); (yyvsp[-2].term)->types.push_back(2); }
#line 2213 "parser.cpp"
    break;

  case 113:
#line 307 "parse.y"
    {if(DEBUG) treeNode << "term(4)" << std::endl; (yyvsp[-2].term)->factors.push_back((yyvsp[0].factor)); (yyvsp[-2].term)->types.push_back(3); }
#line 2219 "parser.cpp"
    break;

  case 114:
#line 308 "parse.y"
    {if(DEBUG) treeNode << "term(5)" << std::endl;(yyval.term) = new NTerm(); (yyval.term)->factors.push_back((yyvsp[0].factor)); (yyval.term)->types.push_back(4); }
#line 2225 "parser.cpp"
    break;

  case 115:
#line 310 "parse.y"
    {if(DEBUG) treeNode << "factor(1)" << std::endl; (yyval.factor) = new NFactor(0, *(yyvsp[0].string)); }
#line 2231 "parser.cpp"
    break;

  case 116:
#line 311 "parse.y"
    {if(DEBUG) treeNode << "factor(2)" << std::endl; (yyval.factor) = new NFactor(1, *(yyvsp[-3].string), (yyvsp[-1].argsList)); }
#line 2237 "parser.cpp"
    break;

  case 117:
#line 312 "parse.y"
    {if(DEBUG) treeNode << "factor(3)" << std::endl; (yyval.factor) = new NFactor(2, (*(yyvsp[0].string))=="abs"?0:(*(yyvsp[0].string))=="chr"?1:(*(yyvsp[0].string))=="odd"?2:(*(yyvsp[0].string))=="ord"?3:(*(yyvsp[0].string))=="pred"?4:(*(yyvsp[0].string))=="sqr"?5:(*(yyvsp[0].string))=="sqrt"?6:7); }
#line 2243 "parser.cpp"
    break;

  case 118:
#line 313 "parse.y"
    {if(DEBUG) treeNode << "factor(4)" << std::endl; (yyval.factor) = new NFactor(3, (*(yyvsp[-3].string))=="abs"?0:(*(yyvsp[-3].string))=="chr"?1:(*(yyvsp[-3].string))=="odd"?2:(*(yyvsp[-3].string))=="ord"?3:(*(yyvsp[-3].string))=="pred"?4:(*(yyvsp[-3].string))=="sqr"?5:(*(yyvsp[-3].string))=="sqrt"?6:7, (yyvsp[-1].argsList)); }
#line 2249 "parser.cpp"
    break;

  case 119:
#line 314 "parse.y"
    {if(DEBUG) treeNode << "factor(5)" << std::endl; (yyval.factor) = new NFactor(4, (yyvsp[0].constValue)); }
#line 2255 "parser.cpp"
    break;

  case 120:
#line 315 "parse.y"
    {if(DEBUG) treeNode << "factor(6)" << std::endl; (yyval.factor) = new NFactor(5, (yyvsp[-1].expression)); }
#line 2261 "parser.cpp"
    break;

  case 121:
#line 316 "parse.y"
    {if(DEBUG) treeNode << "factor(7)" << std::endl; (yyval.factor) = new NFactor(6, (yyvsp[0].factor)); }
#line 2267 "parser.cpp"
    break;

  case 122:
#line 317 "parse.y"
    {if(DEBUG) treeNode << "factor(8)" << std::endl; (yyval.factor) = new NFactor(7, (yyvsp[0].factor)); }
#line 2273 "parser.cpp"
    break;

  case 123:
#line 318 "parse.y"
    {if(DEBUG) treeNode << "factor(9)" << std::endl; (yyval.factor) = new NFactor(8, *(yyvsp[-3].string), (yyvsp[-1].expression)); }
#line 2279 "parser.cpp"
    break;

  case 124:
#line 319 "parse.y"
    {if(DEBUG) treeNode << "factor(10)" << std::endl; (yyval.factor) = new NFactor(9, *(yyvsp[-2].string), *(yyvsp[0].string)); }
#line 2285 "parser.cpp"
    break;

  case 125:
#line 321 "parse.y"
    {if(DEBUG) treeNode << "args_list(1)" << std::endl; (yyvsp[-2].argsList)->expressions.push_back((yyvsp[0].expression)); }
#line 2291 "parser.cpp"
    break;

  case 126:
#line 322 "parse.y"
    {if(DEBUG) treeNode << "args_list(2)" << std::endl; (yyval.argsList) = new NArgsList(); (yyval.argsList)->expressions.push_back((yyvsp[0].expression)); }
#line 2297 "parser.cpp"
    break;


#line 2301 "parser.cpp"

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
#line 324 "parse.y"
