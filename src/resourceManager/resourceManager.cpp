#include "resourceManager.h"

std::unordered_map<std::string, Texture2D> ResourceManager::textures;

Texture2D ResourceManager::GetTexture(const std::string &path)
{
    if (textures.find(path) == textures.end())
    {
        textures[path] = LoadTexture(path.c_str());
    }
    return textures[path];
}

Texture2D
ResourceManager::GetSubTexture(const std::string &path, int row, int col)
{
    Texture2D texture = GetTexture(path);

    if (texture.id == 0)
    {
        TraceLog(LOG_ERROR, "Error: Texture not loaded!");
        return texture;
    }

    Image image = LoadImageFromTexture(texture);

    float x = col * 128;
    float y = row * 128;

    if (x + 128 > image.width || y + 128 > image.height)
    {
        TraceLog(LOG_ERROR, "Error: coordinates are outside the texture!");
        UnloadImage(image);
        return texture;
    }

    Image subImage = ImageFromImage(image, {x, y, 128, 128});

    Texture2D subTexture = LoadTextureFromImage(subImage);

    UnloadImage(image);
    UnloadImage(subImage);

    return subTexture;
}

std::string ResourceManager::GetTileMap(const std::string &path)
{
    std::ifstream file(path);

    if (file.is_open())
    {
        std::stringstream buffer;
        std::string line;

        while (std::getline(file, line))
        {
            buffer << line << "\n";
        }

        file.close();

        return buffer.str();
    }
    else
    {
    }
    return "";
}