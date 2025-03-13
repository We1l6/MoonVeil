#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "../resourceManager/resourceManager.h"
#include <iostream>
#include "../tileMap/tileMap.h"
class Player {
private:
    Vector2 position;
    float speed;
    Texture2D david;
    const Tilemap& tilemap;
public:
    Player(const Tilemap& tilemap);
    void HandleInput(float deltaTime);
    void Update();
    void Draw();
    Vector2 getPosition();
};

#endif // PLAYER_H