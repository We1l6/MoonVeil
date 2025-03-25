#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "scene.h"
#include "../player/player.h"
#include "menuScene.h"
#include "raylib.h"
#include "../tileMap/tileMap.h"
#include "../characters/david/david.h"
#include "../cameraController/cameraController.h"
#include "../collisionSystem/collisionSystem.h"
#include "../interface/HUD/hud.h"
#include <memory>

class GameScene : public Scene {
    private:
        TileMap tileMap;
        std::unique_ptr<CameraController> cameraController;
        std::shared_ptr<Player> player;
        std::vector<std::shared_ptr<Entity>> gameEntities;
        std::vector<std::shared_ptr<Ability>> gameObjects;

        void HandleInput(float deltaTime) override;
        void UpdateEntities(float deltaTime);
        void RenderEntities() const;
    
    public:
    explicit GameScene(Game* game);
        void Update(float deltaTime) override;
        void Render() override;
    };

#endif // GAMESCENE_H