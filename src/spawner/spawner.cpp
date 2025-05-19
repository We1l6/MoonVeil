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
    m_gameTimer->AddTimedEvent(
        3,
        [this]()
        {
            m_gameEntities.push_back(std::make_shared<BloodClaws>(
                m_tileMap, Vector2{0.0f, 0.0f}, m_gameObjects, m_player));
        });
    m_gameTimer->AddTimedEvent(
        12,
        [this]()
        {
            m_gameEntities.push_back(std::make_shared<FloralWretch>(
                m_tileMap, Vector2{200.0f, 100.0f}, m_gameObjects, m_player));
        });
}

void Spawner::SetupMap1()
{
    m_gameTimer->AddTimedEvent(
        3,
        [this]()
        {
            m_gameEntities.push_back(std::make_shared<SteelBound>(
                m_tileMap, Vector2{0.0f, 0.0f}, m_gameObjects, m_player));
        });
    m_gameTimer->AddTimedEvent(
        6,
        [this]()
        {
            m_gameEntities.push_back(std::make_shared<EyeGore>(
                m_tileMap, Vector2{440.0f, 500.0f}, m_gameObjects, m_player));
        });
}