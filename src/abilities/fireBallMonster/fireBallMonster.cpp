#include "fireBallMonster.h"
#include <iostream>

FireBallMonster::FireBallMonster(Vector2 position,
                                 Vector2 velocity,
                                 bool isFacilingLeft)
    : Ability(AbilityAttribute{.abilityType = AbilityType::DestroyOnHit,
                               .name = "FireBallMonster",
                               .cooldown = FireBallConstants::COOLDOWN,
                               .damage = FireBallConstants::DAMAGE,
                               .currentCooldown = 0.0,
                               .isActive = true},
              ObjectAttributes{
                  .objectType = ObjectType::EnemyAttack,
                  .velocity = velocity,
                  .isFacingLeft = isFacilingLeft,
                  .moveTextures = {ResourceManager::GetSubTexture(
                                       "resources/fireballMonster.png", 0, 0),
                                   ResourceManager::GetSubTexture(
                                       "resources/fireballMonster.png", 0, 1),
                                   ResourceManager::GetSubTexture(
                                       "resources/fireballMonster.png", 0, 2),
                                   ResourceManager::GetSubTexture(
                                       "resources/fireballMonster.png", 0, 3),
                                   ResourceManager::GetSubTexture(
                                       "resources/fireballMonster.png", 0, 4),
                                   ResourceManager::GetSubTexture(
                                       "resources/fireballMonster.png", 0, 5)},
                  .hitbox = {position.x, position.y, 128, 128}},
              FrameAtributes{
                  .currentFrame = 0, .frameCounter = 0, .frameSpeed = 2.0f},
              10.0f)
{
}


void FireBallMonster::Update(float deltaTime)
{
    Ability::Update(deltaTime);
    m_objectAttributes.hitbox.x += m_objectAttributes.velocity.x * deltaTime;
    m_objectAttributes.hitbox.y += m_objectAttributes.velocity.y * deltaTime;
}


void FireBallMonster::Draw() const { Ability::Draw(); }

bool FireBallMonster::IsActive() const { return m_abilityAttribute.isActive; }


void FireBallMonster::Deactivate() { m_abilityAttribute.isActive = false; }
