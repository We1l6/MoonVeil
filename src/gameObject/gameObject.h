#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "raylib.h"
#include <vector>

struct ObjectAttributes
{
    Vector2 velocity;
    Texture2D texture;
    Rectangle hitbox;
    std::vector<Texture2D> moveTextures;
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
    bool m_isMoving = false;


  private:
    bool m_markedForDeletion = false;

  public:
    GameObject(ObjectAttributes objectAttributes,
               FrameAtributes frameAtributes);
    virtual ~GameObject() = default;

    virtual void Update(float deltaTime) = 0;
    virtual void Draw() const = 0;

    void MarkForDeletion();
    [[nodiscard]] Vector2 GetPosition() const;
    [[nodiscard]] Rectangle GetHitbox() const;
    [[nodiscard]] bool IsMarkedForDeletion() const;

    [[nodiscard]] static bool CheckCollision(const GameObject &obj1,
                                             const GameObject &obj2);
};


#endif // GAMEOBJECT_H