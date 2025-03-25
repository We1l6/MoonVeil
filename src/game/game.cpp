#include "game.h"
#include "raylib.h"

Game::Game()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(GetScreenWidth(), GetScreenHeight(), "MoonVeil");
    SetTargetFPS(120);
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
        float deltaTime = GetFrameTime();
        currentScene->HandleInput(deltaTime);
        currentScene->Update(deltaTime);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        currentScene->Render();
        // DrawFPS(10, 10, BLACK);
        EndDrawing();
    }
}

void Game::ChangeScene(Scene *newScene)
{
    delete currentScene;
    currentScene = newScene;
}
