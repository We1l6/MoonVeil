#pragma once
#ifndef SCENE_H
#define SCENE_H
class Game;
#include "../imGuiManager/imGuiManager.h"
class Scene
{
  protected:
    Game *m_game = nullptr;

  public:
    Scene(Game *game) : m_game(game) {}
    virtual ~Scene() {}

    virtual void HandleInput(float deltaTime) = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;
};
#endif // SCENE_H