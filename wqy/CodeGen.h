#ifndef CODEGEN_H
#define CODEGEN_H

#include <iostream>

#include <stack>
#include <set>
#include "node.h"

#include <typeinfo>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Attributes.h>
#include <llvm/IR/ValueSymbolTable.h>
#include <llvm/Bitstream/BitstreamReader.h> //my
#include <llvm/Bitstream/BitstreamWriter.h> //my
#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/FileSystem.h>

using namespace llvm;
class CodeGenContext;

static llvm::LLVMContext GlobalContext;

llvm::Function* createPrintf(CodeGenContext *context);

class CodeGenBlock {
public:
    llvm::BasicBlock *block;
    CodeGenBlock *parent;
    std::map<std::string, NConst*> const_locals;
    std::map<std::string, NTypeDecl*> typedefs;
};

class CodeGenContext {
private:
    std::stack<CodeGenBlock*> blocks;
    llvm::Function *mainFunction;
    llvm::Function *currentFunction;

public:
    llvm::Module *module = new llvm::Module("main", GlobalContext);
    std::map<llvm::Function *, llvm::Function*> parent;
    llvm::Function *printf;
    std::map<std::string, NFuncDecl*> defined_functions;

    CodeGenContext()
    {
    }

    llvm::Function *getCurFunc()
    {
        return this->currentFunction;
    }

    void setCurFunc(llvm::Function *func)
    {
        this->currentFunction = func;
    }

    llvm::Type *getLLVMTy(NConst*con)
    {
        if(con == nullptr || con->value == nullptr)
            return llvm::Type::getVoidTy(GlobalContext);
        
        switch(con->value->type)
        {
            case 0: return llvm::Type::getInt32Ty(GlobalContext);
            case 1: return llvm::Type::getFloatTy(GlobalContext);
            case 2: return llvm::Type::getInt8Ty (GlobalContext);
        }
    }

    llvm::Type *getLLVMTy(NTypeDecl *type)
    {
    	if (type == nullptr) {
    		return llvm::Type::getVoidTy(GlobalContext);
    	}

    	switch (type->type) {
    		case 0: {
                return this->getLLVMTy(type->simpleType);
            }
            case 1: {
                return llvm::ArrayType::get(this->getLLVMTy(type->arrayType->simpleType),type->array_end - type->array_start + 1);
    		}

    		// case 3: {
            //     std::vector<llvm::Type*> members;
            //     for (ast::Type *child : type->child_type) {
            //         members.push_back(this->getLLVMTy(child));
            //     }
            //     llvm::StructType *const rcd = llvm::StructType::create(GlobalContext,type->name);  // StringRef Name
            //     rcd->setBody(members);
            //     return rcd;
    		// }

            default: {
               /* CodeGenBlock *curBlock = this->getCurCodeGenBlock();
                while (curBlock != nullptr) {
                    std::map<std::string, NTypeDecl*> typeTable = curBlock->typedefs;
                    if (typeTable.find(type->name) != typeTable.end()) {
    					return this->getLLVMTy(typeTable[type->name]);
                    }
                    curBlock = curBlock->parent;
                }*/
                exit(0);
    		}
    	}
    }

    llvm::Type *getLLVMTy(NSimpleType *type)
    {
        switch(type->Sys_type)
        {
            case 0: return llvm::Type::getInt1Ty (GlobalContext);
            case 1: return llvm::Type::getInt8Ty (GlobalContext);
            case 2: return llvm::Type::getInt32Ty(GlobalContext);
            case 3: return llvm::Type::getFloatTy(GlobalContext);
            default: return nullptr;
        }
    }

