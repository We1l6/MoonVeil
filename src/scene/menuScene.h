#pragma once
#ifndef MENUSCENE_H
#define MENUSCENE_H
#include "scene.h"
#include "raylib.h"
#include "../game/game.h"
#include "gameScene.h"
class MenuScene : public Scene {
public:
    MenuScene(Game* game) : Scene(game) {}
    void HandleInput(float deltaTime) override;
    void Update(float deltaTime) override;
    void Render() override;
};
#endif // MENUSCENE_H