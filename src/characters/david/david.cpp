#include "david.h"
#include <iterator>


David::David(std::shared_ptr<TileMap> &tilemap,
             std::vector<std::shared_ptr<Ability>> &gameObjects)
    : Player(tilemap,
             ObjectAttributes{
                 .objectType = ObjectType::Player,
                 .velocity = {155, 155},
                 .hitbox = {DavidConstants::DAVID_SPAWN_X,
                            DavidConstants::DAVID_SPAWN_Y,
                            .width = DavidConstants::DAVID_WIDTH,
                            .height = DavidConstants::DAVID_HEIGHT},
                 .isFacingLeft = false,
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
             gameObjects,
             ResourceManager::GetTexture("resources/DavidSpells.png"),
             25.0f)
{
    m_firstSpell = Spell{10.0f, 0.0f, false, [this]() { this->firstSpell(); }};
    m_secondSpell = Spell{5.0f, 0.0f, false, [this]() { this->secondSpell(); }};
    m_thirdSpell = Spell{10.0f, 0.0f, false, [this]() { this->thirdSpell(); }};
}

void David::firstSpell()
{
    constexpr Vector2 FIREBALL_OFFSET{0.0f, 0.0f};
    constexpr float VELOCITY_BOOST = 60.0f;
    const Vector2 fireballPosition = {GetPosition().x + FIREBALL_OFFSET.x,
                                      GetPosition().y + FIREBALL_OFFSET.y};
    const float direction = GetIsFacingLeft() ? -1.0f : 1.0f;
    const Vector2 fireballVelocity = {
        direction * (m_objectAttributes.velocity.x + VELOCITY_BOOST), 0.0f};

    m_gameObjects.emplace_back(std::make_shared<FireBall>(
        fireballPosition, fireballVelocity, GetIsFacingLeft(),
        "resources/acidBottle.png"));
}
void David::secondSpell()
{
    Vector2 newPosition = {m_objectAttributes.hitbox.x,
                           m_objectAttributes.hitbox.y};

    if (GetIsFacingLeft())
    {
        newPosition.x -= 75.0f;
    }
    else
    {
        newPosition.x += 75.0f;
    }
    if (CanMoveTo(newPosition.x, newPosition.y))
    {
        m_objectAttributes.hitbox.x = newPosition.x;
        m_objectAttributes.hitbox.y = newPosition.y;
    }
}

void David::thirdSpell()
{
    const Vector2 fireballPosition = {GetPosition().x + 64,
                                      GetPosition().y + 64};

    const Vector2 fireballVelocity = {0.0f, 0.0f};

    m_gameObjects.emplace_back(
        std::make_shared<PoisonousGas>(fireballPosition, fireballVelocity));
}