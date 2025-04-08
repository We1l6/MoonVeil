#include "gameScene.h"


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

    auto update = [deltaTime](const auto &entity)
    {
        if (entity)
        {
            entity->Update(deltaTime);
        }
    };

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
    HUD::Draw(player);
}