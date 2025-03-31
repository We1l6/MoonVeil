#include "entity.h"
#include "raylib.h"


Entity::Entity(ObjectAttributes objectAttributes,
               float hitPoints,
               TileMap &tileMap,
               std::vector<std::shared_ptr<Ability>> &gameObjects)
    : GameObject(objectAttributes),
      m_hitPoints(hitPoints),
      m_tilemap(tileMap),
      m_isFacingLeft(false),
      m_gameObjects(gameObjects),
      m_hitTimer(0.0f)
{
}


Entity::~Entity() {}


void Entity::Update(float deltaTime)
{
    if (m_isHit)
    {
        m_hitTimer -= deltaTime;
        if (m_hitTimer <= 0.0f)
        {
            m_isHit = false;
        }
    }
    if (m_isMoving)
    {
        m_frameCounter++;

        if (m_frameCounter >= (60 / m_frameSpeed))
        {
            m_frameCounter = 0;
            m_currentFrame++;

            if (m_currentFrame >= m_objectAttributes.m_moveTextures.size())
                m_currentFrame = 0;
        }
    }
    else
    {
        m_currentFrame = 0;
        m_frameCounter = 0;
    }
}


void Entity::Draw() const
{
    Texture2D currentTexture =
        m_objectAttributes.m_moveTextures[m_currentFrame];

    Rectangle sourceRec = {
        m_isFacingLeft ? (float)m_objectAttributes.texture.width : 0, 0,
        m_isFacingLeft ? -(float)m_objectAttributes.texture.width
                       : (float)m_objectAttributes.texture.width,
        (float)m_objectAttributes.texture.height};

    Rectangle destRec = {m_objectAttributes.hitbox.x,
                         m_objectAttributes.hitbox.y,
                         (float)m_objectAttributes.texture.width,
                         (float)m_objectAttributes.texture.height};

    Vector2 origin = {0, 0};


    if (m_isHit)
    {
        float redIntensity = 0.5f + 0.5f * sin(m_hitTimer * 10.0f);
        Color tintColor =
            m_isHit ? Color{255, (unsigned char)(255 * (1 - redIntensity)),
                            (unsigned char)(255 * (1 - redIntensity)), 255}
                    : RAYWHITE;

        DrawTexturePro(currentTexture, sourceRec, destRec, origin, 0.0f,
                       tintColor);
    }
    else
    {
        DrawTexturePro(currentTexture, sourceRec, destRec, origin, 0.0f,
                       RAYWHITE);
    }

    const int barWidth = 120;
    const int barHeight = 20;
    const int x = m_objectAttributes.hitbox.x - 0;
    const int y = m_objectAttributes.hitbox.y + 148;

    const float hpPercent = m_hitPoints / 100.0f;
    const int currentWidth = static_cast<int>(barWidth * hpPercent);

    DrawRectangle(x, y, barWidth, barHeight, GRAY);
    DrawRectangle(x, y, currentWidth, barHeight, RED);
    DrawRectangleLines(x, y, barWidth, barHeight, BLACK);

    DrawText(TextFormat("HP: %.1f / 100", m_hitPoints), x + 5, y, 16, WHITE);
}


void Entity::TakeDamage(int amount)
{
    m_hitPoints -= amount;

    if (m_hitPoints < 0)
        m_hitPoints = 0;

    m_isHit = true;
    m_hitTimer = m_hitEffectDuration;
}


Vector2 Entity::GetPosition() const
{
    return {m_objectAttributes.hitbox.x, m_objectAttributes.hitbox.y};
}


float Entity::GetHitPoint() const { return m_hitPoints; }


bool Entity::GetIsFacingLeft() const { return m_isFacingLeft; }


float Entity::GetHitEffectDuration() const { return m_hitEffectDuration; }


bool Entity::CanMoveTo(float x, float y) const
{
    return !m_tilemap.CheckCollisionWithObjects(
        "BarrierLayer",
        {x + m_objectAttributes.hitbox.width / 4, y,
         m_objectAttributes.hitbox.width, m_objectAttributes.hitbox.height});
}