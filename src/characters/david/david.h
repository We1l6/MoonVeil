#ifndef DAVID_H
#define DAVID_H


#include "../../player/player.h"
#include <iostream>
#include <memory>
#include <string_view>
#include <vector>

#include "../../abilities/fireBall/fireBall.h"
#include "../../abilities/poisonousGas/poisonousGas.h"

#include <iterator>

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
    void firstSpell() override;
    void secondSpell() override;
    void thirdSpell() override;
    void FireballAction();
    void DashAction();

    void levelUp() override;

  public:
    David(std::shared_ptr<TileMap> &tilemap,
          std::vector<std::shared_ptr<Ability>> &gameObjects);
    ~David() = default;


  private:
};


#endif // DAVID_H