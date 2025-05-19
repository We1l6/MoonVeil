#ifndef DEFAULT_ATTACK_H
#define DEFAULT_ATTACK_H


#include "../../resourceManager/resourceManager.h"
#include "../abilities.h"
#include "raylib.h"


namespace DefaultAttackConstants
{
constexpr int DAMAGE = 10;
constexpr double COOLDOWN = 1.0;
} // namespace DefaultAttackConstants


class DefaultAttack : public Ability
{
  public:
    DefaultAttack(Vector2 position,
                  Vector2 velocity,
                  bool isFacingLeft,
                  float damage);
    ~DefaultAttack() = default;

    void Update(float deltaTime) override;
    void Draw() const override;
    [[nodiscard]] bool IsActive() const;
    void Deactivate();
};
#endif // DEFAULT_ATTACK_H