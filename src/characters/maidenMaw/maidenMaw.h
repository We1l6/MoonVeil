#ifndef MAIDENMAW_H
#define MAIDENMAW_H


#include "../../enemy/enemy.h"
#include "../../tileMap/tileMap.h"

namespace MaidenMawConstants
{
constexpr std::string_view TEXTURE_RUN_PATH = "resources/MaidenMawRUN.png";
constexpr float WIDTH = 80;
constexpr float HEIGHT = 128;
constexpr float INITIAL_HEALTH = 100;
} // namespace MaidenMawConstants


class MaidenMaw final : public Enemy
{
  public:
    MaidenMaw(std::shared_ptr<TileMap> &tilemap,
              Vector2 position,
              std::vector<std::shared_ptr<Ability>> &gameObjects,
              std::shared_ptr<Player> &player,
              float attackDamage,
              float initialHealth);
    ~MaidenMaw() = default;
};


#endif // MAIDENMAW_H