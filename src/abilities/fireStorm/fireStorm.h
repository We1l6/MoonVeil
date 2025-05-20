#ifndef FIRE_STORM_H
#define FIRE_STORM_H


#include "../../resourceManager/resourceManager.h"
#include "../abilities.h"
#include "raylib.h"

namespace FireStormConstants
{
constexpr float COOLDOWN = 5.0f;
constexpr float DURATION = 3.0f;
constexpr float DAMAGE = 15.0f;
constexpr float WIDTH = 128.0f;
constexpr float HEIGHT = 128.0f;
constexpr float FRAME_SPEED = 2.0f;
constexpr int FRAME_COUNT = 6;
constexpr float OFFSET_X = WIDTH / 2;
} // namespace FireStormConstants


class FireStorm final : public Ability
{
  public:
    FireStorm(Vector2 position, Vector2 velocity);
    ~FireStorm() = default;

    void Update(float deltaTime) override;
    void Draw() const override;
    [[nodiscard]] bool IsActive() const;
    void Deactivate();
};


#endif // FIRE_STORM_H