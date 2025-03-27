#include "fireBall.h"

FireBall::FireBall(Vector2 position, Vector2 velocity)
    : Ability(AbilityAttribute{.name = "FireBall",
                               .cooldown = FireBallConstants::COOLDOWN,
                               .damage = FireBallConstants::DAMAGE,
                               .currentCooldown = 0.0,
                               .isActive = true},
              ObjectAttributes{.velocity = {FireBallConstants::VELOCITY_X,
                                            FireBallConstants::VELOCITY_Y},
                               .texture = ResourceManager::GetTexture(
                                   "resources/greenFireBall.png"),
                               .hitbox = {FireBallConstants::POSITION_X,
                                          FireBallConstants::POSITION_Y,
                                          FireBallConstants::HITBOX_WIDTH,
                                          FireBallConstants::HITBOX_HEIGHT}})
{
    m_objectAttributes = {.hitbox = {.x = position.x, .y = position.y},
                          .velocity = velocity};
}


void FireBall::Update(float deltaTime)
{
    if (!m_abilityAttribute.isActive)
        return;

    m_objectAttributes.hitbox = {.x = m_objectAttributes.hitbox.x +
                                      m_objectAttributes.velocity.x * deltaTime,
                                 .y =
                                     m_objectAttributes.hitbox.y +
                                     m_objectAttributes.velocity.y * deltaTime};
}


void FireBall::Draw() const
{
    if (!m_abilityAttribute.isActive)
        return;


    Rectangle destRec = {m_objectAttributes.hitbox.x,
                         m_objectAttributes.hitbox.y, 128.0f, 128.0f};


    DrawTexturePro(ResourceManager::GetTexture("resources/greenFireBall.png"),

                   {0.0f, 128.0f, 128.0f, 128.0f}, destRec, {0.0f, 0.0f}, 0.0f,
                   WHITE);
}

bool FireBall::IsActive() const { return m_abilityAttribute.isActive; }


void FireBall::Deactivate() { m_abilityAttribute.isActive = false; }
