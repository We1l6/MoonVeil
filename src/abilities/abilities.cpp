#include "abilities.h"


Ability::Ability(AbilityAttribute abilityAttribute,
                 ObjectAttributes objectAttributes,
                 FrameAtributes frameAtributes,
                 float lifetime)
    : GameObject(objectAttributes, frameAtributes),
      m_abilityAttribute(std::move(abilityAttribute)),
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
    if (m_abilityAttribute.abilityType == AbilityType::DestroyOnTimeout)
    {
        m_lifetime -= deltaTime;
        if (m_lifetime <= 0.0f)
        {
            m_markedForDeletion = true;
        }
    }
}


bool Ability::IsReady() const
{
    return m_abilityAttribute.currentCooldown <= 0.0f;
}
float Ability::TakeDamage(float damage) { m_abilityAttribute.isActive = false; }
