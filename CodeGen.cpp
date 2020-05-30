#include <iostream>
#include <vector>
#include <typeinfo>
#include "CodeGen.h"

//--------------------------------------------------------------

llvm::Function *createPrintf(CodeGenContext *context)
{
    std::vector<llvm::Type *> argTypes;
    argTypes.push_back(llvm::Type::getInt8PtrTy(GlobalContext));  // push 第一个参数的类型 char *
    llvm::FunctionType *printType = llvm::FunctionType::get(  // 构造函数类型
		llvm::Type::getInt32Ty(GlobalContext),  // Type *Result 			// 返回 int
		llvm::makeArrayRef(argTypes),       // ArrayRef<Type *> Params  // 参数表
        true);                              // bool isVarArg            // 是否为变长参数
    llvm::Function *func = llvm::Function::Create(  // 根据函数类型构造函数体
		printType,                        // FunctionType *Ty      // 函数类型
		llvm::Function::ExternalLinkage,  // LinkageTypes Linkage  // 定义外部链接
		llvm::Twine("printf"),            // const Twine &N        // 函数名称
		context->module);                  // Module *M             // 装载的 module
    func->setCallingConv(llvm::CallingConv::C);  // 设置调用常数
    return func;
}

llvm::Value *getArrRef(std::string name, NExpression *expression, CodeGenContext *context)  // 获得一个 llvm 数组某下标的地址
{
	std::string arrName = name;

		std::vector<llvm::Value *> arrIdx(2);
        arrIdx[0] = llvm::ConstantInt::get(
			GlobalContext,
			llvm::APInt(32, 0, true));  // 构建 llvm 整型常数，值为 0
        arrIdx[1] = expression->codeGen(context);  //  获取二元表达式的第二个变量的值

        return llvm::GetElementPtrInst::CreateInBounds(
			context->getValue(arrName),               // Value *Ptr                // 从 context 中找到数组变量
			llvm::ArrayRef<llvm::Value *>(arrIdx),  // ArrayRef<Value *> IdxList
			llvm::Twine("tempname"),                 // const Twine &NameStr
			context->getCurBlock());                  // BasicBlock *InsertAtEnd
}

/* ================== code generate =================== */
llvm::Value *NProgram::codeGen(CodeGenContext *context)
{
    this->head->codeGen(context);
	std::cout << "start return" << std::endl;
    return this->routine->codeGen(context);
}

llvm::Value *NProgramHead::codeGen(CodeGenContext *context)
{	
	std::cout << "head codeGen" << std::endl;
    return nullptr;
}

llvm::Value *NRoutine::codeGen(CodeGenContext *context)
{
	std::cout << "routine codegen" << std::endl;
    this->routineHead->codeGen(context);
    return this->routineBody->codeGen(context);
}

llvm::Value *NRoutineHead::codeGen(CodeGenContext *context)
{
	std::cout << "routine head codegen" << std::endl;
    this->constPart->codeGen(context);
	std::cout << "type codegen" << std::endl;
    this->typePart->codeGen(context);
	std::cout << "var codegen" << std::endl;
    this->varPart->codeGen(context);
	std::cout << "route part codegen" << std::endl;
	this->routinePart->codeGen(context);
	return nullptr;
}

llvm::Value *NConstPart::codeGen(CodeGenContext *context)
{
	std::cout << "cost part codegen" << std::endl;
	if(this->constExprList==nullptr){
		return nullptr;//my
	}
    return this->constExprList->codeGen(context);
}

llvm::Value *NConstExpressionList::codeGen(CodeGenContext *context)
{
	std::cout << "cost expression list codegen" << std::endl;
	std::cout <<"const exp list size: "<< this->constList.size() << std::endl;
	/*
	if (this->constList.size() > 1000){
		this->constList.clear();//my
	}
	*/
    for(int i = 0; i < this->constList.size(); i++)
    {
        this->constList[i]->codeGen(context);
    }
    return nullptr;

}

llvm::Value *NConst::codeGen(CodeGenContext *context)
{
	std::cout << "cost list codegen" << std::endl;
	llvm::Value *alloc = new llvm::AllocaInst(  // 为常量分配空间
		context->getLLVMTy(this),   // Type *Ty                 // 类型
		0,                                        // unsigned AddrSpace
		llvm::Twine(this->NAME),                  // const Twine &Name        // 常量名称
		context->getCurBlock());                   // BasicBlock *InsertAtEnd
	llvm::Value *store = new llvm::StoreInst(  // 将常量的值赋到空间中
		this->value->codeGen(context),  // Value *Val              // 常量的值
		alloc,                     // Value *Ptr              // 常量的地址
		false,                     // bool isVolatile         // 不可更改
		context->getCurBlock());    // BasicBlock InsertAtEnd

	context->insertConst(this->NAME, this);  // 添加常量到上下文中
	std::cout << "[Success] Const defined: " << this->NAME << std::endl;
	return store;
}

llvm::Value *NConstValue::codeGen(CodeGenContext *context)
{
	std::cout<<"const value type: "<<this->type<<std::endl;
	switch (this->type)
	{
	case 0: return llvm::ConstantInt::get(llvm::Type::getInt32Ty(GlobalContext), this->Integer, true);
	case 1: return llvm::ConstantInt::get(llvm::Type::getDoubleTy(GlobalContext), this->Real, true);
	case 2: return llvm::ConstantInt::get(llvm::Type::getInt8Ty(GlobalContext), this->Char, true);
	case 3: return llvm::ConstantInt::get(llvm::Type::getInt32Ty(GlobalContext), this->Sys_con, true);
	}
	
}

llvm::Value *NTypePart::codeGen(CodeGenContext *context)
{
	std::cout << "type codegen" << std::endl;
	std::cout << typeid(this).name() << std::endl;
	if (this->typeDefList != nullptr){//my
		return this->typeDefList->codeGen(context);
	}
	else{
		return nullptr;
	}
}

