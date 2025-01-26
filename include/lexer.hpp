#pragma once

#include <string>
#include <vector>

namespace Lexer  
{

enum TokenType
{
    Token_Int = 0,
    Token_Char = 1,
    Token_Float = 2,
    Token_Double = 3,
    Token_IntLiteral = 4,
    Token_FloatLiteral = 5,
    Token_CharLiteral = 6,
    Token_Identifier = 7,
    Token_Equal = 8,
    Token_Semicolon = 9,
    Token_OpenParen = 10,
    Token_CloseParen = 11,
    Token_Exit = 12
};

struct Token 
{
    TokenType type;
    std::string stringValue;
    double doubleValue;
    float floatValue;
    int intValue;
    char charValue;
    int lineNum;
};

char Peek(const std::string& source, int currentIndex, int length = 1);
std::vector<Token> Lex(const std::string& source);

}
