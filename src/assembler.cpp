#include "../include/assembler.hpp"
#include <string>

using namespace Parser;
using namespace Lexer;

#define PeekStmt(count) head.statements[index + count]

namespace Assembler
{

void Instruct(std::string& output, const std::string& instruction, const std::string& reg,
              const std::string& num)
{
    output = output + "    " + instruction + " " + reg + ", " + num + '\n';
}

void SingleInstruct(std::string& output, const std::string& instruction, const std::string& reg)
{
    output = output + "    " + instruction + " " + reg + "\n";
}

void Syscall(std::string& output)
{
    output = output + "    syscall\n";
}

std::string Assemble(NodeHead& head)
{
    std::string dataSection = "global _start\n\nsection .data\n";
    std::string textSection = "\nsection .text\n\n_start:\n";

    for (int index = 0; index < head.statements.size(); ++index)
    {
        switch (PeekStmt(0).type)
        {
            case StatementType::Stmt_Exit:
            {
                Instruct(textSection, "mov", "rax", "60");
                Instruct(textSection, "mov", "rdi", std::to_string(PeekStmt(0).exit.returnCode));
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

                switch (head.variables[PeekStmt(0).definition.variableIndex].type)
                {
                    case VariableType::Var_Int:
                    {
                        Instruct(textSection, "mov", "rax", "0");
                        SingleInstruct(textSection, "push", "rax");

                        int offset =
                            8 * head.variables[PeekStmt(0).definition.variableIndex].stackLocation;

                        Instruct(textSection, "mov", "qword [rsp + " + std::to_string(offset) + "]",
                                 std::to_string(PeekStmt(0).definition.intValue));
                        break;
                    }
                    case VariableType::Var_Float:
                    {
                        std::string dataName = "floatVal" + std::to_string(floatCounter);
                        dataSection = dataSection + "    floatVal" + std::to_string(floatCounter) +
                                      ": dd " + std::to_string(PeekStmt(0).definition.floatValue) +
                                      "\n";
                        floatCounter++;

                        Instruct(textSection, "sub", "rsp", "16");
                        Instruct(textSection, "movss", "xmm0", "dword [" + dataName + "]");
                        Instruct(textSection, "movss", "[rsp]", "xmm0");
                    }
                }
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
