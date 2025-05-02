#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H


#include "../../cameraController/cameraController.h"
#include "../../characters/david/david.h"
#include "../../collisionSystem/collisionSystem.h"
#include "../../interface/HUD/hud.h"
#include "../../player/player.h"
#include "../../scene/deathScene/deathScene.h"
#include "../menuScene/menuScene.h"
#include "../scene.h"
#include "raylib.h"
#include <execution>
#include <memory>

#include "../../gameTimer/gameTimer.h"
class GameScene final : public Scene
{
  private:
    TileMap tileMap;

    std::unique_ptr<CameraController> cameraController = nullptr;
    std::shared_ptr<Player> player = nullptr;
    std::vector<std::shared_ptr<Entity>> gameEntities;
    std::vector<std::shared_ptr<Ability>> gameObjects;
    GameTimer gameTimer;
    void HandleInput(float deltaTime) override;
    void UpdateEntities(float deltaTime);
    void RenderEntities() const;

  public:
    explicit GameScene(Game *game);
    void Update(float deltaTime) override;
    void Render() override;
};


#endif // GAMESCENE_H