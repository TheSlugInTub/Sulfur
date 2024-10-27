#include "../include/assembler.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "error.h"

int nodeIndex = 0;
char output[10000];
char dataSec[10000];
int stackLoc = 0;

Variable* FindVarByIdentifier(Vector* vec, const char* ident)
{
    for (int i = 0; i < variables->size; i++)
    {
        if (strcmp(ident, variables->data[i]) == 0)
        {
            return (Variable*)variables->data[i];
        }
    }

    return NULL;
}

NodeStmt PeekNode(const int offset, NodeProg progNodeM)
{
    if (nodeIndex + offset >= progIndex)
    {
        NodeStmt stmt;
        stmt.type = StmtEmpty;
        return stmt;
    }

    return progNodeM.statements[nodeIndex + offset];
}

void Assemble(const char* filename, NodeProg progNodeM)
{
    const char* cat1 = "section .text\n    global _start\n\n_start:\n";
    strcat(output, cat1);
    const char* cat2 = "section .data\n";
    strcat(dataSec, cat2);

    while (PeekNode(0, progNodeM).type != StmtEmpty)
    {
        NodeStmt stmt = progNodeM.statements[nodeIndex];
        nodeIndex++;

        printf("Assembling node: %d\n", stmt.type);

        if (stmt.type == StmtExit)
        {
            const char* exitInstruction = "    mov rax, 60\n";
            int exitValue = stmt.exit.returnValue;
            strcat(output, exitInstruction);
            
            char exitValueInstruction[50];

            sprintf(exitValueInstruction, "    mov rdi, %d\n    syscall\n", exitValue);
            strcat(output, exitValueInstruction);
        }else if (stmt.type == StmtPrint)
        {
            const char* stringData = "    msg db \'";
            strcat(dataSec, stringData);
            strcat(dataSec, stmt.print.message);
            strcat(dataSec, "\', 0xA\n    msg_len equ $ - msg\n");
            
            char printInstruction[100];

            sprintf(printInstruction, "    mov rax, 1\n    mov rdi, 1\n    mov rsi, msg\n    mov rdx, msg_len\n    syscall\n");
            strcat(output, printInstruction);
        }else if (stmt.type == StmtIntDecl)
        {
            Variable* var = (Variable*)vector_get(variables, stmt.intDecl.indexInVars);
            var->stackLocation = stackLoc;
            stackLoc++;

            const char* instruction = "    mov rax, 0\n    push rax\n";
            strcat(output, instruction);
        }else if (stmt.type == StmtIntAssign)
        {
            char stackInstruction[100];
            int valueToSetTo = 0;

            Variable* leftVar = FindVarByIdentifier(variables, stmt.intAssign.lhs);
            Variable* rightVar = FindVarByIdentifier(variables, stmt.intAssign.rhs);

            if (leftVar == NULL)
            {
                char errorMsg[50];
                sprintf(errorMsg, "Unkown identifier of %s\n", stmt.intAssign.lhs);
                MakeError(ErrorUnknownIdentifier, errorMsg);
            }

            int destOffset = 8 * leftVar->stackLocation;   // Calculate stack offset for the destination variable

            if (strlen(stmt.intAssign.rhs) == 0)
            {
                // Identifier to Identifier
                if (rightVar == NULL)
                {
                    char errorMsg[50];
                    sprintf(errorMsg, "Unkown identifier of %s\n", "bruh");
                    MakeError(ErrorUnknownIdentifier, errorMsg);
                }
                int srcOffset = 8 * rightVar->stackLocation;   // Calculate stack offset for the source variable
                // Move the value from source variable's stack location to destination variable's stack location
                sprintf(stackInstruction,
                        "    mov rax, qword [rsp + %d]\n"
                        "    mov qword [rsp + %d], rax\n",
                        srcOffset, destOffset);
            }
            else
            {
                // Identifier to Integer
                int valueToSetTo = stmt.intAssign.newValue;
                sprintf(stackInstruction, "    mov qword [rsp + %d], %d\n", destOffset, valueToSetTo);
            }

            strcat(output, stackInstruction);
        }
    }

    strcat(dataSec, "\n");
    strcat(dataSec, output);

    // Output
    FILE* outFile;
    outFile = fopen(filename, "w");
    fprintf(outFile, "%s", dataSec);
    fclose(outFile);
}
