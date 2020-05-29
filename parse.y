%{
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
%}

%union {
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
    }


%token <token> LP RP LB RB DOTDOT COMMA COLON SEMI
%token <token> DOT PLUS MINUS MUL DIV_R LT LE NE GT GE ASSIGN
%token <token> AND OR NOT DIV MOD UNEQUAL EQUAL
%token <token> ARRAY START CASE CONST DO DOWNTO ELSE END FOR FUNCTION GOTO
%token <token> IF IN OF PACKED PROCEDURE PROGRAM READ RECORD REPEAT SET THEN
%token <token> TO TYPE UNTIL VAR WHILE WITH
%token <string> SYS_CON SYS_FUNCT SYS_PROC SYS_TYPE ID INTEGER REAL CHAR

%type <program> program
%type <programHead> program_head
%type <routine> routine sub_routine
%type <routineHead> routine_head
%type <routineBody> routine_body
%type <constPart> const_part
%type <constExpressionList> const_expr_list
%type <constValue> const_value
%type <typePart> type_part
%type <typeDefList> type_decl_list
%type <typeDefinition> type_definition
%type <typeDecl> type_decl
%type <simpleType> simple_type_decl
%type <arrayType> array_type_decl
%type <recordType> record_type_decl
%type <fieldDeclList> field_decl_list 
%type <fieldDecl> field_decl
%type <nameList> name_list
%type <varPart> var_part
%type <varDeclList> var_decl_list
%type <varDecl> var_decl
%type <routinePart> routine_part
%type <funcDecl> function_decl
%type <funcHead> function_head
%type <procDecl> procedure_decl
%type <procHead> procedure_head
%type <params> parameters
%type <paramsDeclList> para_decl_list
%type <paramsTypeList> para_type_list
%type <varParamsList> var_para_list
%type <valParamsList> val_para_list
%type <compStmt> compound_stmt
%type <stmtList> stmt_list
%type <stmt> stmt
%type <nonLabStmt> non_label_stmt
%type <assignStmt> assign_stmt
%type <procStmt> proc_stmt
%type <ifStmt> if_stmt
%type <repeatStmt> repeat_stmt
%type <whileStmt> while_stmt
%type <forStmt> for_stmt
%type <caseStmt> case_stmt
%type <gotoStmt> goto_stmt
%type <expression> expression
%type <argsList> args_list
%type <exprList> expression_list
%type <factor> factor
%type <elseStmt> else_clause
%type <direction> direction
%type <caseExprList> case_expr_list
%type <caseExpr> case_expr
%type <expr> expr
%type <term> term

%start program

%%

program : program_head  routine  DOT{if(DEBUG) treeNode << "program" << std::endl; top = new NProgram($1,$2);};

program_head : PROGRAM  ID  SEMI{if(DEBUG) treeNode << "program_head" << std::endl; $$ = new NProgramHead(*$2);};

routine : routine_head  routine_body{ if(DEBUG) treeNode << "routine" << std::endl; $$ = new NRoutine($1,$2);};

sub_routine : routine_head  routine_body{if(DEBUG) treeNode << "sub_routine" << std::endl; $$ = new NRoutine($1,$2); };

routine_head : const_part  type_part  var_part  routine_part{if(DEBUG) treeNode << "routine_head" << std::endl; $$ = new NRoutineHead($1,$2,$3,$4); };

const_part : CONST  const_expr_list{if(DEBUG) treeNode << "const_part(1)" << std::endl; $$ = new NConstPart($2);}
            |{if(DEBUG) treeNode << "const_part(2)" << std::endl; $$ = new NConstPart();};

const_expr_list :const_expr_list  ID  EQUAL  const_value  SEMI{if(DEBUG) treeNode << "const_expr_list(1)" << std::endl; $1->constList.push_back(new NConst(*$2, $4)); }
                |  ID  EQUAL  const_value  SEMI{if(DEBUG) treeNode << "const_expr_list(2)" << std::endl; $$ = new NConstExpressionList();  $$->constList.push_back(new NConst(*$1, $3)); };

