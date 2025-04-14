#include "collisionSystem.h"

void CollisionSystem::CheckCollisions(
    const std::vector<std::shared_ptr<Entity>> &entities,
    std::vector<std::shared_ptr<Ability>> &objects)
{
    for (const auto &entity : entities)
    {
        for (const auto &object : objects)
        {
            if (GameObject::CheckCollision(*entity, *object))
            {
                entity->TakeDamage(object->getDamage());
                object->MarkForDeletion();
            }
        }
    }

    std::erase_if(objects,
                  [](const auto &obj) { return obj->IsMarkedForDeletion(); });
}