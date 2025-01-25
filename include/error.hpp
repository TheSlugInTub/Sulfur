#include <iostream>
#include <string>

struct Error
{
    std::string message = {};
    int lineNum = -1;
};

inline void MakeError(const Error& err)
{
    std::cout << '\n' << "Error on line number: " << std::to_string(err.lineNum) << '\n';
    std::cout << err.message << '\n';
}
