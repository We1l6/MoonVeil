#ifndef ABILITY_H
#define ABILITY_H


#include "../gameObject/gameObject.h"
#include <iostream>
#include <string>
#include <string_view>
#include <utility>


enum class AbilityType
{
    DestroyOnHit,
    DestroyOnTimeout
};

struct AbilityAttribute
{
    AbilityType abilityType;
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
    float m_lifetime = 0.0f;

  public:
    Ability(AbilityAttribute abilityAttribute,
            ObjectAttributes objectAttributes,
            FrameAtributes frameAtributes,
            float lifetime = 0.0f);

    virtual ~Ability() = default;
    virtual void Activate();
    void Update(float deltaTime) override;
    void Draw() const override;
    float getDamage() const { return m_abilityAttribute.damage; }
    AbilityType getAbilityType() const
    {
        return m_abilityAttribute.abilityType;
    }
    [[nodiscard]] bool IsActive() const { return m_abilityAttribute.isActive; }
    bool IsReady() const;
    float TakeDamage(float damage);
};


#endif // ABILITY_H