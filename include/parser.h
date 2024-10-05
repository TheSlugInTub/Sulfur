#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef enum
{
    StmtEmpty = 0, 
    StmtExit,
    StmtPrint
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
    union 
    {
        NodeExit exit;
        NodePrint print;
    };
    StmtType type;
} NodeStmt;

typedef struct
{
    NodeStmt statements[100];
} NodeProg;

extern NodeProg prog;
extern int stmtIndex;
extern int progIndex;

Token PeekTok(const int offset);
NodeProg Parse();

#endif
