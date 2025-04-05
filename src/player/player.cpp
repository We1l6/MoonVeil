#include "player.h"
#include "raylib.h"


Player::Player(TileMap &&tilemap,
               ObjectAttributes &&objectAttributes,
               float hitPoints,
               std::vector<std::shared_ptr<Ability>> &gameObjects)
    : Entity(std::move(objectAttributes),
             hitPoints,
             std::move(tilemap),
             gameObjects)
{
}


void Player::HandleInput(float deltaTime)
{
    m_isMoving = false;
    Vector2 newPosition = {m_objectAttributes.hitbox.x,
                           m_objectAttributes.hitbox.y};

    if (IsKeyDown(KEY_A))
    {
        newPosition.x -= m_objectAttributes.velocity.x * deltaTime;
        m_isMoving = true;
        m_isFacingLeft = true;
    }
    if (IsKeyDown(KEY_D))
    {
        newPosition.x += m_objectAttributes.velocity.x * deltaTime;
        m_isMoving = true;
        m_isFacingLeft = false;
    }
    if (IsKeyDown(KEY_W))
    {
        m_isMoving = true;
        newPosition.y -= m_objectAttributes.velocity.y * deltaTime;
    }
    if (IsKeyDown(KEY_S))
    {
        m_isMoving = true;
        newPosition.y += m_objectAttributes.velocity.y * deltaTime;
    }

    if (IsKeyPressed(KEY_SPACE))
    {
        m_isMoving = true;
        TakeDamage(10);
    }

    if (CanMoveTo(newPosition.x, newPosition.y))
    {
        m_objectAttributes.hitbox.x = newPosition.x;
        m_objectAttributes.hitbox.y = newPosition.y;
    }
}


void Player::Update(float deltaTime) { Entity::Update(deltaTime); }


void Player::Draw() const { Entity::Draw(); }