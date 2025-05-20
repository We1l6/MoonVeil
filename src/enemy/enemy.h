#ifndef ENEMY_H
#define ENEMY_H

#include "../entity/entity.h"
#include "../player/player.h"
#include <memory>


class Enemy : public Entity
{
  private:
    virtual void useAbilityOnDeath();

  protected:
    std::shared_ptr<Player> &m_player;
    Spell m_firstSpell;
    virtual void firstSpell() {}

  public:
    Enemy(std::shared_ptr<TileMap> &tilemap,
          ObjectAttributes &&objectAttributes,
          FrameAtributes &&frameAtributes,
          float hitPoints,
          std::vector<std::shared_ptr<Ability>> &gameObjects,
          std::shared_ptr<Player> &player,
          float attackDamage);
    ~Enemy() = default;
    void TakeDamage(float amount, bool isEnemyFacilingLeft) override;
    void Update(float deltaTime);
    void Draw() const override;
};

#endif // ENEMY_H
