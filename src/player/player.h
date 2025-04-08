#ifndef PLAYER_H
#define PLAYER_H

#include "../abilities/fireBall/fireBall.h"
#include "../entity/entity.h"
#include "../resourceManager/resourceManager.h"
#include "../tileMap/tileMap.h"
#include <vector>


class Player : public Entity
{
  public:
    Player(TileMap &&tilemap,
           ObjectAttributes &&objectAttributes,
           float hitPoints,
           std::vector<std::shared_ptr<Ability>> &gameObjects);

    virtual ~Player() = default;
    virtual void HandleInput(float deltaTime);
    void Update(float deltaTime) override;
    void Draw(const Camera2D &camera) const;
};


#endif // PLAYER_H