llvm::Value *NTypeDefList::codeGen(CodeGenContext *context)
{
	std::cout << "type def list codegen" << std::endl;
	std::cout <<"type def list size: "<<this->typeDefList.size() << std::endl;
	for (int i = 0; i < this->typeDefList.size(); i++)
		this->typeDefList[i]->codeGen(context);
	return nullptr;
}

llvm::Value *NTypeDefinition::codeGen(CodeGenContext *context)
{
	std::cout << "type definition codegen" << std::endl;
	context->getCurCodeGenBlock()->typedefs[this->NAME] = this->typeDecl;
	return nullptr;
}

llvm::Value *NTypeDecl::codeGen(CodeGenContext *context)
{
	return nullptr;
    
}

llvm::Value *NSimpleType::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NArrayType::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NRecordType::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NFieldDeclList::codeGen(CodeGenContext *context)
{
	for (int i = 0; i < this->fieldDecls.size(); i++)
		this->fieldDecls[i]->codeGen(context);
	return nullptr;
}

llvm::Value *NFieldDecl::codeGen(CodeGenContext *context)
{
    
}

llvm::Value *NNameList::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NVarPart::codeGen(CodeGenContext *context)
{
	std::cout << "var part codegen"<< std::endl;
	if (this->varDeclList==nullptr){//my
		return nullptr;
	}
	return this->varDeclList->codeGen(context);
}

llvm::Value *NVarDeclList::codeGen(CodeGenContext *context)
{
	for (int i = 0; i < this->varDecls.size(); i++)
		this->varDecls[i]->codeGen(context);
	return nullptr;
}
/*底层*/
llvm::Value *NVarDecl::codeGen(CodeGenContext *context)
{
	llvm::Value *alloc;

	if (this->typeDecl->type == 1) {  // 如果是数组
		std::cout << " |---|--- Array variable" << std::endl;

		std::vector<llvm::Constant *> vec = std::vector<llvm::Constant *>();
		llvm::Constant *eleOfArr;
		switch (this->typeDecl->arrayType->typeDecl->type) {  // 对全局变量进行初始化
		case 0: { //simple type
			switch (this->typeDecl->arrayType->typeDecl->simpleType->Sys_type) 
			{
			case 0:eleOfArr = llvm::ConstantInt::get(llvm::Type::getInt1Ty(GlobalContext), 0, true); break;
			case 1:eleOfArr = llvm::ConstantInt::get(llvm::Type::getInt8Ty(GlobalContext), 0, true); break;
			case 2:eleOfArr = llvm::ConstantInt::get(llvm::Type::getInt32Ty(GlobalContext), 0, true); break;
			case 3:eleOfArr = llvm::ConstantFP::get(llvm::Type::getFloatTy(GlobalContext), 0);       break;
			}
			break;}
		case 1:   //array type
			break;
		case 2:   //record type
			break;
		default:
			std::cout << "[Warning] Uncomplete feature for global array of record" << std::endl;
			exit(0);
		}

		for (int i = 0; i < this->typeDecl->array_end - this->typeDecl->array_start + 1; i++) 
		{
			vec.push_back(eleOfArr);
		}

		llvm::ArrayType *arrType = static_cast<llvm::ArrayType *>(context->getLLVMTy(this->typeDecl));
		llvm::Constant *arrConst = llvm::ConstantArray::get(arrType, vec);
		for (int i = 0; i < this->nameList->IDs.size(); i++)
		{
			alloc = new llvm::GlobalVariable(
				*context->module,                     // Module &M
				context->getLLVMTy(this->typeDecl),       // Type *Ty               // 全局变量的类型
				false,                               // bool isConstant        // 是否常量
				llvm::GlobalValue::ExternalLinkage,  // LinkageTypes Linkage
				arrConst,                            // Constant *Initializer  // 全局变量初始化为 0
				llvm::Twine(this->nameList->IDs[i]));            // const Twine &Name      // 变量名称             //问题：变量名多个
		}
	}
	else if (this->typeDecl->type == 2) {
		std::cout << "[Warning] Uncomplete feature for gloable record" << std::endl;
		exit(0);
	}
	else {  // 不是数组
		llvm::Constant *arrConst;
		switch (this->typeDecl->simpleType->Sys_type) {
		case 2: arrConst = llvm::ConstantInt::get(llvm::Type::getInt32Ty(GlobalContext), 0, true); break;
		case 3: arrConst = llvm::ConstantFP::get(llvm::Type::getFloatTy(GlobalContext), 0);       break;
		case 1: arrConst = llvm::ConstantInt::get(llvm::Type::getInt8Ty(GlobalContext), 0, true); break;
		case 0: arrConst = llvm::ConstantInt::get(llvm::Type::getInt1Ty(GlobalContext), 0, true); break;
		default:;
		}
		for (int i = 0; i < this->nameList->IDs.size(); i++)
		{
			alloc = new llvm::GlobalVariable(
				*context->module,
				context->getLLVMTy(this->typeDecl),
				false,
				llvm::GlobalValue::ExternalLinkage,
				arrConst,
				llvm::Twine(this->nameList->IDs[0]));
		}		
	}
	return alloc;
}
/*根据type判断是func还是proc，然后分别做对应的codegen*/
llvm::Value *NRoutinePart::codeGen(CodeGenContext *context)
{
	for (int i = 0; i < this->blockDecls.size(); i++)
	{
		if (this->blockDecls[i]->type == 0)
			static_cast<NFuncDecl *>(this->blockDecls[i])->codeGen(context);
		else if (this->blockDecls[i]->type == 1)
			static_cast<NProcDecl *>(this->blockDecls[i])->codeGen(context);
	}
	return nullptr;
}

