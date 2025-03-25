#ifndef FIREBALL_H
#define FIREBALL_H

#include "raylib.h"
#include "../abilities.h"
#include "../../resourceManager/resourceManager.h"
class FireBall: public Ability {

public:
    FireBall(Vector2 position, Vector2 velocity);
    virtual ~FireBall() = default;;
    void Update(float deltaTime) override;
    void Draw() const override;
    bool IsActive() const;
    void Deactivate();

};
#endif //FIREBALL_H