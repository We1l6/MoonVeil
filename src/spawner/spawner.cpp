#include "spawner.h"


Spawner::Spawner(std::shared_ptr<TileMap> &tileMap,
                 std::vector<std::shared_ptr<Entity>> &gameEntities,
                 std::vector<std::shared_ptr<Ability>> &gameObjects,
                 std::shared_ptr<Player> &player,
                 std::shared_ptr<GameTimer> &gameTimer)
    : m_tileMap(tileMap),
      m_gameEntities(gameEntities),
      m_gameObjects(gameObjects),
      m_player(player),
      m_gameTimer(gameTimer)
{
}


struct MonsterType
{
    std::function<std::shared_ptr<Entity>(const Vector2 &, int)> creator;
    int minDamage;
    int maxDamage;
    float minSpawnDelay;
    float maxSpawnDelay;
};

void Spawner::SetupForMap(int mapIndex)
{
    switch (mapIndex)
    {
    case 0:
        SetupMap0();
        break;
    case 1:
        SetupMap1();
        break;
    default:
        SetupMap0();
        break;
    }
}

void Spawner::SetupMap0()
{
    const float mapWidth = 3840.0f;
    const float mapHeight = 3840.0f;
    const float spawnOffset = 100.0f;


    const float maxSpawnTime = 300.0f; // 300.0

    auto getRandomSpawnPosition = [mapWidth, mapHeight,
                                   spawnOffset]() -> Vector2
    {
        bool leftSide = rand() % 2 == 0;
        float x = leftSide ? -spawnOffset : mapWidth + spawnOffset;
        float y = static_cast<float>(rand() % static_cast<int>(mapHeight));
        return Vector2{x, y};
    };

    auto getRandomDamage = [](int minDmg, int maxDmg) -> int
    { return minDmg + (rand() % (maxDmg - minDmg + 1)); };


    std::vector<MonsterType> monsterTypes = {
        {// SteelBound
         [this](const Vector2 &pos, int damage)
         {
             return std::make_shared<SteelBound>(m_tileMap, pos, m_gameObjects,
                                                 m_player, damage, 100);
         },
         15, 25, 3.0f, 4.0f},
        {// EyeGore
         [this](const Vector2 &pos, int damage)
         {
             return std::make_shared<EyeGore>(m_tileMap, pos, m_gameObjects,
                                              m_player, damage, 100);
         },
         10, 20, 3.0f, 7.0f},
        {// BloodClaws
         [this](const Vector2 &pos, int damage)
         {
             return std::make_shared<BloodClaws>(m_tileMap, pos, m_gameObjects,
                                                 m_player, damage, 100);
         },
         20, 30, 2.0f, 5.0f},
        {// FloralWretch
         [this](const Vector2 &pos, int damage)
         {
             return std::make_shared<FloralWretch>(
                 m_tileMap, pos, m_gameObjects, m_player, damage, 100);
         },
         5, 15, 5.0f, 10.0f},
        {// Slug
         [this](const Vector2 &pos, int damage)
         {
             return std::make_shared<Slug>(m_tileMap, pos, m_gameObjects,
                                           m_player, damage, 100);
         },
         8, 12, 5.0f, 9.0f}};

    float currentTime = 0.0f;
    while (currentTime < maxSpawnTime)
    {
        int monsterIndex = rand() % monsterTypes.size();
        const auto &monster = monsterTypes[monsterIndex];

        float spawnDelay = monster.minSpawnDelay +
                           (rand() / (float)RAND_MAX) *
                               (monster.maxSpawnDelay - monster.minSpawnDelay);
        currentTime += spawnDelay;

        if (currentTime > maxSpawnTime)
            break;

        m_gameTimer->AddTimedEvent(
            currentTime,
            [this, monster, getRandomSpawnPosition, getRandomDamage]()
            {
                Vector2 pos = getRandomSpawnPosition();
                int damage =
                    getRandomDamage(monster.minDamage, monster.maxDamage);
                m_gameEntities.push_back(monster.creator(pos, damage));
            });
    }

    m_gameTimer->AddTimedEvent(
        maxSpawnTime,
        [this, getRandomSpawnPosition, getRandomDamage]()
        {
            for (int i = 0; i < 10; ++i)
            {
                Vector2 pos = getRandomSpawnPosition();
                int damage = getRandomDamage(25, 40);
                bool strongMonster = rand() % 2 == 0;

                if (strongMonster)
                {
                    m_gameEntities.push_back(std::make_shared<BloodClaws>(
                        m_tileMap, pos, m_gameObjects, m_player, damage, 100));
                }
                else
                {
                    m_gameEntities.push_back(std::make_shared<SteelBound>(
                        m_tileMap, pos, m_gameObjects, m_player, damage, 100));
                }
            }
            m_allWavesCompleted = true;
        });
}

