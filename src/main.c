#include <stdio.h>
#include <stdlib.h>
#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/assembler.h"

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        printf("Sulfur compiler\nUSAGE:\nsulfur [file-name]\n");
        return 0;
    }

    // Open the file
    FILE* file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET); // reset file pointer

    // Allocate memory to hold the file contents
    char* source = (char*)malloc(file_size + 1); // +1 for null terminator
    if (source == NULL)
    {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    // Read the file into the allocated buffer
    size_t read_size = fread(source, 1, file_size, file);
    source[read_size] = '\0'; // Null-terminate the string
    fclose(file);

    Token* tokenArray = Lex(source);
    
    for (int i = 0; i < tokenIndex; i++)
    {
        printf("Token: Type %d, Value %s\n", tokenArray[i].type, tokenArray[i].value);
    }

    NodeProg progNodeM = Parse();

    Assemble("out.asm", progNodeM);
    system("nasm -felf64 out.asm");    
    system("ld -o out out.o");

    free(source);
    return 0;
}
