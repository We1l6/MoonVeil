#include "abilities.h"


Ability::Ability(AbilityAttribute abilityAttribute,
                 ObjectAttributes objectAttributes)
    : GameObject(std::move(objectAttributes)),
      m_abilityAttribute(std::move(abilityAttribute))
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
    if (m_abilityAttribute.currentCooldown > 0.0f)
    {
        m_abilityAttribute.currentCooldown -= deltaTime;
    }
}


bool Ability::IsReady() const
{
    return m_abilityAttribute.currentCooldown <= 0.0f;
}