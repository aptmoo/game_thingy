#include "vid.h"
#include "GLFW/glfw3.h"

static GLFWwindow* s_window;
vidmode_t vidmode;

void VID_Init(void)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    s_window = glfwCreateWindow(1280, 720, "No title set!", NULL, NULL);
}

void VID_Shutdown(void)
{
    glfwTerminate();
}

void VID_Update(void)
{
    glfwGetWindowSize(s_window, &vidmode.width, &vidmode.height);
    glfwSwapBuffers(s_window);
    glfwPollEvents();
}

void VID_SetMode(vidmode_t mode)
{
    vidmode = mode;
    glfwSetWindowSize(s_window, mode.width, mode.height);
}

void VID_SetFullScreen(windowmode_t mode)
{
    switch (mode)
    {
    case WINDOW_DEFAULT:
        glfwSetWindowMonitor(s_window, NULL, 0, 0, vidmode.width, vidmode.height, GLFW_DONT_CARE);
        break;
    case WINDOW_FULLSCREEN:
        glfwSetWindowMonitor(s_window, glfwGetPrimaryMonitor(), 0, 0, vidmode.width, vidmode.height, GLFW_DONT_CARE);
    case WINDOW_BORDERLESS:
        const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
        glfwSetWindowMonitor(s_window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, GLFW_DONT_CARE);
    default:
        break;
    }
}