#ifndef ABILITY_H
#define ABILITY_H


#include "../gameObject/gameObject.h"
#include <iostream>
#include <string>
#include <string_view>
#include <utility>


struct AbilityAttribute
{
    std::string_view name;
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
            ObjectAttributes objectAttributes,
            FrameAtributes frameAtributes);
    virtual ~Ability() = default;
    virtual void Activate();
    void Update(float deltaTime) override;
    float getDamage() const { return m_abilityAttribute.damage; }
    bool IsReady() const;
    float TakeDamage(float damage);
};


#endif // ABILITY_H