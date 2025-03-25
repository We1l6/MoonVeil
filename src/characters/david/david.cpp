
#include "david.h"

David::David(TileMap &tilemap,
             std::vector<std::shared_ptr<Ability>> &gameObjects)
    : Player(tilemap,
             {{155.0f, 155.0f},
              ResourceManager::GetTexture("resources/David.png"),
              {600, 700, 10, 10}},
             100,
             gameObjects)
{
}

void David::HandleInput(float deltaTime)
{
    Player::HandleInput(deltaTime);
    if (IsKeyPressed(KEY_H))
        std::cout << "abilities[0].Activate()\n";
    if (IsKeyPressed(KEY_J))
    {
        Vector2 circlePosition = GetPosition();
        circlePosition.x += 64;
        circlePosition.y += 44;
        Vector2 circleVelocity = {m_objectAttributes.velocity.x + 60, 0.0f};
        if (m_isFacingLeft)
        {
            circleVelocity.x = -m_objectAttributes.velocity.x - 60;
        }
        m_gameObjects.emplace_back(
            std::make_unique<FireBall>(circlePosition, circleVelocity));
    }
    if (IsKeyPressed(KEY_K))
        std::cout << "abilities[2].Activate()\n";
    if (IsKeyPressed(KEY_L))
        std::cout << "abilities[3].Activate()\n";
}
