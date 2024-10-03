#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef enum
{
    StmtEmpty = 0, StmtExit
} StmtType;

typedef struct
{
    int returnValue;
} NodeExit;

typedef struct
{
    NodeExit exit;
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
