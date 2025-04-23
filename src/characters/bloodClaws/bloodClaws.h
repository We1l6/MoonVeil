#ifndef BLOODCLAWS_H
#define BLOODCLAWS_H


#include "../../enemy/enemy.h"
#include "../../tileMap/tileMap.h"

namespace BloodClawsConstants
{
constexpr float INITIAL_POSITION_X = 155.0f;
constexpr float INITIAL_POSITION_Y = 155.0f;
constexpr std::string_view TEXTURE_PATH = "resources/David.png";
constexpr std::string_view TEXTURE_RUN_PATH = "resources/RunSprite.png";
constexpr int DAVID_WIDTH = 80;
constexpr int DAVID_HEIGHT = 128;
constexpr int DAVID_SPAWN_X = 600;
constexpr int DAVID_SPAWN_Y = 200;
constexpr int COLLIDER_OFFSET_X = 10;
constexpr int COLLIDER_OFFSET_Y = 10;
constexpr int INITIAL_HEALTH = 100;
} // namespace BloodClawsConstants


class BloodClaws final : public Enemy
{
  public:
    BloodClaws(TileMap &tilemap,
               Vector2 position,
               std::vector<std::shared_ptr<Ability>> &gameObjects,
               std::shared_ptr<Player> &player);
    ~BloodClaws() = default;
};


#endif // BLOODCLAWS_H