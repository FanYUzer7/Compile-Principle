#ifndef _NODE_
#define _NODE_
#include <iostream>
#include <vector>
#include "llvm/IR/Value.h"
//#include "CodeGen.h"

// #include <llvm/Value.h>
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
    NProgram(NProgramHead *head, NRoutine *routine) : head(head), routine(routine) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NProgramHead
{
public:
    std::string id;
    NProgramHead(const std::string &id) : id(id) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NRoutine
{
public:
    NRoutineHead *routineHead = nullptr;
    NRoutineBody *routineBody = nullptr;
    NRoutine(NRoutineHead *head, NRoutineBody *body) : routineHead(head), routineBody(body) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NRoutineHead
{
public:
    NConstPart *constPart = nullptr;
    NTypePart *typePart = nullptr;
    NVarPart *varPart = nullptr;
    NRoutinePart *routinePart = nullptr;

    NRoutineHead(NConstPart *constPart, NTypePart *typePart, NVarPart *varPart, NRoutinePart *routinePart) : constPart(constPart), typePart(typePart), varPart(varPart), routinePart(routinePart) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NConstExpressionList
{
public:
    std::vector<NConst *> constList;
public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NConstPart
{
public:
    NConstExpressionList *constExprList = nullptr;
    NConstPart(){
        std::cout<<"default construct"<<std::endl;
    }
    NConstPart(NConstExpressionList *constExprList) : constExprList(constExprList) {
        std::cout<<"reference construct"<<std::endl;
        std::cout<<constExprList->constList.size()<<std::endl;//my
    }

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NConst
{
public:
    std::string NAME;
    NConstValue *value = nullptr;

    NConst(std::string NAME, NConstValue *value) : NAME(NAME), value(value) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NConstValue
{
public:
    int type = -1; //0 for INTEGER, 1 for REAL, 2 for CHAR, 3 for SYS_CON
    int Integer;
    double Real;
    char Char;
    int Sys_con; //0 for false, 1 for maxint, 2 for true

    NConstValue(int type, int Integer) : type(type)
    {
        if (type == 0)
            Integer = Integer;
        else
            Sys_con = Integer;
    }
    NConstValue(int type, double Real) : type(type), Real(Real) {}
    NConstValue(int type, char Char) : type(type), Char(Char) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NTypePart
{
public:
    NTypeDefList *typeDefList = nullptr;

    NTypePart(NTypeDefList *typeDefList) : typeDefList(typeDefList) {}
    NTypePart(){};//my

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NTypeDefList
{
public:
    std::vector<NTypeDefinition *> typeDefList;

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NTypeDefinition
{
public:
    std::string NAME;
    NTypeDecl *typeDecl = nullptr;

    NTypeDefinition(std::string NAME, NTypeDecl *typeDecl) : NAME(NAME), typeDecl(typeDecl) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NSimpleType
{
public:
    int type = -1;     //indicate which derivation rule is used, from 0 to 6
    int Sys_type = -1; //0 for boolean, 1 for char, 2 for integer, 3 for real
    NNameList *nameList = nullptr;
    NConstValue *constValue1, *constValue2 = nullptr;
    std::string NAME1, NAME2;

    NSimpleType(int type, int Sys_type) : type(type), Sys_type(Sys_type) {}
    NSimpleType(int type, std::string NAME) : type(type), NAME1(NAME) {}
    NSimpleType(int type, NNameList *nameList) : type(type), nameList(nameList) {}
    NSimpleType(int type, NConstValue *constValue1, NConstValue *constValue2) : type(type), constValue1(constValue1), constValue2(constValue2) {}
    NSimpleType(int type, std::string NAME1, std::string NAME2) : type(type), NAME1(NAME1), NAME2(NAME2) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NTypeDecl
{
public:
    int type = -1; //0 for simpletype, 1 for arraytype, 2 for recordtype
    NSimpleType *simpleType = nullptr;
    NArrayType *arrayType = nullptr;
    NRecordType *recordType = nullptr;
    int array_start = 0, array_end = 0;

    NTypeDecl(int type, NSimpleType *simpleType) : type(type), simpleType(simpleType)
    {
        if (simpleType != nullptr)
            switch (simpleType->type)
            {
            case (4):
            {
                array_start = simpleType->constValue1->Integer;
                array_end = simpleType->constValue2->Integer;
                break;
            }
            case (5):
            {
                array_start = -(simpleType->constValue1->Integer);
                array_end = simpleType->constValue2->Integer;
                break;
            }
            case (6):
            {
                array_start = -(simpleType->constValue1->Integer);
                array_end = -(simpleType->constValue2->Integer);
                break;
            }
            default:
                break;
            }
    }
    NTypeDecl(int type, NArrayType *arrayType) : type(type), arrayType(arrayType) {}
    NTypeDecl(int type, NRecordType *recordType) : type(type), recordType(recordType) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NArrayType
{
public:
    NSimpleType *simpleType = nullptr;
    NTypeDecl *typeDecl = nullptr;

    NArrayType(NSimpleType *simpleType, NTypeDecl *typeDecl) : simpleType(simpleType), typeDecl(typeDecl) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NRecordType
{
public:
    NFieldDeclList *fieldDeclList = nullptr;

    NRecordType(NFieldDeclList *fieldDeclList) : fieldDeclList(fieldDeclList) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NFieldDeclList
{
public:
    std::vector<NFieldDecl *> fieldDecls;

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NFieldDecl
{
public:
    NNameList *nameList = nullptr;
    NTypeDecl *typeDecl = nullptr;

    NFieldDecl(NNameList *nameList, NTypeDecl *typeDecl) : nameList(nameList), typeDecl(typeDecl) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NNameList
{
public:
    std::vector<std::string> IDs;

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NVarPart
{
public:
    NVarDeclList *varDeclList = nullptr;

    NVarPart(NVarDeclList *varDeclList) : varDeclList(varDeclList) {}
    NVarPart(){};//my

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NVarDeclList
{
public:
    std::vector<NVarDecl *> varDecls;

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NVarDecl
{
public:
    NNameList *nameList = nullptr;
    NTypeDecl *typeDecl = nullptr;

    NVarDecl(NNameList *nameList, NTypeDecl *typeDecl) : nameList(nameList), typeDecl(typeDecl) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NRoutinePart
{
public:
    std::vector<NBlockDecl *> blockDecls;

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NBlockDecl
{
public:
    int type = -1; //0 for func, 1 for proc

    NBlockDecl(int type) : type(type) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NFuncDecl : public NBlockDecl
{
public:
    NFuncHead *funcHead = nullptr;
    NRoutine *subRoutine = nullptr;

    NFuncDecl(NFuncHead *funcHead, NRoutine *subRoutine) : funcHead(funcHead), subRoutine(subRoutine), NBlockDecl(0) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NFuncHead
{
public:
    std::string NAME;
    NParams *params = nullptr;
    NSimpleType *simpleType = nullptr;

    NFuncHead(std::string NAME, NParams *params, NSimpleType *simpleType) : NAME(NAME), params(params), simpleType(simpleType) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NProcDecl : public NBlockDecl
{
public:
    NProcHead *procHead = nullptr;
    NRoutine *subRoutine = nullptr;

    NProcDecl(NProcHead *procHead, NRoutine *subRoutine) : procHead(procHead), subRoutine(subRoutine), NBlockDecl(1) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NProcHead
{
public:
    std::string NAME;
    NParams *params = nullptr;

    NProcHead(std::string NAME, NParams *params) : NAME(NAME), params(params) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NParams
{
public:
    NParamsDeclList *paramsDeclList = nullptr;

    NParams(NParamsDeclList *paramsDeclList) : paramsDeclList(paramsDeclList) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NParamsDeclList
{
public:
    std::vector<NParamsTypeList *> paramsTypes;

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NParamsTypeList
{
public:
    int type = -1; //0 for var_para_list, 1 for val_para_list
    NSimpleType *simpleType = nullptr;
    NVarParamsList *varParamsList = nullptr;
    NValParamsList *valParamsList = nullptr;

    NParamsTypeList(int type, NVarParamsList *varParamsList, NSimpleType *simpleType) : type(type), varParamsList(varParamsList), simpleType(simpleType) {}
    NParamsTypeList(int type, NValParamsList *valParamsList, NSimpleType *simpleType) : type(type), valParamsList(valParamsList), simpleType(simpleType) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NVarParamsList
{
public:
    NNameList *nameList = nullptr;

    NVarParamsList(NNameList *nameList) : nameList(nameList) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NValParamsList
{
public:
    NNameList *nameList = nullptr;

    NValParamsList(NNameList *nameList) : nameList(nameList) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NRoutineBody
{
public:
    NCompStmt *compStmt = nullptr;

    NRoutineBody(NCompStmt *compStmt) : compStmt(compStmt) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NCompStmt
{
public:
    NStmtList *stmtList = nullptr;

    NCompStmt(NStmtList *stmtList) : stmtList(stmtList) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NStmtList
{
public:
    std::vector<NStmt *> stmts;

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NStmt
{
public:
    int type = -1; //0 for the first rule, 1 for the second rule
    int Integer;
    NNonLabStmt *nonLabStmt = nullptr;

    NStmt(int type, NNonLabStmt *nonLabStmt) : type(type), nonLabStmt(nonLabStmt) {}
    NStmt(int type, int Integer, NNonLabStmt *nonLabStmt) : type(type), Integer(Integer), nonLabStmt(nonLabStmt) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
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

    NNonLabStmt(int type, NAssignStmt *assignStmt) : type(type), assignStmt(assignStmt) {}
    NNonLabStmt(int type, NProcStmt *procStmt) : type(type), procStmt(procStmt) {}
    NNonLabStmt(int type, NCompStmt *compStmt) : type(type), compStmt(compStmt) {}
    NNonLabStmt(int type, NIfStmt *ifStmt) : type(type), ifStmt(ifStmt) {}
    NNonLabStmt(int type, NRepeatStmt *repeatStmt) : type(type), repeatStmt(repeatStmt) {}
    NNonLabStmt(int type, NWhileStmt *whileStmt) : type(type), whileStmt(whileStmt) {}
    NNonLabStmt(int type, NForStmt *forStmt) : type(type), forStmt(forStmt) {}
    NNonLabStmt(int type, NCaseStmt *caseStmt) : type(type), caseStmt(caseStmt) {}
    NNonLabStmt(int type, NGotoStmt *gotoStmt) : type(type), gotoStmt(gotoStmt) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NAssignStmt
{
public:
    int type = -1; //0 for the first rule, 1 for the second rule, 2 for the third rule
    std::string ID1;
    std::string ID2;
    NExpression *expression1 = nullptr;
    NExpression *expression2 = nullptr;

    NAssignStmt(int type, std::string id, NExpression *expression) : type(type), ID1(id), expression1(expression) {}
    NAssignStmt(int type, std::string id, NExpression *expression1, NExpression *expression2) : type(type), ID1(id), expression1(expression1), expression2(expression2) {}
    NAssignStmt(int type, std::string ID1, std::string ID2, NExpression *expression) : type(type), ID1(ID1), ID2(ID2), expression1(expression) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
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

    NProcStmt(int type, std::string id) : type(type), id(id) {}
    NProcStmt(int type, std::string id, NArgsList *argsList) : type(type), id(id), argsList(argsList) {}
    NProcStmt(int type, int Sys_proc) : type(type), Sys_proc(Sys_proc) {}
    NProcStmt(int type, int Sys_proc, NExprList *exprList) : type(type), Sys_proc(Sys_proc), exprList(exprList) {}
    NProcStmt(int type, NFactor *factor) : type(type), factor(factor) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NIfStmt
{
public:
    NExpression *expression = nullptr;
    NStmt *stmt = nullptr;
    NElseStmt *elseStmt = nullptr;

    NIfStmt(NExpression *expression, NStmt *stmt, NElseStmt *elseStmt) : expression(expression), stmt(stmt), elseStmt(elseStmt) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NElseStmt
{
public:
    NStmt *stmt = nullptr;

    NElseStmt(NStmt *stmt) : stmt(stmt) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NRepeatStmt
{
public:
    NStmtList *stmtList = nullptr;
    NExpression *expression = nullptr;

    NRepeatStmt(NStmtList *stmtList, NExpression *expression) : stmtList(stmtList), expression(expression) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NWhileStmt
{
public:
    NExpression *expression = nullptr;
    NStmt *stmt = nullptr;

    NWhileStmt(NExpression *expression, NStmt *stmt) : expression(expression), stmt(stmt) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NForStmt
{
public:
    std::string id;
    NExpression *expression1 = nullptr;
    NDirection *direction = nullptr;
    NExpression *expression2 = nullptr;
    NStmt *stmt = nullptr;

    NForStmt(std::string id, NExpression *expression1, NDirection *direction, NExpression *expression2, NStmt *stmt) : id(id), expression1(expression1), direction(direction), expression2(expression2), stmt(stmt) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NDirection
{
public:
    int type = -1; // 0 for TO, 1 for DOWNTO

    NDirection(int type) : type(type) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NCaseStmt
{
public:
    NExpression *expression = nullptr;
    NCaseExprList *caseExprList = nullptr;

    NCaseStmt(NExpression *expression, NCaseExprList *caseExprList) : expression(expression), caseExprList(caseExprList) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NCaseExprList
{
public:
    std::vector<NCaseExpr *> caseExprs;

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NCaseExpr
{
public:
    int type = -1;
    NConstValue *constValue = nullptr;
    NStmt *stmt = nullptr;
    std::string id = nullptr;

    NCaseExpr(int type, NConstValue *constValue, NStmt *stmt) : type(type), constValue(constValue), stmt(stmt) {}
    NCaseExpr(int type, std::string id, NStmt *stmt) : type(type), id(id), stmt(stmt) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NGotoStmt
{
public:
    int Integer = -1;

    NGotoStmt(int Integer) : Integer(Integer) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NExprList
{
public:
    std::vector<NExpression *> expressions;

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NExpression
{
public:
    std::vector<NExpr *> exprs;
    std::vector<int> types; //each ranges from 0 to 6, represents rules 1 to 7

    NExpression() {}
    NExpression(std::vector<NExpr *> exprs, std::vector<int> types) : types(types), exprs(exprs) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NExpr
{
public:
    std::vector<NTerm *> terms;
    std::vector<int> types; //each type ranges from 0 to 3, represents rules 1 to 4

    NExpr() {}
    NExpr(std::vector<NTerm *> terms, std::vector<int> types) : terms(terms), types(types) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NTerm
{
public:
    std::vector<NFactor *> factors;
    std::vector<int> types; //each type ranges from 0 to 4, represents rules 1 to 5

    NTerm() {}
    NTerm(std::vector<NFactor *> factors, std::vector<int> types) : factors(factors), types(types) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
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

    NFactor(int type, std::string NAME) : type(type), NAME(NAME) {}
    NFactor(int type, std::string NAME, NArgsList *argsList) : type(type), NAME(NAME), argsList(argsList) {}
    NFactor(int type, int Sys_funct) : type(type), Sys_funct(Sys_funct) {}
    NFactor(int type, int Sys_funct, NArgsList *argsList) : type(type), Sys_funct(Sys_funct), argsList(argsList) {}
    NFactor(int type, NConstValue *constValue) : type(type), constValue(constValue) {}
    NFactor(int type, NExpression *expression) : type(type), expression(expression) {}
    NFactor(int type, NFactor *factor) : type(type), factor(factor) {}
    NFactor(int type, std::string id, NExpression *expression) : type(type), ID1(id), expression(expression) {}
    NFactor(int type, std::string ID1, std::string ID2) : type(type), ID1(ID1), ID2(ID2) {}

public:
    llvm::Value *codeGen(CodeGenContext *context);
};

class NArgsList
{
public:
    std::vector<NExpression *> expressions;

public:
    llvm::Value *codeGen(CodeGenContext *context);
};
#endif
