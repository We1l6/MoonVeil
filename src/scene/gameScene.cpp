#include "gameScene.h"
#include "../characters/bloodClaws/bloodClaws.h"
#include "../characters/eyeGore/eyeGore.h"
#include "../characters/floralWretch/floralWretch.h"
#include "../characters/maidenMaw/maidenMaw.h"
#include "../characters/slug/slug.h"
#include "../characters/steelBound/steelBound.h"
#include <memory>

#include "../enemy/enemy.h"
#include "raylib.h"
GameScene::GameScene(Game *game)
    : Scene(game),
      cameraController(std::make_unique<CameraController>(GetScreenWidth(),
                                                          GetScreenHeight()))
{
    gameTimer.Start();
    player = std::make_shared<David>(tileMap, gameObjects);
    gameEntities.push_back(player);
    // gameEntities.push_back(std::make_shared<BloodClaws>(
    //     tileMap, Vector2{100.0f, 100.0f}, gameObjects, player));
    // gameEntities.push_back(std::make_shared<FloralWretch>(
    //     tileMap, Vector2{200.0f, 100.0f}, gameObjects, player));

    // gameEntities.push_back(std::make_shared<MaidenMaw>(
    //     tileMap, Vector2{200.0f, 500.0f}, gameObjects, player));

    // gameEntities.push_back(std::make_shared<Slug>(
    //     tileMap, Vector2{500.0f, 500.0f}, gameObjects, player));

    // gameEntities.push_back(std::make_shared<EyeGore>(
    //     tileMap, Vector2{800.0f, 500.0f}, gameObjects, player));
    // gameEntities.push_back(std::make_shared<SteelBound>(
    //     tileMap, Vector2{800.0f, 800.0f}, gameObjects, player));

    gameTimer.AddTimedEvent(
        3,
        [this]()
        {
            gameEntities.push_back(std::make_shared<FloralWretch>(
                tileMap, Vector2{200.0f, 100.0f}, gameObjects, player));
        });

    gameTimer.AddTimedEvent(
        6,
        [this]()
        {
            gameEntities.push_back(std::make_shared<FloralWretch>(
                tileMap, Vector2{200.0f, 100.0f}, gameObjects, player));
        });
    gameTimer.AddTimedEvent(
        9,
        [this]()
        {
            gameEntities.push_back(std::make_shared<EyeGore>(
                tileMap, Vector2{240.0f, 100.0f}, gameObjects, player));
        });
    gameTimer.AddTimedEvent(
        12,
        [this]()
        {
            gameEntities.push_back(std::make_shared<BloodClaws>(
                tileMap, Vector2{240.0f, 100.0f}, gameObjects, player));
        });
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
    player->Draw(cameraController->GetCamera());
    auto draw = [](const auto &renderable) { renderable->Draw(); };
    std::for_each(std::execution::par, gameEntities.begin(), gameEntities.end(),
                  draw);
    std::for_each(std::execution::par, gameObjects.begin(), gameObjects.end(),
                  draw);
}


void GameScene::Update(float deltaTime)
{
    gameTimer.Update(deltaTime);
    cameraController->Update(deltaTime, player->GetPosition());
    CollisionSystem::CheckCollisions(gameEntities, gameObjects);
    UpdateEntities(deltaTime);
}


void GameScene::Render()
{
    BeginMode2D(cameraController->GetCamera());
    tileMap.Draw();

    RenderEntities();
    EndMode2D();
    DrawText(gameTimer.GetFormattedTime().c_str(), 10, 200, 20, WHITE);
    HUD::Draw(player);
}