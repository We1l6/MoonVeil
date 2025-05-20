#include "enemy.h"
#include "raymath.h"

Enemy::Enemy(std::shared_ptr<TileMap> &tilemap,
             ObjectAttributes &&objectAttributes,
             FrameAtributes &&frameAtributes,
             float hitPoints,
             std::vector<std::shared_ptr<Ability>> &gameObjects,
             std::shared_ptr<Player> &player,
             float attackDamage)
    : Entity(std::move(objectAttributes),
             std::move(frameAtributes),
             hitPoints,
             tilemap,
             gameObjects,
             attackDamage),
      m_player(player)
{
}

void Enemy::Update(float deltaTime)
{
    m_firstSpell.Cast();
    m_firstSpell.Update(deltaTime);
    Entity::Update(deltaTime);
    Vector2 enemyCenter = {
        m_objectAttributes.hitbox.x + m_objectAttributes.hitbox.width / 2 + 20,
        m_objectAttributes.hitbox.y + m_objectAttributes.hitbox.height / 2};

    Vector2 playerCenter = {m_player->GetPosition().x + 64,
                            m_player->GetPosition().y + 64};
    Vector2 dirToPlayer = Vector2Subtract(playerCenter, enemyCenter);
    float distance = Vector2Length(dirToPlayer);

    if (distance > 0.0f)
    {
        Vector2 normalizedDir = Vector2Normalize(dirToPlayer);

        float moveSpeed = m_objectAttributes.velocity.x;

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
void Enemy::Draw() const
{
    Entity::Draw();
    const int barWidth = 109;
    const int barHeight = 5;
    const int x = m_objectAttributes.hitbox.x;
    const int y = m_objectAttributes.hitbox.y + 148;

    float hpPercent = m_hitPoints / 100.0f;
    int currentWidth = static_cast<int>(barWidth * hpPercent);

    DrawRectangle(x + 16, y + 3, barWidth, barHeight, GRAY);
    DrawRectangle(x + 16, y + 3, currentWidth, barHeight, RED);
    DrawRectangleLines(x + 16, y + 3, barWidth, barHeight, BLACK);

    DrawTexture(ResourceManager::GetTexture("resources/HPBAR.png"), x, y - 54,
                WHITE);
}

void Enemy::TakeDamage(float amount, bool isEnemyFacilingLeft)
{
    Entity::TakeDamage(amount, isEnemyFacilingLeft);
    if (m_hitPoints == 0.0f && !IsMarkedForDeletion())
    {
        useAbilityOnDeath();
        MarkForDeletion();
        m_player->addLevelBarWidth(200);
    }
}

void Enemy::useAbilityOnDeath() {}