#ifndef POISONOUS_GAS_H
#define POISONOUS_GAS_H


#include "../../resourceManager/resourceManager.h"
#include "../abilities.h"
#include "raylib.h"
#include <iostream>


namespace PoisonousGasConstants
{
constexpr float COOLDOWN = 8.0f;
constexpr float DURATION = 3.0f;
constexpr float DAMAGE_PER_SECOND = 5.0f;
constexpr float WIDTH = 128.0f;
constexpr float HEIGHT = 128.0f;
constexpr float FRAME_SPEED = 2.0f;
constexpr int FRAME_COUNT = 6;
constexpr float OFFSET_X = WIDTH / 2;
} // namespace PoisonousGasConstants

class PoisonousGas final : public Ability
{
  public:
    PoisonousGas(Vector2 position, Vector2 velocity);
    ~PoisonousGas() = default;

    void Update(float deltaTime) override;
    void Draw() const override;
    [[nodiscard]] bool IsActive() const;
    void Deactivate();
};


#endif // POISONOUS_GAS_H