#include "window.hpp"
#include "user_interface.hpp"
#include "checkbox_image.hpp"

#include <stdio.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800

// Main code
int main(int, char **)
{
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT);
    UserInterface interface(window.glwindow);

    const int numRows = 4, numCols = 6;
    CheckboxImage cbimage[numRows * numCols];

    // Main loop
    while (!window.should_close_window())
    {
        window.PreLoop();
        interface.PreLoop();

        ImGui::SetNextWindowSize(ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT));
        ImGui::SetNextWindowPos(ImVec2(0, 0));

        ImGui::Begin("SRI SRINIVASA ENGINEERS", NULL, window.noMovewindowFlags);

        if (ImGui::BeginMenuBar())
        {
            // Begin the File menu
            if (ImGui::BeginMenu("View"))
            {
                // Add items to the File menu
                if (ImGui::MenuItem("Fullscreen"))
                {
                    // Handle the "New" action
                }
                // End the File menu
                ImGui::EndMenu();
            }
            // End the menu bar
            ImGui::EndMenuBar();
        }

        if (ImGui::BeginTabBar("Tabs"))
        {
            // Begin the first tab
            if (ImGui::BeginTabItem("Select Motors"))
            {
                // Content of Tab 1
                ImGui::Text("Tab 1 content select motors");

                for (size_t row = 0; row < numRows; row++)
                {
                    ImGui::Columns(numCols, nullptr, false);
                    for (size_t col = 0; col < numCols; col++)
                    {
                        cbimage[row * 4 + col].render(row, col);
                        ImGui::NextColumn();
                    }
                }

                ImGui::EndTabItem();
            }

            // Begin the second tab
            if (ImGui::BeginTabItem("Execute Motors"))
            {
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
