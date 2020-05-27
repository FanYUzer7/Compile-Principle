#include "node.hpp"
#include <fstream>


extern int yyparse();

int main(int argc, char** argv)
{
    initEntries();
    yyparse();
}