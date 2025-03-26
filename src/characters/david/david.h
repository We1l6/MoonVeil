#ifndef DAVID_H
#define DAVID_H


#include "../../player/player.h"
#include <iostream> // temp
#include <memory>
#include <vector>


namespace DavidConstants
{
constexpr float INITIAL_POSITION_X = 155.0f;
constexpr float INITIAL_POSITION_Y = 155.0f;
constexpr char TEXTURE_PATH[] = "resources/David.png";
constexpr int COLLIDER_WIDTH = 600;
constexpr int COLLIDER_HEIGHT = 700;
constexpr int COLLIDER_OFFSET_X = 10;
constexpr int COLLIDER_OFFSET_Y = 10;
constexpr int INITIAL_HEALTH = 100;
} // namespace DavidConstants


class David : public Player
{
  public:
    David(TileMap &tilemap, std::vector<std::shared_ptr<Ability>> &gameObjects);
    virtual ~David() = default;
    void HandleInput(float deltaTime) override;

  private:
};


#endif // DAVID_H