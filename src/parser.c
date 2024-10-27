#include "../include/parser.h"
#include <stdio.h>
#include <string.h>

NodeProg prog;
int stmtIndex = 0;
int progIndex = 0;
Vector* variables;

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

    variables = vector_init(5);

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
            
            stmtIndex = stmtIndex + 4;
            progIndex++;
        }else if (tok.type == TokenTypeInt)
        {
            NodeIntDecl intDeclNode;
            Token identTok = PeekTok(0);

            strcpy(intDeclNode.identifier, identTok.value);
            intDeclNode.indexInVars = variables->size;

            NodeStmt nodeStmt;
            nodeStmt.type = StmtIntDecl;
            nodeStmt.intDecl = intDeclNode;
            prog.statements[progIndex] = nodeStmt;

            Variable* var = (Variable*)malloc(sizeof(Variable));
            strcpy(var->identifier, identTok.value);
            vector_push_back(variables, var);
            
            stmtIndex++; // Skip semicolon
            progIndex++;
        }else if (tok.type == TokenIdentifier)
        {
            Token operator = PeekTok(0);
            stmtIndex++; // Skip the operator and go to the operand

            if (operator.type == TokenEqual)
            {
                Token nextTok = PeekTok(0);

                NodeIntAssign intAssignNode;
                strcpy(intAssignNode.lhs, tok.value);

                NodeStmt nodeStmt;
                nodeStmt.type = StmtIntAssign;

                if (nextTok.type == TokenNumber)
                {
                    intAssignNode.newValue = nextTok.intValue;
                }else if (nextTok.type == TokenIdentifier)
                {
                    strcpy(intAssignNode.rhs, nextTok.value);
                }

                nodeStmt.intAssign = intAssignNode;
                prog.statements[progIndex] = nodeStmt;
                
                stmtIndex++; // Skip the semicolon at the end of statement
                progIndex++;
            }
        }
    }

    return prog;
}
