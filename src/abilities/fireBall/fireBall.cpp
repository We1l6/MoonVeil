#include "fireBall.h"
#include <iostream>

FireBall::FireBall(Vector2 position, Vector2 velocity, bool isFacilingLeft)
    : Ability(
          AbilityAttribute{.name = "FireBall",
                           .abilityType = AbilityType::DestroyOnHit,
                           .cooldown = FireBallConstants::COOLDOWN,
                           .damage = FireBallConstants::DAMAGE,
                           .currentCooldown = 0.0,
                           .isActive = true},
          ObjectAttributes{.objectType = ObjectType::PlayerAttack,
                           .velocity = velocity,
                           .isFacingLeft = isFacilingLeft,
                           .moveTextures = {ResourceManager::GetSubTexture(
                                                "resources/demon4.png", 0, 0),
                                            ResourceManager::GetSubTexture(
                                                "resources/demon4.png", 0, 1),
                                            ResourceManager::GetSubTexture(
                                                "resources/demon4.png", 0, 2)},
                           .hitbox = {position.x, position.y, 128, 128}},
          FrameAtributes{
              .currentFrame = 0, .frameCounter = 0, .frameSpeed = 2.0f})
{
}


void FireBall::Update(float deltaTime)
{
    // if (!m_abilityAttribute.isActive)
    //     return;

    m_objectAttributes.hitbox = {.x = m_objectAttributes.hitbox.x +
                                      m_objectAttributes.velocity.x * deltaTime,
                                 .y =
                                     m_objectAttributes.hitbox.y +
                                     m_objectAttributes.velocity.y * deltaTime};
}


void FireBall::Draw() const
{
    Rectangle destRec = {m_objectAttributes.hitbox.x,
                         m_objectAttributes.hitbox.y, 128.0f, 128.0f};


    DrawTexturePro(ResourceManager::GetTexture("resources/David.png"),

                   {0.0f, 128.0f, 128.0f, 128.0f}, destRec, {0.0f, 0.0f}, 0.0f,
                   WHITE);
}

bool FireBall::IsActive() const { return m_abilityAttribute.isActive; }


void FireBall::Deactivate() { m_abilityAttribute.isActive = false; }
