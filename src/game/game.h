#pragma once
#ifndef GAME_H
#define GAME_H
class Game;

#include "../scene/menuScene.h"
#include "../scene/scene.h"
#include "raylib.h"
class Game
{
  private:
    Scene *currentScene;

  public:
    Game();
    ~Game();

    void Run() const;
    void ChangeScene(Scene *newScene);
};
#endif // GAME_H