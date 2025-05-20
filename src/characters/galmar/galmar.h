#ifndef GALMAR_H
#define GALMAR_H


#include "../../player/player.h"
#include <iostream>
#include <memory>
#include <string_view>
#include <vector>

#include "../../abilities/fireBall/fireBall.h"
#include "../../abilities/poisonousGas/poisonousGas.h"

#include <iterator>


namespace GalmarConstants
{
constexpr float INITIAL_POSITION_X = 155.0f;
constexpr float INITIAL_POSITION_Y = 155.0f;
constexpr std::string_view TEXTURE_Galmar_PATH = "resources/Galmar.png";
constexpr std::string_view TEXTURE_Galmar_RUN_PATH = "resources/RunSprite.png";
constexpr int Galmar_WIDTH = 80;
constexpr int Galmar_HEIGHT = 128;
constexpr int Galmar_SPAWN_X = 600;
constexpr int Galmar_SPAWN_Y = 200;
constexpr int COLLIDER_OFFSET_X = 10;
constexpr int COLLIDER_OFFSET_Y = 10;
constexpr int INITIAL_HEALTH = 100;
} // namespace GalmarConstants


class Galmar final : public Player
{
  private:
    void firstSpell() override;
    void secondSpell() override;
    void thirdSpell() override;
    void FireballAction();
    void DashAction();
    void levelUp() override;
    float m_fireBallDamage = 30;

  public:
    Galmar(std::shared_ptr<TileMap> &tilemap,
           std::vector<std::shared_ptr<Ability>> &gameObjects);
    ~Galmar() = default;


  private:
};


#endif // GALMAR_H