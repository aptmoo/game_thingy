#include "shared.h"

#include "vid/vid.h"

int main(int argc, char const *argv[])
{
    VID_Init();
    VID_SetMode((vidmode_t){1280, 720});

    while (1)
    {
        VID_Update();
    }
    

    VID_Shutdown();
    return 0;
}
