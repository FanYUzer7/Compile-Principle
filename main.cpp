#include "node.hpp"
#include "CodeGen.h"

extern NProgram *top;
extern int yyparse();

int main(int argc, char **argv)
{
    yyparse();
    InitializeNativeTargetAsmPrinter();
	InitializeNativeTargetAsmParser();
	InitializeNativeTarget();
	CodeGenContext context;
	
	context.generateCode(top);
	
	context.runCode();
}
