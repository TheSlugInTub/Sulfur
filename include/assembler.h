#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "parser.h"

extern int nodeIndex;
extern char output[10000];
extern char dataSec[10000];
extern int stackLoc;

Variable* FindVarByIdentifier(Vector* vec, const char* ident);
NodeStmt PeekNode(const int offset, NodeProg progNodeM);
void Assemble(const char* filename, NodeProg progNodeM);

#endif
