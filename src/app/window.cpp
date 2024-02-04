#include "window.hpp"
#include "user_interface.hpp"
#include <stdio.h>
#include <cstdlib>

static void glfw_error_callback(int error, const char *description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

Window::Window(unsigned int width, unsigned int height)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        exit(-1);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    // Create window with graphics context
    glwindow = glfwCreateWindow(width, height, "SRI SRINIVASHA ENGINEERS CHENNAI-53 +919841334298", nullptr, nullptr);
    if (glwindow == nullptr)
    {
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(glwindow);
    glfwSwapInterval(1); // Enable vsync
    clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("failed to initialize glad\n");
        exit(-1);
    }
    glViewport(0, 0, width, height);
}

int Window::should_close_window()
{
    return glfwWindowShouldClose(glwindow);
}

void Window::PreLoop()
{
    glfwPollEvents();
}

void Window::PostLoop()
{

    int display_w, display_h;
    glfwGetFramebufferSize(glwindow, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

    glfwMakeContextCurrent(glwindow);
    glfwSwapBuffers(glwindow);
}

Window::~Window()
{
    glfwDestroyWindow(glwindow);
    glfwTerminate();
}