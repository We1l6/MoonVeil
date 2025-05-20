#ifndef CONGRATULATIONS_H
#define CONGRATULATIONS_H


#include "../../button/button.h"
class Game;
#include "../../settings/settings.h"
#include "../scene.h"
#include "raylib.h"

class CongratulationsScene final : public Scene
{
  public:
    explicit CongratulationsScene(Game *game, int mapIndex, int heroIndex)
        : Scene(game),
          m_backgroundTexture(LoadTexture("resources/congratulations.png")),
          m_mapIndex(mapIndex),
          m_heroIndex(heroIndex)
    {
        float buttonWidth = 80;
        float buttonHeight = 40;
        float centerY = GetScreenHeight() / 2 - buttonHeight / 2;

        m_buttons.emplace_back(
            "Again",
            Rectangle{GetScreenWidth() / 2.0f - 120, GetScreenHeight() - 250.0f,
                      buttonWidth, buttonHeight},
            Color{17, 27, 29, 255}, Color{57, 75, 76, 255}, WHITE);

        m_buttons.emplace_back(
            "Exit",
            Rectangle{GetScreenWidth() / 2.0f + 120, GetScreenHeight() - 250.0f,
                      buttonWidth, buttonHeight},
            Color{17, 27, 29, 255}, Color{57, 75, 76, 255}, WHITE);
    }
    void HandleInput(float deltaTime) override;
    void Update(float deltaTime) override;
    void Render() override;
    ~CongratulationsScene() {}

  private:
    int m_mapIndex;
    int m_heroIndex;
    Texture2D m_backgroundTexture;
    std::vector<Button> m_buttons;
};


#endif // CONGRATULATIONS_H