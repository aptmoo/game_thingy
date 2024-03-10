#ifndef VID_H
#define VID_H

typedef struct
{
    int width, height;
} vidmode_t;

void VID_Init(void);
void VID_Shutdown(void);

void VID_Update();

void VID_SetMode(vidmode_t mode);
vidmode_t VID_GetMode(void);
vidmode_t VID_GetPrimaryMode(void);

void VID_SetFullscreen(int enable);

#endif