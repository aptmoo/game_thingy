#ifndef CVAR_H
#define CVAR_H

typedef enum
{
    CVAR_NONE,
    CVAR_STRING,
    CVAR_INT,
    CVAR_FLOAT,
    CVAR_NOIMPL,
    CVAR_DONTCHANGE,    /* Forces indirect set functions to not change the type. */
} cvarType_t;

typedef struct cvar_s
{
    char* name;
    char* data;
    cvarType_t type; /* This only exists as a hint about the data. It is not enforced. */

    struct cvar_s* next;    
} cvar_t;

/**
 * @brief Creates and links an all-empty cvar.
 * 
 * @return cvar_t* 
 */
cvar_t* CVAR_AllocateVar(void);

/**
 * @brief Create var?
 * 
 * @param name 
 * @return cvar_t* 
 */
cvar_t* CVAR_CreateVar(char* name, char* value, cvarType_t type);

/**
 * @brief Returns a var with "name" or null.
 * 
 * @param name 
 * @return cvar_t* 
 */
cvar_t* CVAR_FindVar(char* name);

void CVAR_SetByPtr(cvar_t* var, char* value, cvarType_t type);


#endif