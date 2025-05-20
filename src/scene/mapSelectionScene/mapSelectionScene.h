#pragma once

#ifndef MAPSELECTIONSCENE_H
#define MAPSELECTIONSCENE_H

#include "../../button/button.h"
#include "../../game/game.h"
#include "../scene.h"
#include "raylib.h"
#include <string>
#include <vector>

class MapSelectionScene final : public Scene
{
  public:
    explicit MapSelectionScene(Game *game) : Scene(game)
    {
        // Initialize available maps
        m_availableMaps = {"Map1", "Map2"};
        m_currentMapIndex = 0;

        float buttonWidth = 80;
        float buttonHeight = 40;
        float centerY = GetScreenHeight() / 2 - buttonHeight / 2;

        m_buttons.emplace_back("<",
                               Rectangle{60.0f, GetScreenHeight() - 50.0f,
                                         buttonWidth, buttonHeight},
                               Color{17, 27, 29, 255}, Color{57, 75, 76, 255},
                               WHITE);

        m_buttons.emplace_back(">",
                               Rectangle{160.0f, GetScreenHeight() - 50.0f,
                                         buttonWidth, buttonHeight},
                               Color{17, 27, 29, 255}, Color{57, 75, 76, 255},
                               WHITE);

        m_buttons.emplace_back("Select",
                               Rectangle{260.0f, GetScreenHeight() - 50.0f,
                                         buttonWidth, buttonHeight},
                               Color{17, 27, 29, 255}, Color{57, 75, 76, 255},
                               WHITE);
        m_buttons.emplace_back(
            "Back",
            Rectangle{GetScreenWidth() - buttonWidth - 10,
                      GetScreenHeight() - 50.0f, buttonWidth, buttonHeight},
            Color{17, 27, 29, 255}, Color{57, 75, 76, 255}, WHITE);
    }

    ~MapSelectionScene() { UnloadTexture(m_bgTexture); }

    void Update(float deltaTime) override;
    void Render() override;
    void HandleInput(float deltaTime) {};

    std::string GetSelectedMap() const
    {
        return m_availableMaps[m_currentMapIndex];
    }

  private:
    Texture2D m_bgTexture = LoadTexture("resources/chooser1.png");
    std::vector<Button> m_buttons;
    std::vector<std::string> m_availableMaps;
    int m_currentMapIndex;

    Texture2D textures[2] = {LoadTexture("resources/firstMap.png"),
                             LoadTexture("resources/secondMap.png")};
};

#endif // MAPSELECTIONSCENE_H