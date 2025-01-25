#include "../include/assembler.hpp"
#include <exception>
#include <string>

using namespace Parser;
using namespace Lexer;

#define PeekStmt(count) head.statements[index + count]

namespace Assembler
{

void Mov(std::string& output, const std::string& reg, int num)
{
    output = output + "    mov " + reg + ", " + std::to_string(num) + '\n';
}

void Push(std::string& output, const std::string& reg)
{
    output = output + "    push " + reg + "\n";
}

void Syscall(std::string& output)
{
    output = output + "    syscall\n";
}

std::string Assemble(NodeHead& head)
{
    std::string dataSection = "global _start\n\nsection .data\n\n";
    std::string textSection = "section .text\n\n_start:\n";

    for (int index = 0; index < head.statements.size(); ++index)
    {
        switch (PeekStmt(0).type)
        {
            case StatementType::Stmt_Exit:
            {
                Mov(textSection, "rax", 60);
                Mov(textSection, "rdi", PeekStmt(0).exit.returnCode);
                Syscall(textSection);
                break;
            }
            case StatementType::Stmt_Declaration:
            {
                break;
            }
            case StatementType::Stmt_Definition:
            {
                head.variables[PeekStmt(0).definition.variableIndex].stackLocation =
                    currentStackLocation;
                currentStackLocation++;

                Mov(textSection, "rax", 0);
                Push(textSection, "rax");

                int offset = 8 * head.variables[PeekStmt(0).definition.variableIndex].stackLocation;

                Mov(textSection, "qword [rsp + " + std::to_string(offset) + "]", PeekStmt(0).definition.intValue);
                break;
            }
            case StatementType::Stmt_Assignment:
            {
                break;
            }
        }
    }

    return dataSection + textSection;
}

} // namespace Assembler
