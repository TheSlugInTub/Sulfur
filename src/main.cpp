#include <filesystem>
#include <fstream>
#include <iostream>
#include "../include/lexer.hpp"

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

    std::string source((std::istreambuf_iterator<char>(file)),
            std::istreambuf_iterator<char>());

    std::vector<Lexer::Token> tokens = Lexer::Lex(source);

    for (auto& token : tokens)
    {
        std::cout << "Token: " << token.type << '\n';
    }

    return 0;
}
