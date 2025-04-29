#include "menuScene.h"
#include "raylib.h"


void MenuScene::HandleInput(float deltaTime)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        m_game->ChangeScene(new GameScene(m_game));
    }
    if (m_buttons[0].IsClicked())
    {
        m_game->ChangeScene(new GameScene(m_game));
    }
    else if (m_buttons[2].IsClicked())
    {
        CloseWindow();
    }
}


void MenuScene::Render()
{
    DrawTexture(LoadTexture("resources/Menu.png"), 0, 0, WHITE);

    for (const auto &button : m_buttons)
    {
        button.Draw();
    }
}


void MenuScene::Update(float deltaTime)
{
    for (auto &button : m_buttons)
    {
        button.Update();
    }
}