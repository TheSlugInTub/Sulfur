#include "../include/lexer.hpp"
#include "../include/error.hpp"
#include <cctype>

namespace Lexer
{

char Peek(const std::string& source, int currentIndex, int length)
{
    return source[currentIndex + length];
}

std::vector<Token> Lex(const std::string& source)
{
    std::vector<Token> tokens;
    int lineNum = 1;

    for (int index = 0; index < source.length(); index++)
    {
        char ch = source[index];

        if (std::isalpha(ch))
        {
            std::string str = {};
            str = str + ch;
            while (std::isalpha(Peek(source, index)))
            {
                index++;
                ch = source[index];

                str = str + ch;
            }

            if (str == "int")
            {
                Token tok{.type = TokenType::Token_Int, .lineNum = lineNum};
                tokens.push_back(tok);
            }
            else if (str == "char")
            {
                Token tok{.type = TokenType::Token_Char, .lineNum = lineNum};
                tokens.push_back(tok);
            }
            else if (str == "float")
            {
                Token tok{.type = TokenType::Token_Float, .lineNum = lineNum};
                tokens.push_back(tok);
            }
            else if (str == "double")
            {
                Token tok{.type = TokenType::Token_Double, .lineNum = lineNum};
                tokens.push_back(tok);
            }
            else if (str == "exit")
            {
                Token tok{.type = TokenType::Token_Exit, .lineNum = lineNum};
                tokens.push_back(tok);
            }
            else 
            {
                Token tok{.type = TokenType::Token_Identifier, .stringValue = str,
                                                               .lineNum = lineNum};
                tokens.push_back(tok);
            }
            continue;
        }

        if (std::isdigit(ch))
        {
            bool isFloat = false;
            std::string str = {};
            str.push_back(ch); 
            while (std::isdigit(Peek(source, index)) || Peek(source, index) == '.')
            {
                index++;
                ch = source[index];
                str.push_back(ch);

                if (ch == '.') { isFloat = true; }
            }

            if (isFloat)
            {
                Token tok{.type = TokenType::Token_FloatLiteral,
                    .floatValue = std::stof(str), .lineNum = lineNum};
                tokens.push_back(tok);
            }
            else
            {
                Token tok{.type = TokenType::Token_IntLiteral,
                    .intValue = std::stoi(str), .lineNum = lineNum};
                tokens.push_back(tok);
            }
            continue;
        }

        if (ch == '=')
        {
            Token tok{.type = TokenType::Token_Equal, .lineNum = lineNum};
            tokens.push_back(tok);
            continue;
        }

        if (ch == ';')
        {
            Token tok{.type = TokenType::Token_Semicolon, .lineNum = lineNum};
            tokens.push_back(tok);
            continue;
        }

        if (ch == '(')
        {
            Token tok{.type = TokenType::Token_OpenParen, .lineNum = lineNum};
            tokens.push_back(tok);
            continue;
        }

        if (ch == ')')
        {
            Token tok{.type = TokenType::Token_CloseParen, .lineNum = lineNum};
            tokens.push_back(tok);
            continue;
        }

        if (ch == '\n') 
        { 
            lineNum++;
            continue; 
        }

        if (std::isspace(ch) || ch == '\t')
        { 
            continue; 
        }

        std::string err = "Character: ";
        err.push_back(ch);
        err = err + " was not recognized";
        MakeError(Error{.message = err, .lineNum = lineNum});

        index++;
    }

    return tokens;
}

}
