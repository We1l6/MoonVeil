#ifndef DEATHSCENE_H
#define DEATHSCENE_H


#include "../../button/button.h"
class Game;
#include "../scene.h"
#include "raylib.h"


class DeathScene final : public Scene
{
  public:
    explicit DeathScene(Game *game)
        : Scene(game),
          m_backgroundTexture(LoadTexture("resources/DeathScene.png"))
    {
    }
    void HandleInput(float deltaTime) override;
    void Update(float deltaTime) override;
    void Render() override;

  private:
    Texture2D m_backgroundTexture;
    std::vector<Button> m_buttons;
};


#endif // DEATHSCENE_H