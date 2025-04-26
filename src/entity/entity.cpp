#include "entity.h"
#include "raylib.h"
#include <algorithm>
#include <iostream>


Entity::Entity(ObjectAttributes &&objectAttributes,
               FrameAtributes &&frameAtributes,
               float hitPoints,
               TileMap &tileMap,
               std::vector<std::shared_ptr<Ability>> &gameObjects)
    : GameObject(std::move(objectAttributes), std::move(frameAtributes)),
      m_hitPoints(hitPoints),
      m_tilemap(tileMap),
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

    if (m_isAttacking)
    {
        m_attackAnimationTime += deltaTime;
        if (m_attackAnimationTime >= ATTACK_ANIMATION_DURATION)
        {
            m_isAttacking = false;
            m_state = State::IDLE;
        }
        else
        {
            float frameDuration =
                ATTACK_ANIMATION_DURATION / ATTACK_ANIMATION_FRAMES;
            m_frameAtributes.currentFrame =
                static_cast<int>(m_attackAnimationTime / frameDuration);
        }
    }
    else if (m_isMoving)
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
    Texture2D currentTexture = m_objectAttributes.idleTexture[0];
    const std::vector<Texture2D> *textureArray = nullptr;

    if (m_state == State::ATTACKING &&
        !m_objectAttributes.attackTextures.empty())
    {
        textureArray = &m_objectAttributes.attackTextures;
        int frame = std::min(m_frameAtributes.currentFrame,
                             static_cast<int>(textureArray->size()) - 1);
        currentTexture = (*textureArray)[frame];
    }
    else
    {
        switch (m_state)
        {
        case State::IDLE:
            if (!m_objectAttributes.idleTexture.empty())
                textureArray = &m_objectAttributes.idleTexture;
            break;

        case State::RUNNING:
            if (!m_objectAttributes.moveTextures.empty())
                textureArray = &m_objectAttributes.moveTextures;
            break;

        case State::TAKING_DAMAGE:
            if (m_objectAttributes.damageTexture.id != 0)
                currentTexture = m_objectAttributes.damageTexture;
            break;
        }

        if (textureArray && !textureArray->empty())
        {
            float animationSpeed = (m_state == State::RUNNING)
                                       ? m_objectAttributes.runAnimationSpeed
                                       : m_objectAttributes.idleAnimationSpeed;
            float frameTime = GetTime() * animationSpeed;
            int frame = static_cast<int>(frameTime) % textureArray->size();
            currentTexture = (*textureArray)[frame];
        }
    }

    const Rectangle sourceRec = {0.0f, 0.0f,
                                 static_cast<float>(currentTexture.width) *
                                     (m_isFacingLeft ? 1.0f : -1.0f),
                                 static_cast<float>(currentTexture.height)};

    const Rectangle destRec = {
        m_objectAttributes.hitbox.x, m_objectAttributes.hitbox.y,
        static_cast<float>(m_objectAttributes.idleTexture[0].width),
        static_cast<float>(m_objectAttributes.idleTexture[0].height)};

    Vector2 origin = {0, 0};

    if (m_isHit)
    {
        float redIntensity = 0.5f + 0.5f * sin(m_hitTimer * 10.0f);
        Color tintColor = {
            255, static_cast<unsigned char>(255 * (1 - redIntensity)),
            static_cast<unsigned char>(255 * (1 - redIntensity)), 255};
        DrawTexturePro(currentTexture, sourceRec, destRec, origin, 0.0f,
                       tintColor);
    }
    else
    {
        DrawTexturePro(currentTexture, sourceRec, destRec, origin, 0.0f,
                       RAYWHITE);
    }

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


void Entity::TakeDamage(float amount, bool isEnemyFacilingLeft)
{
    LOG_INFO("TakeDamage");
    m_hitPoints -= amount;
    m_hitPoints = std::max(m_hitPoints, 0.0f);
    m_isHit = true;
    m_hitTimer = m_hitEffectDuration;

    if (m_hitPoints == 0.0f)
    {
        MarkForDeletion();
    }

    if (isEnemyFacilingLeft)
    {
        if (CanMoveTo(m_objectAttributes.hitbox.x - 20,
                      m_objectAttributes.hitbox.y))
            move(-20, 0);
    }
    else
    {
        if (CanMoveTo(m_objectAttributes.hitbox.x + 20,
                      m_objectAttributes.hitbox.y))
            move(+20, 0);
    }
}


Vector2 Entity::GetPosition() const
{
    return {m_objectAttributes.hitbox.x, m_objectAttributes.hitbox.y};
}


float Entity::GetHitPoint() const { return m_hitPoints; }


float Entity::GetHitEffectDuration() const { return m_hitEffectDuration; }


bool Entity::CanMoveTo(float x, float y) const
{
    return !m_tilemap.CheckCollisionWithObjects(
        "BarrierLayer",
        {x + (m_objectAttributes.hitbox.width / 4.0f), y,
         m_objectAttributes.hitbox.width, m_objectAttributes.hitbox.height});
}