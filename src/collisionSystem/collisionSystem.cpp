#include "collisionSystem.h"

void CollisionSystem::CheckCollisions(
    const std::vector<std::shared_ptr<Entity>> &entities,
    std::vector<std::shared_ptr<Ability>> &objects)
{
    // Phase 1: Entity <-> Ability
    for (const auto &entity : entities)
    {
        if (!entity || entity->IsMarkedForDeletion())
            continue;

        for (const auto &object : objects)
        {
            if (!object || object->IsMarkedForDeletion())
                continue;

            if (GameObject::CheckCollision(*entity, *object))
            {
                HandleAbilityEntityCollision(entity, object);
            }
        }
    }

    // Phase 2: Entity <-> Entity
    for (size_t i = 0; i < entities.size(); ++i)
    {
        const auto &entityA = entities[i];
        if (!entityA || entityA->IsMarkedForDeletion())
            continue;

        for (size_t j = i + 1; j < entities.size(); ++j)
        {
            const auto &entityB = entities[j];
            if (!entityB || entityB->IsMarkedForDeletion())
                continue;

            if (GameObject::CheckCollision(*entityA, *entityB))
            {
                HandleEntityEntityCollision(entityA, entityB);
            }
        }
    }
}

void CollisionSystem::HandleAbilityEntityCollision(
    const std::shared_ptr<Entity> &entity,
    const std::shared_ptr<Ability> &object)
{
    const auto entityType = entity->GetObjectType();
    const auto objectType = object->GetObjectType();

    if (entityType == ObjectType::Player &&
        objectType == ObjectType::EnemyAttack)
    {
        entity->TakeDamage(object->getDamage(), object->GetIsFacingLeft());
        object->MarkForDeletion();
    }
    else if (entityType == ObjectType::Enemy &&
             objectType == ObjectType::PlayerAttack)
    {
        entity->TakeDamage(object->getDamage(), object->GetIsFacingLeft());

        if (object->getAbilityType() == AbilityType::DestroyOnHit)
        {
            object->MarkForDeletion();
        }
    }
}

void CollisionSystem::HandleEntityEntityCollision(
    const std::shared_ptr<Entity> &entityA,
    const std::shared_ptr<Entity> &entityB)
{
    const auto typeA = entityA->GetObjectType();
    const auto typeB = entityB->GetObjectType();

    if ((typeA == ObjectType::Player && typeB == ObjectType::Enemy) ||
        (typeA == ObjectType::Enemy && typeB == ObjectType::Player))
    {
        auto player = (typeA == ObjectType::Player) ? entityA : entityB;
        auto enemy = (typeA == ObjectType::Enemy) ? entityA : entityB;

        player->TakeDamage(enemy->GetAttackDamage(), enemy->GetIsFacingLeft());
    }

    PushEntitiesApart(entityA, entityB);
}


void CollisionSystem::PushEntitiesApart(const std::shared_ptr<Entity> &entityA,
                                        const std::shared_ptr<Entity> &entityB)
{
    const auto &posA = entityA->GetPosition();
    const auto &posB = entityB->GetPosition();
    const auto &sizeA = entityA->getSize();
    const auto &sizeB = entityB->getSize();

    float dx = (posB.x + sizeB.x / 2) - (posA.x + sizeA.x / 2);
    float dy = (posB.y + sizeB.y / 2) - (posA.y + sizeA.y / 2);

    float distance = std::sqrt(dx * dx + dy * dy);
    if (distance == 0)
        distance = 0.001f;

    dx /= distance;
    dy /= distance;

    float penetration = (sizeA.x / 2 + sizeB.x / 2) - distance;
    if (penetration < 0)
        penetration = 0;

    const float pushForce = 0.5f;

    float pushX = dx * penetration * pushForce;
    float pushY = dy * penetration * pushForce;

    if (entityA->CanMoveTo(posA.x - pushX, posA.y - pushY))
        entityA->move(-pushX, -pushY);
    if (entityB->CanMoveTo(posB.x + pushX, posB.y + pushY))
        entityB->move(pushX, pushY);
}