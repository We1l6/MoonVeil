#ifndef LOGGERWINDOW_H
#define LOGGERWINDOW_H

#include "imgui.h"
#include "rlImGui.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class LoggerWindow
{
  public:
    LoggerWindow();
    ~LoggerWindow();
    void renderLoggerWindow();

  private:
    void setLogColor(const std::string &line);
    void loadLogFile(const std::string &filePath);
    bool m_showLogWindow = true;
    std::vector<std::string> logLines;
};

#endif // LOGGERWINDOW_H