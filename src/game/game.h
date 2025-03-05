#pragma once
#ifndef GAME_H
#define GAME_H
#include "../scene/scene.h"

class Game {
private:
    Scene* currentScene;
public:
    Game();
    ~Game();

    void Run();
    void ChangeScene(Scene* newScene);
};
#endif //GAME_H