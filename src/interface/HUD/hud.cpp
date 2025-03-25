#include "hud.h"

void HUD::Draw(const std::shared_ptr<Player>& player) {
    int barWidth = 200;
    int barHeight = 40;
    int x = 20, y = 20;

    float hpPercent = player->GetHitPoint() / 100.0f;
    int currentWidth = static_cast<int>(barWidth * hpPercent);

    DrawRectangle(x, y, barWidth, barHeight, GRAY);
    DrawRectangle(x, y, currentWidth, barHeight, RED);
    DrawRectangleLines(x, y, barWidth, barHeight, BLACK);

    DrawText(TextFormat("HP: %.1f / 100", player->GetHitPoint()), x + 5, y + 2, 16, WHITE);
}