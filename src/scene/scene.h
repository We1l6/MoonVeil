#pragma once
#ifndef SCENE_H
#define SCENE_H
class Game;

class Scene
{
  protected:
    Game *m_game;

  public:
    Scene(Game *game) : m_game(game) {}
    virtual ~Scene() {}

    virtual void HandleInput(float deltaTime) = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;
};
#endif // SCENE_H