#include "imGuiManager.h"

ImGuiManager::ImGuiManager() {
    rlImGuiSetup(true); 
    showWindow = true;  
}

ImGuiManager::~ImGuiManager() {
    rlImGuiShutdown(); 
}

void ImGuiManager::ToggleWindow() {
    showWindow = !showWindow;
}

void ImGuiManager::Render() {
    rlImGuiBegin();

    if (showWindow) {
        ImGui::ShowDemoWindow();
        ImGui::Begin("Hello, ImGui!");

        if (ImGui::Button("Click Me")) {
            TraceLog(LOG_INFO, "Button clicked!");
        }

        if (ImGui::Button("Save")) {
            TraceLog(LOG_INFO, "Save button clicked!");
        }

        static char buf[256] = "";
        ImGui::InputText("string", buf, IM_ARRAYSIZE(buf));

        static float f = 0.5f;
        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

        ImGui::End();
    }

    rlImGuiEnd();
}
