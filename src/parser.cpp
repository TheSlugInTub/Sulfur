#include "../include/parser.hpp"
#include "../include/error.hpp"

namespace Parser
{

using namespace Lexer;

#define PeekTok(peekSize) tokens[index + peekSize]
#define Consume() index++; token = tokens[index];

NodeHead Parse(const std::vector<Lexer::Token>& tokens)
{
    NodeHead head;

    for (int index = 0; index < tokens.size(); index++)
    {
        Token token = tokens[index];

        switch (token.type)
        {
            case TokenType::Token_Int:
            {
                break;
            }
            case TokenType::Token_Char:
            {
                break;
            }
            case TokenType::Token_Float:
            {
                break;
            }
            case TokenType::Token_Double:
            {
                break;
            }
            case TokenType::Token_IntLiteral:
            {
                break;
            }
            case TokenType::Token_FloatLiteral:
            {
                break;
            }
            case TokenType::Token_Identifier:
            {
                break;
            }
            case TokenType::Token_Equal:
            {
                break;
            }
            case TokenType::Token_Semicolon:
            {
                break;
            }
            case TokenType::Token_OpenParen:
            {
                break;
            }
            case TokenType::Token_CloseParen:
            {
                break;
            }
            case TokenType::Token_Exit:
            {
                if (PeekTok(1).type != TokenType::Token_OpenParen)
                {
                    Error err = {.message = "Expected '(' after 'exit' because it is built-in compiler function", .lineNum = token.lineNum};
                    MakeError(err);
                }
                Consume(); // Consume exit token
                if (PeekTok(1).type != TokenType::Token_IntLiteral)
                {
                    Error err = {.message = "Expected an int literal as the argument to 'exit' function call", .lineNum = token.lineNum};
                    MakeError(err);
                }
                Consume(); // Consume open paren
                NodeExit exit = {.returnCode = token.intValue};
                NodeStatement stmt = {.type = StatementType::Stmt_Exit, .exit = exit};
                
                if (PeekTok(1).type != TokenType::Token_Semicolon)
                {
                    Error err = {.message = "Expected a semicolon after the statement", .lineNum = token.lineNum};
                    MakeError(err);
                }

                head.statements.push_back(stmt);

                break;
            }
        }

        continue;
    }

    return head;
}

} // namespace Parser
