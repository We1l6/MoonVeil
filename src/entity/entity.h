#ifndef ENTITY_H
#define ENTITY_H

#include "../abilities/abilities.h"
#include "../tileMap/tileMap.h"
#include "raylib.h"
#include <cmath>
#include <memory>
#include <string>
#include <vector>


enum class State
{
    IDLE,
    RUNNING,
    ATTACKING,
    TAKING_DAMAGE
};

struct HitData
{
    bool isHit = false;
    float hitTimer = 0.0f;
    const float hitEffectDuration = 0.5f;
};


class Entity : public GameObject
{
  protected:
    State m_state = State::IDLE;
    float m_hitPoints = 0.0f;


    std::vector<std::shared_ptr<Ability>> &m_gameObjects;
    std::shared_ptr<TileMap> &m_tilemap;
    HitData hitData;
    float m_attackAnimationTime = 0.0f;
    bool m_isAttacking = false;
    const float ATTACK_ANIMATION_DURATION = 1.0f;
    const int ATTACK_ANIMATION_FRAMES = 6;

  private:
    float m_attackDamage;

  public:
    Entity(ObjectAttributes &&objectAttributes,
           FrameAtributes &&frameAtributes,
           float hitPoints,
           std::shared_ptr<TileMap> &tileMap,
           std::vector<std::shared_ptr<Ability>> &gameObjects,
           float attackDamage);
    ~Entity();
    float GetAttackDamage() const { return m_attackDamage; }
    virtual void Update(float deltaTime) override;
    virtual void Draw() const override;
    virtual void TakeDamage(float amount, bool isEnemyFacilingLeft);
    [[nodiscard]] Vector2 GetPosition() const;
    [[nodiscard]] float GetHitPoint() const;
    [[nodiscard]] float GetHitEffectDuration() const;
    [[nodiscard]] bool CanMoveTo(float x, float y) const;
};

#endif