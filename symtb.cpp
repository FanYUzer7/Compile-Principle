#include"symtb.hpp"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASEOFFSET 0


int lastblock;
int blocknumber;       	/* Number of current block being compiled */
int contblock[MAXBLOCKS];  /* Containing block for each block (the outer block of this block)        */
int blockoffs[MAXBLOCKS] = {0};  		/* Storage offsets for each block         */
SYMENTRY symtab[MAXBLOCKS][HASH_SIZE];     /* Symbol chain for each block            */


/* Sizes of basic types  INTEGER  REAL  	CHAR  	BOOL 	 STRING   */
int basicsizes[5] =      { 4,       8,       1,         4,        16 };

char* symprint[10]  = {"ARGM", "BASIC", "CONST", "VAR", "SYM_SUBRANGE",
                       "FUNCTION", "ARRAY", "RECORD", "TYPE", "ARGLIST"};
int symsize[10] = { 1, 5, 5, 3, 8, 8, 5, 6, 4, 7 };

SYMENTRY symAlloc(){
    //printf("symAlloc\n");
    return ((SYMENTRY)calloc(1,sizeof(SYMITEM)));
}

SYMENTRY createByName(char name[]){
    SYMENTRY entry = symAlloc();
    strcpy(entry->name,name);
    entry->next = NULL;
    return entry;
}

SYMENTRY insertEntry(char name[]){
    return insertByDepth(name,blocknumber);
}

SYMENTRY searchByName(char name[]){
    SYMENTRY entry = NULL;
    int depth = blocknumber;
    //printf("depth = %d\n",blocknumber);
    while(entry==NULL&&depth>=0){
        entry = searchByDepth(name,depth);
        if(depth>0) depth = contblock[depth];
        else depth = -1;
    }
    if(DEBUG_SYMTAB) printf("searchByName %8s %ld at depth %d\n",
        name,(long)entry,depth);
    return entry;
}

SYMENTRY searchByDepth(char name[],int depth){
    int pos = hash(name);
    SYMENTRY entry;
    while((entry=symtab[depth][pos])!=NULL){
        if(strcmp(name,entry->name)==0) return entry;
        pos = (pos + 1)%HASH_SIZE;
        if(pos==hash(name)) return NULL;
    }
    return NULL;
}
// search a entry ,if not found then create it and insert
SYMENTRY searchAndInsert(char name[]){
    SYMENTRY entry = searchByName(name);
    if(entry!=NULL) return entry;
    else{
        entry = insertEntry(name);
        return entry;
    }
}
// insert basictype
SYMENTRY insertBT(char name[], int basicType, int size){
    SYMENTRY entry = insertEntry(name);
    entry->type = SYM_BASIC;
    entry->basicType = basicType;
    entry->size = size;
    return entry;
}
// insert function
SYMENTRY insertFunc(char name[],SYMENTRY resType,SYMENTRY argType){
    SYMENTRY fun,res,arg;
    fun = insertEntry(name);
    fun->type = SYM_FUNCTION;
    res = symAlloc();
    res->type = SYM_ARGMENT;
    res->dataType = resType;
    if(resType!=NULL) res->basicType = resType->basicType;
    arg = symAlloc();
    arg->type = SYM_ARGMENT;
    arg->dataType = argType;
    if(argType!=NULL) arg->basicType = argType->basicType;
    arg->next = NULL;
    res->next = arg;
    fun->dataType = res;
    return fun;
}
// insert function with argument list
SYMENTRY insertFuncList(char name[],SYMENTRY resType,SYMENTRY argList){
    SYMENTRY fun,res;
    fun = insertByDepth(name,contblock[blocknumber]);
    fun->type = SYM_FUNCTION;
    res = symAlloc();
    res->type = SYM_ARGMENT;
    res->dataType = resType;
    if(resType!=NULL) res->basicType = resType->basicType;

    res->next = argList;
    fun->dataType = res;
    return fun;
}
// insert by depth
SYMENTRY insertByDepth(char name[],int depth){
    SYMENTRY entry = createByName(name);
    int pos = hash(name);
    while(symtab[depth][pos]!=NULL){
        pos = (pos +1)%HASH_SIZE;
        if(pos == hash(name)){
            printf("ERR:SYMBOL TABLE OVERFLOW\n");
            exit(-1);
        }
    }
    symtab[depth][pos] = entry;
    entry->depth = depth;

    if(entry->type==SYM_VAR){
        entry->offset = blockoffs[depth];
        blockoffs[depth] += basicsizes[entry->basicType];
    }
    if(DEBUG_SYMTAB) printf("insertByDepth %8s %ld at depth %d,pos %d\n",
                            name,(long)entry,depth,pos);
    return entry;
}

