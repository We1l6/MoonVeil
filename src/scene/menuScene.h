#pragma once
#ifndef MENUSCENE_H
#define MENUSCENE_H
#include "../game/game.h"
#include "gameScene.h"
#include "raylib.h"
#include "scene.h"
class MenuScene : public Scene
{
  public:
    explicit MenuScene(Game *game) : Scene(game) {}
    void HandleInput(float deltaTime) override;
    void Update(float deltaTime) override;
    void Render() override;
};
#endif // MENUSCENE_H