const_value :INTEGER{if(DEBUG) treeNode << "const_value(1)" << std::endl; $$ = new NConstValue(0, std::stoi(*$1)); }
          |  REAL{if(DEBUG) treeNode << "const_value(2)" << std::endl; $$ = new NConstValue(1, std::stod(*$1)); }
          |  CHAR{if(DEBUG) treeNode << "const_value(3)" << std::endl; $$ = new NConstValue(2, $1->at(0)); }
          |  SYS_CON{if(DEBUG) treeNode << "const_value(4)" << std::endl; $$ = new NConstValue(3, (*$1=="false")?0:(*$1=="maxint")?1:2); };

type_part :TYPE type_decl_list {if(DEBUG) treeNode << "type_part(1)" << std::endl; $$ = new NTypePart($2); }
            |{if(DEBUG) treeNode << "type_part(2)" << std::endl; $$ = new NTypePart();};

type_decl_list :type_decl_list  type_definition{if(DEBUG) treeNode << "type_decl_list(1)" << std::endl; $1->typeDefList.push_back($2); }
                |  type_definition{ if(DEBUG) treeNode << "type_decl_list(2)" << std::endl; $$ = new NTypeDefList(); $$->typeDefList.push_back($1); };

type_definition :ID  EQUAL  type_decl  SEMI{if(DEBUG) treeNode << "type_definition" << std::endl; $$ = new NTypeDefinition(*$1,$3);};

type_decl :simple_type_decl{if(DEBUG) treeNode << "type_decl(1)" << std::endl; $$ = new NTypeDecl(0, $1); }
         |  array_type_decl{if(DEBUG) treeNode << "type_decl(2)" << std::endl; $$ = new NTypeDecl(1, $1); } 
         |  record_type_decl{if(DEBUG) treeNode << "type_decl(3)" << std::endl; $$ = new NTypeDecl(2, $1); };

simple_type_decl : SYS_TYPE{if(DEBUG) treeNode << "simple_type_decl(1)" << std::endl; $$ = new NSimpleType(0, (*$1=="boolean")?0:(*$1=="char")?1:(*$1=="integer")?2:3); }
                 |  ID{if(DEBUG) treeNode << "simple_type_decl(2)" << std::endl; $$ = new NSimpleType(1, *$1); }
                 |  LP  name_list  RP{if(DEBUG) treeNode << "simple_type_decl(3)" << std::endl; $$ = new NSimpleType(2, $2); }
                 |  const_value  DOTDOT  const_value{if(DEBUG) treeNode << "simple_type_decl(4)" << std::endl; $$ = new NSimpleType(3, $1, $3); }
                 |  MINUS  const_value  DOTDOT  const_value{if(DEBUG) treeNode << "simple_type_decl(5)" << std::endl; $$ = new NSimpleType(4, $2, $4); }
                 |  MINUS  const_value  DOTDOT  MINUS  const_value{if(DEBUG) treeNode << "simple_type_decl(6)" << std::endl; $$ = new NSimpleType(5, $2, $5); }
                 |  ID  DOTDOT  ID{if(DEBUG) treeNode << "simple_type_decl(7)" << std::endl; $$ = new NSimpleType(6, *$1, *$3); };

array_type_decl :ARRAY  LB  simple_type_decl  RB  OF  type_decl{if(DEBUG) treeNode << "array_type_decl" << std::endl; $$ = new NArrayType($3, $6); };

record_type_decl :RECORD  field_decl_list  END{if(DEBUG) treeNode << "record_type_decl" << std::endl; $$ = new NRecordType($2); };

field_decl_list :field_decl_list  field_decl{if(DEBUG) treeNode << "field_decl_list(1)" << std::endl; $1->fieldDecls.push_back($2); }
                  |  field_decl{if(DEBUG) treeNode << "field_decl_list(2)" << std::endl; $$ = new NFieldDeclList(); $$->fieldDecls.push_back($1); };

