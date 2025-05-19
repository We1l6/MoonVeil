#include "galmar.h"
#include "../../abilities/fireStorm/fireStorm.h"
#include <iterator>

Galmar::Galmar(std::shared_ptr<TileMap> &tilemap,
               std::vector<std::shared_ptr<Ability>> &gameObjects)
    : Player(tilemap,
             ObjectAttributes{
                 .objectType = ObjectType::Player,
                 .velocity = {150, 150},
                 .hitbox = {GalmarConstants::Galmar_SPAWN_X,
                            GalmarConstants::Galmar_SPAWN_Y,
                            .width = GalmarConstants::Galmar_WIDTH,
                            .height = GalmarConstants::Galmar_HEIGHT},
                 .isFacingLeft = false,
                 .idleAnimationSpeed = 4.0f,
                 .runAnimationSpeed = 6.0f,
                 .attackAnimationSpeed = 6.0f,
                 .idleTexture = {ResourceManager::GetSubTexture(
                                     "resources/GalmarIDLE.png", 0, 0),
                                 ResourceManager::GetSubTexture(
                                     "resources/GalmarIDLE.png", 0, 1),
                                 ResourceManager::GetSubTexture(
                                     "resources/GalmarIDLE.png", 0, 2),
                                 ResourceManager::GetSubTexture(
                                     "resources/GalmarIDLE.png", 0, 3),
                                 ResourceManager::GetSubTexture(
                                     "resources/GalmarIDLE.png", 0, 4),
                                 ResourceManager::GetSubTexture(
                                     "resources/GalmarIDLE.png", 0, 5)},

                 .moveTextures = {ResourceManager::GetSubTexture(
                                      "resources/GalmarRUN.png", 0, 0),
                                  ResourceManager::GetSubTexture(
                                      "resources/GalmarRUN.png", 0, 1),
                                  ResourceManager::GetSubTexture(
                                      "resources/GalmarRUN.png", 0, 2),
                                  ResourceManager::GetSubTexture(
                                      "resources/GalmarRUN.png", 0, 3),
                                  ResourceManager::GetSubTexture(
                                      "resources/GalmarRUN.png", 0, 4),
                                  ResourceManager::GetSubTexture(
                                      "resources/GalmarRUN.png", 0, 5)},

                 .attackTextures = {ResourceManager::GetSubTexture(
                                        "resources/GalmarATTACK.png", 0, 0),
                                    ResourceManager::GetSubTexture(
                                        "resources/GalmarATTACK.png", 0, 1),
                                    ResourceManager::GetSubTexture(
                                        "resources/GalmarATTACK.png", 0, 2),
                                    ResourceManager::GetSubTexture(
                                        "resources/GalmarATTACK.png", 0, 3),
                                    ResourceManager::GetSubTexture(
                                        "resources/GalmarATTACK.png", 0, 4),
                                    ResourceManager::GetSubTexture(
                                        "resources/GalmarATTACK.png", 0, 5)},

                 .damageTexture =
                     ResourceManager::GetTexture("resources/demon1.png")},
             FrameAtributes{
                 .currentFrame = 0, .frameCounter = 0, .frameSpeed = 2.0f},
             100.0f,
             gameObjects,
             ResourceManager::GetTexture("resources/GalmarSpells.png"),
             20.0f)
{
    m_firstSpell = Spell{8.0f, 0.0f, false, [this]() { this->firstSpell(); }};
    m_secondSpell = Spell{5.0f, 0.0f, false, [this]() { this->secondSpell(); }};
    m_thirdSpell = Spell{10.0f, 0.0f, false, [this]() { this->thirdSpell(); }};
}

void Galmar::firstSpell()
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
        "resources/FireBall.png"));
}
void Galmar::secondSpell()
{
    Vector2 newPosition = {m_objectAttributes.hitbox.x,
                           m_objectAttributes.hitbox.y};

    if (GetIsFacingLeft())
    {
        newPosition.x -= 65.0f;
    }
    else
    {
        newPosition.x += 65.0f;
    }
    if (CanMoveTo(newPosition.x, newPosition.y))
    {
        m_objectAttributes.hitbox.x = newPosition.x;
        m_objectAttributes.hitbox.y = newPosition.y;
    }
}

void Galmar::thirdSpell()
{
    const Vector2 fireballPosition = {GetPosition().x + 64,
                                      GetPosition().y + 64};

    const Vector2 fireballVelocity = {0.0f, 0.0f};

    m_gameObjects.emplace_back(
        std::make_shared<FireStorm>(fireballPosition, fireballVelocity));
}