#include "entity.h"

#include "raylib.h"
#include <algorithm>


Entity::Entity(ObjectAttributes &&objectAttributes,
               FrameAtributes &&frameAtributes,
               float hitPoints,
               TileMap &tileMap,
               std::vector<std::shared_ptr<Ability>> &gameObjects)
    : GameObject(std::move(objectAttributes), std::move(frameAtributes)),
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
        m_frameAtributes.frameCounter++;

        if (m_frameAtributes.frameCounter >=
            (60.0f / m_frameAtributes.frameSpeed))
        {
            m_frameAtributes.frameCounter = 0;
            m_frameAtributes.currentFrame++;

            if (m_frameAtributes.currentFrame >=
                m_objectAttributes.moveTextures.size())
                m_frameAtributes.currentFrame = 0;
        }
    }
    else
    {
        m_frameAtributes.currentFrame = 0;
        m_frameAtributes.frameCounter = 0;
    }
}


void Entity::Draw() const
{
    const Texture2D currentTexture =
        m_objectAttributes.moveTextures[m_frameAtributes.currentFrame];

    const Rectangle sourceRec = {
        static_cast<float>(m_isFacingLeft ? m_objectAttributes.texture.width
                                          : 0.0f),
        0.0f,
        static_cast<float>(m_isFacingLeft ? m_objectAttributes.texture.width
                                          : -m_objectAttributes.texture.width),
        static_cast<float>(m_objectAttributes.texture.height)};

    const Rectangle destRec = {
        m_objectAttributes.hitbox.x, m_objectAttributes.hitbox.y,
        static_cast<float>(m_objectAttributes.texture.width),
        static_cast<float>(m_objectAttributes.texture.height)};

    Vector2 origin = {0, 0};

    if (m_isHit) [[unlikely]]
    {
        const float redIntensity = 0.5f + 0.5f * sin(m_hitTimer * 10.0f);
        const Color tintColor =
            m_isHit ? Color{255, (unsigned char)(255 * (1 - redIntensity)),
                            (unsigned char)(255 * (1 - redIntensity)), 255}
                    : RAYWHITE;

        DrawTexturePro(currentTexture, sourceRec, destRec, origin, 0.0f,
                       tintColor);
    }
    else [[likely]]
    {
        DrawTexturePro(currentTexture, sourceRec, destRec, origin, 0.0f,
                       RAYWHITE);
    }

    const int barWidth = 109;
    const int barHeight = 5;
    const int x = m_objectAttributes.hitbox.x;
    const int y = m_objectAttributes.hitbox.y + 148;

    const float hpPercent = m_hitPoints / 100.0f;
    const int currentWidth = static_cast<int>(barWidth * hpPercent);

    DrawRectangle(x + 16, y + 3, barWidth, barHeight, GRAY);
    DrawRectangle(x + 16, y + 3, currentWidth, barHeight, RED);
    DrawRectangleLines(x + 16, y + 3, barWidth, barHeight, BLACK);

    DrawTexture(ResourceManager::GetTexture("resources/HPBAR.png"), x, y - 54,
                WHITE);
}


void Entity::TakeDamage(float amount)
{
    LOG_INFO("TakeDamage");
    m_hitPoints -= amount;

    m_hitPoints = std::max(m_hitPoints, 0.0f);
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
        {x + (m_objectAttributes.hitbox.width / 4.0f), y,
         m_objectAttributes.hitbox.width, m_objectAttributes.hitbox.height});
}