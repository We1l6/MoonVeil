#include "gameObject.h"
#include "raylib.h"

GameObject::GameObject(ObjectAttributes objectAttributes)
    : m_objectAttributes(objectAttributes),
      m_markedForDeletion(false)
{
}

Rectangle GameObject::GetHitbox() const { return m_objectAttributes.hitbox; }

bool GameObject::CheckCollision(const GameObject &obj1, const GameObject &obj2)
{
    return CheckCollisionRecs(obj1.GetHitbox(), obj2.GetHitbox());
}

bool GameObject::IsMarkedForDeletion() const { return m_markedForDeletion; }

void GameObject::MarkForDeletion() { m_markedForDeletion = true; }