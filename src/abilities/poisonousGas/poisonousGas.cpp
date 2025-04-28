#include "poisonousGas.h"
#include "raylib.h"
#include <iostream>

PoisonousGas::PoisonousGas(Vector2 position, Vector2 velocity)
    : Ability(AbilityAttribute{.name = "PoisonousGas",
                               .abilityType = AbilityType::DestroyOnTimeout,
                               .cooldown = PoisonousGasConstants::COOLDOWN,
                               .damage = PoisonousGasConstants::DAMAGE,
                               .currentCooldown = 0.0,
                               .isActive = true},
              ObjectAttributes{
                  .objectType = ObjectType::PlayerAttack,
                  .velocity = velocity,
                  .moveTextures = {ResourceManager::GetSubTexture(
                                       "resources/demon4.png", 0, 0),
                                   ResourceManager::GetSubTexture(
                                       "resources/demon4.png", 0, 1),
                                   ResourceManager::GetSubTexture(
                                       "resources/demon4.png", 0, 2)},
                  .hitbox = {position.x - 128 / 2, position.y, 128, 128}},
              FrameAtributes{
                  .currentFrame = 0, .frameCounter = 0, .frameSpeed = 2.0f},
              3)
{
}


void PoisonousGas::Update(float deltaTime) { Ability::Update(deltaTime); }


void PoisonousGas::Draw() const
{
    DrawRectangle(m_objectAttributes.hitbox.x, m_objectAttributes.hitbox.y,
                  m_objectAttributes.hitbox.width,
                  m_objectAttributes.hitbox.height, GREEN);
}

bool PoisonousGas::IsActive() const { return m_abilityAttribute.isActive; }


void PoisonousGas::Deactivate() { m_abilityAttribute.isActive = false; }
