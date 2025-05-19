#ifndef BLOODCLAWS_H
#define BLOODCLAWS_H


#include "../../enemy/enemy.h"
#include "../../tileMap/tileMap.h"
#include <memory>

namespace BloodClawsConstants
{
constexpr std::string_view TEXTURE_RUN_PATH = "resources/BloodclawsRUN.png";
constexpr float WIDTH = 80;
constexpr float HEIGHT = 128;
constexpr float INITIAL_HEALTH = 100;
} // namespace BloodClawsConstants


class BloodClaws final : public Enemy
{
  public:
    BloodClaws(std::shared_ptr<TileMap> &tilemap,
               Vector2 position,
               std::vector<std::shared_ptr<Ability>> &gameObjects,
               std::shared_ptr<Player> &player);
    ~BloodClaws() = default;
};


#endif // BLOODCLAWS_H