void Spawner::SetupMap1()
{
    const float mapWidth = 3840.0f;
    const float mapHeight = 1280.0f;
    const float spawnOffset = 100.0f;


    const float maxSpawnTime = 10.0f;

    auto getRandomSpawnPosition = [mapWidth, mapHeight,
                                   spawnOffset]() -> Vector2
    {
        bool leftSide = rand() % 2 == 0;
        float x = leftSide ? -spawnOffset : mapWidth + spawnOffset;
        float y = static_cast<float>(rand() % static_cast<int>(mapHeight));
        return Vector2{x, y};
    };

    auto getRandomDamage = [](int minDmg, int maxDmg) -> int
    { return minDmg + (rand() % (maxDmg - minDmg + 1)); };


    std::vector<MonsterType> monsterTypes = {
        {// SteelBound
         [this](const Vector2 &pos, int damage)
         {
             return std::make_shared<SteelBound>(m_tileMap, pos, m_gameObjects,
                                                 m_player, damage, 100);
         },
         15, 25, 3.0f, 4.0f},
        {// EyeGore
         [this](const Vector2 &pos, int damage)
         {
             return std::make_shared<EyeGore>(m_tileMap, pos, m_gameObjects,
                                              m_player, damage, 100);
         },
         10, 20, 3.0f, 7.0f},
        {// BloodClaws
         [this](const Vector2 &pos, int damage)
         {
             return std::make_shared<BloodClaws>(m_tileMap, pos, m_gameObjects,
                                                 m_player, damage, 100);
         },
         20, 30, 2.0f, 5.0f},
        {// FloralWretch
         [this](const Vector2 &pos, int damage)
         {
             return std::make_shared<FloralWretch>(
                 m_tileMap, pos, m_gameObjects, m_player, damage, 100);
         },
         5, 15, 5.0f, 10.0f},
        {// Slug
         [this](const Vector2 &pos, int damage)
         {
             return std::make_shared<Slug>(m_tileMap, pos, m_gameObjects,
                                           m_player, damage, 100);
         },
         8, 12, 5.0f, 9.0f}};

    float currentTime = 0.0f;
    while (currentTime < maxSpawnTime)
    {
        int monsterIndex = rand() % monsterTypes.size();
        const auto &monster = monsterTypes[monsterIndex];

        float spawnDelay = monster.minSpawnDelay +
                           (rand() / (float)RAND_MAX) *
                               (monster.maxSpawnDelay - monster.minSpawnDelay);
        currentTime += spawnDelay;

        if (currentTime > maxSpawnTime)
            break;

        m_gameTimer->AddTimedEvent(
            currentTime,
            [this, monster, getRandomSpawnPosition, getRandomDamage]()
            {
                Vector2 pos = getRandomSpawnPosition();
                int damage =
                    getRandomDamage(monster.minDamage, monster.maxDamage);
                m_gameEntities.push_back(monster.creator(pos, damage));
            });
    }

    m_gameTimer->AddTimedEvent(
        maxSpawnTime,
        [this, getRandomSpawnPosition, getRandomDamage]()
        {
            for (int i = 0; i < 10; ++i)
            {
                Vector2 pos = getRandomSpawnPosition();
                int damage = getRandomDamage(25, 40);
                bool strongMonster = rand() % 2 == 0;

                if (strongMonster)
                {
                    m_gameEntities.push_back(std::make_shared<BloodClaws>(
                        m_tileMap, pos, m_gameObjects, m_player, damage, 100));
                }
                else
                {
                    m_gameEntities.push_back(std::make_shared<SteelBound>(
                        m_tileMap, pos, m_gameObjects, m_player, damage, 100));
                }
            }
            m_allWavesCompleted = true;
        });
}
bool Spawner::AreAllWavesCompleted() const { return m_allWavesCompleted; }