llvm::Value *NBlockDecl::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NFuncDecl::codeGen(CodeGenContext *context)
{
	context->defined_functions[this->funcHead->NAME] = this;
	std::vector<llvm::Type *> argTy;
	int i, j;
	for (i = 0; i < this->funcHead->params->paramsDeclList->paramsTypes.size(); i++)
	{
		if (this->funcHead->params->paramsDeclList->paramsTypes[i]->type == 1)  //val
		{
			for (j = 0; j < this->funcHead->params->paramsDeclList->paramsTypes[i]->valParamsList->nameList->IDs.size(); j++)
			{
				argTy.push_back(context->getLLVMTy(this->funcHead->params->paramsDeclList->paramsTypes[i]->simpleType));
			}
		}

		if (this->funcHead->params->paramsDeclList->paramsTypes[i]->type == 0)  //var
		{
			for (j = 0; j < this->funcHead->params->paramsDeclList->paramsTypes[i]->varParamsList->nameList->IDs.size(); j++)
			{
				argTy.push_back(llvm::Type::getInt32PtrTy(GlobalContext));
			}
		}
	}

	llvm::FunctionType *funcType = llvm::FunctionType::get(
		context->getLLVMTy(this->funcHead->simpleType),  // Type *Ty                 // 函数返回值类型
		llvm::makeArrayRef(argTy),          // ArrayRef<Type *> Params  // 参数类型
		false);                             // bool isVarArg            // 定长
	llvm::Function *func = llvm::Function::Create(
		funcType,
		llvm::GlobalValue::InternalLinkage,
		llvm::Twine(this->funcHead->NAME),             // 函数名
		context->module);

	llvm::BasicBlock *block = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("entry"),
		func,
		nullptr);              // BasicBlock *InsertBefore


	llvm::Function *oldFunc = context->getCurFunc();
	context->setCurFunc(func);
	llvm::BasicBlock *oldBlock = context->getCurBlock();
	context->parent[func] = oldFunc;
	context->pushBlock(block);

	/*变量表*/
	llvm::Value *argValue;
	llvm::Argument *argValue_iter = func->arg_begin();

	for (i = 0; i < this->funcHead->params->paramsDeclList->paramsTypes.size(); i++)
	{
		if (this->funcHead->params->paramsDeclList->paramsTypes[i]->type == 1) //val
		{
			for (j = 0; j < this->funcHead->params->paramsDeclList->paramsTypes[i]->valParamsList->nameList->IDs.size(); j++)
			{
				llvm::Type *ty;
				ty = context->getLLVMTy(this->funcHead->params->paramsDeclList->paramsTypes[i]->simpleType);
				llvm::Value *alloc = new llvm::AllocaInst(  // 为参数分配空间
					ty,                               // 参数类型
					0,
					llvm::Twine(this->funcHead->params->paramsDeclList->paramsTypes[i]->valParamsList->nameList->IDs[j]),  // 参数名
					context->getCurBlock());
				argValue = argValue_iter++;
				argValue->setName(llvm::Twine(this->funcHead->params->paramsDeclList->paramsTypes[i]->valParamsList->nameList->IDs[j]));
				new llvm::StoreInst(  // 存参数值
					argValue,  // 参数值
					alloc,     // 参数地址
					false,     // 非常量
					block);
			}
		}

		if (this->funcHead->params->paramsDeclList->paramsTypes[i]->type == 0) //var
		{
			for (j = 0; j < this->funcHead->params->paramsDeclList->paramsTypes[i]->varParamsList->nameList->IDs.size(); j++)
			{
				llvm::Type *ty;
				ty = llvm::Type::getInt32PtrTy(GlobalContext);
				llvm::Value *alloc = new llvm::AllocaInst(  // 为参数分配空间
					ty,                               // 参数类型
					0,
					llvm::Twine(this->funcHead->params->paramsDeclList->paramsTypes[i]->varParamsList->nameList->IDs[j]),  // 参数名
					context->getCurBlock());
				argValue = argValue_iter++;
				argValue->setName(llvm::Twine(this->funcHead->params->paramsDeclList->paramsTypes[i]->varParamsList->nameList->IDs[j]));
				new llvm::StoreInst(  // 存参数值
					argValue,  // 参数值
					alloc,     // 参数地址
					false,     // 非常量
					block);
			}
		}
	}

	if (this->funcHead->simpleType != nullptr) {
		new llvm::AllocaInst(  // 为返回值分配地址
			context->getLLVMTy(this->funcHead->simpleType),
			0,
			llvm::Twine(this->funcHead->NAME),
			context->getCurBlock());
		std::cout << "|--- Function return value declaration" << std::endl;
	}
	std::cout << "|--- [Success] Function header part generated success!" << std::endl;


	this->subRoutine->codeGen(context);

	if (this->funcHead->simpleType != nullptr) {
		llvm::Type *ty;
		ty = llvm::Type::getInt32PtrTy(GlobalContext);//my
		std::cout << "|--- Generating return value for function" << std::endl;
		llvm::Value *load = new llvm::LoadInst( // 加载返回值的地址
			ty,//my
			context->getValue(this->funcHead->NAME),
			llvm::Twine(""),
			false,
			context->getCurBlock());
		llvm::ReturnInst::Create(
			GlobalContext,
			load,
			context->getCurBlock());
		std::cout << "|--- Function returned" << std::endl;
	}
	else {
		std::cout << "|--- Generating return void for procedure" << std::endl;
		llvm::ReturnInst::Create(
			GlobalContext,
			context->getCurBlock());
		std::cout << "|--- Procedure returned" << std::endl;
	}

	while (context->getCurBlock() != oldBlock) {  // 函数定义完成
		context->popBlock();
	}
	context->setCurFunc(oldFunc);

	std::cout << "[Success] Defined function: " << this->funcHead->NAME << std::endl;
	return func;
}

