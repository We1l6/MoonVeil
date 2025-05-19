#include "fireStorm.h"
#include "raylib.h"
#include <iostream>

FireStorm::FireStorm(Vector2 position, Vector2 velocity)
    : Ability(AbilityAttribute{.name = "FireStorm",
                               .abilityType = AbilityType::DestroyOnTimeout,
                               .cooldown = FireStormConstants::COOLDOWN,
                               .damage = 15.0f,
                               .currentCooldown = 0.0,
                               .isActive = true},
              ObjectAttributes{
                  .objectType = ObjectType::PlayerAttack,
                  .velocity = velocity,
                  .moveTextures = {ResourceManager::GetSubTexture(
                                       "resources/FireStorm.png", 0, 0),
                                   ResourceManager::GetSubTexture(
                                       "resources/FireStorm.png", 0, 1),
                                   ResourceManager::GetSubTexture(
                                       "resources/FireStorm.png", 0, 2),
                                   ResourceManager::GetSubTexture(
                                       "resources/FireStorm.png", 0, 3),
                                   ResourceManager::GetSubTexture(
                                       "resources/FireStorm.png", 0, 4),
                                   ResourceManager::GetSubTexture(
                                       "resources/FireStorm.png", 0, 5)},
                  .hitbox = {position.x - 128 / 2, position.y, 128, 128}},
              FrameAtributes{
                  .currentFrame = 0, .frameCounter = 0, .frameSpeed = 2.0f},
              3.0f)
{
}


void FireStorm::Update(float deltaTime) { Ability::Update(deltaTime); }


void FireStorm::Draw() const { Ability::Draw(); }

bool FireStorm::IsActive() const { return m_abilityAttribute.isActive; }


void FireStorm::Deactivate() { m_abilityAttribute.isActive = false; }
