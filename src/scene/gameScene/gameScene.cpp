#include "gameScene.h"

#include "../../characters/galmar/galmar.h"

#include "../../enemy/enemy.h"
#include "raylib.h"
#include <filesystem>
#include <memory>
GameScene::GameScene(Game *game, int mapIndex, int heroIndex)
    : Scene(game),
      cameraController(std::make_unique<CameraController>(GetScreenWidth(),
                                                          GetScreenHeight())),
      m_mapIndex(mapIndex),
      m_heroIndex(heroIndex)
{
    InitAudioDevice();
    try
    {
        std::filesystem::path mapPath;
        if (mapIndex == 0)
        {
            mapPath = "resources/dangeon.tmx";
            music = LoadMusicStream("resources/sound/GenesisRetakeLight.mp3");
        }
        else if (mapIndex == 1)
        {
            mapPath = "resources/sawerage.tmx";
            music = LoadMusicStream("resources/sound/RiverOfDespair.mp3");
        }

        tileMap = std::make_shared<TileMap>(mapPath.string());

        if (heroIndex == 1)
        {
            player = std::make_shared<Galmar>(tileMap, gameObjects);
        }
        else
        {
            player = std::make_shared<David>(tileMap, gameObjects);
        }
        gameEntities.push_back(player);
        gameTimer = std::make_shared<GameTimer>();
        gameTimer->Start();
        m_spawner = std::make_unique<Spawner>(tileMap, gameEntities,
                                              gameObjects, player, gameTimer);
        m_spawner->SetupForMap(1);
        SetMusicVolume(music, SettingsGlobal::g_volume / 100.0f);
        PlayMusicStream(music);
    }
    catch (const std::exception &e)
    {
        TraceLog(LOG_ERROR, "Failed to initialize GameScene: %s", e.what());
    }
}


void GameScene::HandleInput(float deltaTime) { player->HandleInput(deltaTime); }


void GameScene::UpdateEntities(float deltaTime)
{
    player->Update(deltaTime);

    auto update = [deltaTime](const auto &entity)
    {
        if (entity)
        {
            entity->Update(deltaTime);
        }
    };

    std::erase_if(gameObjects,
                  [](const auto &obj) { return obj->IsMarkedForDeletion(); });

    std::erase_if(gameEntities,
                  [](const auto &obj) { return obj->IsMarkedForDeletion(); });


    std::for_each(std::execution::par, gameEntities.begin(), gameEntities.end(),
                  update);
    std::for_each(std::execution::par, gameObjects.begin(), gameObjects.end(),
                  update);
}


void GameScene::RenderEntities() const
{
    auto draw = [](const auto &renderable) { renderable->Draw(); };
    std::for_each(std::execution::par, gameObjects.begin(), gameObjects.end(),
                  draw);
    std::for_each(std::execution::par, gameEntities.begin(), gameEntities.end(),
                  draw);
}


void GameScene::Update(float deltaTime)
{
    UpdateMusicStream(music);
    std::cout << "GameObjects size: " << gameObjects.size() << "\n";
    std::cout << "GameEntities size: " << gameEntities.size() << "\n";

    if (player->IsMarkedForDeletion())
    {
        m_game->ChangeScene(new DeathScene(m_game, m_mapIndex, m_heroIndex));
        return;
    }
    gameTimer->Update(deltaTime);
    cameraController->Update(deltaTime, player->GetPosition());
    CollisionSystem::CheckCollisions(gameEntities, gameObjects);
    UpdateEntities(deltaTime);
}


void GameScene::Render()
{
    BeginMode2D(cameraController->GetCamera());
    tileMap->Draw();

    RenderEntities();
    EndMode2D();
    DrawText(gameTimer->GetFormattedTime().c_str(), 10, 200, 20, WHITE);
    HUD::Draw(player);
}