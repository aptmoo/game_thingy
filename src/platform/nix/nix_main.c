#include "shared/cvar.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    cvar_t* testVar = CVAR_CreateVar("Hello!", "Test", CVAR_STRING);
    cvar_t* testVar2 = CVAR_CreateVar("Goodbye", "Test2", CVAR_STRING);
    printf("%s\n", testVar->data);
    CVAR_SetByPtr(testVar, ":3", CVAR_STRING);
    printf("%s\n", testVar->data);
    return 0;
}