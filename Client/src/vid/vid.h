#ifndef VID_H
#define VID_H

typedef struct
{
    int width, height;
    int fullscreen;
} viddesc_t;

void VID_Init(viddesc_t desc);
void VID_Shutdown(void);

void VID_SetSize(int width, int height);

void VID_SetFullscreen(int fullscreen);

#endif