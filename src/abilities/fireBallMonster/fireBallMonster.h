#ifndef FIREBALL_H
#define FIREBALL_H


#include "../../resourceManager/resourceManager.h"
#include "../abilities.h"
#include "raylib.h"
#include <iostream>

namespace FireBallMonsterConstants
{
constexpr float COOLDOWN = 5.0f;
constexpr float DURATION = 10.0f;
constexpr float WIDTH = 128.0f;
constexpr float HEIGHT = 128.0f;
constexpr float FRAME_SPEED = 2.0f;
constexpr int FRAME_COUNT = 6;
constexpr float DAMAGE = 10.0f;
} // namespace FireBallMonsterConstants


class FireBallMonster final : public Ability
{
  public:
    FireBallMonster(Vector2 position, Vector2 velocity, bool isFacilingLeft);
    ~FireBallMonster() = default;

    void Update(float deltaTime) override;
    void Draw() const override;
    [[nodiscard]] bool IsActive() const;
    void Deactivate();
};


#endif // FIREBALL_H