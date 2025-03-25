#ifndef HUD_H
#define HUD_H

#include "../../player/player.h"
#include <memory>

class HUD {
    public:
        static void Draw(const std::shared_ptr<Player>& player);
    };

#endif // HUD_H
