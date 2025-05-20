#include "fireStorm.h"


FireStorm::FireStorm(Vector2 position, Vector2 velocity)
    : Ability(AbilityAttribute{.name = "FireStorm",
                               .abilityType = AbilityType::DestroyOnTimeout,
                               .cooldown = FireStormConstants::COOLDOWN,
                               .damage = FireStormConstants::DAMAGE,
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
                  .hitbox = {position.x - FireStormConstants::OFFSET_X,
                             position.y, FireStormConstants::WIDTH,
                             FireStormConstants::HEIGHT}},
              FrameAtributes{.currentFrame = 0,
                             .frameCounter = 0,
                             .frameSpeed = FireStormConstants::FRAME_SPEED},
              FireStormConstants::DURATION)
{
}


void FireStorm::Update(float deltaTime) { Ability::Update(deltaTime); }


void FireStorm::Draw() const { Ability::Draw(); }

bool FireStorm::IsActive() const { return m_abilityAttribute.isActive; }


void FireStorm::Deactivate() { m_abilityAttribute.isActive = false; }
