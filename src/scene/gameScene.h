#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "scene.h"
#include "../player/player.h"
#include "menuScene.h"
#include "raylib.h"
#include "../tileMap/tileMap.h"

class GameScene : public Scene {
private:
    Player player;

public:
    GameScene(Game* game) : Scene(game), player(tileMap), tileMap(ResourceManager::GetTileMap("resources/maps/first.txt")) {
        tileMap.LoadTextures();
        camera = { 0, 0};
        camera.target = (Vector2){ player.getPosition().x, player.getPosition().y};
        camera.offset = (Vector2){ GetScreenWidth()/2.0f-64, GetScreenHeight()/2.0f-64 };
        camera.rotation = 0.0f;

        camera.zoom = 1.0f;
    }
    void HandleInput(float deltaTime) override;
    void Update(float deltaTime) override;
    void Render() override;
    Tilemap tileMap;
    Camera2D camera;
};
#endif // GAMESCENE_H