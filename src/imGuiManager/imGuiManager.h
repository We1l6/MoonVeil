#ifndef IMGUIMANAGER_H
#define IMGUIMANAGER_H

#include "rlImGui.h"
#include "imgui.h"
#include <string>

class ImGuiManager {
private:
    bool showWindow;

public:
    ImGuiManager();
    ~ImGuiManager();

    void ToggleWindow(); 
    void Render();       
};

#endif // IMGUIMANAGER_H
