#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "raylib.h"
#include <vector>


enum class ObjectType
{
    Player,
    Enemy,
    PlayerAttack,
    EnemyAttack
};

struct ObjectAttributes
{
    ObjectType objectType;
    Vector2 velocity;
    Rectangle hitbox;
    bool isFacingLeft = false;
    Texture2D damageTexture;

    float idleAnimationSpeed = 5.0f;
    float runAnimationSpeed = 10.0f;
    float attackAnimationSpeed = 15.0f;

    std::vector<Texture2D> idleTexture;
    std::vector<Texture2D> moveTextures;
    std::vector<Texture2D> attackTextures;
};


struct FrameAtributes
{
    int currentFrame = 0;
    int frameCounter = 0;
    float frameSpeed = 2.0f;
};


class GameObject
{
  protected:
    ObjectAttributes m_objectAttributes;
    FrameAtributes m_frameAtributes;
    bool m_markedForDeletion = false;
    bool m_isMoving = false;

  public:
    GameObject(ObjectAttributes objectAttributes,
               FrameAtributes frameAtributes);
    virtual ~GameObject() = default;

    virtual void Update(float deltaTime) = 0;
    virtual void Draw() const = 0;
    [[nodiscard]] ObjectType GetObjectType() const;
    void MarkForDeletion();
    [[nodiscard]] Vector2 GetPosition() const;
    [[nodiscard]] Rectangle GetHitbox() const;
    [[nodiscard]] bool IsMarkedForDeletion() const;
    [[nodiscard]] Vector2 getSize() const;
    bool GetIsFacingLeft() const;
    [[nodiscard]] static bool CheckCollision(const GameObject &obj1,
                                             const GameObject &obj2);

    void move(float dx, float dy);
};


#endif // GAMEOBJECT_H