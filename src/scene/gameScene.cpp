#include "gameScene.h"
#include <memory>


GameScene::GameScene(Game *game)
    : Scene(game),
      cameraController(std::make_unique<CameraController>(GetScreenWidth(),
                                                          GetScreenHeight()))
{
    player = std::make_shared<David>(tileMap, gameObjects);

    gameEntities.push_back(std::make_shared<Entity>(
        ObjectAttributes{
            .hitbox = {.height = 128, .width = 128, .x = 600, .y = 600},
            .moveTextures =
                {
                    ResourceManager::GetSubTexture(
                        "resources/BloodclawsRUN.png", 0, 0),
                    ResourceManager::GetSubTexture(
                        "resources/BloodclawsRUN.png", 0, 1),
                    ResourceManager::GetSubTexture(
                        "resources/BloodclawsRUN.png", 0, 2),
                    ResourceManager::GetSubTexture(
                        "resources/BloodclawsRUN.png", 0, 3),
                    ResourceManager::GetSubTexture(
                        "resources/BloodclawsRUN.png", 0, 4),
                    ResourceManager::GetSubTexture(
                        "resources/BloodclawsRUN.png", 0, 5),
                },
            .texture = ResourceManager::GetSubTexture(
                "resources/BloodclawsRUN.png", 0, 0),
            .velocity = {0.0f, 0.0f}},
        FrameAtributes{.currentFrame = 0, .frameCounter = 0, .frameSpeed = 3},
        100, tileMap, gameObjects));
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