#ifndef DEFAULT_ATTACK_H
#define DEFAULT_ATTACK_H


#include "../../resourceManager/resourceManager.h"
#include "../abilities.h"
#include "raylib.h"


namespace DefaultAttackConstants
{
constexpr float COOLDOWN = 0.5f;
constexpr float WIDTH = 128.0f;
constexpr float HEIGHT = 128.0f;
constexpr float FRAME_SPEED = 2.0f;
constexpr float DURATION = 0.2f;
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