    void generateCode(NProgram *root)
    {
    	std::cout << "Generating code...\n";
        std::vector<llvm::Type*> argTypes;  // 对于一个函数，llvm需要一个参数类型表
        // 构造一个main函数的函数类型，返回值为void，定长参数
        llvm::FunctionType *funcType = llvm::FunctionType::get(llvm::Type::getVoidTy(GlobalContext),  // Type *Result: 返回值类型
                                                               llvm::makeArrayRef(argTypes),      // ArrayRef<Type*> Params: 参数列表
                                                               false);                            // bool isVarArg: 是否为变长参数
        // 利用构造的main函数函数类型，构造一个main函数
        this->mainFunction = llvm::Function::Create(funcType,                            // FunctionType *Ty: 函数类型
                                                    llvm::GlobalValue::InternalLinkage,  // LinkageTypes Linkage
                                                    llvm::Twine("main"),                 // const Twine &N
                                                    this->module);                       // Module *M
        // 主程序入口（main）
        llvm::BasicBlock *basBlock = llvm::BasicBlock::Create(GlobalContext,             // LLVMContext &Context
                                                              llvm::Twine("entry"),  // const Twine &Name
                                                              this->mainFunction,    // Function *Parent
                                                              nullptr);              // BasicBlock *InsertBefore

        this->printf = createPrintf(this);

        this->pushBlock(basBlock);  // 将程序入口（main函数的block）压栈
        this->currentFunction = this->mainFunction;
        std::cout << "start codeGen" << std::endl;
        root->codeGen(this);
        std::cout << "start create" << std::endl;
        llvm::ReturnInst::Create(GlobalContext,              // LLVMContext &Context
                                 this->getCurBlock());  // BasicBlock *InsertAtEnd
        std::cout << "start pop" << std::endl;
        this->popBlock();  // 出栈

    	std::cout << "Code is generated.\n";

        // 生成中间代码
    	llvm::legacy::PassManager pm;
    	pm.add(llvm::createPrintModulePass(llvm::outs()));
    	pm.run(*this->module);

        // 二进制代码
        std::error_code EC;
        llvm::raw_fd_ostream OS("LLVM_IR", EC, llvm::sys::fs::F_None);
        llvm::WriteBitcodeToFile(*this->module, OS);
        llvm::raw_fd_ostream OS2("LLVM_LL", EC, llvm::sys::fs::F_None);
        this->module->print(OS2, nullptr, false);
        OS.flush();
    }

    llvm::GenericValue runCode()
    {
    	std::cout << "Running code...\n";

        llvm::ExecutionEngine *exeEngine = llvm::EngineBuilder(std::unique_ptr<llvm::Module>(this->module)).create();
        exeEngine->finalizeObject();  // ensure the module is fully processed and is usable.
        std::cout <<"finalized"<<std::endl;
        llvm::ArrayRef<llvm::GenericValue> noArgs;
        llvm::GenericValue value = exeEngine->runFunction(this->mainFunction,  //  Function *f
                                                          noArgs);             //  ArrayRef<GenericValue>  ArgValues
        std::cout << "Code run.\n";
        return value;
    }

    llvm::BasicBlock *getCurBlock()
    {
        return blocks.top()->block;
    }

    CodeGenBlock *getCurCodeGenBlock()
    {
        return blocks.top();
    }

    void pushBlock(llvm::BasicBlock *block)
    {
        std::cout << "pushing..." << std::endl;
        blocks.push(new CodeGenBlock());
        blocks.top()->block = block;
        std::cout << "pushing success" << std::endl;
    }
    void popBlock()
    {
        std::cout << "poping..." << std::endl;
        CodeGenBlock *top = blocks.top();
        blocks.pop();
        delete top;
    }

    void insertConst(std::string name, NConst*const_v)
    {
        blocks.top()->const_locals[name] = const_v;
    }

    llvm::Value *getValue(std::string name)
    {
        std::cout << "Start get value for " << name << std::endl;

        llvm::Value *ret;
        if ((ret = this->currentFunction->getValueSymbolTable()->lookup(name)) != nullptr) {  // 在 curFunc 的局部变量中找到
            std::cout << "[Success] Found local variable: " << name << std::endl;
            return ret;
        } else if ((ret = this->module->getGlobalVariable(name)) != nullptr) {  // 在 module 的全局变量中找到
            std::cout << "[Success] Found global variable: " << name << std::endl;
            return ret;
        } else {  // 找不到
            std::cout << "[Error] Undeclared variable: " << name << std::endl;
            exit(0);
        }
    }
};

template <typename T> static std::string Print(T* value_or_type) {
    std::string str;
    llvm::raw_string_ostream stream(str);
    value_or_type->print(stream);
    return str;
}



#endif

