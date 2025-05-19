#ifndef DEATHSCENE_H
#define DEATHSCENE_H


#include "../../button/button.h"
class Game;
#include "../../settings/settings.h"
#include "../scene.h"
#include "raylib.h"

class DeathScene final : public Scene
{
  public:
    explicit DeathScene(Game *game, int mapIndex, int heroIndex)
        : Scene(game),
          m_backgroundTexture(LoadTexture("resources/DeathScene.png")),
          m_mapIndex(mapIndex),
          m_heroIndex(heroIndex)
    {
        float buttonWidth = 80;
        float buttonHeight = 40;
        float centerY = GetScreenHeight() / 2 - buttonHeight / 2;

        m_buttons.emplace_back(
            "YES",
            Rectangle{GetScreenWidth() / 3.0f - 60, GetScreenHeight() - 550.0f,
                      buttonWidth, buttonHeight},
            Color{17, 27, 29, 255}, Color{57, 75, 76, 255}, WHITE);

        m_buttons.emplace_back(
            "NO",
            Rectangle{GetScreenWidth() / 3.0f + 60, GetScreenHeight() - 550.0f,
                      buttonWidth, buttonHeight},
            Color{17, 27, 29, 255}, Color{57, 75, 76, 255}, WHITE);
    }
    void HandleInput(float deltaTime) override;
    void Update(float deltaTime) override;
    void Render() override;
    ~DeathScene() {}

  private:
    int m_mapIndex;
    int m_heroIndex;
    Texture2D m_backgroundTexture;
    std::vector<Button> m_buttons;
};


#endif // DEATHSCENE_H