void initEntries(){
    SYMENTRY entry,realEntry,intEntry,charEntry,boolEntry;
    blocknumber = 0;
    blockoffs[1] = BASEOFFSET;

    realEntry = insertBT("real",TYPE_REAL,8);
    intEntry  = insertBT("integer", TYPE_INT, 4);
	charEntry = insertBT("char", TYPE_CHAR, 1);
	boolEntry = insertBT("boolean", TYPE_BOOL, 4);

    entry = insertFunc("abs", realEntry, realEntry);
	entry = insertFunc("sqr", realEntry, realEntry);
	entry = insertFunc("sqrt", realEntry, realEntry);
	entry = insertFunc("ord", intEntry, intEntry);
	entry = insertFunc("chr", charEntry, intEntry);
	entry = insertFunc("pred", charEntry, charEntry);
	entry = insertFunc("succ", charEntry, charEntry);
	entry = insertFunc("odd", boolEntry, intEntry);

	entry = insertFunc("write", NULL, charEntry);
	entry = insertFunc("writeln", NULL, charEntry);
	entry = insertFunc("read", NULL, NULL);
	entry = insertFunc("readln", NULL, NULL);

    blocknumber = 1;             /* Start the user program in block 1 */
	lastblock = 1;
	contblock[1] = 0;

}

void debugPrint(SYMENTRY entry){
    if(entry != NULL){
        printf("%ld  %10s type %1d %1d  basictype %ld depth %1d  size %5d  offset %5d next %ld\n",
                (long)entry,entry->name,entry->type,entry->basicType,entry->depth,entry->size,entry->offset,entry->next);
    }
}
void pprintEntry(SYMENTRY entry, int col){
    SYMENTRY op;
    int nextcol,begin,i,flag;
    if(entry == NULL){
        printf("pprintEntry:entry = NULL\n");
        return;
    }
    if(PPDEBUG != 0){
        printf("pprintEntry: col %d\n",col);
        debugPrint(entry);
    }
    switch(entry->type){
        case SYM_BASIC:
            printf("%s",entry->name);
            nextcol = col + 1 + strlen(entry->name);
            break;
        case SYM_SUBRANGE:
            printf("%3d ..%4d",entry->lowerBound,entry->higherBound);
            nextcol = col + 10;
            break;
        case SYM_FUNCTION:
        case SYM_ARRAY:
        case SYM_RECORD:
            printf("(%s",symprint[entry->type]);
            nextcol = col + 2 + symsize[entry->type];
            if(entry->type == SYM_ARRAY){
                printf(" %3d ..%4d",entry->lowerBound,entry->higherBound);
                nextcol = col + 11;
            }
            op = entry->dataType;
            begin = 0;
            flag = 0;
            while(op != NULL && flag == 0){
                if(begin == 0) printf(" ");
                else{
                    printf("\n");
                    for(i=0;i<nextcol;i++) printf(" ");
                }
                if(entry->type == SYM_RECORD){
                    printf("(%s ",op->name);
                    pprintEntry(op,nextcol + 2 +strlen(op->name));
                    printf(")");
                }else pprintEntry(op,nextcol);
                begin = 1;
                if(entry->type == SYM_ARRAY) flag = 1;
                op = op->next;
            }
            printf(")");
            break;
        default:
            if(entry->dataType != NULL) pprintEntry(entry->dataType,col);
            else printf("NULL");
            break;

    }
}

