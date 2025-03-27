#ifndef ENTITY_H
#define ENTITY_H

#include "../abilities/abilities.h"
#include "../tileMap/tileMap.h"
#include "raylib.h"
#include <cmath>
#include <memory>
#include <string>
#include <vector>

class Entity : public GameObject
{
  protected:
    float m_hitPoints = 0.0f;
    bool m_isFacingLeft = 0.0f;
    std::vector<std::shared_ptr<Ability>> &m_gameObjects;
    TileMap &m_tilemap;

  private:
    bool m_isHit = false;
    float m_hitTimer = 0.0f;
    const float m_hitEffectDuration = 0.2f;

  public:
    Entity(ObjectAttributes objectAttributes,
           float hitPoints,
           TileMap &tileMap,
           std::vector<std::shared_ptr<Ability>> &gameObjects);
    ~Entity();

    virtual void Update(float deltaTime) override;
    virtual void Draw() const override;
    void TakeDamage(int amount);

    Vector2 GetPosition() const;
    float GetHitPoint() const;
    bool GetIsFacingLeft() const;
    float GetHitEffectDuration() const;
};

#endif