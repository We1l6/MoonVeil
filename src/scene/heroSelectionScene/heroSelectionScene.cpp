#include "heroSelectionScene.h"


void HeroSelectionScene::Render()
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

    float scaler = 3.0f;
    DrawTextureEx(heroSelections[m_currentHeroIndex].texturePath,
                  (Vector2){80, 80}, 0.0f, scaler, WHITE);

    DrawTexture(heroSelections[m_currentHeroIndex].abilityPath, 80,
                128 * scaler + 100, WHITE);

    DrawText(heroSelections[m_currentHeroIndex].lore, 128 * scaler + 100, 80,
             16, WHITE);
    DrawText(heroSelections[m_currentHeroIndex].abilities, 80,
             128 * scaler + 250, 16, WHITE);
}


void HeroSelectionScene::Update(float deltaTime)
{
    for (size_t i = 0; i < m_buttons.size(); i++)
    {
        m_buttons[i].Update();

        if (m_buttons[i].IsClicked())
        {
            if (i == 0)
            {
                m_currentHeroIndex--;
                if (m_currentHeroIndex < 0)
                    m_currentHeroIndex = m_availableMaps.size() - 1;
            }
            else if (i == 1)
            {
                m_currentHeroIndex++;
                if (m_currentHeroIndex >= m_availableMaps.size())
                    m_currentHeroIndex = 0;
            }
            else if (i == 2)
            {
                m_game->ChangeScene(
                    new GameScene(m_game, m_mapIndex, m_currentHeroIndex));
            }
            else if (i == 3)
            {
                m_game->ChangeScene(new MapSelectionScene(m_game));
            }
        }
    }
}