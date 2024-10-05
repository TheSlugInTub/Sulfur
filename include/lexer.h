#ifndef LEXER_H
#define LEXER_H

typedef enum
{
    TokenEmpty = 0,
    TokenExit,
    TokenPrint,
    TokenOpenParen,
    TokenCloseParen,
    TokenSemicolon,
    TokenNumber,
    TokenStringLiteral
} TokenType;

typedef struct
{
    TokenType type;
    char value[100];
    int intValue;
} Token;

extern int srcIndex;
extern Token tokens[100];
extern int tokenIndex;

char Peek(const char* src, const int offset, int length);
Token* Lex(const char* source);

#endif
