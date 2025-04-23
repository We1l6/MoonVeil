#ifndef DEFAULT_ATTACK_H
#define DEFAULT_ATTACK_H


#include "../../resourceManager/resourceManager.h"
#include "../abilities.h"
#include "raylib.h"


namespace DefaultAttackConstants
{
constexpr int HITBOX_WIDTH = 10;
constexpr int HITBOX_HEIGHT = 10;

constexpr int DAMAGE = 10;
constexpr double COOLDOWN = 1.0;

constexpr float POSITION_X = 0.0f;
constexpr float POSITION_Y = 0.0f;

constexpr double VELOCITY_X = 155.0f;
constexpr double VELOCITY_Y = 155.0f;
constexpr int RADIUS = 20;
} // namespace DefaultAttackConstants


class DefaultAttack : public Ability
{
  private:
    float m_lifetime = 0.1f;
    float m_currentLifetime = 0.0f;

  public:
    DefaultAttack(Vector2 position, Vector2 velocity);
    ~DefaultAttack() = default;

    void Update(float deltaTime) override;
    void Draw() const override;
    [[nodiscard]] bool IsActive() const;
    void Deactivate();
};
#endif // DEFAULT_ATTACK_H