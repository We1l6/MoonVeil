#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H


#include "../../cameraController/cameraController.h"
#include "../../characters/david/david.h"
#include "../../collisionSystem/collisionSystem.h"
#include "../../gameTimer/gameTimer.h"
#include "../../interface/HUD/hud.h"
#include "../../player/player.h"
#include "../../scene/deathScene/deathScene.h"
#include "../../spawner/spawner.h"
#include "../menuScene/menuScene.h"
#include "../scene.h"
#include "raylib.h"
#include <execution>
#include <memory>
class GameScene final : public Scene
{
  private:
    std::shared_ptr<TileMap> tileMap;
    Music music;
    std::unique_ptr<CameraController> cameraController = nullptr;
    std::shared_ptr<Player> player = nullptr;
    std::vector<std::shared_ptr<Entity>> gameEntities;
    std::vector<std::shared_ptr<Ability>> gameObjects;
    std::shared_ptr<GameTimer> gameTimer;
    void HandleInput(float deltaTime) override;
    void UpdateEntities(float deltaTime);
    void RenderEntities() const;
    int m_mapIndex;
    int m_heroIndex;
    std::unique_ptr<Spawner> m_spawner = nullptr;

  public:
    explicit GameScene(Game *game, int mapIndex, int heroIndex);
    void Update(float deltaTime) override;
    void Render() override;
    ~GameScene()
    {
        UnloadMusicStream(music);
        CloseAudioDevice();
    }
};


#endif // GAMESCENE_H