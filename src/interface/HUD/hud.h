#ifndef HUD_H
#define HUD_H


#include "../../player/player.h"
#include <memory>


class HUD
{
  private:
    static void DrawSpellCooldown(float cooldown,
                                  int spellX,
                                  int spellY,
                                  Texture2D texture);

  public:
    static void Draw(const std::shared_ptr<Player> &player);
};


#endif // HUD_H
