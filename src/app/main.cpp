#include "window.hpp"
#include "user_interface.hpp"
#include "checkbox_container.hpp"
#include <chrono>
#include <stdio.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800
#define SPLASH_SCREEN_DURATION 10.5f
#define FPS_CAP 60

unsigned int open_time = 0;
unsigned int close_time = 0;
unsigned int forward_time = 0;
unsigned int reverse_time = 0;
unsigned int randomNumberSize = 0;
unsigned int randomNumber = 0;
unsigned int target_open_set_time = 0;
unsigned int target_open_read_time = 0;
std::vector<unsigned int> randomNumberSequence;

void generateRandomNumber()
{
    int k;
    bool m;
    unsigned int randomCounter = 0;
    for (int k = 0; k < randomNumberSize - 1; k++)
    {
        randomNumberSequence[k] = 0;
    }
    while (randomCounter < randomNumberSize)
    {
        randomNumber = (randomNumberSize * rand()) + 1;
        for (int k = 0; k < randomNumberSize - 1; k++)
        {
            if (randomNumberSequence[k] == randomNumber)
            {
                m = true;
            }
            if (m == false)
            {
                randomNumberSequence[randomCounter] = randomNumber;
                randomCounter = randomCounter + 1;
            }
            m = false;
        }
    }
}

// Main code
int main(int, char **)
{
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT);
    UserInterface interface(window.glwindow);

    CheckBoxContainer container(4, 6);
    auto startTime = std::chrono::steady_clock::now();
    Image splashScreen("assets/splashscreen.png");
    ImTextureID imguiimage = splashScreen.get_image_id();
    bool showSplash = true;

    // Main loop
    while (!window.should_close_window())
    {
        window.PreLoop();
        interface.PreLoop();

        if (showSplash)
        {
            auto currentTime = std::chrono::steady_clock::now();
            float elapsedTime = std::chrono::duration<float>(currentTime - startTime).count();

            ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
            ImGui::SetNextWindowSize(ImVec2(1280, 720), ImGuiCond_Always);
            ImGui::Begin("Splash Screen", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBackground);
            ImGui::Image(imguiimage, ImVec2(23, 23));
            // Center text

            ImGui::SetCursorPosX(ImGui::GetWindowWidth() * 0.15f);
            ImGui::SetCursorPosY(ImGui::GetWindowHeight() * 0.35f);
            ImGui::Image(imguiimage, ImVec2(200, 200));


            ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("Designed by").x) * 0.25f);
            ImGui::SetCursorPosY((ImGui::GetWindowHeight() - ImGui::CalcTextSize("Designed by").y) * 0.35f);

            ImGui::Text("Designed by");
            ImGui::SetCursorPosY(100);
            ImGui::SetCursorPosX(200);
            
            if (elapsedTime >= SPLASH_SCREEN_DURATION)
                showSplash = false;
            interface.PostLoop();
            window.PostLoop();
            continue;
        }

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

                container.Render();

                ImGui::EndTabItem();
            }

            // Begin the second tab
            if (ImGui::BeginTabItem("Execute Motors"))
            {
                // Content of Tab 2
                ImGui::Text("Tab 2 execute motors");

                container.RenderSelectedBlocks();

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
