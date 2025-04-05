#include "gameScene.h"
#include "raylib.h"


GameScene::GameScene(Game *game)
    : Scene(game),
      cameraController(std::make_unique<CameraController>(GetScreenWidth(),
                                                          GetScreenHeight()))
{
    player = std::make_shared<David>(std::move(tileMap), gameObjects);
}


void GameScene::HandleInput(float deltaTime) { player->HandleInput(deltaTime); }


void GameScene::UpdateEntities(float deltaTime)
{
    player->Update(deltaTime);
    for (const auto &entity : gameEntities)
    {
        entity->Update(deltaTime);
    }
    for (const auto &object : gameObjects)
    {
        object->Update(deltaTime);
    }
}


void GameScene::RenderEntities() const
{
    player->Draw();
    for (const auto &object : gameObjects)
    {
        object->Draw();
    }
    for (const auto &entity : gameEntities)
    {
        entity->Draw();
    }
}


void GameScene::Update(float deltaTime)
{
    cameraController->Update(deltaTime, player->GetPosition());
    CollisionSystem::CheckCollisions(gameEntities, gameObjects);
    UpdateEntities(deltaTime);
}


void GameScene::Render()
{
    BeginMode2D(cameraController->camera);
    tileMap.Draw();

    RenderEntities();
    EndMode2D();
    HUD::Draw(player);
}