#include "collisionSystem.h"

void CollisionSystem::CheckCollisions(
    const std::vector<std::shared_ptr<Entity>> &entities,
    std::vector<std::shared_ptr<Ability>> &objects)
{
    for (const auto &entity : entities)
    {
        if (!entity)
            continue;

        for (const auto &object : objects)
        {
            if (!object || object->IsMarkedForDeletion())
                continue;
            if (GameObject::CheckCollision(*entity, *object))
            {
                const ObjectType entityType = entity->GetObjectType();
                const ObjectType objectType = object->GetObjectType();

                if (entityType == ObjectType::Player &&
                    objectType == ObjectType::EnemyAttack)
                {
                    entity->TakeDamage(object->getDamage());
                    object->MarkForDeletion();
                }
                else if (entityType == ObjectType::Enemy &&
                         objectType == ObjectType::PlayerAttack)
                {
                    entity->TakeDamage(object->getDamage());
                    object->MarkForDeletion();
                }
            }
        }
        for (size_t i = 0; i < entities.size(); ++i)
        {
            const auto &entityA = entities[i];
            if (!entityA)
                continue;

            for (size_t j = i + 1; j < entities.size(); ++j)
            {
                const auto &entityB = entities[j];
                if (!entityB)
                    continue;

                if (GameObject::CheckCollision(*entityA, *entityB))
                {
                    const ObjectType typeA = entityA->GetObjectType();
                    const ObjectType typeB = entityB->GetObjectType();

                    if ((typeA == ObjectType::Player &&
                         typeB == ObjectType::Enemy) ||
                        (typeA == ObjectType::Enemy &&
                         typeB == ObjectType::Player))
                    {
                        auto player =
                            (typeA == ObjectType::Player) ? entityA : entityB;
                        player->TakeDamage(0.1);
                    }
                }
            }
        }
    }

    std::erase_if(objects,
                  [](const auto &obj) { return obj->IsMarkedForDeletion(); });
}