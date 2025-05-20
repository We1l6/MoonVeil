#include "deathScene.h"
#include "../gameScene/gameScene.h"
void DeathScene::HandleInput(float deltaTime) {}


void DeathScene::Render()
{
    float scale = fmaxf((float)GetScreenWidth() / m_backgroundTexture.width,
                        (float)GetScreenHeight() / m_backgroundTexture.height);

    Vector2 pos = {
        (GetScreenWidth() - (m_backgroundTexture.width * scale)) * 0.5f,
        (GetScreenHeight() - (m_backgroundTexture.height * scale)) * 0.5f};

    DrawTextureEx(m_backgroundTexture, pos, 0.0f, scale, WHITE);
    for (const auto &button : m_buttons)
    {
        button.Draw();
    }
}
void DeathScene::Update(float deltaTime)
{
    for (size_t i = 0; i < m_buttons.size(); i++)
    {
        m_buttons[i].Update();

        if (m_buttons[i].IsClicked())
        {
            if (i == 0)
            {
                m_game->ChangeScene(
                    new GameScene(m_game, m_mapIndex, m_heroIndex));
            }

            else if (i == 1)
            {
                m_game->ChangeScene(new MenuScene(m_game));
            }
        }
    }
}