void ppEntry(SYMENTRY entry){
    pprintEntry(entry,0);
    printf("\n");
}
void printEntry(SYMENTRY entry){
    if(entry == NULL){
        printf("printEntry:entry = NULL\n");
        return;
    }
    switch(entry->type){
        case SYM_FUNCTION:
        case SYM_ARRAY:
        case SYM_RECORD:
            printf(" %ld  %10s  typ %1d %1d  btp %ld  dep %2d  siz %5d  off %5d\n",
                (long)entry,entry->name,entry->type,entry->basicType,entry->depth,entry->size,entry->offset,entry->next);
            ppEntry(entry);
            break;
        case SYM_VAR:
            if(entry->dataType->type == SYM_BASIC)
                printf(" %ld  %10s  VAR    %1d btp %7s  dep %2d  siz %5d  off %5d\n",
                        (long)entry, entry->name, entry->basicType, entry->dataType->name,
                        entry->depth, entry->size, entry->offset);
            else printf(" %ld  %10s  VAR    %1d btp %ld  dep %2d  siz %5d  off %5d\n",
                        (long)entry, entry->name, entry->basicType, entry->dataType->name,
                        entry->depth, entry->size, entry->offset);
            break;
        case SYM_TYPE:
            printf(" %ld  %10s  TYPE   btp %ld  dep %2d  siz %5d  off %5d\n",
                (long)entry,entry->name,entry->basicType,entry->depth,entry->size,entry->offset,entry->next);
            if(entry->dataType->type != SYM_BASIC) ppEntry(entry->dataType);
            break;
        case SYM_BASIC:
            printf(" %ld  %10s  BASIC  basicType %3d          siz %5d\n",
                (long)entry,entry->name,entry->basicType);
            break;
        case SYM_SUBRANGE:
            printf(" %ld  %10s  SUBRA  btp %7d  val %5d .. %5d\n",
                (long)entry,entry->name,entry->basicType,entry->lowerBound,entry->higherBound);    
            break;
        case SYM_CONST:
            switch(entry->basicType){
                case TYPE_INT:
                    printf(" %ld  %10s  CONST  typ INTEGER  val  %d\n",
                    (long)entry,entry->name,entry->constVal.intVal);
                    break;
                case TYPE_REAL:
                    printf(" %ld  %10s  CONST  typ    REAL  val  %12e\n",
                    (long)entry,entry->name,entry->constVal.realVal);
                    break;
                case TYPE_STR:
                	printf(" %ld  %10s  CONST  typ  STRING  val  %12s\n",
                    (long)entry,entry->name,entry->constVal.string);
                    break;
                case TYPE_CHAR:
                    printf(" %ld  %10s  CONST  typ  STRING  val  %c\n",
                    (long)entry,entry->name,entry->constVal.charConst);
                    break;
            }
            break;
    }
}

void printDepth(int depth){
    printf("SYMBOL TABLE DEPTH %d\n",depth);
    for(int i=0;i<HASH_SIZE;i++){
        printf("%2d: ",i);
        if(symtab[depth][i]!=NULL) printEntry(symtab[depth][i]);
        else printf("NULL\n");
    }
}

void printAll(){
    for(int i=0;i<=lastblock;i++){
        printDepth(i);
    }
}


/* alignsize returns the required alignment boundary for a type  */
int alignsize(SYMENTRY entry){
    switch (entry->type) {
		case SYM_BASIC:
		case SYM_SUBRANGE:
			return entry->size;
			break;
		case SYM_ARRAY:
		case SYM_RECORD:
			return 16;
			break;
		default:
			return 8;
			break;
	}
}
// hash function
int hash(char name[]){
    if (name[0] == '_') return 26;
	return tolower(name[0])-'a';
}

