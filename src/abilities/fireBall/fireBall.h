#ifndef FIREBALL_H
#define FIREBALL_H


#include "../../resourceManager/resourceManager.h"
#include "../abilities.h"
#include "raylib.h"


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