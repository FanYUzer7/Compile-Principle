#include "node.hpp"

NProgram::NProgram(NProgramHead *head, NRoutine *routine): head(head), routine(routine) {}

NProgramHead::NProgramHead(const std::string &id) : id(id) {}

NRoutine::NRoutine(NRoutineHead *head, NRoutineBody *body) : routineHead(head), routineBody(body) {}

NRoutineHead::NRoutineHead(NConstPart *constPart, NTypePart *typePart, NVarPart *varPart, NRoutinePart *routinePart): constPart(constPart), typePart(typePart), 
                varPart(varPart), routinePart(routinePart) {}

NConstPart::NConstPart(NConstExpressionList *constExprList): constExprList(constExprList){}

NConst::NConst(std::string NAME, NConstValue *value): NAME(NAME), value(value) {
	SYMENTRY sym = insertEntry((char*)NAME.c_str());

	switch (value->type)
	{
	case TYPE_INT:
		sym->type = SYM_BASIC;
		sym->basicType = TYPE_INT;
		sym->constVal.intVal = value->Integer;
		break;
	case TYPE_REAL:
		sym->type = SYM_BASIC;
		sym->basicType = TYPE_REAL;
		sym->constVal.realVal = value->Real;
		break;
	case TYPE_CHAR:
		sym->type = SYM_BASIC;
		sym->basicType = TYPE_CHAR;
		sym->constVal.charConst = value->Char;
		break;
	case TYPE_BOOL:
		sym->type = SYM_BASIC;
		sym->basicType = TYPE_CHAR;
		sym->constVal.intVal = value->Char;
		break;
	}
}

NConstValue::NConstValue(int type, int Integer) : type(type) { 
	if(type==0) 
		Integer = Integer;
	else
		Sys_con = Integer;
}

NConstValue::NConstValue(int type, double Real) : type(type), Real(Real) { }

NConstValue::NConstValue(int type, char Char) : type(type), Char(Char) { }

NTypePart::NTypePart(NTypeDefList *typeDefList): typeDefList(typeDefList){}

NTypeDefinition::NTypeDefinition(std::string NAME, NTypeDecl *typeDecl) : NAME(NAME), typeDecl(typeDecl) {}

NSimpleType::NSimpleType(int type, int Sys_type) : type(type), Sys_type(Sys_type) {}

NSimpleType::NSimpleType(int type, std::string NAME) : type(type), NAME1(NAME) {}

NSimpleType::NSimpleType(int type, NNameList *nameList) : type(type), nameList(nameList) {}

NSimpleType::NSimpleType(int type, NConstValue *constValue1, NConstValue *constValue2) : type(type), constValue1(constValue1), constValue2(constValue2) {}

NSimpleType::NSimpleType(int type, std::string NAME1, std::string NAME2) : type(type), NAME1(NAME1), NAME2(NAME2) {}

NTypeDecl::NTypeDecl(int type, NSimpleType *simpleType) : type(type), simpleType(simpleType) {
	if(simpleType != nullptr)
		switch(simpleType->type){
			case 4: {
				array_start = simpleType->constValue1->Integer;
				array_end = simpleType->constValue2->Integer;
				break;
			}
			case 5: {
				array_start = -(simpleType->constValue1->Integer);
				array_end = simpleType->constValue2->Integer;
				break;
			}
			case 6: {
				array_start = -(simpleType->constValue1->Integer);
				array_end = -(simpleType->constValue2->Integer);
				break;
			}
			default: break;
		}
}

NTypeDecl::NTypeDecl(int type, NArrayType *arrayType) : type(type), arrayType(arrayType) {}

NTypeDecl::NTypeDecl(int type, NRecordType *recordType) : type(type), recordType(recordType) {}

NArrayType::NArrayType(NSimpleType *simpleType, NTypeDecl *typeDecl) : simpleType(simpleType), typeDecl(typeDecl) {}

NRecordType::NRecordType(NFieldDeclList *fieldDeclList) : fieldDeclList(fieldDeclList) {}

