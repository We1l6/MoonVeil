#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include <cmath>
#include <iostream>


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

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Attack();
        return;
    }

    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        m_firstSpell.Cast();
    }
    if (IsKeyDown(KEY_SPACE))
    {
        m_secondSpell.Cast();
    }
    if (IsKeyPressed(KEY_E))
    {
        m_thirdSpell.Cast();
    }


    Vector2 newPosition = {m_objectAttributes.hitbox.x,
                           m_objectAttributes.hitbox.y};

    if (IsKeyDown(KEY_A))
    {
        newPosition.x -= m_objectAttributes.velocity.x * deltaTime;
        m_isMoving = true;
        m_objectAttributes.isFacingLeft = true;
    }
    if (IsKeyDown(KEY_D))
    {
        newPosition.x += m_objectAttributes.velocity.x * deltaTime;
        m_isMoving = true;
        m_objectAttributes.isFacingLeft = false;
    }
    if (IsKeyDown(KEY_W))
    {
        newPosition.y -= m_objectAttributes.velocity.y * deltaTime;
        m_isMoving = true;
    }
    if (IsKeyDown(KEY_S))
    {
        newPosition.y += m_objectAttributes.velocity.y * deltaTime;
        m_isMoving = true;
    }


    if (CanMoveTo(newPosition.x, newPosition.y))
    {
        m_objectAttributes.hitbox.x = newPosition.x;
        m_objectAttributes.hitbox.y = newPosition.y;
    }

    if (m_state != State::ATTACKING)
    {
        m_state = m_isMoving ? State::RUNNING : State::IDLE;
    }
}


void Player::Update(float deltaTime)
{
    Entity::Update(deltaTime);
    m_firstSpell.Update(deltaTime);
    m_secondSpell.Update(deltaTime);
    m_thirdSpell.Update(deltaTime);
}


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

void Player::Attack()
{
    if (m_isAttacking)
        return;

    m_state = State::ATTACKING;
    m_isAttacking = true;
    m_attackAnimationTime = 0.0f;
    m_frameAtributes.currentFrame = 0;

    constexpr float ATTACK_OFFSET = 35.0f;
    constexpr float ATTACK_HITBOX_WIDTH = 126.0f;
    constexpr float ATTACK_HITBOX_HEIGHT = 126.0f;

    float direction = m_objectAttributes.isFacingLeft ? -1.0f : 1.0f;

    Vector2 AttackPosition = GetPosition();

    if (m_objectAttributes.isFacingLeft)
    {
        AttackPosition.x -= (ATTACK_HITBOX_WIDTH - ATTACK_OFFSET);
    }
    else
    {
        AttackPosition.x += (m_objectAttributes.hitbox.width);
    }

    AttackPosition.y += (m_objectAttributes.hitbox.height / 2.0f) -
                        (ATTACK_HITBOX_HEIGHT / 2.0f);

    const Vector2 AttackVelocity = {0.0f, 0.0f};

    m_gameObjects.emplace_back(std::make_unique<DefaultAttack>(
        AttackPosition, AttackVelocity, GetIsFacingLeft()));
}