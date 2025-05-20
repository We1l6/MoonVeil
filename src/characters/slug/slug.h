#ifndef SLUG_H
#define SLUG_H


#include "../../enemy/enemy.h"
#include "../../tileMap/tileMap.h"

namespace SlugConstants
{
constexpr std::string_view TEXTURE_RUN_PATH = "resources/SlugRUN.png";
constexpr float WIDTH = 80;
constexpr float HEIGHT = 128;
constexpr float INITIAL_HEALTH = 100;
} // namespace SlugConstants


class Slug final : public Enemy
{
  private:
    void useAbilityOnDeath() override;

  public:
    Slug(std::shared_ptr<TileMap> &tilemap,
         Vector2 position,
         std::vector<std::shared_ptr<Ability>> &gameObjects,
         std::shared_ptr<Player> &player,
         float attackDamage,
         float initialHealth);
    ~Slug() = default;
};


#endif // SLUG_H