#include "../include/assembler.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int nodeIndex = 0;
char output[10000];

NodeStmt PeekNode(const int offset, NodeProg progNodeM)
{
    printf("Prog index: %d, Node index + offset: %d\n", progIndex, nodeIndex + offset);
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
    const char* cat1 = "global _start\n\n_start:\n";
    strcat(output, cat1);

    while (PeekNode(0, progNodeM).type != StmtEmpty)
    {
        NodeStmt stmt = progNodeM.statements[nodeIndex];
        nodeIndex++;

        printf("It aint empty\n");
        printf("Type of node: %d\n", stmt.type);

        if (stmt.type == StmtExit)
        {
            const char* exitInstruction = "    mov rax, 60\n";
            int exitValue = stmt.exit.returnValue;
            strcat(output, exitInstruction);
            
            char exitValueInstruction[50];

            sprintf(exitValueInstruction, "    mov rdi, %d\n    syscall", exitValue);
            strcat(output, exitValueInstruction);
        }
    }

    // Output
    FILE* outFile;
    outFile = fopen(filename, "w");
    fprintf(outFile, "%s", output);
    fclose(outFile);
}
