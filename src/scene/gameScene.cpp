#include "gameScene.h"

GameScene::GameScene(Game *game)
    : Scene(game),
      tileMap(ResourceManager::GetTileMap("resources/maps/first.txt")),
      cameraController(std::make_unique<CameraController>(GetScreenWidth(),
                                                          GetScreenHeight()))

{
    tileMap.LoadTextures();
    player = std::make_shared<David>(tileMap, gameObjects);
    ObjectAttributes attributes1 = {
        {0.0f, 0.0f},
        ResourceManager::GetTexture("resources/David.png"),
        {200.0f, 600.0f, 128.0f, 128.0f}};

    gameEntities.emplace_back(
        std::make_shared<Entity>(attributes1, 100, tileMap, gameObjects));
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