llvm::Value *NFuncHead::codeGen(CodeGenContext *context)
{
	return nullptr;
}

/*底层，暂未实现*/
llvm::Value *NProcDecl::codeGen(CodeGenContext *context)
{
	this->procHead->codeGen(context);
	this->subRoutine->codeGen(context);
	return nullptr;
}

llvm::Value *NProcHead::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NParams::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NParamsDeclList::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NParamsTypeList::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NVarParamsList::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NValParamsList::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NRoutineBody::codeGen(CodeGenContext *context)
{
	std::cout << "route body codegen" << std::endl;
	return this->compStmt->codeGen(context);
}

llvm::Value *NCompStmt::codeGen(CodeGenContext *context)
{
	return this->stmtList->codeGen(context);
}

llvm::Value *NStmtList::codeGen(CodeGenContext *context)
{
	for (int i = 0; i < this->stmts.size(); i++)
		this->stmts[i]->codeGen(context);
	return nullptr;
}
/*暂未考虑第一种类型，即不考虑INTEGER COLON，不带标签*/
llvm::Value *NStmt::codeGen(CodeGenContext *context)
{
	return this->nonLabStmt->codeGen(context);
}

llvm::Value *NNonLabStmt::codeGen(CodeGenContext *context)
{
	switch (this->type)
	{
	case 0:this->assignStmt->codeGen(context);break;
	case 1:this->procStmt->codeGen(context); break;
	case 2:this->compStmt->codeGen(context); break;
	case 3:this->ifStmt->codeGen(context); break;
	case 4:this->repeatStmt->codeGen(context); break;
	case 5:this->whileStmt->codeGen(context); break;
	case 6:this->forStmt->codeGen(context); break;
	case 7:this->caseStmt->codeGen(context); break;
	case 8:this->gotoStmt->codeGen(context); break;
	default:break;
	}
	std::cout<<"nonlabstmt return"<<std::endl;
	return nullptr;
}

/*底层*/
llvm::Value *NAssignStmt::codeGen(CodeGenContext *context)
{
	std::cout << "Creating assignment statment..." << std::endl;
	std::cout <<"assignment type: "<<this->type << std::endl;
	if (this->type == 0)
	{
		llvm::Type *ty;
		ty = llvm::Type::getInt32PtrTy(GlobalContext); //my
		llvm::Value *tmp = context->getValue(this->ID1);
		std::cout<< "tmp type: "<<Print(tmp->getType())<<std::endl;
		llvm::Value *load;
		/*my
		do {
			load = tmp;
			tmp = new llvm::LoadInst(
				tmp,
				llvm::Twine(""),
				false,
				context->getCurBlock());
		} while (tmp->getType()->isPointerTy());
		*/
		load = tmp;
		tmp = new llvm::LoadInst(
			tmp->getType(),
			tmp,
			llvm::Twine(""),
			false,
			context->getCurBlock());
		std::cout<<"loadinst"<<std::endl;
		llvm::Value* exp_val = this->expression1->codeGen(context);
		std::cout<<"exp val"<<std::endl;
		llvm::Value* val = new llvm::StoreInst(
			exp_val,  // 值（右）
			load,          // 地址（左）
			false,
			context->getCurBlock());
		std::cout<<"assignstmt return"<<std::endl;
		return val;
	}
	else if (this->type == 1)
	{
		llvm::Value *elementPtr = getArrRef(this->ID1, this->expression1, context);  // 取得目标地址
		std::cout << "[Success] Assignment statment generate" << std::endl;
		return new llvm::StoreInst(
			this->expression2->codeGen(context),  // 值
			elementPtr,                           // 地址
			false,
			context->getCurBlock());
	}
	else if (this->type == 2)
	{
		//TODO
	}
	else
	{  // 如果左值不为变量/二元表达式
		std::cout << "[Error] Wrong left value type" << std::endl;
		exit(0);
	}
}

