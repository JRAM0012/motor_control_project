#include "window.hpp"
#include "user_interface.hpp"
#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include <thread>

static void glfw_error_callback(int error, const char *description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

Window::Window(unsigned int width, unsigned int height)
{

    noMovewindowFlags = ImGuiWindowFlags_NoTitleBar;
    noMovewindowFlags |= ImGuiWindowFlags_NoMove;
    noMovewindowFlags |= ImGuiWindowFlags_NoResize;
    noMovewindowFlags |= ImGuiWindowFlags_NoCollapse;
    noMovewindowFlags |= ImGuiWindowFlags_MenuBar;

    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        exit(-1);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1);

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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
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
    startTime = glfwGetTime();
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

    double currentTime = glfwGetTime();
    double frameTime = currentTime - startTime;
    startTime = currentTime;

    if (frameTime > (1.0f/60.0f))
    {
        frameTime = (1.0f/60.0f);
    }

    double remainingTime = (1.0f/60.0f) - frameTime;
    if (remainingTime > 0)
    {
        std::this_thread::sleep_for(std::chrono::duration<double>(remainingTime));
    }
}

Window::~Window()
{
    glfwDestroyWindow(glwindow);
    glfwTerminate();
}