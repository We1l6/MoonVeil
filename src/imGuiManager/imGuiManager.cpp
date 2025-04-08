#include "imGuiManager.h"
#include "imgui.h"

ImGuiManager::ImGuiManager()
{
    rlImGuiSetup(true);
    // LoadLogFile("logs/logs.log");
    LOG_TRACE("This is a trace message.");
    LOG_DEBUG("This is a debug message.");
    LOG_INFO("This is an info message.");
    LOG_WARN("This is a warning message.");
    LOG_ERROR("This is an error message.");
    LOG_CRITICAL("This is a critical message.");
}

ImGuiManager::~ImGuiManager() { rlImGuiShutdown(); }

void ImGuiManager::ToggleWindow() {}

void ImGuiManager::ToggleLogWindow() {}

void ImGuiManager::RenderLoggerWindow()
{
    rlImGuiBegin();
    loggerWindow.renderLoggerWindow();
    rlImGuiEnd();
}
