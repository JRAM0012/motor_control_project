#include "window.hpp"
#include "user_interface.hpp"
#include "image.hpp"

#include <stdio.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800



// Main code
int main(int, char**)
{
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT);
    UserInterface interface(window.glwindow);

    Image image("assets/icon_small.png");

    // Main loop
    while (!window.should_close_window())
    {
        window.PreLoop();
        interface.PreLoop();

        ImGui::SetNextWindowSize(ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT));
        ImGui::SetNextWindowPos(ImVec2(0, 0));

        ImGuiWindowFlags windowFlags;
        windowFlags = ImGuiWindowFlags_NoTitleBar;
        windowFlags |= ImGuiWindowFlags_NoMove;
        windowFlags |= ImGuiWindowFlags_NoResize;
        windowFlags |= ImGuiWindowFlags_NoCollapse;
        windowFlags |= ImGuiWindowFlags_MenuBar;

        ImGui::Begin("SRI SRINIVASA ENGINEERS", NULL, windowFlags);

        if (ImGui::BeginMenuBar()) {
            // Begin the File menu
            if (ImGui::BeginMenu("View")) {
                // Add items to the File menu
                if (ImGui::MenuItem("Fullscreen")) {
                    // Handle the "New" action
                }
                // End the File menu
                ImGui::EndMenu();
            }
            // End the menu bar
            ImGui::EndMenuBar();
        }


        if (ImGui::BeginTabBar("Tabs")) {
            // Begin the first tab
            if (ImGui::BeginTabItem("Select Motors")) {
                // Content of Tab 1
                ImGui::Text("Tab 1 content select motors");

                ImGui::Image(image.get_image_id(), image.get_image_size());
                
                ImGui::EndTabItem();
            }

            // Begin the second tab
            if (ImGui::BeginTabItem("Execute Motors")) {
                // Content of Tab 2
                ImGui::Text("Tab 2 execute motors");
                ImGui::EndTabItem();
            }

            // End the tab bar
            ImGui::EndTabBar();
        }

        interface.PostLoop();
        window.PostLoop();
    }
    return 0;
}
