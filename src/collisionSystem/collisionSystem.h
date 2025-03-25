#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "raylib.h"
#include <vector>
#include <memory>
#include "../entity/entity.h"
#include <algorithm>

class CollisionSystem {
    public:
        static void CheckCollisions(const std::vector<std::shared_ptr<Entity>>& entities,
                                    std::vector<std::shared_ptr<Ability>>& objects);
    };

#endif //COLLISIONSYSTEM_H