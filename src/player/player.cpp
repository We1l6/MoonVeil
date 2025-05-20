#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include <cmath>
#include <iostream>
#include <memory>

#include "../settings/settings.h"
Player::Player(std::shared_ptr<TileMap> &tilemap,
               ObjectAttributes &&objectAttributes,
               FrameAtributes &&frameAtributes,
               float hitPoints,
               std::vector<std::shared_ptr<Ability>> &gameObjects,
               Texture2D spellsTexture,
               float attackDamage)
    : Entity(std::move(objectAttributes),
             std::move(frameAtributes),
             hitPoints,
             tilemap,
             gameObjects,
             attackDamage),
      m_spellsTexture(spellsTexture),
      m_attackDamage(attackDamage)
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
    if (IsKeyDown(SettingsGlobal::g_controls.dash))
    {
        m_secondSpell.Cast();
    }
    if (IsKeyPressed(SettingsGlobal::g_controls.thirdSpell))
    {
        if (m_remainingAbilitiesByArea > 0 && m_thirdSpell.Cast())
        {
            --m_remainingAbilitiesByArea;
        }
    }


    Vector2 newPosition = {m_objectAttributes.hitbox.x,
                           m_objectAttributes.hitbox.y};

    if (IsKeyDown(SettingsGlobal::g_controls.moveLeft))
    {
        newPosition.x -= m_objectAttributes.velocity.x * deltaTime;
        m_isMoving = true;
        m_objectAttributes.isFacingLeft = true;
    }
    if (IsKeyDown(SettingsGlobal::g_controls.moveRight))
    {
        newPosition.x += m_objectAttributes.velocity.x * deltaTime;
        m_isMoving = true;
        m_objectAttributes.isFacingLeft = false;
    }
    if (IsKeyDown(SettingsGlobal::g_controls.moveUp))
    {
        newPosition.y -= m_objectAttributes.velocity.y * deltaTime;
        m_isMoving = true;
    }
    if (IsKeyDown(SettingsGlobal::g_controls.moveDown))
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


void Player::Draw(const Camera2D &camera) const { Entity::Draw(); }

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

    m_gameObjects.emplace_back(std::make_shared<DefaultAttack>(
        AttackPosition, AttackVelocity, GetIsFacingLeft(), m_attackDamage));
}

void Player::addLevelBarWidth(int width)
{
    m_levelBarWidth += width;
    if (m_levelBarWidth >= 520)
    {
        levelUp();
    }
}

void Player::TakeDamage(float amount, bool isEnemyFacilingLeft)
{
    Entity::TakeDamage(amount, isEnemyFacilingLeft);


    if (m_hitPoints <= 0.0f)
    {
        m_markedForDeletion = true;
    }
}