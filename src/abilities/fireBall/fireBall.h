#ifndef FIREBALL_H
#define FIREBALL_H


#include "../../resourceManager/resourceManager.h"
#include "../abilities.h"
#include "raylib.h"


namespace FireBallConstants
{
constexpr float COOLDOWN = 5.0f;
constexpr float DURATION = 10.0f;
constexpr float WIDTH = 128.0f;
constexpr float HEIGHT = 128.0f;
constexpr float FRAME_SPEED = 2.0f;
constexpr int FRAME_COUNT = 6;
constexpr float DAMAGE = 10.0f;
} // namespace FireBallConstants


class FireBall final : public Ability
{
  public:
    FireBall(Vector2 position,
             Vector2 velocity,
             bool isFacilingLeft,
             std::string textureSrc,
             float fireBallDamage);
    ~FireBall() = default;

    void Update(float deltaTime) override;
    void Draw() const override;
    [[nodiscard]] bool IsActive() const;
    void Deactivate();
};


#endif // FIREBALL_H