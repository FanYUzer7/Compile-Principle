#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include<string>
#include <llvm/IR/Value.h>
#include "symtb.hpp"

extern int line_cnt;

class NProgramHead;
class NRoutine;
class NRoutineHead;
class NRoutineBody;
class NConstPart;
class NConstExpressionList;
class NConst;
class NConstValue;
class NTypePart;
class NTypeDefList;
class NTypeDefinition;
class NTypeDecl;
class NSimpleType;
class NArrayType;
class NRecordType;
class NFieldDeclList;
class NFieldDecl;
class NNameList;
class NVarPart;
class NVarDeclList;
class NVarDecl;
class NRoutinePart;
class NBlockDecl;
class NFuncDecl;
class NFuncHead;
class NProcDecl;
class NProcHead;
class NParams;
class NParamsDeclList;
class NParamsTypeList;
class NVarParamsList;
class NValParamsList;
class NCompStmt;
class NStmtList;
class NStmt;
class NNonLabStmt;
class NAssignStmt;
class NProcStmt;
class NIfStmt;
class NRepeatStmt;
class NWhileStmt;
class NForStmt;
class NCaseStmt;
class NGotoStmt;
class NExpression;
class NArgsList;
class NExprList;
class NFactor;
class NElseStmt;
class NDirection;
class NCaseExprList;
class NCaseExpr;
class NExpr;
class NTerm;

class CodeGenContext;

