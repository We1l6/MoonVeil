#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H


#include "../cameraController/cameraController.h"
#include "../characters/david/david.h"
#include "../collisionSystem/collisionSystem.h"
#include "../interface/HUD/hud.h"
#include "../player/player.h"
#include "menuScene.h"
#include "raylib.h"
#include "scene.h"
#include <memory>

class GameScene final : public Scene
{
  private:
    TileMap tileMap;

    std::unique_ptr<CameraController> cameraController = nullptr;
    std::shared_ptr<Player> player = nullptr;
    std::vector<std::shared_ptr<Entity>> gameEntities;
    std::vector<std::shared_ptr<Ability>> gameObjects;

    void HandleInput(float deltaTime) override;
    void UpdateEntities(float deltaTime);
    void RenderEntities() const;

  public:
    explicit GameScene(Game *game);
    void Update(float deltaTime) override;
    void Render() override;
};


#endif // GAMESCENE_H