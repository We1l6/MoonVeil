#ifndef ENEMY_H
#define ENEMY_H

#include "../entity/entity.h"
#include "../player/player.h"
#include <memory>


class Enemy : public Entity
{
  private:
    std::shared_ptr<Player> &m_player;

  public:
    Enemy(TileMap &tilemap,
          ObjectAttributes &&objectAttributes,
          FrameAtributes &&frameAtributes,
          float hitPoints,
          std::vector<std::shared_ptr<Ability>> &gameObjects,
          std::shared_ptr<Player> &player);

    ~Enemy() = default;
    void TakeDamage(float amount, bool isEnemyFacilingLeft) override;
    void Update(float deltaTime);
    void Draw() const override;
};

#endif // ENEMY_H
