#ifndef ENEMY_H
#define ENEMY_H

#include "../entity/entity.h"

class Enemy : public Entity
{
  public:
    Enemy(TileMap &tilemap,
          ObjectAttributes objectAttributes,
          float hitPoints,
          std::vector<std::shared_ptr<Ability>> &gameObjects);

    ~Enemy() = default;

    void Update(float deltaTime) override;
    void Draw() const override;
};

#endif // ENEMY_H
