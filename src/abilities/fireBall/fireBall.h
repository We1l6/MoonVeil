#ifndef FIREBALL_H
#define FIREBALL_H


#include "../../resourceManager/resourceManager.h"
#include "../abilities.h"
#include "raylib.h"


namespace FireBallConstants
{
constexpr int HITBOX_WIDTH = 10;
constexpr int HITBOX_HEIGHT = 10;

constexpr int DAMAGE = 10;
constexpr double COOLDOWN = 1.0;

constexpr int POSITION_X = 0;
constexpr int POSITION_Y = 0;

constexpr double VELOCITY_X = 155.0;
constexpr double VELOCITY_Y = 155.0;
constexpr int RADIUS = 20;
} // namespace FireBallConstants


class FireBall : public Ability
{
  public:
    FireBall(Vector2 position, Vector2 velocity);
    virtual ~FireBall() = default;

    void Update(float deltaTime) override;
    void Draw() const override;
    bool IsActive() const;
    void Deactivate();
};


#endif // FIREBALL_H