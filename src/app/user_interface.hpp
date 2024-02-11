#ifndef __USER_INTERFACE__
#define __USER_INTERFACE__

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include <GLFW/glfw3.h>

class UserInterface
{
public:
    UserInterface(GLFWwindow *window);

    void PreLoop();
    void PostLoop();

    ~UserInterface();
};

#endif //__USER_INTERFACE__