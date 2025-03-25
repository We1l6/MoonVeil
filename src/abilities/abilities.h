#ifndef ABILITY_H
#define ABILITY_H

#include "../gameObject/gameObject.h"
#include <iostream>
#include <string>

struct AbilityAttribute
{
    const std::string name;
    float cooldown;
    float damage;
    float currentCooldown;
    bool isActive = true;
};

class Ability : public GameObject
{
  protected:
    AbilityAttribute m_abilityAttribute;

  public:
    Ability(AbilityAttribute abilityAttribute,
            ObjectAttributes objectAttributes);
    virtual ~Ability() = default;
    virtual void Activate();
    void Update(float deltaTime) override;
    float getDamage() const { return m_abilityAttribute.damage; }
    bool IsReady() const;
};

#endif