#include "cvar.h"
#include <stdlib.h>
#include <string.h>

#include "stringutils.h"

static cvar_t* s_Cvars;

cvar_t* CVAR_AllocateVar(void)
{
    cvar_t* var = malloc(sizeof(cvar_t));
    memset(var, 0, sizeof(cvar_t));
    if(!s_Cvars)
    {
        s_Cvars = var;
        return s_Cvars;
    }
    var->next = s_Cvars;
    s_Cvars = var;
    return s_Cvars;
}

cvar_t* CVAR_CreateVar(char* name, char* value, cvarType_t type)
{
    cvar_t* var = CVAR_FindVar(name);
    if(!var)
        var = CVAR_AllocateVar();

    /* Not checking for null. Would be rather silly to pass null here anyways */
    var->name = STR_CopyString(name);

    /* Value being null makes some sense i guess */
    if(value)
        var->data = STR_CopyString(value);
    else
        var->data = STR_CopyString("");
    
    var->type = type;
}

cvar_t* CVAR_FindVar(char* name)
{
    cvar_t* var;
    if(!s_Cvars)
        return NULL; /* Too bad! */

    for(var = s_Cvars; var != NULL; var = var->next)
    {
        if(!var->name)
            continue;

        if(!strcmp(name, var->name))
        {
            return var;
        }
    }

    return NULL;
}

void CVAR_SetByPtr(cvar_t* var, char* value, cvarType_t type)
{
    if(!var)    
        return; /* You didn't actually pass a cvar silly */

    if(var->data)
        free(var->data);
    var->data = STR_CopyString(value);
    if(type !=  CVAR_DONTCHANGE)
        var->type = type;
}