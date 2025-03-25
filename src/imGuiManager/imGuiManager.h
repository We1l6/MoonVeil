#ifndef IMGUIMANAGER_H
#define IMGUIMANAGER_H

#include "imgui.h"
#include "rlImGui.h"
#include <string>

#include "../loggerManager/loggerManager.h"
#include "loggerWindow/loggerWindow.h"
#include <iostream>
#include <vector>
class ImGuiManager
{
  public:
    ImGuiManager();
    ~ImGuiManager();
    void ToggleWindow();
    void Render();
    void ToggleLogWindow();
    void LoadLogFile(const std::string &filePath);

  private:
    bool m_showWindow = false;
    bool m_showLogWindow = false;
    std::vector<std::string> m_logLines;
    LoggerWindow loggerWindow;
};

#endif // IMGUIMANAGER_H
