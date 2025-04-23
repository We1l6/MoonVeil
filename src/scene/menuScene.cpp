#include "menuScene.h"
#include "raylib.h"


void MenuScene::HandleInput(float deltaTime)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        m_game->ChangeScene(new GameScene(m_game));
    }
}


void MenuScene::Render()
{
    DrawText("Start", 200, 250, 20, WHITE);
    DrawText("Settings", 200, 270, 20, WHITE);
    DrawText("Exit", 200, 290, 20, WHITE);
}


void MenuScene::Update(float deltaTime) {}