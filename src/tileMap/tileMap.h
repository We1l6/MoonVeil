#ifndef TILEMAP_H
#define TILEMAP_H


#include "../resourceManager/resourceManager.h"
#include "raylib-tmx.h"
#include "raylib.h"
#include <cstring>

class TileMap
{
  public:
    TileMap();
    ~TileMap();
    bool CheckCollisionWithObjects(const std::string &layer_name,
                                   const Rectangle &object) const;
    tmx_layer *GetLayerByName(tmx_map *map, const std::string &name) const;
    void LoadTextures() const;
    void Draw() const;


  private:
    tmx_map *map = nullptr;
};

#endif