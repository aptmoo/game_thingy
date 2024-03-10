//move to build sys
#ifndef REFAPI_DEFINED
#define REFAPI_GL
#endif

#ifdef REFAPI_GL
#include "vid.h"

#include <stdlib.h>

#include "GLFW/glfw3.h"

static GLFWwindow* s_Window = NULL;
static GLFWvidmode* s_VidMode = NULL;
static GLFWmonitor* s_Monitor = NULL;

static vidmode_t s_CurrentMode;
static int s_Fullscreen = 0;

void VID_glfwFramebufferCallback(GLFWwindow*, int, int);

void VID_Init()
{
    if(s_Window != NULL)
    {
        // TODO: Throw error to shared
        return;
    }

    glfwInit();
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    s_Monitor = glfwGetPrimaryMonitor();

    s_VidMode = glfwGetVideoMode(s_Monitor);
    glfwWindowHint(GLFW_RED_BITS, s_VidMode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, s_VidMode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, s_VidMode->blueBits);

    s_Window = glfwCreateWindow(s_VidMode->width, s_VidMode->height, "Default title", NULL, NULL);
    glfwMakeContextCurrent(s_Window);

    glfwSetFramebufferSizeCallback(s_Window, VID_glfwFramebufferCallback);

    s_CurrentMode.height = s_VidMode->height;
    s_CurrentMode.width = s_VidMode->width;
}

void VID_Shutdown(void)
{
    //TODO: This probably sucks.
    glfwTerminate();
}

void VID_Update()
{
    glfwSwapBuffers(s_Window);
    glfwPollEvents();   // This should not be VID's responsibility. Whatever.
}

void VID_SetMode(vidmode_t mode)
{
    s_CurrentMode = mode;
    glfwSetWindowSize(s_Window, mode.width, mode.height);
}

vidmode_t VID_GetMode(void)
{
    vidmode_t mode;
    mode.height = s_CurrentMode.height;
    mode.width = s_CurrentMode.width;
    return mode;
}

vidmode_t VID_GetPrimaryMode(void)
{
    vidmode_t mode;
    mode.height = s_VidMode->height;
    mode.width = s_VidMode->width;
    return mode;
}

void VID_SetFullscreen(int enable)
{
    s_Fullscreen = enable;
    if(enable)
        glfwSetWindowMonitor(s_Window, s_Monitor, 0, 0, s_CurrentMode.width, s_CurrentMode.height, s_VidMode->refreshRate);
    else
        glfwSetWindowMonitor(s_Window, NULL, 0, 0, s_CurrentMode.width, s_CurrentMode.height, s_VidMode->refreshRate);
}

// Should theoretically never happen, since GLFW_RESIZABLE is false.
void VID_glfwFramebufferCallback(GLFWwindow* window, int width, int height)
{
    s_CurrentMode.width = width;
    s_CurrentMode.height = height;
}

// ??
// void VID_QueryModes()
// {
//     int glfwModeNum;
//     GLFWvidmode* glfwModes = glfwGetVideoModes(glfwGetPrimaryMonitor(), &glfwModeNum);

//     s_Modes.arr = malloc(glfwModeNum * sizeof(vidmode_t));
//     s_Modes.size = glfwModeNum;
//     for(int i = 0; i < glfwModeNum; i++)
//     {
//         s_Modes.arr[i].width = glfwModes[i].width;
//         s_Modes.arr[i].height = glfwModes[i].height;
//     }
// }

#endif