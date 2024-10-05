#include "../include/lexer.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "../include/error.h"

int srcIndex = 0;
Token tokens[100];
int tokenIndex = 0;

char Peek(const char* src, const int offset, int length)
{
    if (srcIndex + offset >= length)
    {
        return '~';
    }
    return src[srcIndex + offset];
}

Token* Lex(const char* source)
{
    int length = strlen(source);

    while (Peek(source, 0, length) != '~')
    {
        char ch = source[srcIndex];

        if (isalpha(ch))
        {
            char ident[50]; // Initialize ident
            int identIndex = 0;

            while (isalpha(source[srcIndex]))
            {
                ident[identIndex] = source[srcIndex];
                srcIndex++;
                identIndex++;
            }
            ident[identIndex] = '\0';

            if (strcmp(ident, "exit") == 0)
            {
                Token newToken;
                newToken.type = TokenExit;
                strcpy(newToken.value, "exit");
                tokens[tokenIndex] = newToken; 
                tokenIndex++;
            }else if (strcmp(ident, "printf") == 0)
            {
                Token newToken;
                newToken.type = TokenPrint;
                strcpy(newToken.value, "printf");
                tokens[tokenIndex] = newToken; 
                tokenIndex++;
            }else 
            {
                char errorMsg[50];
                sprintf(errorMsg, "Unkown identifier of %s\n", ident);
                MakeError(ErrorUnknownIdentifier, errorMsg);
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
            srcIndex++;
        }else if (ch == '(')
        {
            Token newToken;
            newToken.type = TokenOpenParen;
            strcpy(newToken.value, "(");
            tokens[tokenIndex] = newToken;
            tokenIndex++;
            srcIndex++;
        }else if (ch == ')')
        {
            Token newToken;
            newToken.type = TokenCloseParen;
            strcpy(newToken.value, ")");
            tokens[tokenIndex] = newToken;
            tokenIndex++; 
            srcIndex++;
        }else if (ch == ';') {
            Token newToken;
            newToken.type = TokenSemicolon;
            strcpy(newToken.value, ";");
            tokens[tokenIndex] = newToken;
            tokenIndex++;
            srcIndex++;
        }else if (ch == '\"')
        {
            Token newToken;
            newToken.type = TokenStringLiteral;
            char stringLit[100]; 

            int strIndex = 0;
            srcIndex++; // Skip the initial double-quote character

            char strChar;
            while ((strChar = Peek(source, 0, length)) != '\"' && strChar != '~') 
            {
                stringLit[strIndex] = source[srcIndex]; 
                srcIndex++;
                strIndex++;
            }

            stringLit[strIndex] = '\0'; // Null-terminate the string

            strcpy(newToken.value, stringLit);
            tokens[tokenIndex] = newToken;
            tokenIndex++;

            srcIndex++;
        }else if (isspace(ch))
        {
            srcIndex++;
        }else if (ch == '\n') {
            srcIndex++;
        }
        else 
        {
            char errorMsg[50];
            sprintf(errorMsg, "Unkown symbol of %c\n", ch);
            MakeError(ErrorUnkownSymbol, errorMsg);
        }
    }

    return tokens;
}
