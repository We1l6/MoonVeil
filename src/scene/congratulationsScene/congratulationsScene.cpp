#include "congratulationsScene.h"
#include "../gameScene/gameScene.h"
void CongratulationsScene::HandleInput(float deltaTime) {}


void CongratulationsScene::Render()
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
    const char *text = "CONGRATULATIONS";
    int fontSize = 60;      // Размер шрифта
    Color textColor = GOLD; // Цвет текста (можно изменить)

    // Получаем размер текста
    Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, 2);

    // Вычисляем позицию для центрирования
    Vector2 textPos = {
        (GetScreenWidth() - textSize.x) * 0.5f,
        (GetScreenHeight() * 0.33f) - textSize.y * 0.5f // 1/3 высоты экрана
    };

    DrawTextEx(GetFontDefault(), text, textPos, fontSize, 2,
               textColor); // Основной текст
}
void CongratulationsScene::Update(float deltaTime)
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