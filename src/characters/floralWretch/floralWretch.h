#ifndef FLORALWRETCH_H
#define FLORALWRETCH_H


#include "../../enemy/enemy.h"
#include "../../tileMap/tileMap.h"

namespace FloralWretchConstants
{
constexpr std::string_view TEXTURE_RUN_PATH = "resources/FloralWretchRUN.png";
constexpr float WIDTH = 80;
constexpr float HEIGHT = 128;
constexpr float INITIAL_HEALTH = 100;
} // namespace FloralWretchConstants


class FloralWretch final : public Enemy
{
  public:
    FloralWretch(TileMap &tilemap,
                 Vector2 position,
                 std::vector<std::shared_ptr<Ability>> &gameObjects,
                 std::shared_ptr<Player> &player);
    ~FloralWretch() = default;
};


#endif // FLORALWRETCH_H