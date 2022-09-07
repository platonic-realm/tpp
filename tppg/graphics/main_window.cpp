// Author:        Arash Fatehi
// Date:          2022-08-24
// Description:

// Index of this file:
// [SECTION] MainWindow::Draw
// [SECTION] MainWindow::SummaryFrame
// [SECTION] MainWindow::MainFrame
// [SECTION] MainWindow::FilterFrame
// [SECTION] MainWindow::CommandFrame
// [SECTION] MainWindow::UpdateMonitorInfo

// Standard Headers
#include <iostream>
#include <stdio.h>
#include <math.h> 

// Local Headers
#include "glfw/glfw_utils.hpp"
#include "main_window.hpp"

namespace TPP
{


MainWindow::MainWindow(TPP& _tpp)
    : IMGUIOpenGL<MainWindow>(_tpp)
{
    // Style Configuration
    style.WindowPadding = ImVec2(0, 0);
    style.TabRounding = 0.0f;
    style.ItemSpacing = ImVec2(0, 0);

    // Setting the dark theme
    ImGui::StyleColorsDark();

    // Font Configuration
    ImGuiIO& io = ImGui::GetIO();
    ImFont* font = io.Fonts->AddFontFromFileTTF("/home/arash/Abyss/Projects/01-Linux/tpp/tppg/res/alice.regular.ttf", 20);
}

// [SECTION] MainWindow::Draw
void MainWindow::Draw()
{

    UpdateMonitorInfo();

    // Collecting the size of the glfw window
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    // Be sure that the MainWindow will always remin fullscreen, even after resize
    ImGui::SetNextWindowSize(ImVec2(width, height));

    static ImGuiTableFlags s_main_window_flags = ImGuiWindowFlags_NoTitleBar |
                                                 ImGuiWindowFlags_NoResize |
                                                 ImGuiWindowFlags_NoMove;
    static bool s_is_active = true;

    ImGui::Begin("MainWindow",
                 &s_is_active,
                 s_main_window_flags);

    {

        // clang-format off
        // Calculating frames width and height
        int command_frame_height_mm    = 8;
        int command_frame_height_pixel = command_frame_height_mm*heightPPM;
        int filter_frame_width_mm    = 40;
        int filter_frame_width_pixel = filter_frame_width_mm*widthPPM; 
        
        int usable_height = height - command_frame_height_pixel;
        int usable_width  = width  - filter_frame_width_pixel;
        
        const int heigth_divisor = 30;
        int summary_frame_height = ((float)usable_height / heigth_divisor) * 5;
        int main_frame_height    = ((float)usable_height / heigth_divisor) * 25;
        // clang-format on

        // Drawing main UI components
        SummaryFrame(0, summary_frame_height);
        MainFrame(usable_width, main_frame_height);

        // For horizental alignement
        ImGui::SameLine();
        FilterFrame(0, main_frame_height);

        // Set command heigth to 10mm height = command_frame_height/dpmHeight
        CommandFrame(0, command_frame_height_pixel);
    }

    // bool showDemo = true;
    // ImGui::ShowDemoWindow(&showDemo);

    ImPlot::ShowDemoWindow();

    ImGui::End();
}

// [SECTION] MainWindow::SummaryFrame
void MainWindow::SummaryFrame(const int& _width, const int& _height)
{
    ImGui::BeginChild("SummaryFrame", ImVec2(0, _height), true, ImGuiWindowFlags_None);


    
    ImGui::EndChild();
}

// [SECTION] MainWindow::MainFrame
void MainWindow::MainFrame(const int& _width, const int& _height)
{
    ImGui::BeginChild("MianFrame", ImVec2(_width, _height), true, ImGuiWindowFlags_None);
    {

        if (ImGui::BeginTabBar("MyTabBar", ImGuiWindowFlags_None))
        {

            if (ImGui::BeginTabItem("  Avocado  "))
            {
                static ImGuiTableFlags flags = ImGuiTableFlags_Resizable |
                                               ImGuiTableFlags_Reorderable |
                                               ImGuiTableFlags_Hideable |
                                               ImGuiTableFlags_ScrollY |
                                               ImGuiTableFlags_RowBg;

                if (ImGui::BeginTable("table2", 3, flags))
                {
                    ImGui::TableSetupColumn("One");
                    ImGui::TableSetupColumn("Two");
                    ImGui::TableSetupColumn("Three");
                    ImGui::TableSetupScrollFreeze(1, 1);
                    ImGui::TableHeadersRow();

                    for (int row = 0; row < 6; row++)
                    {
                        ImGui::TableNextRow();
                        for (int column = 0; column < 3; column++)
                        {
                            ImGui::TableSetColumnIndex(column);
                            ImGui::Text("Fixed %d,%d", column, row);
                        }
                    }

                    ImGui::EndTable();
                }

                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("  Broccoli  "))
            {
                ImGui::Text("This is the Broccoli tab!\nblah blah blah blah blah");
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("  Cucumber  "))
            {
                ImGui::Text("This is the Cucumber tab!\nblah blah blah blah blah");
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
    }

    ImGui::EndChild();
}

// [SECTION] MainWindow::FilterFrame
void MainWindow::FilterFrame(const int& _width, const int& _height)
{
    ImGui::BeginChild("FileterFrame", ImVec2(_width, _height), true, ImGuiWindowFlags_None);

    ImGui::EndChild();
}

// [SECTION] MainWindow::CommandFrame
void MainWindow::CommandFrame(const int& _width, const int& _height)
{
    ImGui::BeginChild("CommandFrame", ImVec2(0, _height), true, ImGuiWindowFlags_None);

    ImGui::EndChild();
}

// [SECTION] MainWindow::UpdateMonitorInfo
void MainWindow::UpdateMonitorInfo()
{
    // Collecting the current monitor size
    GLFWmonitor* monitor = get_current_monitor(window);
    glfwGetMonitorPhysicalSize(monitor, &widthMM, &heightMM);

    // Collecting the current monitor resolution
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    widthPixel = mode->width;
    heightPixel = mode->height;

    // PPM: pixel per milimeter
    widthPPM = (float)widthPixel / widthMM;
    heightPPM = (float)heightPixel / heightMM;
}

} // namespace TPP
