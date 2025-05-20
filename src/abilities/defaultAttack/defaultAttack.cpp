#include "defaultAttack.h"


DefaultAttack::DefaultAttack(Vector2 position,
                             Vector2 velocity,
                             bool isFacingLeft,
                             float damage)
    : Ability(
          AbilityAttribute{.abilityType = AbilityType::DestroyOnHit,
                           .name = "DefaultAttack",
                           .cooldown = DefaultAttackConstants::COOLDOWN,
                           .damage = damage,
                           .currentCooldown = 0.0,

                           .isActive = true},
          ObjectAttributes{
              .objectType = ObjectType::PlayerAttack,
              .velocity = velocity,
              .isFacingLeft = isFacingLeft,
              .moveTextures =
                  {ResourceManager::GetSubTexture("resources/demon4.png", 0, 0),
                   ResourceManager::GetSubTexture("resources/demon4.png", 0, 1),
                   ResourceManager::GetSubTexture(
                       "resources/demon4.png", 0, 2)},
              .hitbox = {position.x, position.y, DefaultAttackConstants::WIDTH,
                         DefaultAttackConstants::HEIGHT}},
          FrameAtributes{.currentFrame = 0,
                         .frameCounter = 0,
                         .frameSpeed = DefaultAttackConstants::FRAME_SPEED},
          DefaultAttackConstants::DURATION)

{
}

bool DefaultAttack::IsActive() const { return m_abilityAttribute.isActive; }


void DefaultAttack::Deactivate() { m_abilityAttribute.isActive = false; }


void DefaultAttack::Update(float deltaTime) { Ability::Update(deltaTime); }


void DefaultAttack::Draw() const {}
