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

class Entity : public GameObject
{
  protected:
    State m_state = State::IDLE;
    float m_hitPoints = 0.0f;


    std::vector<std::shared_ptr<Ability>> &m_gameObjects;
    TileMap &m_tilemap;

    float m_attackAnimationTime = 0.0f;
    bool m_isAttacking = false;
    const float ATTACK_ANIMATION_DURATION = 1.0f;
    const int ATTACK_ANIMATION_FRAMES = 6;

  private:
    bool m_isHit = false;
    float m_hitTimer = 0.0f;
    const float m_hitEffectDuration = 0.5f;


  public:
    Entity(ObjectAttributes &&objectAttributes,
           FrameAtributes &&frameAtributes,
           float hitPoints,
           TileMap &tileMap,
           std::vector<std::shared_ptr<Ability>> &gameObjects);
    ~Entity();

    virtual void Update(float deltaTime) override;
    virtual void Draw() const override;
    void TakeDamage(float amount, bool isEnemyFacilingLeft);
    [[nodiscard]] Vector2 GetPosition() const;
    [[nodiscard]] float GetHitPoint() const;
    [[nodiscard]] float GetHitEffectDuration() const;
    [[nodiscard]] bool CanMoveTo(float x, float y) const;
};

#endif