field_decl :name_list  COLON  type_decl  SEMI{if(DEBUG) treeNode << "field_decl" << std::endl; $$ = new NFieldDecl($1, $3); };

name_list :name_list  COMMA  ID{if(DEBUG) treeNode << "name_list(1)" << std::endl; $1->IDs.push_back(*$3); }
          |  ID{if(DEBUG) treeNode << "name_list(2)" << std::endl; $$ = new NNameList(); $$->IDs.push_back(*$1); };

var_part :VAR  var_decl_list{if(DEBUG) treeNode << "var_part(1)" << std::endl; $$ = new NVarPart($2); }
            |{if(DEBUG) treeNode << "var_part(2)" << std::endl; $$ = new NVarPart();};

var_decl_list :  var_decl_list  var_decl{if(DEBUG) treeNode << "var_decl_list(1)" << std::endl; $1->varDecls.push_back($2); }
              |  var_decl{if(DEBUG) treeNode << "var_decl_list(2)" << std::endl; $$ = new NVarDeclList();$$->varDecls.push_back($1); };

var_decl :  name_list  COLON  type_decl  SEMI{if(DEBUG) treeNode << "var_decl" << std::endl; $$ = new NVarDecl($1, $3);};

routine_part:  routine_part  function_decl{if(DEBUG) treeNode << "routine_part(1)" << std::endl; $1->blockDecls.push_back($2);}
              |  routine_part  procedure_decl{if(DEBUG) treeNode << "routine_part(2)" << std::endl; $1->blockDecls.push_back($2); }
              |  function_decl{if(DEBUG) treeNode << "routine_part(3)" << std::endl; $$ = new NRoutinePart(); $$->blockDecls.push_back($1);}
              |  procedure_decl{if(DEBUG) treeNode << "routine_part(4)" << std::endl; $$ = new NRoutinePart(); $$->blockDecls.push_back($1); }  
              | {if(DEBUG) treeNode << "routine_part(5)" << std::endl; $$ = new NRoutinePart();};

function_decl : function_head  SEMI  sub_routine  SEMI{if(DEBUG) treeNode << "function_decl" << std::endl; $$ = new NFuncDecl($1, $3); };

function_head :  FUNCTION  ID  parameters  COLON  simple_type_decl {if(DEBUG) treeNode << "function_head" << std::endl; $$ = new NFuncHead(*$2, $3, $5); };

procedure_decl :  procedure_head  SEMI  sub_routine  SEMI{if(DEBUG) treeNode << "procedure_decl" << std::endl; $$ = new NProcDecl($1, $3); };

procedure_head :  PROCEDURE ID parameters{if(DEBUG) treeNode << "procedure_head" << std::endl; $$ = new NProcHead(*$2, $3); };

parameters :LP  para_decl_list  RP  {if(DEBUG) treeNode << "parameters(1)" << std::endl; $$ = new NParams($2); }
            |  {if(DEBUG) treeNode << "parameters(2)" << std::endl; $$ = new NParams();};

para_decl_list :para_decl_list  SEMI  para_type_list {if(DEBUG) treeNode << "para_decl_list(1)" << std::endl; $1->paramsTypes.push_back($3); }
                | para_type_list{if(DEBUG) treeNode << "para_decl_list(2)" << std::endl; $$ = new NParamsDeclList(); $$->paramsTypes.push_back($1); };

para_type_list :var_para_list COLON  simple_type_decl  {if(DEBUG) treeNode << "para_type_list(1)" << std::endl; $$ = new NParamsTypeList(0, $1, $3); }
                |  val_para_list  COLON  simple_type_decl{if(DEBUG) treeNode << "para_type_list(2)" << std::endl; $$ = new NParamsTypeList(1, $1, $3); };

