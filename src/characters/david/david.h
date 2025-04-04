#ifndef DAVID_H
#define DAVID_H


#include "../../player/player.h"
#include <iostream> // temp
#include <memory>
#include <string_view>
#include <vector>


class David final : public Player
{
  private:
    constexpr static float INITIAL_POSITION_X = 155.0f;
    constexpr static float INITIAL_POSITION_Y = 155.0f;
    constexpr static std::string_view TEXTURE_DAVID_PATH =
        "resources/David.png"; //!!!!!
    constexpr static std::string_view TEXTURE_DAVID_RUN_PATH =
        "resources/RunSprite.png";
    constexpr static int DAVID_WIDTH = 80;
    constexpr static int DAVID_HEIGHT = 128;
    constexpr static int DAVID_SPAWN_X = 600;
    constexpr static int DAVID_SPAWN_Y = 200;
    constexpr static int COLLIDER_OFFSET_X = 10;
    constexpr static int COLLIDER_OFFSET_Y = 10;
    constexpr static int INITIAL_HEALTH = 100;

  public:
    David(TileMap &tilemap, std::vector<std::shared_ptr<Ability>> &gameObjects);
    ~David() = default;
    void HandleInput(float deltaTime) override;

  private:
};


#endif // DAVID_H