class NProgram
{
public:
    NProgramHead *head = nullptr;
    NRoutine *routine = nullptr;
    NProgram(NProgramHead *head, NRoutine *routine);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NProgramHead
{
public:
    std::string id;
    NProgramHead(const std::string &id);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NRoutine
{
public:
    NRoutineHead *routineHead = nullptr;
    NRoutineBody *routineBody = nullptr;
    NRoutine(NRoutineHead *head, NRoutineBody *body);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NRoutineHead
{
public:
    NConstPart *constPart = nullptr;
    NTypePart *typePart = nullptr;
    NVarPart *varPart = nullptr;
    NRoutinePart *routinePart = nullptr;
    NRoutineHead(NConstPart *constPart, NTypePart *typePart, NVarPart *varPart, NRoutinePart *routinePart);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NConstPart
{
public:
    NConstExpressionList *constExprList = nullptr;
    NConstPart(NConstExpressionList *constExprList);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NConstExpressionList
{
public:
    std::vector<NConst *> constList;
    llvm::Value* codeGen(CodeGenContext *context);
};

class NConst
{
public:
    std::string NAME;
    NConstValue *value = nullptr;

    NConst(std::string NAME, NConstValue *value);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NConstValue
{
public:
    int type = -1; //0 for INTEGER, 1 for REAL, 2 for CHAR, 3 for SYS_CON
    int Integer;
    double Real;
    char Char;
    int Sys_con; //0 for false, 1 for maxint, 2 for true

    NConstValue(int type, int Integer);
    NConstValue(int type, double Real);
    NConstValue(int type, char Char);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NTypePart
{
public:
    NTypeDefList *typeDefList = nullptr;

    NTypePart(NTypeDefList *typeDefList);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NTypeDefList
{
public:
    std::vector<NTypeDefinition*> typeDefList;

    llvm::Value* codeGen(CodeGenContext *context);
};

class NTypeDefinition
{
public:
    std::string NAME;
    NTypeDecl *typeDecl = nullptr;

    NTypeDefinition(std::string NAME, NTypeDecl *typeDecl);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NSimpleType
{
public:
    int type = -1;     //indicate which derivation rule is used, from 0 to 6
    int Sys_type = -1; //0 for boolean, 1 for char, 2 for integer, 3 for real
    NNameList *nameList = nullptr;
    NConstValue *constValue1, *constValue2 = nullptr;
    std::string NAME1, NAME2;

    NSimpleType(int type, int Sys_type);
    NSimpleType(int type, std::string NAME);
    NSimpleType(int type, NNameList *nameList);
    NSimpleType(int type, NConstValue *constValue1, NConstValue *constValue2);
    NSimpleType(int type, std::string NAME1, std::string NAME2);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NTypeDecl
{
public:
    int type = -1; //0 for simpletype, 1 for arraytype, 2 for recordtype
    NSimpleType *simpleType = nullptr;
    NArrayType *arrayType = nullptr;
    NRecordType *recordType = nullptr;
    int array_start = 0, array_end = 0;

    NTypeDecl(int type, NSimpleType *simpleType);
    NTypeDecl(int type, NArrayType *arrayType);
    NTypeDecl(int type, NRecordType *recordType);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NArrayType
{
public:
    NSimpleType *simpleType = nullptr;
    NTypeDecl *typeDecl = nullptr;

    NArrayType(NSimpleType *simpleType, NTypeDecl *typeDecl);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NRecordType
{
public:
    NFieldDeclList *fieldDeclList = nullptr;

    NRecordType(NFieldDeclList *fieldDeclList);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NFieldDeclList
{
public:
    std::vector<NFieldDecl*> fieldDecls;
    llvm::Value* codeGen(CodeGenContext *context);
};

class NFieldDecl
{
public:
    NNameList *nameList = nullptr;
    NTypeDecl *typeDecl = nullptr;

    NFieldDecl(NNameList *nameList, NTypeDecl *typeDecl);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NNameList
{
public:
    std::vector<std::string> IDs;

    llvm::Value* codeGen(CodeGenContext *context);
};

class NVarPart
{
public:
    NVarDeclList *varDeclList = nullptr;

    NVarPart(NVarDeclList *varDeclList);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NVarDeclList
{
public:
    std::vector<NVarDecl*> varDecls;

    llvm::Value* codeGen(CodeGenContext *context);
};

class NVarDecl
{
public:
    NNameList *nameList = nullptr;
    NTypeDecl *typeDecl = nullptr;

    NVarDecl(NNameList *nameList, NTypeDecl *typeDecl);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NRoutinePart
{
public:
    std::vector<NBlockDecl *> blockDecls;

    llvm::Value* codeGen(CodeGenContext *context);
};

class NBlockDecl
{
public:
    int type = -1; //0 for func, 1 for proc

    NBlockDecl(int type);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NFuncDecl : public NBlockDecl
{
public:
    NFuncHead *funcHead = nullptr;
    NRoutine *subRoutine = nullptr;

    NFuncDecl(NFuncHead *funcHead, NRoutine *subRoutine);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NFuncHead
{
public:
    std::string NAME;
    NParams *params = nullptr;
    NSimpleType *simpleType = nullptr;

    NFuncHead(std::string NAME, NParams *params, NSimpleType *simpleType);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NProcDecl : public NBlockDecl
{
public:
    NProcHead *procHead = nullptr;
    NRoutine *subRoutine = nullptr;

    NProcDecl(NProcHead *procHead, NRoutine *subRoutine);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NProcHead
{
public:
    std::string NAME;
    NParams *params = nullptr;

    NProcHead(std::string NAME, NParams *params);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NParams
{
public:
    NParamsDeclList *paramsDeclList = nullptr;

    NParams(NParamsDeclList *paramsDeclList);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NParamsDeclList
{
public:
    std::vector<NParamsTypeList *> paramsTypes;

    llvm::Value* codeGen(CodeGenContext *context);
};

class NParamsTypeList
{
public:
    int type = -1; //0 for var_para_list, 1 for val_para_list
    NSimpleType *simpleType = nullptr;
    NVarParamsList *varParamsList = nullptr;
    NValParamsList *valParamsList = nullptr;

    NParamsTypeList(int type, NVarParamsList *varParamsList, NSimpleType *simpleType);
    NParamsTypeList(int type, NValParamsList *valParamsList, NSimpleType *simpleType);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NVarParamsList
{
public:
    NNameList *nameList = nullptr;

    NVarParamsList(NNameList *nameList);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NValParamsList
{
public:
    NNameList *nameList = nullptr;

    NValParamsList(NNameList *nameList);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NRoutineBody
{
public:
    NCompStmt *compStmt = nullptr;

    NRoutineBody(NCompStmt *compStmt);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NCompStmt
{
public:
    NStmtList *stmtList = nullptr;

    NCompStmt(NStmtList *stmtList);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NStmtList
{
public:
    std::vector<NStmt*> stmts;

    llvm::Value* codeGen(CodeGenContext *context);
};

class NStmt
{
public:
    int type = -1; //0 for the first rule, 1 for the second rule
    int Integer;
    NNonLabStmt *nonLabStmt = nullptr;

    NStmt(int type, NNonLabStmt *nonLabStmt);
    NStmt(int type, int Integer, NNonLabStmt *nonLabStmt);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NNonLabStmt
{
public:
    int type = -1; //0 for assign_stmt, 1 for proc_stmt, 2 for compound_stmt, 3 for if_stmt, 4 for repeat_stmt, 5 for while_stmt, 6 for for_stmt, 7 for case_stmt, 8 for goto_stmt
    NAssignStmt *assignStmt = nullptr;
    NProcStmt *procStmt = nullptr;
    NCompStmt *compStmt = nullptr;
    NIfStmt *ifStmt = nullptr;
    NRepeatStmt *repeatStmt = nullptr;
    NWhileStmt *whileStmt = nullptr;
    NForStmt *forStmt = nullptr;
    NCaseStmt *caseStmt = nullptr;
    NGotoStmt *gotoStmt = nullptr;

    NNonLabStmt(int type, NAssignStmt *assignStmt);
    NNonLabStmt(int type, NProcStmt *procStmt);
    NNonLabStmt(int type, NCompStmt *compStmt);
    NNonLabStmt(int type, NIfStmt *ifStmt);
    NNonLabStmt(int type, NRepeatStmt *repeatStmt);
    NNonLabStmt(int type, NWhileStmt *whileStmt);
    NNonLabStmt(int type, NForStmt *forStmt);
    NNonLabStmt(int type, NCaseStmt *caseStmt);
    NNonLabStmt(int type, NGotoStmt *gotoStmt);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NAssignStmt
{
public:
    int type = -1; //0 for the first rule, 1 for the second rule, 2 for the third rule
    std::string ID1;
    std::string ID2;
    NExpression *expression1 = nullptr;
    NExpression *expression2 = nullptr;

    NAssignStmt(int type, std::string id, NExpression *expression);
    NAssignStmt(int type, std::string id, NExpression *expression1, NExpression *expression2);
    NAssignStmt(int type, std::string ID1, std::string ID2, NExpression *expression);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NProcStmt
{
public:
    int type = -1; //0 for the first rule, 1 for the second rule, 2 for the third rule, 3 for the fourth rule, 4 for the fifth rule
    std::string id;
    NArgsList *argsList = nullptr;
    int Sys_proc; //0 for write, 1 for writeln
    NExprList *exprList = nullptr;
    NFactor *factor = nullptr;

    NProcStmt(int type, std::string id);
    NProcStmt(int type, std::string id, NArgsList *argsList);
    NProcStmt(int type, int Sys_proc);
    NProcStmt(int type, int Sys_proc, NExprList *exprList);
    NProcStmt(int type, NFactor *factor);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NIfStmt
{
public:
    NExpression *expression = nullptr;
    NStmt *stmt = nullptr;
    NElseStmt *elseStmt = nullptr;

    NIfStmt(NExpression *expression, NStmt *stmt, NElseStmt *elseStmt);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NElseStmt
{
public:
    NStmt *stmt = nullptr;

    NElseStmt(NStmt *stmt);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NRepeatStmt
{
public:
    NStmtList *stmtList = nullptr;
    NExpression *expression = nullptr;

    NRepeatStmt(NStmtList *stmtList, NExpression *expression);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NWhileStmt
{
public:
    NExpression *expression = nullptr;
    NStmt *stmt = nullptr;

    NWhileStmt(NExpression *expression, NStmt *stmt);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NForStmt
{
public:
    std::string id;
    NExpression *expression1 = nullptr;
    NDirection *direction = nullptr;
    NExpression *expression2 = nullptr;
    NStmt *stmt = nullptr;

    NForStmt(std::string id, NExpression *expression1, NDirection *direction, NExpression *expression2, NStmt *stmt);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NDirection
{
public:
    int type = -1; // 0 for TO, 1 for DOWNTO

    NDirection(int type);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NCaseStmt
{
public:
    NExpression *expression = nullptr;
    NCaseExprList *caseExprList = nullptr;

    NCaseStmt(NExpression *expression, NCaseExprList *caseExprList);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NCaseExprList
{
public:
    std::vector<NCaseExpr *> caseExprs;

    llvm::Value* codeGen(CodeGenContext *context);
};

class NCaseExpr
{
public:
    int type = -1;
    NConstValue *constValue = nullptr;
    NStmt *stmt = nullptr;
    std::string id = nullptr;

    NCaseExpr(int type, NConstValue *constValue, NStmt *stmt);
    NCaseExpr(int type, std::string id, NStmt *stmt);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NGotoStmt
{
public:
    int Integer = -1;

    NGotoStmt(int Integer);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NExprList
{
public:
    std::vector<NExpression *> expressions;

    llvm::Value* codeGen(CodeGenContext *context);
};

class NExpression
{
public:
    std::vector<NExpr *> exprs;
    std::vector<int> types; //each ranges from 0 to 6, represents rules 1 to 7

    NExpression();
    NExpression(std::vector<NExpr *> exprs, std::vector<int> types);
    llvm::Value* codeGen(CodeGenContext *context);
};

class NExpr
{
public:
    std::vector<NTerm *> terms;
    std::vector<int> types; //each type ranges from 0 to 3, represents rules 1 to 4

    NExpr();
    NExpr(std::vector<NTerm *> terms, std::vector<int> types);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NTerm
{
public:
    std::vector<NFactor *> factors;
    std::vector<int> types; //each type ranges from 0 to 4, represents rules 1 to 5

    NTerm();
    NTerm(std::vector<NFactor *> factors, std::vector<int> types);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NFactor
{
public:
    int type = -1; //type ranges from 0 to 9, represents rules 1 to 10
    std::string NAME;
    NArgsList *argsList = nullptr;
    int Sys_funct; //0 for abs, 1 for chr, 2 for odd, 3 for ord, 4 for pred, 5 for sqr, 6 for sqrt, 7 for succ
    NConstValue *constValue = nullptr;
    NExpression *expression = nullptr;
    NFactor *factor = nullptr;
    std::string ID1;
    std::string ID2;

    NFactor(int type, std::string NAME);
    NFactor(int type, std::string NAME, NArgsList *argsList);
    NFactor(int type, int Sys_funct);
    NFactor(int type, int Sys_funct, NArgsList *argsList);
    NFactor(int type, NConstValue *constValue);
    NFactor(int type, NExpression *expression);
    NFactor(int type, NFactor *factor);
    NFactor(int type, std::string id, NExpression *expression);
    NFactor(int type, std::string ID1, std::string ID2);

    llvm::Value* codeGen(CodeGenContext *context);
};

class NArgsList
{
public:
    std::vector<NExpression *> expressions;

    llvm::Value* codeGen(CodeGenContext *context);
};

#endif