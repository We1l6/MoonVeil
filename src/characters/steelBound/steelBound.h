#ifndef STEELBOUND_H
#define STEELBOUND_H


#include "../../enemy/enemy.h"
#include "../../tileMap/tileMap.h"

namespace SteelBoundConstants
{
constexpr std::string_view TEXTURE_RUN_PATH = "resources/SteelBoundRUN.png";
constexpr float WIDTH = 80;
constexpr float HEIGHT = 128;
constexpr float INITIAL_HEALTH = 100;
} // namespace SteelBoundConstants


class SteelBound final : public Enemy
{
  public:
    SteelBound(TileMap &tilemap,
               Vector2 position,
               std::vector<std::shared_ptr<Ability>> &gameObjects,
               std::shared_ptr<Player> &player);
    ~SteelBound() = default;
};


#endif // STEELBOUND_H