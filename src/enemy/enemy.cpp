#include "enemy.h"
#include "raymath.h"

Enemy::Enemy(TileMap &tilemap,
             ObjectAttributes &&objectAttributes,
             FrameAtributes &&frameAtributes,
             float hitPoints,
             std::vector<std::shared_ptr<Ability>> &gameObjects,
             std::shared_ptr<Player> &player)
    : Entity(std::move(objectAttributes),
             std::move(frameAtributes),
             hitPoints,
             tilemap,
             gameObjects),
      m_player(player)
{
}

void Enemy::Update(float deltaTime)
{
    Entity::Update(deltaTime);

    Vector2 enemyCenter = {
        m_objectAttributes.hitbox.x + m_objectAttributes.hitbox.width / 2 + 20,
        m_objectAttributes.hitbox.y + m_objectAttributes.hitbox.height / 2};

    Vector2 dirToPlayer = Vector2Subtract(m_player->GetPosition(), enemyCenter);
    float distance = Vector2Length(dirToPlayer);

    if (distance > 0.0f)
    {
        Vector2 normalizedDir = Vector2Normalize(dirToPlayer);

        float moveSpeed = 100.0f;

        Vector2 velocity = Vector2Scale(normalizedDir, moveSpeed * deltaTime);

        m_objectAttributes.hitbox.x += velocity.x;
        m_objectAttributes.hitbox.y += velocity.y;

        m_isMoving = true;

        if (velocity.x > 0.0f)
        {
            m_objectAttributes.isFacingLeft = false;
        }
        else if (velocity.x < 0.0f)
        {
            m_objectAttributes.isFacingLeft = true;
        }
    }
    else
    {
        m_isMoving = false;
    }
}
void Enemy::Draw() const { Entity::Draw(); }