#ifndef TILEMAP_H
#define TILEMAP_H


#include "../resourceManager/resourceManager.h"
#include "raylib.h"
#include <string>
#include <vector>


class TileMap
{
  public:
    explicit TileMap(const std::string &asciiMap);
    ~TileMap();

    void LoadTextures();
    void Draw();
    bool IsWalkable(int x, int y) const;
    bool IsColliding(float x, float y, float width, float height) const;
    void UnloadTextures();

  private:
    std::vector<std::vector<char>> map;
    Texture2D tex_grass;
    Texture2D tex_wall;
    Texture2D tex_water;
    Texture2D tex_yellow;
    Texture2D tex_purple;
    Texture2D tex_snow[9];
    int mapWidth;
    int mapHeight;
    const int tileSize = 128;
};


#endif