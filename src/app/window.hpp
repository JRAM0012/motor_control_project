#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "glad.h"
#include <GLFW/glfw3.h>
#include "user_interface.hpp"

class Window
{
public:
    Window(unsigned int height, unsigned int width);
    ImVec4 clear_color;

    int should_close_window();

    void PreLoop();
    void PostLoop();

    ~Window();

    GLFWwindow *glwindow = nullptr;
    ImGuiWindowFlags noMovewindowFlags;
};

#endif //__WINDOW_HPP__