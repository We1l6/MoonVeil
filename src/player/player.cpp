#include "player.h"
#include "raylib.h"


Player::Player(TileMap &tilemap,
               ObjectAttributes objectAttributes,
               float hitPoints,
               std::vector<std::shared_ptr<Ability>> &gameObjects)
    : Entity(objectAttributes, hitPoints, tilemap, gameObjects)
{
}


void Player::HandleInput(float deltaTime)
{
    Vector2 newPosition;
    newPosition.x = m_objectAttributes.hitbox.x;
    newPosition.y = m_objectAttributes.hitbox.y;

    if (IsKeyDown(KEY_A))
    {
        newPosition.x -= m_objectAttributes.velocity.x * deltaTime;
        ;
        m_isFacingLeft = true;
    }
    if (IsKeyDown(KEY_D))
    {
        newPosition.x += m_objectAttributes.velocity.x * deltaTime;
        ;
        m_isFacingLeft = false;
    }
    if (IsKeyDown(KEY_W))
        newPosition.y -= m_objectAttributes.velocity.y * deltaTime;
    if (IsKeyDown(KEY_S))
        newPosition.y += m_objectAttributes.velocity.y * deltaTime;

    if (IsKeyPressed(KEY_SPACE))
        TakeDamage(10);

    if (!m_tilemap.IsColliding(newPosition.x + 32, newPosition.y + 40, 48, 84))
    {
        m_objectAttributes.hitbox.x = newPosition.x;
        m_objectAttributes.hitbox.y = newPosition.y;
    }
}


void Player::Update(float deltaTime) { Entity::Update(deltaTime); }


void Player::Draw() const { Entity::Draw(); }