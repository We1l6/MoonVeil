#include "game.h"


namespace GameConstants
{
constexpr int TARGET_FPS = 60;
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
}


void Game::Run()
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
