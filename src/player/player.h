#ifndef PLAYER_H
#define PLAYER_H

#include "../entity/entity.h"

#include "../tileMap/tileMap.h"

#include "../abilities/fireBall/fireBall.h"
#include "../resourceManager/resourceManager.h"
#include <vector>

class Player : public Entity
{
  protected:
  public:
    Player(TileMap &tilemap,
           ObjectAttributes objectAttributes,
           float hitPoints,
           std::vector<std::shared_ptr<Ability>> &gameObjects);
    virtual ~Player() = default;
    virtual void HandleInput(float deltaTime);
    void Update(float deltaTime) override;
    void Draw() const override;
};
#endif // PLAYER_H