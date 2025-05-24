#pragma once

#ifndef MAPSELECTIONSCENE_H
#define MAPSELECTIONSCENE_H

#include "../../button/button.h"
#include "../../game/game.h"
#include "../heroSelectionScene/heroSelectionScene.h"
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
        m_availableMaps = {
            {"Once, Alcastr was a great city-laboratory, \nwhere the kingdom's "
             "alchemists conducted their experiments \nin search of eternal "
             "life and absolute power. \nBut their pride led to catastrophe. "
             "\nOne of the experiments spiraled out of control, \nand within "
             "hours, a poisonous mist engulfed the city, \nturning its "
             "inhabitants into monsters \nand its walls into ruins soaked in "
             "alchemical filth. \n\nNow, Alcastr is a sinister arena \nwhere "
             "darkness and poison clash with fire and steel. \nThe air here is "
             "thick and bitter, \nand the ground is covered in a gray film of "
             "congealed reagents. \nThe shattered towers loom over the "
             "battlefield \nlike the skeletons of ancient giants, \nwhile "
             "underfoot, the shards of alchemical flasks \ncrunch like "
             "remnants of bygone experiments. \n"},
            "The scorched, towering walls of Mordheim Citadel \nrise above the "
            "burnt plains \nlike the gnashing teeth of a dead giant. \nOnce, "
            "this was an impregnable fortress of the kingdom, \nbut traitor "
            "alchemists opened its gates to the darkness— \nand now the "
            "Citadel has become a nest of the most horrific experiments. \nIts "
            "towers spew poisonous smoke, \nand in its dungeons, monsters are "
            "born \nthat no living man should ever lay eyes upon. \n\nNow, "
            "those who come here seek either \nto purge the corruption once "
            "and for all… \nor to seize its power for themselves. \nDavid, "
            "with his hatred for alchemy, \nand Galmar, whose flames can "
            "purify even this carrion, \nare but the first in a long line of "
            "madmen \nwho dared to storm these cursed walls. \n"};
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