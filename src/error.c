#include "../include/error.h"
#include <stdio.h>

void MakeError(ErrorType errorType, const char* errorMsg)
{
    printf("\033[0;31m");
    printf("Error of type: %d\n", errorType);
    printf("\033[0m");
    printf(errorMsg);
}
