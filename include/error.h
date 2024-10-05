#ifndef ERROR_H
#define ERROR_H

// ANSI escape codes for different colors
#define T_RESET   "\x1b[0m"
#define T_RED     "\x1b[31m"
#define T_GREEN   "\x1b[32m"
#define T_YELLOW  "\x1b[33m"
#define T_BLUE    "\x1b[34m"
#define T_MAGENTA "\x1b[35m"
#define T_CYAN    "\x1b[36m"
#define T_WHITE   "\x1b[37m"

typedef enum
{
    ErrorNone = 0,
    ErrorUnknownIdentifier,
    ErrorUnkownSymbol
} ErrorType;

void MakeError(ErrorType errorType, const char* errorMsg);

#endif