var_para_list   : VAR name_list  {if(DEBUG) treeNode << "var_para_list" << std::endl; $$ = new NVarParamsList($2); };

val_para_list   : name_list  {if(DEBUG) treeNode << "val_para_list" << std::endl; $$ = new NValParamsList($1); };

routine_body    : compound_stmt  {if(DEBUG) treeNode << "routine_body" << std::endl; $$ = new NRoutineBody($1); };

compound_stmt   : START NULLPART stmt_list  END  {if(DEBUG) treeNode << "compound_stmt" << std::endl; $$ = new NCompStmt($3); lastblock=contblock[blocknumber]; };

NULLPART        : {blocknumber++; contblock[blocknumber]=lastblock; lastblock=blocknumber;}
            
stmt_list   : stmt_list  stmt  SEMI  {if(DEBUG) treeNode << "stmt_list(1)" << std::endl; $1->stmts.push_back($2); }
            | {if(DEBUG) treeNode << "stmt_list(2)" << std::endl; $$ = new NStmtList(); };
            
stmt    : INTEGER  COLON  non_label_stmt  {if(DEBUG) treeNode << "stmt(1)" << std::endl; $$ = new NStmt(0, std::stoi(*$1), $3); }
        | non_label_stmt  {if(DEBUG) treeNode << "stmt(2)" << std::endl; $$ = new NStmt(1, $1); };

non_label_stmt  : assign_stmt   {if(DEBUG) treeNode << "non_label_stmt(1)" << std::endl; $$ = new NNonLabStmt(0, $1); }
                | proc_stmt     {if(DEBUG) treeNode << "non_label_stmt(2)" << std::endl; $$ = new NNonLabStmt(1, $1); }
                | compound_stmt {if(DEBUG) treeNode << "non_label_stmt(3)" << std::endl; $$ = new NNonLabStmt(2, $1); }
                | if_stmt       {if(DEBUG) treeNode << "non_label_stmt(4)" << std::endl; $$ = new NNonLabStmt(3, $1); }
                | repeat_stmt   {if(DEBUG) treeNode << "non_label_stmt(5)" << std::endl; $$ = new NNonLabStmt(4, $1); }
                | while_stmt    {if(DEBUG) treeNode << "non_label_stmt(6)" << std::endl; $$ = new NNonLabStmt(5, $1); }
                | for_stmt      {if(DEBUG) treeNode << "non_label_stmt(7)" << std::endl; $$ = new NNonLabStmt(6, $1); }
                | case_stmt     {if(DEBUG) treeNode << "non_label_stmt(8)" << std::endl; $$ = new NNonLabStmt(7, $1); }
                | goto_stmt     {if(DEBUG) treeNode << "non_label_stmt(9)" << std::endl; $$ = new NNonLabStmt(8, $1); };

assign_stmt : ID  ASSIGN  expression  {if(DEBUG) treeNode << "assign_stmt(1)" << std::endl; $$ = new NAssignStmt(0, *$1, $3); }
            | ID LB expression RB ASSIGN expression  {if(DEBUG) treeNode << "assign_stmt(2)" << std::endl; $$ = new NAssignStmt(1, *$1, $3, $6); }
            | ID  DOT  ID  ASSIGN  expression  {if(DEBUG) treeNode << "assign_stmt(3)" << std::endl; $$ = new NAssignStmt(0, *$1, *$3, $5); };

proc_stmt   : ID  {if(DEBUG) treeNode << "proc_stmt(1)" << std::endl; $$ = new NProcStmt(0, *$1); }
            | ID  LP  args_list  RP  {if(DEBUG) treeNode << "proc_stmt(2)" << std::endl; $$ = new NProcStmt(1, *$1, $3); }
            | SYS_PROC  {if(DEBUG) treeNode << "proc_stmt(3)" << std::endl; $$ = new NProcStmt(2, (*$1=="write")?0:1); }
            | SYS_PROC  LP  expression_list  RP  {if(DEBUG) treeNode << "proc_stmt(4)" << std::endl; $$ = new NProcStmt(3, (*$1=="write")?0:1, $3); }
            | READ  LP  factor  RP  {if(DEBUG) treeNode << "proc_stmt(5)" << std::endl; $$ = new NProcStmt(4, $3); };

