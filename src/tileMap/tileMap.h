#ifndef TILEMAP_H
#define TILEMAP_H


#include "../resourceManager/resourceManager.h"
#include "raylib-tmx.h"
#include "raylib.h"
#include <cstring>
#include <string>
class TileMap
{
  public:
    TileMap(std::string mapPath);
    ~TileMap();
    [[nodiscard]] bool CheckCollisionWithObjects(const std::string &layer_name,
                                                 const Rectangle &object) const;
    tmx_layer *GetLayerByName(tmx_map *map, const std::string &name) const;
    void LoadTextures() const;
    void Draw() const;

    TileMap();

  private:
    tmx_map *map = nullptr;
};

#endif