#include "fireBall.h"

FireBall::FireBall(Vector2 position, Vector2 velocity)
    : Ability(AbilityAttribute{.name = "FireBall",
                               .cooldown = FireBallConstants::COOLDOWN,
                               .damage = FireBallConstants::DAMAGE,
                               .currentCooldown = 0.0,
                               .isActive = true},
              ObjectAttributes{
                  .velocity = {FireBallConstants::VELOCITY_X,
                               FireBallConstants::VELOCITY_Y},
                  .texture = ResourceManager::GetTexture("resources/David.png"),
                  .hitbox = {FireBallConstants::POSITION_X,
                             FireBallConstants::POSITION_Y,
                             FireBallConstants::HITBOX_WIDTH,
                             FireBallConstants::HITBOX_HEIGHT}})
{
    m_objectAttributes.hitbox.x = position.x;
    m_objectAttributes.hitbox.y = position.y;
    m_objectAttributes.velocity = velocity;
}


void FireBall::Update(float deltaTime)
{
    if (!m_abilityAttribute.isActive)
        return;
    m_objectAttributes.hitbox.x += m_objectAttributes.velocity.x * deltaTime;
    m_objectAttributes.hitbox.y += m_objectAttributes.velocity.y * deltaTime;
}


void FireBall::Draw() const
{
    if (!m_abilityAttribute.isActive)
        return;
    Vector2 vec;
    vec.x = m_objectAttributes.hitbox.x;
    vec.y = m_objectAttributes.hitbox.y;

    DrawCircleV(vec, FireBallConstants::RADIUS, RED);
}


bool FireBall::IsActive() const { return m_abilityAttribute.isActive; }


void FireBall::Deactivate() { m_abilityAttribute.isActive = false; }