llvm::Value *NProcStmt::codeGen(CodeGenContext *context)
{
	std::vector<llvm::Value *> argValues;
	switch (this->type)
	{
	case 0:{
		llvm::Function *func = context->module->getFunction(this->id.c_str());  // 找到这个函数
		if (func == nullptr) {
			std::cout << "[Error] Function not defined" << std::endl;
			exit(0);
		}
		return llvm::CallInst::Create(
			func,
			nullptr,
			llvm::Twine(""),
			context->getCurBlock());}
	case 1:{
		llvm::Function *func = context->module->getFunction(this->id.c_str());  // 找到这个函数
		if (func == nullptr) {
			std::cout << "[Error] Function not defined" << std::endl;
			exit(0);
		}		
		auto funcArgs_iter = func->arg_begin();
		for (NExpression *arg : this->argsList->expressions) {
			llvm::Value *funcArgValue = static_cast<llvm::Value *>(funcArgs_iter++);
			if (funcArgValue->getType()->isPointerTy()) 
			{  // 如果这个参数是指针（全局变量）
				if (arg->exprs[0]->terms[0]->factors[0]->type == 0) {  // 如果这个参数是变量
					llvm::Value *ptr = context->getValue(
						arg->exprs[0]->terms[0]->factors[0]->NAME);  // 取得变量的值
					llvm::Type *ty;
					ty = llvm::Type::getInt32PtrTy(GlobalContext);//my
					while (ptr->getType() != llvm::Type::getInt32PtrTy(GlobalContext)) {
						ptr = new llvm::LoadInst(
							ty,
							ptr,
							llvm::Twine(""),
							false,
							context->getCurBlock());
					}
					argValues.push_back(ptr);
				}
				else if (arg->exprs[0]->terms[0]->factors[0]->type == 8) {
					if (true) {
						std::vector<llvm::Value*> arrIdx(2);
						arrIdx[0] = llvm::ConstantInt::get(
							GlobalContext,
							llvm::APInt(32, 0, true));
						arrIdx[1] = arg->exprs[0]->terms[0]->factors[0]->expression->codeGen(context);
						llvm::Value* ptr = llvm::GetElementPtrInst::CreateInBounds(
							context->getValue(arg->exprs[0]->terms[0]->factors[0]->ID1),
							llvm::ArrayRef<llvm::Value*>(arrIdx),
							llvm::Twine("tempname"),
							context->getCurBlock());
						argValues.push_back(ptr);
					}
					else {
						std::cout << "[Error] Array's Ref is not an array type variable" << std::endl;
						exit(0);
					}
					/*BinaryExp* node = static_cast<BinaryExp*>(arg);*/
					//if (node->op_code == OP_DOT) {  // 记录类型
					//	if (node->operand2->node_type == N_VARIABLE_EXP) {
					//		VariableExp* op2 = static_cast<VariableExp*>(node->operand2);
					//		int index = getRecordIndex(
					//			node->operand1->return_type,
					//			op2->name);
					//		std::vector<llvm::Value*> arrIdx(2);
					//		arrIdx[0] = llvm::ConstantInt::get(  // 0
					//			MyContext,
					//			llvm::APInt(32, 0, true));
					//		arrIdx[1] = llvm::ConstantInt::get(  // index
					//			MyContext,
					//			llvm::APInt(32, index, true));
					//		llvm::Value *ptr = llvm::GetElementPtrInst::Create(
					//			context->getLLVMTy(node->operand1->return_type),  // 类型
					//			context->getValue(op2->name),                     // 值
					//			arrIdx,                                         // 记录所存在的序号
					//			llvm::Twine(""),                                 // 名称
					//			context->getCurBlock());
					//		argValues.push_back(ptr);
					//	}
					//	else {
					//		std::cout << "[Error] operand2 of dot operation is not a variable exp type" << std::endl;
					//		exit(0);
					//	}
					//}
					//else if (node->op_code == OP_INDEX) {  // 数组类型
					//	if (node->operand1->node_type == N_VARIABLE_EXP) {
					//		VariableExp* op1 = static_cast<VariableExp*>(node->operand1);
					//		std::vector<llvm::Value*> arrIdx(2);
					//		arrIdx[0] = llvm::ConstantInt::get(
					//			MyContext,
					//			llvm::APInt(32, 0, true));
					//		arrIdx[1] = node->operand2->codeGen(context);
					//		llvm::Value* ptr = llvm::GetElementPtrInst::CreateInBounds(
					//			context->getValue(op1->name),
					//			llvm::ArrayRef<llvm::Value*>(arrIdx),
					//			llvm::Twine("tempname"),
					//			context->getCurBlock());
					//		argValues.push_back(ptr);
					//	}
					//	else {
					//		std::cout << "[Error] Array's Ref is not an array type variable" << std::endl;
					//		exit(0);
					//	}
					//  }
				}
				else {
					std::cout << "[Error] Wrong left value type" << std::endl;
				}
			}
			else {
				argValues.push_back(arg->codeGen(context));
			}
		}
		ArrayRef< Value* > arguments(argValues); //my
		return llvm::CallInst::Create(
			func,
			arguments,
			llvm::Twine(""),
			context->getCurBlock());
		}
	case 2:{
		if (this->Sys_proc == 0 or this->Sys_proc == 1)
		{
			std::string printf_format;
			std::vector<llvm::Value *> printfArgs;
			for (NExpression *arg : this->exprList->expressions) {
				llvm::Value *argValue = arg->codeGen(context);  // 得到参数的值
				if (argValue->getType() == llvm::Type::getInt32Ty(GlobalContext)) {
					printf_format += "%d";
					std::cout << "|--- System call write variable previous name" << argValue->getName().str() << std::endl;
					printfArgs.push_back(argValue);
				}
				else if (argValue->getType()->isFloatTy()) {
					printf_format += "%f";
					printfArgs.push_back(argValue);
				}
				else if (argValue->getType() == llvm::Type::getInt8PtrTy(GlobalContext)) {
					std::cout << "[Warning] string print is not supported" << std::endl;
					exit(0);
				}
				else {
					std::cout << "[Error] Unknown type for printf" << std::endl;
				}
			}
			if(this->Sys_proc == 1)
				printf_format += "\n";
			std::cout << "print format: " << printf_format << std::endl;
			llvm::Constant *printf_format_const = llvm::ConstantDataArray::getString(  // 创建常量 char*
				GlobalContext,
				printf_format.c_str());
			llvm::GlobalVariable *format_string_var = new llvm::GlobalVariable(  // 创建一个全局变量
				*context->module,
				llvm::ArrayType::get(                      // 变量类型 char*
					llvm::IntegerType::getInt8Ty(GlobalContext),
					strlen(printf_format.c_str()) + 1),
				true,                                      // 常量
				llvm::GlobalValue::PrivateLinkage,
				printf_format_const,                       // 变量的值
				llvm::Twine(".str"));
			llvm::Constant *zero = llvm::Constant::getNullValue(  // 创建一个 0
				llvm::IntegerType::getInt32Ty(GlobalContext));
			std::vector<llvm::Constant *> arrIdx;
			arrIdx.push_back(zero);
			arrIdx.push_back(zero);
			llvm::Constant *var_ref = llvm::ConstantExpr::getGetElementPtr(
				llvm::ArrayType::get(
					llvm::IntegerType::getInt8Ty(GlobalContext),
					strlen(printf_format.c_str()) + 1),
				format_string_var,                         // 全局变量
				arrIdx);                                  // 从 0 开始
			printfArgs.insert(printfArgs.begin(), var_ref);
			std::cout << "[Success] Print call generated" << std::endl;
			return llvm::CallInst::Create(
				context->printf,
				llvm::makeArrayRef(printfArgs),
				llvm::Twine(""),
				context->getCurBlock());
		}
		else
		{
			//error info
		}}
	case 3:  //SYS_PROC LP expression RP
		break;
	case 4:
		break;
	default:
		break;	
	}
}

