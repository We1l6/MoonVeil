#pragma once


#ifndef HEROSELECTIONSCENE_H
#define HEROSELECTIONSCENE_H

#include "../../button/button.h"
#include "../../game/game.h"
#include "../mapSelectionScene/mapSelectionScene.h"
#include "../scene.h"
#include "raylib.h"


struct HeroSelection
{
    std::string name;
    Texture2D texturePath;
    Texture2D abilityPath;
    char *lore;
    char *abilities;
};

class HeroSelectionScene final : public Scene
{
  public:
    explicit HeroSelectionScene(Game *game, int mapIndex)
        : Scene(game),
          m_mapIndex(mapIndex)
    {
        // Initialize available maps
        m_availableMaps = {"Galmar", "David"};
        m_currentHeroIndex = 0;

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
    void Update(float deltaTime) override;
    void Render() override;
    void HandleInput(float deltaTime) {};

  private:
    Texture2D m_bgTexture = LoadTexture("resources/chooser2.png");
    std::vector<std::string> m_availableMaps;
    int m_currentHeroIndex;
    int m_mapIndex;
    // Texture2D textures[2] = {
    //     ResourceManager::GetSubTexture("resources/DavidIDLE.png", 0, 0),
    //     ResourceManager::GetSubTexture("resources/FloralWretchRUN.png", 0,
    //     0)};

    HeroSelection heroSelections[2] = {
        {"resources/DavidIDLE.png",
         ResourceManager::GetSubTexture("resources/DavidIDLE.png", 0, 0),
         ResourceManager::GetTexture("resources/DavidSpells.png"),
         {"Character Lore: David"
          "\nBackground:\nDavid was once a simple lumberjack living on\n"
          "the edge of the kingdom. His village bordered an ancient forest,\n"
          "rumored to be cursed—but David never believed in fairy tales. That\n"
          "is, until the day he stumbled upon alchemists conducting twisted\n"
          "experiments deep in the woods. They turned the trees into rotting\n"
          "husks and filled the air with toxic fumes. David survived only by\n"
          "snatching one of their  purifying plant\n"
          " canisters and strapping it to his back. Now, he breathes through "
          "a\n"
          "tube, his lungs unable to tolerate normal\n"
          "air.\n\nMotivation:\nDavid is convinced that alchemists and\n"
          "monsters are two sides of the same coin. Now, he roams castles and\n"
          "ruins—places where their labs fester—burning away every trace of\n"
          "their corruption. His axe cuts down flesh, and his acid bombs\n"
          "dissolve the remnants of their work. He seeks no gold or glory—only "
          "a\n"
          "world cleansed of their poison.\n"},
         {"Attack: 20\nHealth: 100\nSpeed: 155\n\nFirst Spell -> Acid "
          "Bottle\n-damage: 30\n-lifetime: 5\n-cooldown: 10\n\nSecond Spell "
          "-> Dash\n-range: 75\n-cooldown: 5\n\nThird Spell -> Poisonous "
          "Gas\n-damage: 10\n-lifetime: 3\n-cooldown: 10\n"
          "Every Level Up -> +5% Attack Damage\n"}},
        {"resources/FloralWretchRUN.png",
         ResourceManager::GetSubTexture("resources/GalmarIDLE.png", 0, 0),
         ResourceManager::GetTexture("resources/GalmarSpells.png"),
         {"Galmar was once a proud knight of the royal guard,\nsworn to "
          "protect "
          "the\n"
          "kingdom from external threats. However, during a brutal siege, his "
          "fortress\n"
          "was overrun by alchemical monstrosities—creatures twisted by foul "
          "experiments.\n"
          "Trapped in the burning ruins, Galmar should have perished, but the "
          "flames themselves\n"
          "seemed to spare him. When he awoke, his armor was scorched black, "
          "and embers\n"
          "pulsed beneath his skin. The fire had chosen him."
          "/n"
          "Now, he wields flame as a\nweapon and a shield, his greatsword "
          "glowing white-hot\n"
          "with every swing. The same alchemical corruption that ravages the "
          "land festers\n in his veins,\n"
          "but where others rot, he burns. The heat keeps the decay at bay, "
          "though\n it consumes him slowly."
          "\nHe knows his time is limited—but until his final ember fades, he "
          "will hunt those who\npoison the world."},
         {"Attack: 20\nHealth: 100\nSpeed: 150\n\nFirst Spell -> FireBall"
          "\n-damage: 30\n-lifetime: 5\n-cooldown: 8\n\nSecond Spell "
          "-> Dash\n-range: 65\n-cooldown: 5\n\nThird Spell -> Fire "
          "Storm\n-damage: 15\n-lifetime: 3\n-cooldown: 10\n"
          "Every Level Up -> +5% FireBall Damage\n"}},
    };

    std::vector<Button> m_buttons;
};


#endif // HEROSELECTIONSCENE_H