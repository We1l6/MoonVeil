#include "game.h"
#include "raylib.h"
#include <string_view>


namespace GameConstants
{
constexpr int TARGET_FPS = 120;
constexpr std::string_view WINDOW_TITLE = "MoonVeil";
} // namespace GameConstants


Game::Game() : currentScene(nullptr)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(GetScreenWidth(), GetScreenHeight(),
               std::data(GameConstants::WINDOW_TITLE));
    SetTargetFPS(GameConstants::TARGET_FPS);
    currentScene = new MenuScene(this);
}


Game::~Game()
{
    delete currentScene;
    CloseWindow();
    // glfwTerminate();
}


void Game::Run() const
{
    while (!WindowShouldClose())
    {
        const float deltaTime = GetFrameTime();
        currentScene->HandleInput(deltaTime);
        currentScene->Update(deltaTime);
        BeginDrawing();
        ClearBackground(BLACK);
        currentScene->Render();
        EndDrawing();
    }
}


void Game::ChangeScene(Scene *newScene)
{
    delete currentScene;
    currentScene = newScene;
}
