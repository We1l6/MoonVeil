#include "deathScene.h"

void DeathScene::HandleInput(float deltaTime) {}


void DeathScene::Render()
{
    {
        float scale =
            fmaxf((float)GetScreenWidth() / m_backgroundTexture.width,
                  (float)GetScreenHeight() / m_backgroundTexture.height);

        Vector2 pos = {
            (GetScreenWidth() - (m_backgroundTexture.width * scale)) * 0.5f,
            (GetScreenHeight() - (m_backgroundTexture.height * scale)) * 0.5f};

        DrawTextureEx(m_backgroundTexture, pos, 0.0f, scale, WHITE);
    }
}
void DeathScene::Update(float deltaTime) {}