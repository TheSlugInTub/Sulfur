#ifndef LEXER_H
#define LEXER_H

typedef enum
{
    TokenEmpty = 0,
    TokenExit,
    TokenOpenParen,
    TokenCloseParen,
    TokenSemicolon,
    TokenNumber
} TokenType;

typedef struct
{
    TokenType type;
    char value[10];
    int intValue;
} Token;

extern int srcIndex;
extern Token tokens[100];
extern int tokenIndex;

char Peek(const char* src, const int offset, int length);
Token* Lex(const char* source);

#endif
