#include "slug.h"
#include "../../abilities/fireBallMonster/fireBallMonster.h"

Slug::Slug(std::shared_ptr<TileMap> &tilemap,
           Vector2 position,
           std::vector<std::shared_ptr<Ability>> &gameObjects,
           std::shared_ptr<Player> &player,
           float attackDamage,
           float initialHealth)
    : Enemy(
          tilemap,
          ObjectAttributes{.objectType = ObjectType::Enemy,
                           .hitbox = {.height = SlugConstants::HEIGHT,
                                      .width = SlugConstants::WIDTH,
                                      .x = position.x,
                                      .y = position.y},

                           .idleTexture =
                               {
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 0),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 1),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 2),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 3),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 4),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 5),
                               },

                           .moveTextures =
                               {
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 0),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 1),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 2),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 3),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 4),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 5),
                               },

                           .attackTextures =
                               {
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 0),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 1),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 2),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 3),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 4),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 5),
                               },

                           .velocity = {100.0f, 0.0f}},
          FrameAtributes{.currentFrame = 0, .frameCounter = 0, .frameSpeed = 3},
          initialHealth,
          gameObjects,
          player,
          attackDamage)
{
}

void Slug::useAbilityOnDeath()
{
    constexpr Vector2 FIREBALL_OFFSET{0.0f, 0.0f};
    constexpr float VELOCITY_BOOST = 100.0f;
    const Vector2 fireballPosition = {GetPosition().x + FIREBALL_OFFSET.x,
                                      GetPosition().y + FIREBALL_OFFSET.y};
    const float direction = GetIsFacingLeft() ? -1.0f : 1.0f;
    Vector2 fireballVelocity = {
        (1) * (m_objectAttributes.velocity.x + VELOCITY_BOOST), 0.0f};

    m_gameObjects.emplace_back(std::make_shared<FireBallMonster>(
        fireballPosition, fireballVelocity, GetIsFacingLeft()));

    fireballVelocity = {(-1) * (m_objectAttributes.velocity.x + VELOCITY_BOOST),
                        0.0f};

    m_gameObjects.emplace_back(std::make_shared<FireBallMonster>(
        fireballPosition, fireballVelocity, GetIsFacingLeft()));

    fireballVelocity = {
        0.0f, (-1) * (m_objectAttributes.velocity.x + VELOCITY_BOOST)};

    m_gameObjects.emplace_back(std::make_shared<FireBallMonster>(
        fireballPosition, fireballVelocity, GetIsFacingLeft()));

    fireballVelocity = {0.0f,
                        (1) * (m_objectAttributes.velocity.x + VELOCITY_BOOST)};

    m_gameObjects.emplace_back(std::make_shared<FireBallMonster>(
        fireballPosition, fireballVelocity, GetIsFacingLeft()));
}