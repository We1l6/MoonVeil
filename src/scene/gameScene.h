#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "scene.h"
#include "../player/player.h"
#include "raylib.h"

class GameScene : public Scene {
private:
    Player player;

public:
    GameScene(Game* game) : Scene(game) {}
    void HandleInput() override;
    void Update() override;
    void Render() override;
};
#endif // GAMESCENE_H