#include "hud.h"


namespace HUDConstants
{
constexpr int HITPOINT_BAR_WIDTH = 200;
constexpr int HITPOINT_BAR_HEIGHT = 40;
constexpr int HITPOINT_X = 20;
constexpr int HITPOINT_Y = 20;
} // namespace HUDConstants


void HUD::Draw(const std::shared_ptr<Player> &player)
{
    const float hpPercent = player->GetHitPoint() / 100.0f;
    int currentWidth =
        static_cast<int>(HUDConstants::HITPOINT_BAR_WIDTH * hpPercent);

    DrawRectangle(HUDConstants::HITPOINT_X, HUDConstants::HITPOINT_Y,
                  HUDConstants::HITPOINT_BAR_WIDTH,
                  HUDConstants::HITPOINT_BAR_HEIGHT, GRAY);
    DrawRectangle(HUDConstants::HITPOINT_X, HUDConstants::HITPOINT_Y,
                  currentWidth, HUDConstants::HITPOINT_BAR_HEIGHT, RED);
    DrawRectangleLines(HUDConstants::HITPOINT_X, HUDConstants::HITPOINT_Y,
                       HUDConstants::HITPOINT_BAR_WIDTH,
                       HUDConstants::HITPOINT_BAR_HEIGHT, BLACK);

    DrawText(TextFormat("HP: %.1f / 100", player->GetHitPoint()),
             HUDConstants::HITPOINT_X + 5, HUDConstants::HITPOINT_Y + 2, 16,
             WHITE);

    DrawTexture(ResourceManager::GetTexture("resources/HPBAR2.png"),
                HUDConstants::HITPOINT_X, HUDConstants::HITPOINT_Y - 54, WHITE);
}