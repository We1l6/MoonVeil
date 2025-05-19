#include "mapSelectionScene.h"
#include "../heroSelectionScene/heroSelectionScene.h"
#include "raylib.h"
void MapSelectionScene::Render()
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

    // Draw current map
    const char *currentMap = m_availableMaps[m_currentMapIndex].c_str();
    int fontSize = 30;
    Vector2 textSize = MeasureTextEx(GetFontDefault(), currentMap, fontSize, 1);

    float textureScale = 0.5f;
    Vector2 texturePos = {(GetScreenWidth() / 2 -
                           textures[m_currentMapIndex].width * textureScale) *
                                  0.5f +
                              125,
                          (GetScreenHeight() -
                           textures[m_currentMapIndex].height * textureScale) *
                              0.3f};
    DrawTextureEx(textures[m_currentMapIndex], texturePos, 0.0f, textureScale,
                  WHITE);

    DrawText(currentMap, GetScreenWidth() / 2 - textSize.x / 2,
             GetScreenHeight() / 2 - 50, fontSize, WHITE);
}

void MapSelectionScene::Update(float deltaTime)
{
    for (size_t i = 0; i < m_buttons.size(); i++)
    {
        m_buttons[i].Update();

        if (m_buttons[i].IsClicked())
        {
            if (i == 0)
            {
                m_currentMapIndex--;
                if (m_currentMapIndex < 0)
                    m_currentMapIndex = m_availableMaps.size() - 1;
            }
            else if (i == 1)
            {
                m_currentMapIndex++;
                if (m_currentMapIndex >= m_availableMaps.size())
                    m_currentMapIndex = 0;
            }
            else if (i == 2)
            {
                m_game->ChangeScene(
                    new HeroSelectionScene(m_game, m_currentMapIndex));
            }
            else if (i == 3)
            {
                m_game->ChangeScene(new MenuScene(m_game));
            }
        }
    }
}