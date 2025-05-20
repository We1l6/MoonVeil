#ifndef SETTINGSSCENE_H
#define SETTINGSSCENE_H


#include "../../button/button.h"

class Game;
#include "../gameScene/gameScene.h"
#include "../scene.h"
#include "raylib.h"


#include "../../settings/settings.h"

namespace Settings
{

constexpr int TITLE_FONT_SIZE = 40;
constexpr int LABEL_FONT_SIZE = 30;
constexpr int CONTROL_FONT_SIZE = 20;

constexpr float SLIDER_WIDTH = 400;
constexpr float SLIDER_HEIGHT = 20;

constexpr int START_X = 40;
constexpr int START_Y = 40;

constexpr int SLIDER_Y = 140;
constexpr int CONTROLS_START_Y = 200;
constexpr int CONTROL_SPACING = 40;
} // namespace Settings

class SettingsScene final : public Scene
{
  public:
    explicit SettingsScene(Game *game)
        : Scene(game),
          m_backgroundTexture(LoadTexture("resources/SettingsScene.png"))
    {
    }
    void HandleInput(float deltaTime) override;
    void Update(float deltaTime) override;
    void Render() override;

  private:
    Texture2D m_backgroundTexture;
    int *currentlyChangingKey = nullptr;
};


#endif // SETTINGSSCENE_H