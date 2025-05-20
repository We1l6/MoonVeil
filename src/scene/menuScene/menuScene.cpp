#include "menuScene.h"


void MenuScene::HandleInput(float deltaTime)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        m_game->ChangeScene(new MapSelectionScene(m_game));
    }
    if (m_buttons[0].IsClicked())
    {
        m_game->ChangeScene(new MapSelectionScene(m_game));
    }
    if (m_buttons[1].IsClicked())
    {
        m_game->ChangeScene(new SettingsScene(m_game));
    }
    else if (m_buttons[2].IsClicked())
    {
        CloseWindow();
    }
}


void MenuScene::Render()
{
    float scale = fmaxf((float)GetScreenWidth() / m_bgTexture.width,
                        (float)GetScreenHeight() / m_bgTexture.height);

    Vector2 pos = {(GetScreenWidth() - (m_bgTexture.width * scale)) * 0.5f,
                   (GetScreenHeight() - (m_bgTexture.height * scale)) * 0.5f};

    DrawTexture(m_bgTexture, pos.x, pos.y, WHITE);

    for (const auto &button : m_buttons)
    {
        button.Draw();
    }
}


void MenuScene::Update(float deltaTime)
{
    UpdateMusicStream(music);
    for (auto &button : m_buttons)
    {
        button.Update();
    }
}