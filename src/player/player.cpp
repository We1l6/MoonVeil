#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include <cmath>


Player::Player(TileMap &tilemap,
               ObjectAttributes &&objectAttributes,
               FrameAtributes &&frameAtributes,
               float hitPoints,
               std::vector<std::shared_ptr<Ability>> &gameObjects)
    : Entity(std::move(objectAttributes),
             std::move(frameAtributes),
             hitPoints,
             tilemap,
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


void Player::Draw(const Camera2D &camera) const
{
    Entity::Draw();

    Vector2 playerCenter = {
        m_objectAttributes.hitbox.x + m_objectAttributes.hitbox.width / 2 + 20,
        m_objectAttributes.hitbox.y + m_objectAttributes.hitbox.height / 2};


    Vector2 mouseScreenPos = GetMousePosition();
    Vector2 mouseWorldPos;
    mouseWorldPos.x =
        (mouseScreenPos.x - camera.offset.x) / camera.zoom + camera.target.x;
    mouseWorldPos.y =
        (mouseScreenPos.y - camera.offset.y) / camera.zoom + camera.target.y;

    Vector2 dirToMouse = Vector2Subtract(mouseWorldPos, playerCenter);
    float distance = Vector2Length(dirToMouse);

    if (distance > 0.0f)
    {
        Vector2 normalizedDir = Vector2Normalize(dirToMouse);
        Vector2 targetPos =
            Vector2Add(playerCenter, Vector2Scale(normalizedDir, 100.0f));

        DrawCircleV(targetPos, 10, RED);
    }
}