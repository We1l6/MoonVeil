#include "gameObject.h"


GameObject::GameObject(ObjectAttributes objectAttributes,
                       FrameAtributes frameAtributes)
    : m_objectAttributes(std::move(objectAttributes)),
      m_frameAtributes(std::move(frameAtributes)),
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

ObjectType GameObject::GetObjectType() const
{
    return m_objectAttributes.objectType;
}

Vector2 GameObject::getSize() const
{
    return {m_objectAttributes.hitbox.width, m_objectAttributes.hitbox.height};
}

void GameObject::move(float dx, float dy)
{
    m_objectAttributes.hitbox.x += dx;
    m_objectAttributes.hitbox.y += dy;
}

bool GameObject::GetIsFacingLeft() const
{
    return m_objectAttributes.isFacingLeft;
}