NFieldDecl::NFieldDecl(NNameList *nameList, NTypeDecl *typeDecl) : nameList(nameList), typeDecl(typeDecl) {}

NVarPart::NVarPart(NVarDeclList *varDeclList) : varDeclList(varDeclList) {}

NVarDecl::NVarDecl(NNameList *nameList, NTypeDecl *typeDecl) : nameList(nameList), typeDecl(typeDecl) {
	for(std::string& name:nameList->IDs){
		SYMENTRY sym = insertEntry((char*)name.c_str());
		if(typeDecl->type == 0) //simpleType
		{
			if(typeDecl->simpleType != nullptr){
				if(typeDecl->simpleType->type == 0){
					switch (typeDecl->simpleType->Sys_type)
					{
					case 0:
						sym->basicType = TYPE_BOOL;
						sym->type = SYM_BASIC;
						break;
					case 1:
						sym->basicType = TYPE_CHAR;
						sym->type = SYM_BASIC;
						break;
					case 2:
						sym->basicType = TYPE_INT;
						sym->type = SYM_BASIC;
						break;
					case 3:
						sym->basicType = TYPE_REAL;
						sym->type = SYM_BASIC;
						break;
					}
				}
			}
		}
		else if(typeDecl->type == 1){  //arrayType
			sym->type = SYM_ARRAY;
			if(typeDecl->arrayType->typeDecl->type==0){
				if(typeDecl->arrayType->typeDecl->simpleType != nullptr){
					if(typeDecl->simpleType->type == 0){
						switch (typeDecl->simpleType->Sys_type)
						{
						case 0:
							sym->basicType = TYPE_BOOL;
							break;
						case 1:
							sym->basicType = TYPE_CHAR;
							break;
						case 2:
							sym->basicType = TYPE_INT;
							break;
						case 3:
							sym->basicType = TYPE_REAL;
							break;
						}
					}
				}
			}
			if(typeDecl->arrayType->simpleType->type==3){
				if(typeDecl->arrayType->simpleType->constValue1->type==0 && typeDecl->arrayType->simpleType->constValue2->type==0){
					sym->lowerBound = typeDecl->arrayType->simpleType->constValue1->Integer;
					sym->higherBound = typeDecl->arrayType->simpleType->constValue2->Integer;
				}
				else{
					printf("ERROR: at line %d: array bound must be integer\n",line_cnt);
					exit(-1);
				}
			}
			else if(typeDecl->arrayType->simpleType->type == 6){
				SYMENTRY sym1 = searchByName((char*)typeDecl->arrayType->simpleType->NAME1.c_str());
				SYMENTRY sym2 = searchByName((char*)typeDecl->arrayType->simpleType->NAME2.c_str());
				if(sym1==nullptr){
					printf("ERROR: at line %d: %s is not defined!\n",line_cnt,typeDecl->arrayType->simpleType->NAME1.c_str());
					exit(-1);
				}
				if(sym2==nullptr){
					printf("ERROR: at line %d: %s is not defined!\n",line_cnt,typeDecl->arrayType->simpleType->NAME2.c_str());
					exit(-1);
				}
				if(sym1->basicType != TYPE_INT){
					printf("ERROR: at line %d: %s is not integer!\n",line_cnt,sym1->name);
					exit(-1);
				}
				if(sym2->basicType != TYPE_INT){
					printf("ERROR: at line %d: %s is not integer!\n",line_cnt,sym2->name);
					exit(-1);
				}
				sym->lowerBound = sym1->constVal.intVal;
				sym->higherBound = sym2->constVal.intVal;
			}
		}
	}
}

NBlockDecl::NBlockDecl(int type) : type(type) {}

NFuncDecl::NFuncDecl(NFuncHead *funcHead, NRoutine *subRoutine) :funcHead(funcHead), subRoutine(subRoutine), NBlockDecl(0) { }

