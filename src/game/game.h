#pragma once
#include "imgui_internal.h"
#ifndef GAME_H
#define GAME_H
class Game;


#include "../scene/menuScene.h"
#include "../scene/scene.h"
#include "raylib.h"
#include <string_view>


class Game
{
  private:
    Scene *currentScene;


  public:
    Game();
    ~Game();

    void Run();
    void ChangeScene(Scene *newScene);
};


#endif // GAME_H