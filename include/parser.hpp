#pragma once

#include <vector>
#include <string>
#include "lexer.hpp"

namespace Parser  
{

enum VariableType : unsigned char 
{
    Var_Int = 0,
    Var_Char = 1,
    Var_Float = 2,
    Var_Double = 3
};

struct Variable 
{
    std::string identifier;
    int stackLocation = 0;
    VariableType type;
};

struct NodeDeclaration
{
    VariableType type;
};

struct NodeAssignment
{
    union 
    {
        double doubleValue;
        float floatValue;
        int intValue;
        char charVaue;
    };
    int variableIndex; // Index in NodeHead's variables vector
    VariableType type;
};

struct NodeAssignmentToVar
{
    int lvalue; // Index in NodeHead's variables vector
    int rvalue; // Index in NodeHead's variables vector
    VariableType type;
};

struct NodeExit
{
    int returnCode;
};

enum StatementType : unsigned char
{
    Stmt_Declaration = 0,
    Stmt_Assignment = 1,
    Stmt_Exit = 2
};

struct NodeStatement
{
    union
    {
        NodeDeclaration declaration;
        NodeAssignment assignment;
        NodeExit exit;
    };
    StatementType type;
};

struct NodeHead 
{
    std::vector<NodeStatement> statements;
    std::vector<Variable> variables;
};

NodeHead Parse(const std::vector<Lexer::Token>& tokens);

}