NFuncHead::NFuncHead(std::string NAME, NParams *params, NSimpleType *simpleType) : NAME(NAME), params(params), simpleType(simpleType) {
	printf("NFuncHead\n");
	SYMENTRY res = symAlloc();
	if(res == nullptr) printf("res is nullptr\n");
	if(simpleType != nullptr && simpleType->type==0){
		switch (simpleType->Sys_type)
		{
		case 0:
			res->basicType = TYPE_BOOL;
			res->type = SYM_BASIC;
			break;
		case 1:
			res->basicType = TYPE_CHAR;
			res->type = SYM_BASIC;
			break;
		case 2:
			res->basicType = TYPE_INT;
			res->type = SYM_BASIC;
			break;
		case 3:
			res->basicType = TYPE_REAL;
			res->type = SYM_BASIC;
			break;
		}
	}
	
	SYMENTRY head = nullptr;
	SYMENTRY tail = nullptr;
	for(NParamsTypeList * paramsTypeList:params->paramsDeclList->paramsTypes){
		if(paramsTypeList == nullptr) printf("paramsTypeList is nullptr\n");
		if(paramsTypeList->type == 0){ //var_par_list
			if(paramsTypeList->varParamsList==nullptr) printf("paramsTypeList->varParamsList is nullptr\n");
			if(paramsTypeList->varParamsList->nameList==nullptr) printf("nameList is nullptr\n");
			for(std::string& name:paramsTypeList->varParamsList->nameList->IDs){
				SYMENTRY sym = createByName((char*)name.c_str());
				if(sym==nullptr) printf("sym_var is nullptr\n");
				sym->type = SYM_VAR;
				if(paramsTypeList->simpleType != nullptr && paramsTypeList->simpleType->type==0){
					switch (paramsTypeList->simpleType->Sys_type)
					{
					case 0:
						sym->basicType = TYPE_BOOL;
						break;
					case 1:
						sym->basicType = TYPE_CHAR;
						break;
					case 2:
						sym->basicType = TYPE_INT;
						break;
					case 3:
						sym->basicType = TYPE_REAL;
						break;
					}
				}
				if(head == nullptr){
					head = sym;
					head->next = nullptr;
					tail = head;
				}
				else{
					tail->next = sym;
					tail = tail->next;
				}
			}
		}
		else if(paramsTypeList->type == 1){ //val_par_list
			for(std::string& name:paramsTypeList->varParamsList->nameList->IDs){
				SYMENTRY sym = createByName((char*)name.c_str());
				if(sym==nullptr) printf("sym_val is nullptr\n");
				sym->type = SYM_ARGMENT;
				if(paramsTypeList->simpleType != nullptr && paramsTypeList->simpleType->type==0){
					switch (paramsTypeList->simpleType->Sys_type)
					{
					case 0:
						sym->basicType = TYPE_BOOL;
						break;
					case 1:
						sym->basicType = TYPE_CHAR;
						break;
					case 2:
						sym->basicType = TYPE_INT;
						break;
					case 3:
						sym->basicType = TYPE_REAL;
						break;
					}
				}
				if(head == nullptr){
					head = sym;
					head->next = nullptr;
					tail = head;
				}
				else{
					tail->next = sym;
					tail = tail->next;
				}
			}
		}
	}
	insertFuncList((char*)NAME.c_str(),res,head);
	printf("insert success\n");
}

NProcDecl::NProcDecl(NProcHead *procHead, NRoutine *subRoutine) : procHead(procHead), subRoutine(subRoutine), NBlockDecl(1){}

NProcHead::NProcHead(std::string NAME, NParams *params) : NAME(NAME), params(params) {}

NParams::NParams(NParamsDeclList *paramsDeclList) : paramsDeclList(paramsDeclList) {}

NParamsTypeList::NParamsTypeList(int type, NVarParamsList *varParamsList, NSimpleType *simpleType) : type(type), varParamsList(varParamsList), simpleType(simpleType) {}

NParamsTypeList::NParamsTypeList(int type, NValParamsList *valParamsList, NSimpleType *simpleType) : type(type), valParamsList(valParamsList), simpleType(simpleType) {}

