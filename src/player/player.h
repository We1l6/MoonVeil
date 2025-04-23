#ifndef PLAYER_H
#define PLAYER_H

#include "../entity/entity.h"
#include "../resourceManager/resourceManager.h"
#include "../tileMap/tileMap.h"
#include <vector>


#include "../abilities/defaultAttack/defaultAttack.h"
class Player : public Entity
{
    float m_attackCooldown = 0.0f;
    const float ATTACK_COOLDOWN_TIME = 0.5f;
    void Attack();
    int m_currentAttackFrame = 0;
    bool m_isAttackAnimationPlaying = false;

  public:
    Player(TileMap &tilemap,
           ObjectAttributes &&objectAttributes,
           FrameAtributes &&frameAtributes,
           float hitPoints,
           std::vector<std::shared_ptr<Ability>> &gameObjects);

    virtual ~Player() = default;
    virtual void HandleInput(float deltaTime);
    void Update(float deltaTime) override;
    void Draw(const Camera2D &camera) const;
};


#endif // PLAYER_H