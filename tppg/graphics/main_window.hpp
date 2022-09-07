// Author:        Arash Fatehi
// Date:          2022-08-24
// Description:

#pragma once

// Local Includes
#include "imgui/imgui_gl.hpp"

namespace TPP
{
    class MainWindow : public IMGUIOpenGL<MainWindow>
    {
    public:
        MainWindow(TPP& _tpp);
        void Draw();

    private:
        void SummaryFrame(const int& _width, const int& _height);
        void MainFrame(const int& _width, const int& _height);
        void FilterFrame(const int& _width, const int& _height);
        void CommandFrame(const int& _width, const int& _height);
        
        void UpdateMonitorInfo();

    private:
        ImGuiStyle& style = ImGui::GetStyle();
    };
} // namespace TPP
