#include "../include/parser.h"
#include <stdio.h>

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
            progIndex++;
        }
    }

    printf("Prog index: %d\n", progIndex);

    return prog;
}
