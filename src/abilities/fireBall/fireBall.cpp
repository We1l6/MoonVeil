#include "fireBall.h"

FireBall::FireBall(Vector2 position, Vector2 velocity)
    : Ability(
        {"FireBall", 1, 10, 0.0, true}, 
        { {155.0f, 155.0f}, ResourceManager::GetTexture("resources/David.png"), {0, 0, 10, 10} } // objectAttributes напрямую
      )
{
    m_objectAttributes.hitbox.x = position.x;
    m_objectAttributes.hitbox.y = position.y;
    m_objectAttributes.velocity = velocity;
}

    
void FireBall::Update(float deltaTime) {
    if (!m_abilityAttribute.isActive) return;
    m_objectAttributes.hitbox.x += m_objectAttributes.velocity.x * deltaTime;
    m_objectAttributes.hitbox.y += m_objectAttributes.velocity.y * deltaTime;
}
    
void FireBall::Draw() const {
    if (!m_abilityAttribute.isActive) return;
    Vector2 vec;
    vec.x = m_objectAttributes.hitbox.x;
    vec.y = m_objectAttributes.hitbox.y;
    DrawCircleV(vec, 20, RED); 
}
    
bool FireBall::IsActive() const { return m_abilityAttribute.isActive; }
void FireBall::Deactivate() { m_abilityAttribute.isActive = false; }