NVarParamsList::NVarParamsList(NNameList *nameList) : nameList(nameList) {}

NValParamsList::NValParamsList(NNameList *nameList) : nameList(nameList) {}

NRoutineBody::NRoutineBody(NCompStmt *compStmt) : compStmt(compStmt) {}

NCompStmt::NCompStmt(NStmtList *stmtList) : stmtList(stmtList) {}

NStmt::NStmt(int type, NNonLabStmt *nonLabStmt) : type(type), nonLabStmt(nonLabStmt) {}

NStmt::NStmt(int type, int Integer, NNonLabStmt *nonLabStmt) : type(type), Integer(Integer), nonLabStmt(nonLabStmt) {}

NNonLabStmt::NNonLabStmt(int type, NAssignStmt *assignStmt) : type(type), assignStmt(assignStmt) {}

NNonLabStmt::NNonLabStmt(int type, NProcStmt *procStmt) : type(type), procStmt(procStmt) {}

NNonLabStmt::NNonLabStmt(int type, NCompStmt *compStmt) : type(type), compStmt(compStmt) {}

NNonLabStmt::NNonLabStmt(int type, NIfStmt *ifStmt) : type(type), ifStmt(ifStmt) {}

NNonLabStmt::NNonLabStmt(int type, NRepeatStmt *repeatStmt) : type(type), repeatStmt(repeatStmt) {}

NNonLabStmt::NNonLabStmt(int type, NWhileStmt *whileStmt) : type(type), whileStmt(whileStmt) {}

NNonLabStmt::NNonLabStmt(int type, NForStmt *forStmt) : type(type), forStmt(forStmt) {}

NNonLabStmt::NNonLabStmt(int type, NCaseStmt *caseStmt) : type(type), caseStmt(caseStmt) {}

NNonLabStmt::NNonLabStmt(int type, NGotoStmt *gotoStmt) : type(type), gotoStmt(gotoStmt) {}

NAssignStmt::NAssignStmt(int type, std::string id, NExpression *expression) : type(type), ID1(id), expression1(expression) {
	SYMENTRY sym = searchByName((char*)id.c_str());
	if(sym == nullptr){
		printf("ERROR: at line %d: %s is not defined!\n",line_cnt,id.c_str());
		exit(-1);
	}
}

NAssignStmt::NAssignStmt(int type, std::string id, NExpression *expression1, NExpression *expression2) : type(type), ID1(id), expression1(expression1), expression2(expression2) {
	SYMENTRY sym = searchByName((char*)id.c_str());
	if(sym == nullptr){
		printf("ERROR: at line %d: %s is not defined!\n",line_cnt,id.c_str());
		exit(-1);
	}
	if(sym->type != SYM_ARRAY){
		printf("ERROR: at line %d: %s is not an array type!\n",line_cnt,id.c_str());
		exit(-1);
	}
}

NAssignStmt::NAssignStmt(int type, std::string ID1, std::string ID2, NExpression *expression) : type(type), ID1(ID1), ID2(ID2), expression1(expression) {}

NProcStmt::NProcStmt(int type, std::string id) : type(type), id(id) {}

NProcStmt::NProcStmt(int type, std::string id, NArgsList *argsList) : type(type), id(id), argsList(argsList) {}

NProcStmt::NProcStmt(int type, int Sys_proc) : type(type), Sys_proc(Sys_proc) {}

NProcStmt::NProcStmt(int type, int Sys_proc, NExprList *exprList) : type(type), Sys_proc(Sys_proc), exprList(exprList) {}

NProcStmt::NProcStmt(int type, NFactor *factor) : type(type), factor(factor) {}

NIfStmt::NIfStmt(NExpression *expression, NStmt *stmt, NElseStmt *elseStmt) : expression(expression), stmt(stmt), elseStmt(elseStmt) {}

NElseStmt::NElseStmt(NStmt *stmt) : stmt(stmt) {}

NRepeatStmt::NRepeatStmt(NStmtList *stmtList, NExpression *expression) : stmtList(stmtList), expression(expression) {}

