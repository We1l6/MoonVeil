#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H


#include "../entity/entity.h"
#include "raylib.h"
#include <algorithm>
#include <memory>
#include <vector>

class CollisionSystem
{
  private:
    static void
    HandleEntityEntityCollision(const std::shared_ptr<Entity> &entityA,
                                const std::shared_ptr<Entity> &entityB);
    static void
    HandleAbilityEntityCollision(const std::shared_ptr<Entity> &entity,
                                 const std::shared_ptr<Ability> &object);

  public:
    static void
    CheckCollisions(const std::vector<std::shared_ptr<Entity>> &entities,
                    std::vector<std::shared_ptr<Ability>> &objects);
    static void PushEntitiesApart(const std::shared_ptr<Entity> &entityA,
                                  const std::shared_ptr<Entity> &entityB);
};


#endif // COLLISIONSYSTEM_H