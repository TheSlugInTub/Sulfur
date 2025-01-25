#include <filesystem>
#include <fstream>
#include <iostream>
#include "../include/lexer.hpp"
#include "../include/parser.hpp"
#include "../include/assembler.hpp"

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cout << "Sulfur compiler. Please add a file as the argument.";
        return 0;
    }

    std::filesystem::path filePath = argv[1];

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filePath << '\n';
        return -1;
    }

    std::string source((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::vector<Lexer::Token> tokens = Lexer::Lex(source);

    for (auto& token : tokens) { std::cout << "Token: " << token.type << '\n'; }

    Parser::NodeHead head = Parser::Parse(tokens);

    std::string output = Assembler::Assemble(head);

    std::ofstream outputFile("output.asm");
    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open output file.\n";
        return -1;
    }

    outputFile << output;
    outputFile.close();

    system("nasm -felf64 output.asm");
    system("ld -o out output.o");
    system("rm output.o");

    return 0;
}
