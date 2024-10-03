#include "../include/lexer.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int srcIndex = -1;
Token tokens[100];
int tokenIndex = 0;

char Peek(const char* src, const int offset, int length)
{
    if (srcIndex + offset >= length)
    {
        return '~';
    }

    return src[srcIndex++];
}

Token* Lex(const char* source)
{
    int length = strlen(source);

    while (Peek(source, 0, length) != '~')
    {
        char ch = source[srcIndex];

        if (isalpha(ch))
        {
            char ident[10]; // Initialize ident
            int identIndex = 0;

            while (isalpha(source[srcIndex]))
            {
                ident[identIndex] = source[srcIndex];
                srcIndex++;
                identIndex++;
            }

            if (strcmp(ident, "exit") == 0)
            {
                Token newToken;
                newToken.type = TokenExit;
                strcpy(newToken.value, "exit");
                tokens[tokenIndex] = newToken; 
                tokenIndex++;
                srcIndex--;
            }else 
            {
                printf("Unkown identifier %s\n", ident);
            }
        }else if (isdigit(ch))
        {
            Token newToken;
            newToken.type = TokenNumber; 
            int intNumber = ch - '0';
            newToken.intValue =  intNumber;
            strcpy(newToken.value, "Number");
            tokens[tokenIndex] = newToken;
            tokenIndex++;
        }else if (ch == '(')
        {
            Token newToken;
            newToken.type = TokenOpenParen;
            strcpy(newToken.value, "(");
            tokens[tokenIndex] = newToken;
            tokenIndex++;
        }else if (ch == ')')
        {
            Token newToken;
            newToken.type = TokenCloseParen;
            strcpy(newToken.value, ")");
            tokens[tokenIndex] = newToken;
            tokenIndex++;
        }else if (ch == ';')
        {
            Token newToken;
            newToken.type = TokenSemicolon;
            strcpy(newToken.value, ";");
            tokens[tokenIndex] = newToken;
            tokenIndex++;
        }else if (isspace(ch))
        {
        }else 
        {
            printf("Unknown symbol of %c\n", ch);
        }
    }

    return tokens;
}
