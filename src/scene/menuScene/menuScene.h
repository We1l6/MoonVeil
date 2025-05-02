#pragma once


#ifndef MENUSCENE_H
#define MENUSCENE_H
#include "../../settings/settings.h"

#include "../../button/button.h"
#include "../../game/game.h"
#include "../gameScene/gameScene.h"
#include "../scene.h"
#include "raylib.h"

class MenuScene final : public Scene
{
  public:
    explicit MenuScene(Game *game) : Scene(game)
    {
        float buttonWidth = 200;
        float buttonHeight = 40;
        float startY = GetScreenHeight() / 2 - buttonHeight;

        m_buttons.emplace_back("Start",
                               Rectangle{GetScreenWidth() / 2 - buttonWidth / 2,
                                         startY, buttonWidth, buttonHeight},
                               Color{17, 27, 29, 255}, Color{57, 75, 76, 255},
                               WHITE);

        m_buttons.emplace_back(
            "Settings",
            Rectangle{GetScreenWidth() / 2 - buttonWidth / 2,
                      startY + buttonHeight + 10, buttonWidth, buttonHeight},
            Color{17, 27, 29, 255}, Color{57, 75, 76, 255}, WHITE);

        m_buttons.emplace_back("Exit",
                               Rectangle{GetScreenWidth() / 2 - buttonWidth / 2,
                                         startY + 2 * (buttonHeight + 10),
                                         buttonWidth, buttonHeight},
                               Color{17, 27, 29, 255}, Color{57, 75, 76, 255},
                               WHITE);
        SettingsGlobal::LoadInputSettings();
    }
    void HandleInput(float deltaTime) override;
    void Update(float deltaTime) override;
    void Render() override;

  private:
    Texture2D m_bgTexture = LoadTexture("resources/MenuScene.png");
    std::vector<Button> m_buttons;
};


#endif // MENUSCENE_H