#include "shared/cvar.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    cvar_t* testVar = CVAR_AllocateVar();
    cvar_t* testVar2 = CVAR_AllocateVar();
    CVAR_SetByPtr(testVar, "Test!", CVAR_STRING);
    printf("%s\n", testVar->data);
    return 0;
}