#ifndef LOGGERWINDOW_H
#define LOGGERWINDOW_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "rlImGui.h"
#include "imgui.h"
#include <unordered_map>

class LoggerWindow {
    public:
        LoggerWindow();
        ~LoggerWindow();
        void renderLoggerWindow();

    
    private:
        void setLogColor(const std::string& line);
        void loadLogFile(const std::string& filePath);
        bool m_showLogWindow = true;
        std::vector<std::string> logLines;  
    };

#endif // LOGGERWINDOW_H