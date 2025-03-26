#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H


#include "../entity/entity.h"
#include "raylib.h"
#include <algorithm>
#include <memory>
#include <vector>


class CollisionSystem
{
  public:
    static void
    CheckCollisions(const std::vector<std::shared_ptr<Entity>> &entities,
                    std::vector<std::shared_ptr<Ability>> &objects);
};


#endif // COLLISIONSYSTEM_H