#pragma once

#include "parser.hpp"

namespace Assembler
{

inline int floatCounter; // How many float values are defined in the .data section

std::string Assemble(Parser::NodeHead& head);

} // namespace Assembler
