#include "../include/assembler.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int nodeIndex = 0;
char output[10000];
char dataSec[10000];

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
