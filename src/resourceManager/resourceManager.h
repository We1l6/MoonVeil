#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H


#include "raylib.h"
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>


class ResourceManager
{
  public:
    static Texture2D GetTexture(const std::string &path);
    static std::string GetTileMap(const std::string &path);
    static Texture2D GetSubTexture(const std::string &path, int row, int col);

  private:
    static std::unordered_map<std::string, Texture2D> textures;
};


#endif // RESOURCEMANAGER_H