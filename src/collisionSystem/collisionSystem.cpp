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

    objects.erase(std::remove_if(objects.begin(), objects.end(),
                                 [](const std::shared_ptr<Ability> &obj)
                                 { return obj->IsMarkedForDeletion(); }),
                  objects.end());
}