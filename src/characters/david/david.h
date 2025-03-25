#ifndef DAVID_H
#define DAVID_H

#include "../../player/player.h"
#include <iostream> // temp
#include <memory>
#include <vector>

class David : public Player
{
  public:
    David(TileMap &tilemap, std::vector<std::shared_ptr<Ability>> &gameObjects);
    virtual ~David() = default;
    ;
    void HandleInput(float deltaTime) override;

  private:
};

#endif