llvm::Value *NIfStmt::codeGen(CodeGenContext *context)
{
	std::cout << "Creating if statment" << std::endl;
	llvm::Value* cond = this->expression->codeGen(context);
	std::cout << "|--- [Success] Condition generated" << std::endl;
	llvm::BasicBlock *trueBlock = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("then"),
		context->getCurFunc());
	llvm::BasicBlock *falseBlock = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("else"),
		context->getCurFunc());
	llvm::BasicBlock *mergeBlock = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("merge"),
		context->getCurFunc());

	llvm::Value *ret = llvm::BranchInst::Create(
		trueBlock,               // BasicBlock *True
		falseBlock,              // BasicBlock *False
		cond,                    // Value *cond
		context->getCurBlock());  // BasicBlock *InsertAtEnd

	context->pushBlock(trueBlock);
	this->stmt->codeGen(context);
	std::cout << "|--- [Success] True block generated" << std::endl;
	llvm::BranchInst::Create(  // 为真的语句生成完成，回到 merge
		mergeBlock,
		context->getCurBlock());
	context->popBlock();
	context->pushBlock(falseBlock);
	if (this->elseStmt != nullptr) {
		this->elseStmt->codeGen(context);
		std::cout << "|--- [Success] False block generated" << std::endl;
	}
	llvm::BranchInst::Create(  // 为假的语句生成完成，回到 merge
		mergeBlock,
		context->getCurBlock());
	context->popBlock();
	context->pushBlock(mergeBlock);
	std::cout << "[Success] If statment generated" << std::endl;
	return ret;
}

llvm::Value *NElseStmt::codeGen(CodeGenContext *context)
{
	return this->stmt->codeGen(context);
}

llvm::Value *NRepeatStmt::codeGen(CodeGenContext *context)
{
	std::cout << "Creating repeat statement" << std::endl;
	llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("loop"),
		context->getCurFunc());
	llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("exit"),
		context->getCurFunc());
	llvm::BranchInst::Create(  // 跳入 loopBlock
		loopBlock,
		context->getCurBlock());
	context->pushBlock(loopBlock);  // loopBlock
	this->stmtList->codeGen(context);  // 生成代码块
	llvm::Value* cond = this->expression->codeGen(context);  // 跳转条件
	llvm::Instruction *ret = llvm::BranchInst::Create(
		exitBlock,               // 符合 until 条件，退出
		loopBlock,               // 不符合，跳回 loopBlock
		cond,
		context->getCurBlock());
	context->popBlock();
	context->pushBlock(exitBlock);  // exitBlock
	std::cout << "[Success] Repeat loop generated" << std::endl;
	return ret;
}

llvm::Value *NWhileStmt::codeGen(CodeGenContext *context)
{
	std::cout << "Creating while statement" << std::endl;
	llvm::BasicBlock *startBlock = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("start"),
		context->getCurFunc());
	llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("loop"),
		context->getCurFunc());
	llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("exit"),
		context->getCurFunc());
	llvm::BranchInst::Create(  // 首先跳转入 startBlock
		startBlock,
		context->getCurBlock());
	context->pushBlock(startBlock);  // startBlock
	llvm::Value *ret = llvm::BranchInst::Create(
		loopBlock,                          // 符合 cond ，继续 loopBlock
		exitBlock,                          // 不符合 cond ，跳入 exitBlock
		this->expression->codeGen(context),
		context->getCurBlock());
	context->popBlock();
	context->pushBlock(loopBlock);  // loopBlock
	this->stmt->codeGen(context);  // 生成代码块
	llvm::BranchInst::Create(  // 继续循环，跳入 startBlock
		startBlock,
		context->getCurBlock());
	context->popBlock();
	context->pushBlock(exitBlock);  // exitBlock
	std::cout << "[Success] While loop generated" << std::endl;
	return ret;
}

llvm::Value *NForStmt::codeGen(CodeGenContext *context)
{
	std::cout << "Creating for statement" << std::endl;
	llvm::BasicBlock *startBlock = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("start"),
		context->getCurFunc());
	llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("loop"),
		context->getCurFunc());
	llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(
		GlobalContext,
		llvm::Twine("exit"),
		context->getCurFunc());

	NAssignStmt *initLoopVar = new NAssignStmt(  // 为循环变量赋初值
		1,
		this->id,
		this->expression1);
	initLoopVar->codeGen(context);  // 生成赋初值的代码 (i := start)
	llvm::BranchInst::Create(  // 跳转入 startBlock
		startBlock,
		context->getCurBlock());
	// 循环过程
	context->pushBlock(startBlock);  // startBlock
	
	llvm::Instruction *ret = llvm::BranchInst::Create(
		exitBlock,                // 到达终点值，跳入 exitBlock
		loopBlock,                // 未到达终点值，跳入 loopBlock
		llvm::CmpInst::Create(
			llvm::Instruction::ICmp,
			llvm::CmpInst::ICMP_EQ,
			context->getValue(this->id), 
			this->expression2->codeGen(context),
			llvm::Twine(""),
			context->getCurBlock()),
		context->getCurBlock());
	context->popBlock();
	context->pushBlock(loopBlock);  // loopBlock
	this->stmt->codeGen(context);  // 生成代码块
	// 循环变量的更新
	NConstValue * int1 = new NConstValue(0, 1);
	if (this->direction->type == 1)
		int1->Integer = -1;
	NFactor* factor1 = new NFactor(4, int1);
	NFactor* factorLoopVar = new NFactor(0, this->id);

	std::vector<NFactor*>VecFactor1;
	std::vector<NFactor*>VecFactorLoopVar;
	VecFactorLoopVar.push_back(factorLoopVar);
	VecFactor1.push_back(factor1);

	std::vector<int>VecFactorInt1;
	std::vector<int>VecFactorIntLoopVar;
	VecFactorInt1.push_back(4);
	VecFactorIntLoopVar.push_back(4);
	NTerm* term1 = new NTerm(VecFactor1, VecFactorInt1);
	NTerm* termLoopVar = new NTerm(VecFactorLoopVar, VecFactorIntLoopVar);
	std::vector<NTerm*>VecTerm;
	VecTerm.push_back(term1);
	VecTerm.push_back(termLoopVar);
	std::vector<int>VecTermInt;
	VecTermInt.push_back(3);
	VecTermInt.push_back(0);
	NExpr* expr1 = new NExpr(VecTerm, VecTermInt);
	std::vector<NExpr*>VecExpr;
	VecExpr.push_back(expr1);
	std::vector<int>VecExprInt;
	VecExprInt.push_back(6);
	NExpression* expressionUpdate = new NExpression(VecExpr, VecExprInt);


	NAssignStmt *updateLoopVar = new NAssignStmt(  // 更新循环变量的语句
		1,
		this->id,
		expressionUpdate);
	updateLoopVar->codeGen(context);   // i := i + 1 或 i := i - 1
	llvm::BranchInst::Create(  // 跳入 startBlock
		startBlock,
		context->getCurBlock());
	context->popBlock();
	context->pushBlock(exitBlock);  // exitBlock
	this->stmt->codeGen(context);  // 最后一次循环
	std::cout << "[Success] For loop generated" << std::endl;
	return ret;
}

