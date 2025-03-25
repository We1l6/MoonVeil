#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "raylib.h"


struct ObjectAttributes{
    Vector2 velocity;
    Texture2D texture; 
    Rectangle hitbox; 
};

class GameObject {

protected:
    ObjectAttributes m_objectAttributes;
    
private:
    bool m_markedForDeletion = false;
public:
    GameObject(ObjectAttributes m_objectAttributes);
    virtual ~GameObject() = default;;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() const = 0;
    Vector2 GetPosition() const;
    Rectangle GetHitbox() const; 
    static bool CheckCollision(const GameObject& obj1, const GameObject& obj2);
    void MarkForDeletion() { m_markedForDeletion = true; }
    bool IsMarkedForDeletion() const { return m_markedForDeletion; }
};



#endif //GAMEOBJECT_H