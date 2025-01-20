#pragma once

#include <string>
#include <cstdint>
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
    Token_Identifier = 6,
    Token_Equal = 7,
    Token_Semicolon = 8,
    Token_OpenParen = 9,
    Token_CloseParen = 10,
    Token_Exit = 11
};

struct Token 
{
    TokenType type;
    std::string stringValue;
    int64_t intValue;
    float floatValue;
    double doubleValue;
};

char Peek(const std::string& source, int currentIndex, int length = 1);
std::vector<Token> Lex(const std::string& source);

}
