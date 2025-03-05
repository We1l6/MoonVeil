#include "game.h"

Game::Game() {
    InitWindow(800, 600, "Raylib Game");
    currentScene = new MenuScene(this);
}

Game::~Game() {
    delete currentScene;
    CloseWindow();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        currentScene->HandleInput();
        currentScene->Update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        currentScene->Render();
        EndDrawing();
    }
}

void Game::ChangeScene(Scene* newScene) {
    delete currentScene;
    currentScene = newScene;
}
