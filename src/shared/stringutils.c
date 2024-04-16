#include "stringutils.h"
#include "stdlib.h"
#include "string.h"

char* STR_CopyString(char* source)
{
    size_t len = strlen(source);
    char* str = malloc((len + 1) * sizeof(char));
    strncpy(str, source, len);
    return str;
}