#include "hud.h"
#include "raylib.h"


namespace HUDConstants
{
constexpr int HITPOINT_BAR_WIDTH = 520;
constexpr int HITPOINT_BAR_HEIGHT = 30;
constexpr int HITPOINT_X = 205;
constexpr int HITPOINT_Y = 24;
} // namespace HUDConstants


void HUD::Draw(const std::shared_ptr<Player> &player)
{
    const float hpPercent = player->GetHitPoint() / 100.0f;
    int currentRedWidth =
        static_cast<int>(HUDConstants::HITPOINT_BAR_WIDTH * hpPercent);
    int currentYellowWidth = player->m_levelBarWidth;
    int currentGreenWidth = 126 * player->m_remainingAbilitiesByArea;

    DrawRectangle(HUDConstants::HITPOINT_X, HUDConstants::HITPOINT_Y,
                  currentRedWidth, HUDConstants::HITPOINT_BAR_HEIGHT, RED);
    DrawRectangle(280, 127, currentYellowWidth, 28, YELLOW);

    std::string levelText = "Level: " + std::to_string(player->m_level);
    DrawText(levelText.c_str(), 310, 129, 20, GRAY);

    DrawRectangle(295, 74, currentGreenWidth, 15, GREEN);


    DrawTexture(ResourceManager::GetTexture("resources/HPDAR3.png"), 20, -32,
                WHITE);
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    Texture2D texture = player->m_spellsTexture;
    int spellY = screenHeight - 128;

    DrawTexture(texture, screenWidth / 2 - 192, spellY, WHITE);

    int spellX = screenWidth / 2 - 192;

    DrawSpellCooldown(player->getFirstSpellСurrCooldown(), spellX, spellY,
                      texture);

    spellX = screenWidth / 2 - 320;

    DrawSpellCooldown(player->getSecondSpellСurrCooldown(), spellX, spellY,
                      texture);
    spellX = screenWidth / 2 - 64;
    DrawSpellCooldown(player->getThirdSpellСurrCooldown(), spellX, spellY,
                      texture);
}

void HUD::DrawSpellCooldown(float cooldown,
                            int spellX,
                            int spellY,
                            Texture2D texture)
{
    const char *cooldownText = TextFormat("%.1f", cooldown);
    int textWidth = MeasureText(cooldownText, 20);
    int textX = spellX + (texture.width - textWidth) / 2;
    int textY = spellY + (texture.height - 20) / 2;
    DrawText(cooldownText, textX, textY, 20, WHITE);
}