if_stmt : IF  expression  THEN  stmt  else_clause  {if(DEBUG) treeNode << "if_stmt" << std::endl; $$ = new NIfStmt($2, $4, $5); };

else_clause : ELSE  stmt  {if(DEBUG) treeNode << "else_clause(1)" << std::endl; $$ = new NElseStmt($2); }
            | {if(DEBUG) treeNode << "else_clause(2)" << std::endl; $$ = new NElseStmt();};

repeat_stmt : REPEAT  stmt_list  UNTIL  expression  {if(DEBUG) treeNode << "repeat_stmt" << std::endl; $$ = new NRepeatStmt($2, $4); };

while_stmt  : WHILE  expression  DO  stmt  {if(DEBUG) treeNode << "while_stmt" << std::endl; $$ = new NWhileStmt($2, $4); };

for_stmt    : FOR  ID  ASSIGN  expression  direction  expression  DO  stmt  {if(DEBUG) treeNode << "for_stmt" << std::endl; $$ = new NForStmt(*$2, $4, $5, $6, $8); };

direction   : TO  {if(DEBUG) treeNode << "direction(1)" << std::endl; $$ = new NDirection(0); }
            | DOWNTO  {if(DEBUG) treeNode << "direction(2)" << std::endl; $$ = new NDirection(1); };

case_stmt   : CASE  expression  OF  case_expr_list  END  {if(DEBUG) treeNode << "case_stmt" << std::endl; $$ = new NCaseStmt($2, $4); };

case_expr_list  : case_expr_list  case_expr  {if(DEBUG) treeNode << "case_expr_list(1)" << std::endl; $1->caseExprs.push_back($2); }
                | case_expr  {if(DEBUG) treeNode << "case_expr_list(2)" << std::endl; $$ = new NCaseExprList(); $$->caseExprs.push_back($1); };

case_expr   : const_value  COLON  stmt  SEMI  {if(DEBUG) treeNode << "case_expr(1)" << std::endl; $$ = new NCaseExpr(0, $1, $3); }
            | ID  COLON  stmt  SEMI  {if(DEBUG) treeNode << "case_expr(2)" << std::endl; $$ = new NCaseExpr(1, *$1, $3); };

goto_stmt   : GOTO  INTEGER  {if(DEBUG) treeNode << "goto_stmt" << std::endl; $$ = new NGotoStmt(std::stoi(*$2)); };

expression_list : expression_list  COMMA  expression  {if(DEBUG) treeNode << "expression_list(1)" << std::endl; $1->expressions.push_back($3); }
                | expression  {if(DEBUG) treeNode << "expression_list(2)" << std::endl; $$ = new NExprList(); $$->expressions.push_back($1); };

expression  : expression  GE  expr  {if(DEBUG) treeNode << "expression(1)" << std::endl; $1->exprs.push_back($3); $1->types.push_back(0); }
            | expression  GT  expr  {if(DEBUG) treeNode << "expression(2)" << std::endl; $1->exprs.push_back($3); $1->types.push_back(1); }
            | expression  LE  expr  {if(DEBUG) treeNode << "expression(3)" << std::endl; $1->exprs.push_back($3); $1->types.push_back(2); }
            | expression  LT  expr  {if(DEBUG) treeNode << "expression(4)" << std::endl; $1->exprs.push_back($3); $1->types.push_back(3); }
            | expression  EQUAL  expr   {if(DEBUG) treeNode << "expression(5)" << std::endl; $1->exprs.push_back($3); $1->types.push_back(4); }
            | expression  UNEQUAL  expr {if(DEBUG) treeNode << "expression(6)" << std::endl; $1->exprs.push_back($3); $1->types.push_back(5); }
            | expr   {if(DEBUG) treeNode << "expression(7)" << std::endl; $$ = new NExpression(); $$->exprs.push_back($1); $$->types.push_back(6); };

