#include "loggerWindow.h"

LoggerWindow::LoggerWindow() {}
LoggerWindow::~LoggerWindow() {}
void LoggerWindow::loadLogFile(const std::string &filePath)
{
    logLines.clear();
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open log file: " << filePath << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        logLines.push_back(line);
    }
    file.close();
    std::cout << "Loaded " << logLines.size() << " lines from log file."
              << std::endl;
}

void LoggerWindow::renderLoggerWindow()
{
    ImGui::Begin("Log Window", &m_showLogWindow);

    if (ImGui::Button("Reload"))
    {
        loadLogFile("logs/logs.log");
    }

    for (const auto &line : logLines)
    {
        setLogColor(line);
        ImGui::Text("%s", line.c_str());
        ImGui::PopStyleColor();
    }

    ImGui::End();
}

void LoggerWindow::setLogColor(const std::string &line)
{
    static const std::unordered_map<std::string, ImU32> logColors = {
        {"[info]", IM_COL32(255, 255, 255, 255)},
        {"[warning]", IM_COL32(255, 255, 0, 255)},
        {"[error]", IM_COL32(255, 0, 0, 255)},
        {"[trace]", IM_COL32(128, 128, 128, 255)},
        {"[debug]", IM_COL32(0, 0, 255, 255)},
        {"[critical]", IM_COL32(220, 20, 60, 255)}};

    ImU32 color = IM_COL32(255, 255, 255, 255);

    for (const auto &[tag, col] : logColors)
    {
        if (line.find(tag) != std::string::npos)
        {
            color = col;
            break;
        }
    }

    ImGui::PushStyleColor(ImGuiCol_Text, color);
}