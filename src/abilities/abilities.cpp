#include "abilities.h"
#include "raylib.h"


Ability::Ability(AbilityAttribute abilityAttribute,
                 ObjectAttributes objectAttributes,
                 FrameAtributes frameAtributes,
                 float lifetime)
    : GameObject(objectAttributes, frameAtributes),
      m_abilityAttribute(abilityAttribute),
      m_lifetime(lifetime)
{
}


void Ability::Activate()
{
    if (m_abilityAttribute.currentCooldown <= 0.0f)
    {
        std::cout << "Ability " << m_abilityAttribute.name << " activated!\n";
        m_abilityAttribute.currentCooldown = m_abilityAttribute.cooldown;
    }
    else [[likely]]
    {
        std::cout << "Ability " << m_abilityAttribute.name
                  << " is on cooldown!\n";
    }
}


void Ability::Update(float deltaTime)
{
    m_lifetime -= deltaTime;
    if (m_lifetime <= 0.0f)
    {
        m_markedForDeletion = true;
    }
}


bool Ability::IsReady() const
{
    return m_abilityAttribute.currentCooldown <= 0.0f;
}
float Ability::TakeDamage(float damage) { m_abilityAttribute.isActive = false; }


void Ability::Draw() const
{
    Rectangle destRec = {
        m_objectAttributes.hitbox.x, m_objectAttributes.hitbox.y,
        m_objectAttributes.hitbox.width, m_objectAttributes.hitbox.height};

    Texture2D currentTexture = m_objectAttributes.moveTextures[0];
    const std::vector<Texture2D> *textureArray =
        &m_objectAttributes.moveTextures;

    if (textureArray && !textureArray->empty())
    {
        float animationSpeed = 4;
        float frameTime = GetTime() * animationSpeed;
        int frame = static_cast<int>(frameTime) % textureArray->size();
        currentTexture = (*textureArray)[frame];
    }

    DrawTexturePro(currentTexture, {0.0f, 128.0f, 128.0f, 128.0f}, destRec,
                   {0.0f, 0.0f}, 0.0f, WHITE);
}