llvm::Value *NDirection::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NCaseStmt::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NCaseExprList::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NCaseExpr::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NGotoStmt::codeGen(CodeGenContext *context)
{
	return nullptr;
}

llvm::Value *NExprList::codeGen(CodeGenContext *context)
{
	for (int i = 0; i < this->expressions.size(); i++)
		this->expressions[i]->codeGen(context);
	return nullptr;
}

llvm::Value *NExpression::codeGen(CodeGenContext *context)
{
	std::cout<<"expression codegen"<<std::endl;
	std::cout<<"expression expr size: "<<this->exprs.size()<<std::endl;
	llvm::Value *result = this->exprs[0]->codeGen(context);
	if (this->exprs.size() == 1){
		std::cout<<"expression early return"<<std::endl;
		return result;
	}
	for (int i = 0; i < this->types.size(); i++)
	{
		std::cout<<"expression i "<<i<<" type "<<this->types[i]<<std::endl;
		switch (this->types[i])
		{
		case 0:{
			result = llvm::CmpInst::Create(
			llvm::Instruction::ICmp,
			llvm::CmpInst::ICMP_SGE,
			result, this->exprs[i]->codeGen(context),
			llvm::Twine(""),
			context->getCurBlock());
			break;
		}
		case 1:{
			result = llvm::CmpInst::Create(
			llvm::Instruction::ICmp,
			llvm::CmpInst::ICMP_SGT,
			result, this->exprs[i]->codeGen(context),
			llvm::Twine(""),
			context->getCurBlock());
			break;}
		case 2:{
			result = llvm::CmpInst::Create(
				llvm::Instruction::ICmp,
				llvm::CmpInst::ICMP_SLE,
				result, this->exprs[i]->codeGen(context),
				llvm::Twine(""),
				context->getCurBlock());
			break;}
		case 3:{
			result = llvm::CmpInst::Create(
				llvm::Instruction::ICmp,
				llvm::CmpInst::ICMP_SLT,
				result, this->exprs[i]->codeGen(context),
				llvm::Twine(""),
				context->getCurBlock());
			break;}
		case 4:{
			result = llvm::CmpInst::Create(
				llvm::Instruction::ICmp,
				llvm::CmpInst::ICMP_EQ,
				result, this->exprs[i]->codeGen(context),
				llvm::Twine(""),
				context->getCurBlock());
			break;}
		case 5:{
			result = llvm::CmpInst::Create(
				llvm::Instruction::ICmp,
				llvm::CmpInst::ICMP_NE,
				result, this->exprs[i]->codeGen(context),
				llvm::Twine(""),
				context->getCurBlock());
			break;}
		case 6:break;
		default:
			//error info
			break;
		}
	}
	std::cout<<"expression return"<<std::endl;
	return result;
}

llvm::Value *NExpr::codeGen(CodeGenContext *context)
{
	std::cout<<"expr codegen"<<std::endl;
	std::cout<<"expr term size "<<this->terms.size()<<std::endl;
	llvm::Value * result = this->terms[0]->codeGen(context);
	std::cout<<"expr result"<<std::endl;
	if (this->terms.size() == 1){
		std::cout<<"expr early return"<<std::endl;
		return result;
	}
	for (int i = 0; i < this->types.size(); i++)
	{
		std::cout<<"i: "<<i<<"type: "<<this->types[i]<<std::endl;
		switch (this->types[i])
		{
		case 0:{
			llvm::Value * tmp = this->terms[i]->codeGen(context);//my
			std::cout<<"get tmp"<<std::endl;
			result = llvm::BinaryOperator::Create(
				llvm::Instruction::FAdd,
				result, tmp,
				llvm::Twine(""),
				context->getCurBlock());
			break;}
		case 1:{
			result = llvm::BinaryOperator::Create(
				llvm::Instruction::FSub,
				result, this->terms[i]->codeGen(context),
				llvm::Twine(""),
				context->getCurBlock());
			break;}
		case 2:{
			result = llvm::BinaryOperator::Create(
				llvm::Instruction::Or,
				result, this->terms[i]->codeGen(context),
				llvm::Twine(""),
				context->getCurBlock());
			break;
		}
		case 3:break;
		default:
			//error info
			break;
		}
	}
	std::cout<<"expr return"<<std::endl;
	return result;
}

