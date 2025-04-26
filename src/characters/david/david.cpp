#include "david.h"
#include <iterator>


David::David(TileMap &tilemap,
             std::vector<std::shared_ptr<Ability>> &gameObjects)
    : Player(tilemap,
             ObjectAttributes{
                 .objectType = ObjectType::Player,
                 .velocity = {DavidConstants::INITIAL_POSITION_X,
                              DavidConstants::INITIAL_POSITION_Y},
                 .hitbox = {DavidConstants::DAVID_SPAWN_X,
                            DavidConstants::DAVID_SPAWN_Y,
                            .width = DavidConstants::DAVID_WIDTH,
                            .height = DavidConstants::DAVID_HEIGHT},
                 .idleAnimationSpeed = 4.0f,
                 .runAnimationSpeed = 6.0f,
                 .attackAnimationSpeed = 6.0f,
                 .idleTexture = {ResourceManager::GetSubTexture(
                                     "resources/DavidIDLE.png", 0, 0),
                                 ResourceManager::GetSubTexture(
                                     "resources/DavidIDLE.png", 0, 1),
                                 ResourceManager::GetSubTexture(
                                     "resources/DavidIDLE.png", 0, 2),
                                 ResourceManager::GetSubTexture(
                                     "resources/DavidIDLE.png", 0, 3),
                                 ResourceManager::GetSubTexture(
                                     "resources/DavidIDLE.png", 0, 4),
                                 ResourceManager::GetSubTexture(
                                     "resources/DavidIDLE.png", 0, 5)},

                 .moveTextures = {ResourceManager::GetSubTexture(
                                      "resources/DavidRUN.png", 0, 0),
                                  ResourceManager::GetSubTexture(
                                      "resources/DavidRUN.png", 0, 1),
                                  ResourceManager::GetSubTexture(
                                      "resources/DavidRUN.png", 0, 2),
                                  ResourceManager::GetSubTexture(
                                      "resources/DavidRUN.png", 0, 3),
                                  ResourceManager::GetSubTexture(
                                      "resources/DavidRUN.png", 0, 4),
                                  ResourceManager::GetSubTexture(
                                      "resources/DavidRUN.png", 0, 5)},

                 .attackTextures = {ResourceManager::GetSubTexture(
                                        "resources/DavidATTACK.png", 0, 0),
                                    ResourceManager::GetSubTexture(
                                        "resources/DavidATTACK.png", 0, 1),
                                    ResourceManager::GetSubTexture(
                                        "resources/DavidATTACK.png", 0, 2),
                                    ResourceManager::GetSubTexture(
                                        "resources/DavidATTACK.png", 0, 3),
                                    ResourceManager::GetSubTexture(
                                        "resources/DavidATTACK.png", 0, 4),
                                    ResourceManager::GetSubTexture(
                                        "resources/DavidATTACK.png", 0, 5)},

                 .damageTexture =
                     ResourceManager::GetTexture("resources/demon1.png")},
             FrameAtributes{
                 .currentFrame = 0, .frameCounter = 0, .frameSpeed = 2.0f},
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
        const float direction = GetIsFacingLeft() ? -1.0f : 1.0f;
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