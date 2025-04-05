#include "david.h"
#include <iterator>


David::David(TileMap &&tilemap,
             std::vector<std::shared_ptr<Ability>> &gameObjects)
    : Player(std::move(tilemap),
             ObjectAttributes{
                 .velocity = {DavidConstants::INITIAL_POSITION_X,
                              DavidConstants::INITIAL_POSITION_Y},
                 .texture = ResourceManager::GetTexture(
                     std::data(DavidConstants::TEXTURE_DAVID_PATH)), //!!!!!!!!
                 .hitbox = {DavidConstants::DAVID_SPAWN_X,
                            DavidConstants::DAVID_SPAWN_Y,
                            .width = DavidConstants::DAVID_WIDTH,
                            .height = DavidConstants::DAVID_HEIGHT},
                 .moveTextures = {ResourceManager::GetSubTexture(
                                      "resources/RunSprite.png", 0, 0),
                                  ResourceManager::GetSubTexture(
                                      "resources/RunSprite.png", 0, 1),
                                  ResourceManager::GetSubTexture(
                                      "resources/RunSprite.png", 0, 2),
                                  ResourceManager::GetSubTexture(
                                      "resources/RunSprite.png", 0, 3),
                                  ResourceManager::GetSubTexture(
                                      "resources/RunSprite.png", 0, 4),
                                  ResourceManager::GetSubTexture(
                                      "resources/RunSprite.png", 0, 5)}},
             DavidConstants::INITIAL_HEALTH,
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
        constexpr Vector2 FIREBALL_OFFSET{0.0f, 0.0f};
        constexpr float VELOCITY_BOOST = 60.0f;
        const Vector2 fireballPosition = {GetPosition().x + FIREBALL_OFFSET.x,
                                          GetPosition().y + FIREBALL_OFFSET.y};
        const float direction = m_isFacingLeft ? -1.0f : 1.0f;
        const Vector2 fireballVelocity = {
            direction * (m_objectAttributes.velocity.x + VELOCITY_BOOST), 0.0f};

        m_gameObjects.emplace_back(
            std::make_unique<FireBall>(fireballPosition, fireballVelocity));
    }
    if (IsKeyPressed(KEY_K))
        std::cout << "abilities[2].Activate()\n";
    if (IsKeyPressed(KEY_L))
        std::cout << "abilities[3].Activate()\n";
}
