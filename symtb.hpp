#ifndef SYMTB_H
#define SYMTB_H

#define TYPE_INT    0             /* number types */
#define TYPE_REAL   1
#define TYPE_CHAR    2
#define TYPE_BOOL   3
#define TYPE_STR	4

#define SYM_ARGMENT		0
#define SYM_BASIC		1
#define SYM_CONST		2
#define SYM_VAR			3
#define SYM_SUBRANGE	4
#define SYM_FUNCTION	5
#define SYM_ARRAY		6   
#define SYM_RECORD		7
#define SYM_TYPE		8
#define SYM_POINTER		9
#define SYM_ARGLIST		10

#define PPDEBUG 0
#define DEBUG_SYMTAB 0
#define HASH_SIZE 27

#define MAXBLOCKS 50


typedef struct symtbEntry
{
    struct symtbEntry* next;
    struct symtbEntry* dataType;
    char name[16];
    int type;
    int basicType;
    int size;
    int offset;
    int depth;
    int lowerBound;
    int higherBound;
    union
    {
        int intVal;
        double realVal;
        char charConst;
        char string[16];

    }constVal;
}SYMITEM,*SYMENTRY;

// mem allocate
SYMENTRY symAlloc();
// create a entry with given name
SYMENTRY createByName(char name[]);
// create a entry with gien name and insert it
SYMENTRY insertEntry(char name[]);

SYMENTRY searchByName(char name[]);

SYMENTRY searchByDepth(char name[],int depth);
// search a entry ,if not found then create it and insert
SYMENTRY searchAndInsert(char name[]);
// insert basictype
SYMENTRY insertBT(char name[], int basicType, int size);
// insert function
SYMENTRY insertFunc(char name[],SYMENTRY resType,SYMENTRY argType);
// insert function with argument list
SYMENTRY insertFuncList(char name[],SYMENTRY resType,SYMENTRY argList);
// insert by depth
SYMENTRY insertByDepth(char name[],int depth);

void initEntries();

void debugPrint(SYMENTRY entry);

void printEntry(SYMENTRY entry);

void printDepth(int depth);

void printAll();

void pprintEntry(SYMENTRY entry, int col);

void ppEntry(SYMENTRY entry);

/* alignsize returns the required alignment boundary for a type  */
int alignsize(SYMENTRY sym);
// hash function
int hash(char name[]);



#endif