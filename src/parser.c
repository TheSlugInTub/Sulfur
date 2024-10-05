#include "../include/parser.h"
#include <stdio.h>
#include <string.h>

NodeProg prog;
int stmtIndex = 0;
int progIndex = 0;

Token PeekTok(const int offset)
{
    if (stmtIndex + offset >= tokenIndex)
    {
        Token newTok;
        newTok.type = TokenEmpty;
        return newTok;
    }

    return tokens[stmtIndex + offset];
}

NodeProg Parse()
{
    NodeProg prog;

    while (PeekTok(0).type != TokenEmpty)
    {
        stmtIndex++;
        Token tok = tokens[stmtIndex - 1];

        printf("Parsing token type: %d\n", tok.type);
        
        if (tok.type == TokenExit)
        {
            NodeExit exitNode;
            Token numTok = PeekTok(1);

            exitNode.returnValue = numTok.intValue;

            NodeStmt nodeStmt;
            nodeStmt.type = StmtExit;
            nodeStmt.exit = exitNode;
            prog.statements[progIndex] = nodeStmt;
            stmtIndex = stmtIndex + 4;
            progIndex++;
        }else if (tok.type == TokenPrint)
        {
            NodePrint printNode;
            Token strTok = PeekTok(1);

            strcpy(printNode.message, strTok.value);

            NodeStmt nodeStmt;
            nodeStmt.type = StmtPrint;
            nodeStmt.print = printNode;
            prog.statements[progIndex] = nodeStmt;
            
            progIndex++;
        }
    }

    return prog;
}
