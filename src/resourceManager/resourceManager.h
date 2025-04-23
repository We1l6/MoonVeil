#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H


#include "../loggerManager/loggerManager.h"
#include "raylib.h"
#include <string>
#include <unordered_map>


class ResourceManager
{
  public:
    static Texture2D GetTexture(std::string_view path);
    static Texture2D GetSubTexture(std::string_view path, int row, int col);

  private:
    static std::unordered_map<std::string, Texture2D> textures;
};


#endif // RESOURCEMANAGER_H