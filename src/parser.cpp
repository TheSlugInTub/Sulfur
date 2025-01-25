#include "../include/parser.hpp"
#include "../include/error.hpp"

namespace Parser
{

using namespace Lexer;

#define PeekTok(peekSize) tokens[index + peekSize]
#define Consume() \
    index++;      \
    token = tokens[index];

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
                Consume(); // Consume int

                if (PeekTok(0).type != TokenType::Token_Identifier)
                {
                    Error err = {.message = "Expected an identifier after 'int'",
                                 .lineNum = token.lineNum};
                    MakeError(err);
                }

                // Check if declaration
                if (PeekTok(1).type == TokenType::Token_Semicolon)
                {
                    NodeDeclaration decl = {.type = VariableType::Var_Int};
                    NodeStatement   stmt = {.declaration = decl,
                                            .type = StatementType::Stmt_Declaration};
                    Variable var = {.identifier = token.stringValue, .type = VariableType::Var_Int};
                    head.variables.push_back(var);
                    Consume(); // Consume identifier
                }
                // Check if definition
                else if (PeekTok(1).type == TokenType::Token_Equal)
                {
                    if (PeekTok(2).type != TokenType::Token_IntLiteral)
                    {
                        Error err = {.message = "Expected an int literal as int definition",
                                     .lineNum = token.lineNum};
                        MakeError(err);
                    }

                    NodeDeclaration decl = {.type = VariableType::Var_Int};
                    NodeStatement   declStmt = {.declaration = decl,
                                                .type = StatementType::Stmt_Declaration};

                    Variable var = {.identifier = token.stringValue, .type = VariableType::Var_Int};
                    head.variables.push_back(var);

                    NodeDefinition def = {.intValue = PeekTok(2).intValue,
                                          .variableIndex = (int)head.variables.size() - 1};
                    NodeStatement  defStmt = {.definition = def,
                                              .type = StatementType::Stmt_Definition};
                    head.statements.push_back(defStmt);
                    Consume(); // Consume identifier
                    Consume(); // Consume equals sign
                    Consume(); // Consume int literal
                }
                else
                {
                    Error err = {.message =
                                     "Expected a semicolon or an equals sign after int declaration",
                                 .lineNum = token.lineNum};
                    MakeError(err);
                }

                if (PeekTok(0).type != TokenType::Token_Semicolon)
                {
                    Error err = {.message = "Expected a semicolon after the statement",
                                 .lineNum = token.lineNum};
                    MakeError(err);
                }

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
                    Error err = {
                        .message =
                            "Expected '(' after 'exit' because it is built-in compiler function",
                        .lineNum = token.lineNum};
                    MakeError(err);
                }
                Consume();                                          // Consume exit token
                if (PeekTok(1).type != TokenType::Token_IntLiteral) // current token is open paren
                {
                    Error err = {
                        .message =
                            "Expected an int literal as the argument to 'exit' function call",
                        .lineNum = token.lineNum};
                    MakeError(err);
                }
                Consume(); // Consume open paren, current token is int literal

                NodeExit      exit = {.returnCode = token.intValue};
                NodeStatement stmt = {.exit = exit, .type = StatementType::Stmt_Exit};

                Consume(); // Consume int literal, current token is close paren
                Consume(); // Consume close paren, current token is semicolon

                if (PeekTok(0).type != TokenType::Token_Semicolon)
                {
                    Error err = {.message = "Expected a semicolon after the statement",
                                 .lineNum = token.lineNum};
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
