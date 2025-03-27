#include "game.h"
#include "raylib.h"


namespace GameConstants
{
constexpr int TARGET_FPS = 120;
constexpr char WINDOW_TITLE[] = "MoonVeil";
} // namespace GameConstants


Game::Game()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(GetScreenWidth(), GetScreenHeight(),
               GameConstants::WINDOW_TITLE);
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
        ClearBackground(RAYWHITE);
        currentScene->Render();
        EndDrawing();
    }
}


void Game::ChangeScene(Scene *newScene)
{
    delete currentScene;
    currentScene = newScene;
}
