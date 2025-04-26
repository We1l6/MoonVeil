#include "defaultAttack.h"


DefaultAttack::DefaultAttack(Vector2 position,
                             Vector2 velocity,
                             bool isFacingLeft)
    : Ability(
          AbilityAttribute{.name = "DefaultAttack",
                           .cooldown = DefaultAttackConstants::COOLDOWN,
                           .damage = DefaultAttackConstants::DAMAGE,
                           .currentCooldown = 0.0,
                           .isActive = true},
          ObjectAttributes{.objectType = ObjectType::PlayerAttack,
                           .velocity = velocity,
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
    m_isFacingLeft = isFacingLeft;
}

bool DefaultAttack::IsActive() const { return m_abilityAttribute.isActive; }


void DefaultAttack::Deactivate() { m_abilityAttribute.isActive = false; }


void DefaultAttack::Update(float deltaTime)
{
    m_currentLifetime += deltaTime;
    if (m_currentLifetime >= m_lifetime)
    {
        m_markedForDeletion = true;
    }
}


void DefaultAttack::Draw() const
{
    Rectangle destRec = {m_objectAttributes.hitbox.x,
                         m_objectAttributes.hitbox.y, 128.0f, 128.0f};


    DrawTexturePro(ResourceManager::GetTexture("resources/Daviddsf.png"),

                   {0.0f, 128.0f, 128.0f, 128.0f}, destRec, {0.0f, 0.0f}, 0.0f,
                   WHITE);
}
