#include "poisonousGas.h"

PoisonousGas::PoisonousGas(Vector2 position, Vector2 velocity)
    : Ability(
          AbilityAttribute{.name = "PoisonousGas",
                           .abilityType = AbilityType::DestroyOnTimeout,
                           .cooldown = PoisonousGasConstants::COOLDOWN,
                           .damage = PoisonousGasConstants::DAMAGE_PER_SECOND,
                           .currentCooldown = 0.0,
                           .isActive = true},
          ObjectAttributes{
              .objectType = ObjectType::PlayerAttack,
              .velocity = velocity,
              .moveTextures =
                  {ResourceManager::GetSubTexture("resources/Acid.png", 0, 0),
                   ResourceManager::GetSubTexture("resources/Acid.png", 0, 1),
                   ResourceManager::GetSubTexture("resources/Acid.png", 0, 2),
                   ResourceManager::GetSubTexture("resources/Acid.png", 0, 3),
                   ResourceManager::GetSubTexture("resources/Acid.png", 0, 4),
                   ResourceManager::GetSubTexture("resources/Acid.png", 0, 5)},
              .hitbox = {position.x - PoisonousGasConstants::OFFSET_X,
                         position.y, PoisonousGasConstants::WIDTH,
                         PoisonousGasConstants::HEIGHT}},
          FrameAtributes{.currentFrame = 0,
                         .frameCounter = 0,
                         .frameSpeed = PoisonousGasConstants::FRAME_SPEED},
          PoisonousGasConstants::DURATION)
{
}


void PoisonousGas::Update(float deltaTime) { Ability::Update(deltaTime); }


void PoisonousGas::Draw() const { Ability::Draw(); }

bool PoisonousGas::IsActive() const { return m_abilityAttribute.isActive; }


void PoisonousGas::Deactivate() { m_abilityAttribute.isActive = false; }
