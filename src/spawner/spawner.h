#ifndef SPAWNER_H
#define SPAWNER_H

#include "../gameObject/gameObject.h"
#include "../gameTimer/gameTimer.h"
#include "../player/player.h"
#include "../tileMap/tileMap.h"


#include "../characters/bloodClaws/bloodClaws.h"
#include "../characters/eyeGore/eyeGore.h"
#include "../characters/floralWretch/floralWretch.h"
#include "../characters/maidenMaw/maidenMaw.h"
#include "../characters/slug/slug.h"
#include "../characters/steelBound/steelBound.h"

class Spawner
{
    std::shared_ptr<TileMap> &m_tileMap;
    std::vector<std::shared_ptr<Entity>> &m_gameEntities;
    std::vector<std::shared_ptr<Ability>> &m_gameObjects;
    std::shared_ptr<Player> &m_player;

    std::shared_ptr<GameTimer> &m_gameTimer;

  public:
    Spawner(std::shared_ptr<TileMap> &tileMap,
            std::vector<std::shared_ptr<Entity>> &gameEntities,
            std::vector<std::shared_ptr<Ability>> &gameObjects,
            std::shared_ptr<Player> &player,
            std::shared_ptr<GameTimer> &gameTimer);

    void SetupForMap(int mapIndex);
    void SetupMap0();
    void SetupMap1();
};

#endif // SPAWNER_H