#ifndef EYEGORE_H
#define EYEGORE_H


#include "../../enemy/enemy.h"
#include "../../tileMap/tileMap.h"

namespace EyeGoreConstants
{
constexpr std::string_view TEXTURE_RUN_PATH = "resources/EyeGoreRUN.png";
constexpr float WIDTH = 80;
constexpr float HEIGHT = 128;
constexpr float INITIAL_HEALTH = 100;
} // namespace EyeGoreConstants


class EyeGore final : public Enemy
{
  public:
    EyeGore(TileMap &tilemap,
            Vector2 position,
            std::vector<std::shared_ptr<Ability>> &gameObjects,
            std::shared_ptr<Player> &player);
    ~EyeGore() = default;
};


#endif // EYEGORE_H