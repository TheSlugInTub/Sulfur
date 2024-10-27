#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "vector.h"

typedef enum
{
    StmtEmpty = 0, 
    StmtExit,
    StmtPrint,
    StmtIntDecl,
    StmtIntAssign
} StmtType;

typedef struct
{
    int returnValue;
} NodeExit;

typedef struct
{
    char message[100];
} NodePrint;

typedef struct
{
    char identifier[50];
    int indexInVars;
} NodeIntDecl;

typedef struct
{
    union
    {
        int newValue;
        char rhs[50];
    };
    char lhs[50];
} NodeIntAssign;

typedef struct
{
    union 
    {
        NodeExit exit;
        NodePrint print;
        NodeIntDecl intDecl;
        NodeIntAssign intAssign;
    };
    StmtType type;
} NodeStmt;

typedef struct
{
    NodeStmt statements[100];
} NodeProg;

typedef struct
{
    char identifier[50];
    int stackLocation;
} Variable;

extern NodeProg prog;
extern int stmtIndex;
extern int progIndex;
extern Vector* variables;

Token PeekTok(const int offset);
NodeProg Parse();

#endif