expr    : expr  PLUS  term  {if(DEBUG) treeNode << "expr(1)" << std::endl; $1->terms.push_back($3); $1->types.push_back(0); }
        | expr  MINUS  term {if(DEBUG) treeNode << "expr(2)" << std::endl; $1->terms.push_back($3); $1->types.push_back(1); }
        | expr  OR  term    {if(DEBUG) treeNode << "expr(3)" << std::endl; $1->terms.push_back($3); $1->types.push_back(2); }
        | term  {if(DEBUG) treeNode << "expr(4)" << std::endl; $$ = new NExpr(); $$->terms.push_back($1); $$->types.push_back(3); };

term    : term  MUL  factor {if(DEBUG) treeNode << "term(1)" << std::endl; $1->factors.push_back($3); $1->types.push_back(0); }
        | term  DIV  factor {if(DEBUG) treeNode << "term(2)" << std::endl; $1->factors.push_back($3); $1->types.push_back(1); }
        | term  MOD  factor {if(DEBUG) treeNode << "term(3)" << std::endl; $1->factors.push_back($3); $1->types.push_back(2); }
        | term  AND  factor {if(DEBUG) treeNode << "term(4)" << std::endl; $1->factors.push_back($3); $1->types.push_back(3); }
        | factor    {if(DEBUG) treeNode << "term(5)" << std::endl;$$ = new NTerm(); $$->factors.push_back($1); $$->types.push_back(4); };

factor  : ID  {if(DEBUG) treeNode << "factor(1)" << std::endl; $$ = new NFactor(0, *$1); }
        | ID  LP  args_list  RP  {if(DEBUG) treeNode << "factor(2)" << std::endl; $$ = new NFactor(1, *$1, $3); }
        | SYS_FUNCT  {if(DEBUG) treeNode << "factor(3)" << std::endl; $$ = new NFactor(2, (*$1)=="abs"?0:(*$1)=="chr"?1:(*$1)=="odd"?2:(*$1)=="ord"?3:(*$1)=="pred"?4:(*$1)=="sqr"?5:(*$1)=="sqrt"?6:7); }
        | SYS_FUNCT  LP  args_list  RP  {if(DEBUG) treeNode << "factor(4)" << std::endl; $$ = new NFactor(3, (*$1)=="abs"?0:(*$1)=="chr"?1:(*$1)=="odd"?2:(*$1)=="ord"?3:(*$1)=="pred"?4:(*$1)=="sqr"?5:(*$1)=="sqrt"?6:7, $3); } 
        | const_value  {if(DEBUG) treeNode << "factor(5)" << std::endl; $$ = new NFactor(4, $1); }
        | LP  expression  RP  {if(DEBUG) treeNode << "factor(6)" << std::endl; $$ = new NFactor(5, $2); }
        | NOT  factor  {if(DEBUG) treeNode << "factor(7)" << std::endl; $$ = new NFactor(6, $2); }
        | MINUS  factor  {if(DEBUG) treeNode << "factor(8)" << std::endl; $$ = new NFactor(7, $2); }
        | ID  LB  expression  RB  {if(DEBUG) treeNode << "factor(9)" << std::endl; $$ = new NFactor(8, *$1, $3); }
        | ID  DOT  ID  {if(DEBUG) treeNode << "factor(10)" << std::endl; $$ = new NFactor(9, *$1, *$3); };

args_list   : args_list  COMMA  expression  {if(DEBUG) treeNode << "args_list(1)" << std::endl; $1->expressions.push_back($3); }
            | expression  {if(DEBUG) treeNode << "args_list(2)" << std::endl; $$ = new NArgsList(); $$->expressions.push_back($1); };

%%