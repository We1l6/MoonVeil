#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#include <string>
#include <math.h>
#include "../abilities/abilities.h"
#include <vector>
#include <memory>
#include "../tileMap/tileMap.h"

class Entity: public GameObject {

protected:
    float m_hitPoints;
    bool m_isFacingLeft;
    TileMap& m_tilemap;
    
    bool m_isHit = false;  
    float m_hitTimer = 0.0f;  
    const float m_hitEffectDuration = 0.2f; 
    std::vector<std::shared_ptr<Ability>>& m_gameObjects; 

public:
    Entity(ObjectAttributes objectAttributes, float hitPoints, TileMap& tileMap, std::vector<std::shared_ptr<Ability>>& gameObjects);
    ~Entity();
    virtual void Update(float deltaTime) override;
    virtual void Draw() const override;
    void TakeDamage(int amount);
    Vector2 GetPosition() const;
    float GetHitPoint() const;
};

#endif