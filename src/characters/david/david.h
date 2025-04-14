#ifndef DAVID_H
#define DAVID_H


#include "../../player/player.h"
#include <iostream> // temp
#include <memory>
#include <string_view>
#include <vector>


enum class AbilitySlot
{
    Primary,
    Secondary,
    Tertiary,
    Quaternary,
    Count
};

namespace DavidConstants
{
constexpr float INITIAL_POSITION_X = 155.0f;
constexpr float INITIAL_POSITION_Y = 155.0f;
constexpr std::string_view TEXTURE_DAVID_PATH = "resources/David.png";
constexpr std::string_view TEXTURE_DAVID_RUN_PATH = "resources/RunSprite.png";
constexpr int DAVID_WIDTH = 80;
constexpr int DAVID_HEIGHT = 128;
constexpr int DAVID_SPAWN_X = 600;
constexpr int DAVID_SPAWN_Y = 200;
constexpr int COLLIDER_OFFSET_X = 10;
constexpr int COLLIDER_OFFSET_Y = 10;
constexpr int INITIAL_HEALTH = 100;
} // namespace DavidConstants


class David final : public Player
{
  private:
  public:
    David(TileMap &tilemap, std::vector<std::shared_ptr<Ability>> &gameObjects);
    ~David() = default;
    void HandleInput(float deltaTime) override;

  private:
};


#endif // DAVID_H