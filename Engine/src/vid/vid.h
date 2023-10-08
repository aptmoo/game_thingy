#ifndef VID_H
#define VID_H

typedef enum
{
    WINDOW_DEFAULT = 0,
    WINDOW_FULLSCREEN,
    WINDOW_BORDERLESS,
} windowmode_t;

typedef struct
{
    int width, height;
} vidmode_t;

extern vidmode_t vidmode;

/**
 * @brief Init the video system.
 * Should be done before initing the renderer.
 * 
 */
void VID_Init(void);

/**
 * @brief Terminate the video system.
 * Should be done after shutting down the renderer.
 * 
 */
void VID_Shutdown(void);

/**
 * @brief Update the video system.
 * Swaps buffers and sets vidmode.
 * Should be done after each frame.
 * 
 */
void VID_Update(void);

/**
 * @brief Sets the window size.
 * 
 * @param mode 
 */
void VID_SetMode(vidmode_t mode);

/**
 * @brief Set the fullscreen mode.
 * 
 * @param mode 
 */
void VID_SetFullScreen(windowmode_t mode);

#endif