llvm::Value *NTerm::codeGen(CodeGenContext *context)
{
	std::cout<<"term codegen"<<std::endl;
	std::cout<<"term factor size "<<this->factors.size()<<std::endl;
	llvm::Value *result = this->factors[0]->codeGen(context);
	std::cout<<"term result"<<std::endl;
	if (this->factors.size() == 1){
		std::cout<<"term early return"<<std::endl;
		return result;
	}
	for (int i = 0; i < this->types.size(); i++)
	{
		switch (this->types[i])
		{
		case 0:{
			result = llvm::BinaryOperator::Create(
				llvm::Instruction::FMul,
				result, this->factors[i]->codeGen(context),
				llvm::Twine(""),
				context->getCurBlock());
			break;}
		case 1:{
			result = llvm::BinaryOperator::Create(
				llvm::Instruction::FDiv,
				result, this->factors[i]->codeGen(context),
				llvm::Twine(""),
				context->getCurBlock());
			break;}
		case 2:{
			result = llvm::BinaryOperator::Create(
				llvm::Instruction::FRem,
				result, this->factors[i]->codeGen(context),
				llvm::Twine(""),
				context->getCurBlock());
			break;}
		case 3:{
			result = llvm::BinaryOperator::Create(
				llvm::Instruction::And,
				result, this->factors[i]->codeGen(context),
				llvm::Twine(""),
				context->getCurBlock());
			break;}
		case 4:break;
		default:
			std::cout<<"Unknown term type"<<std::endl;
			break;
		}
	}
	return result;
}

llvm::Value *NFactor::codeGen(CodeGenContext *context)
{
	std::cout<<"factor codegen"<<std::endl;
	std::cout<<this->type<<std::endl;
	if (this->factor!=nullptr){//my
		std::cout<<"this factor type: "<<this->factor->type<<std::endl;
	}
	if(this->constValue!=nullptr){
		std::cout<<"this const type: "<<this->constValue->type<<std::endl;
	}
	switch (this->type)
	{
	case 0: return context->getValue(this->NAME);  //NAME
	case 1:  //NAME  LP  args_list  RP
	case 2:  //SYS_FUNCT
	case 3:{ //my //SYS_FUNCT  LP  args_list  RP
		std::vector<llvm::Value *> argValues;  
		llvm::Function *func = context->module->getFunction(this->NAME.c_str());  // 找到这个函数
		if (func == nullptr) {
			std::cout << "[Error] Function not defined" << std::endl;
			exit(0);
		}		
		auto funcArgs_iter = func->arg_begin();
		for (NExpression *arg : this->argsList->expressions) {
			llvm::Value *funcArgValue = static_cast<llvm::Value *>(funcArgs_iter++);
			if (funcArgValue->getType()->isPointerTy()) 
			{  // 如果这个参数是指针（全局变量）
				std::cout<<"func arg is point"<<std::endl;
				if (arg->exprs[0]->terms[0]->factors[0]->type == 0) {  // 如果这个参数是变量
					llvm::Value *ptr = context->getValue(
						arg->exprs[0]->terms[0]->factors[0]->NAME);  // 取得变量的值
					llvm::Type *ty;
					while (ptr->getType() != llvm::Type::getInt32PtrTy(GlobalContext)) {
						ptr = new llvm::LoadInst(
							ptr->getType(), //my
							ptr,
							llvm::Twine(""),
							false,
							context->getCurBlock());
					}
					argValues.push_back(ptr);
				}
				else if (arg->exprs[0]->terms[0]->factors[0]->type == 8) {
					if (true) {
						std::vector<llvm::Value*> arrIdx(2);
						arrIdx[0] = llvm::ConstantInt::get(
							GlobalContext,
							llvm::APInt(32, 0, true));
						arrIdx[1] = arg->exprs[0]->terms[0]->factors[0]->expression->codeGen(context);
						llvm::Value* ptr = llvm::GetElementPtrInst::CreateInBounds(
							context->getValue(arg->exprs[0]->terms[0]->factors[0]->ID1),
							llvm::ArrayRef<llvm::Value*>(arrIdx),
							llvm::Twine("tempname"),
							context->getCurBlock());
						argValues.push_back(ptr);
					}
					else {
						std::cout << "[Error] Array's Ref is not an array type variable" << std::endl;
						exit(0);
					}
				}
				else {
					std::cout << "[Error] Wrong left value type" << std::endl;
				}
			}
			else {
				std::cout<<"func arg is not point"<<std::endl;
				argValues.push_back(arg->codeGen(context));
			}
		}
		ArrayRef< Value* > arguments(argValues);
		return llvm::CallInst::Create(
			func,
			arguments,
			llvm::Twine(""),
			context->getCurBlock());
		} break;
	case 4:  return this->constValue->codeGen(context);//my //const_value
	case 5:  //LP  expression  RP
	case 6: { 
		llvm::CmpInst::Create(
			llvm::Instruction::ICmp,
			llvm::CmpInst::ICMP_SGT,
			this->factor->codeGen(context),
			llvm::ConstantInt::get(llvm::Type::getInt32Ty(GlobalContext), 0, true),
			llvm::Twine(""),
			context->getCurBlock());}//NOT  factor
	case 7:  return llvm::BinaryOperator::Create(
		llvm::Instruction::FSub,
		llvm::ConstantInt::get(llvm::Type::getInt32Ty(GlobalContext), 0, true),
		this->factor->codeGen(context),
		llvm::Twine(""),
		context->getCurBlock());//MINUS  factor
	case 8:  return getArrRef(this->ID1, this->expression, context);//ID  LB  expression  RB
	case 9:  //ID  DOT  ID
	default: 
		//error info
		break;
	}
}

llvm::Value *NArgsList::codeGen(CodeGenContext *context)
{
	return nullptr;
}
