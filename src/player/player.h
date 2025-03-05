#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

class Player {
private:
    Vector2 position;
    float speed;
public:
    Player();
    void HandleInput();
    void Update();
    void Draw();
};

#endif // PLAYER_H