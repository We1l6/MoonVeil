#include "raylib.h"
#include "imGuiManager/imGuiManager.h"

int main() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Test");
    SetTargetFPS(60);

    ImGuiManager imguiManager;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_P)) {
            imguiManager.ToggleWindow();
        }
        if (IsKeyPressed(KEY_F)) {
            ToggleFullscreen();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Press P to toggle window", 0, 0, 20, DARKGRAY);
        imguiManager.Render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