NWhileStmt::NWhileStmt(NExpression *expression, NStmt *stmt) : expression(expression), stmt(stmt) {}

NForStmt::NForStmt(std::string id, NExpression *expression1, NDirection *direction, NExpression *expression2, NStmt *stmt) : id(id), expression1(expression1), direction(direction), expression2(expression2), stmt(stmt) {}

NDirection::NDirection(int type) : type(type) {}

NCaseStmt::NCaseStmt(NExpression *expression, NCaseExprList *caseExprList) : expression(expression), caseExprList(caseExprList) {}

NCaseExpr::NCaseExpr(int type, NConstValue *constValue, NStmt *stmt) : type(type), constValue(constValue), stmt(stmt) {}

NCaseExpr::NCaseExpr(int type, std::string id, NStmt *stmt) : type(type), id(id), stmt(stmt) {}

NGotoStmt::NGotoStmt(int Integer) : Integer(Integer) {}

NExpression::NExpression(){}

NExpression::NExpression(std::vector<NExpr *> exprs, std::vector<int> types):types(types), exprs(exprs){}

NExpr::NExpr(){}

NExpr::NExpr(std::vector<NTerm *> terms, std::vector<int> types): terms(terms), types(types){}

NTerm::NTerm(){}

NTerm::NTerm(std::vector<NFactor *> factors, std::vector<int> types): factors(factors), types(types){}

NFactor::NFactor(int type, std::string NAME) : type(type), NAME(NAME) {
	printf("%s\n",NAME.c_str());
	if(type==0){
		printf("before search\n");
		SYMENTRY sym = searchByName((char*)NAME.c_str());
		printf("after search\n");
		if(sym == nullptr){
			printf("sym in Factor(0) is nullptr\n");
			printf("ERROR: at line %d: %s is not defined!\n",line_cnt,NAME.c_str());
			exit(-1);
		}
	}
}

NFactor::NFactor(int type, std::string NAME, NArgsList *argsList) : type(type), NAME(NAME), argsList(argsList) {
	if(type == 1){
		SYMENTRY sym = searchByName((char*)NAME.c_str());
		if(sym == nullptr){
			printf("ERROR: at line %d: %s is not defined!\n",line_cnt,NAME.c_str());
			exit(-1);
		}
		if(sym->type != SYM_FUNCTION){
			printf("ERROR: at line %d: %s is a function!\n",line_cnt,NAME.c_str());
			exit(-1);
		}
		int argCont = 0;
		for(SYMENTRY ptr = sym->dataType->next;ptr != nullptr && ptr->next != nullptr;ptr = ptr->next){
			argCont++;
		}
		if(argCont != argsList->expressions.size()){
			printf("ERROR: at line %d: %s receives wrong number of arguments!\n",line_cnt,NAME.c_str());
			exit(-1);
		}
	}
}

NFactor::NFactor(int type, int Sys_funct) : type(type), Sys_funct(Sys_funct) {}

NFactor::NFactor(int type, int Sys_funct, NArgsList *argsList) : type(type), Sys_funct(Sys_funct), argsList(argsList) {}

NFactor::NFactor(int type, NConstValue *constValue) : type(type), constValue(constValue) {}

NFactor::NFactor(int type, NExpression *expression) : type(type), expression(expression) {}

NFactor::NFactor(int type, NFactor *factor) : type(type), factor(factor) {}

NFactor::NFactor(int type, std::string id, NExpression *expression) : type(type), ID1(id), expression(expression) {
	if(type == 8){
		SYMENTRY sym = searchByName((char*)id.c_str());
		if(sym == nullptr){
			printf("ERROR: at line %d: %s is not defined!\n",line_cnt,id.c_str());
			exit(-1);
		}
		if(sym->type != SYM_ARRAY){
			printf("ERROR: at line %d: %s is not an array type!\n",line_cnt,id.c_str());
			exit(-1);
		}
	}
}

NFactor::NFactor(int type, std::string ID1, std::string ID2) : type(type), ID1(ID1), ID2(ID2) {}