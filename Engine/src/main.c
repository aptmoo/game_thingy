#include "vid/vid.h"

int main(int argc, char const *argv[])
{
    VID_Init();
    VID_SetFullScreen(WINDOW_BORDERLESS);

    while (1)
    {
        
        VID_Update();
    }
    

    VID_Shutdown();
    return 0;
}
