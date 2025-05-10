#include "fireBall.h"
#include <iostream>

FireBall::FireBall(Vector2 position, Vector2 velocity, bool isFacilingLeft)
    : Ability(AbilityAttribute{.abilityType = AbilityType::DestroyOnHit,
                               .name = "FireBall",
                               .cooldown = 5,
                               .damage = 20,
                               .currentCooldown = 0.0,
                               .isActive = true},
              ObjectAttributes{
                  .objectType = ObjectType::PlayerAttack,
                  .velocity = velocity,
                  .hitbox = {position.x, position.y, 128.0f, 128.0f},
                  .isFacingLeft = isFacilingLeft,
                  .moveTextures = {ResourceManager::GetSubTexture(
                                       "resources/acidBottle.png", 0, 0),
                                   ResourceManager::GetSubTexture(
                                       "resources/acidBottle.png", 0, 1),
                                   ResourceManager::GetSubTexture(
                                       "resources/acidBottle.png", 0, 2),
                                   ResourceManager::GetSubTexture(
                                       "resources/acidBottle.png", 0, 3),
                                   ResourceManager::GetSubTexture(
                                       "resources/acidBottle.png", 0, 4),
                                   ResourceManager::GetSubTexture(
                                       "resources/acidBottle.png", 0, 5)},
              },
              FrameAtributes{
                  .currentFrame = 0, .frameCounter = 0, .frameSpeed = 2.0f},
              5.0f)
{
}


void FireBall::Update(float deltaTime)
{
    Ability::Update(deltaTime);
    m_objectAttributes.hitbox.x += m_objectAttributes.velocity.x * deltaTime;
    m_objectAttributes.hitbox.y += m_objectAttributes.velocity.y * deltaTime;
}


void FireBall::Draw() const { Ability::Draw(); }

bool FireBall::IsActive() const { return m_abilityAttribute.isActive; }


void FireBall::Deactivate() { m_abilityAttribute.isActive = false; }
