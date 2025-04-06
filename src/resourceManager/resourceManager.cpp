#include "resourceManager.h"


std::unordered_map<std::string, Texture2D> ResourceManager::textures;


Texture2D ResourceManager::GetTexture(std::string_view path)
{
    auto it = textures.find(std::string(path));
    if (it == textures.end())
    {
        std::string key(path);
        it = textures.emplace(std::move(key), LoadTexture(path.data())).first;
    }
    return it->second;
}

Texture2D
ResourceManager::GetSubTexture(std::string_view path, int row, int col)
{
    const Texture2D &texture = GetTexture(path);

    if (texture.id == 0)
    {
        LOG_ERROR("Error: Texture not loaded!");
        return texture;
    }

    const Image image = LoadImageFromTexture(texture);
    if (!image.data)
    {
        LOG_ERROR("Failed to load image from texture");
        return texture;
    }

    constexpr float TILE_SIZE = 128.0f;
    const float x = static_cast<float>(col) * TILE_SIZE;
    const float y = static_cast<float>(row) * TILE_SIZE;

    if (x + TILE_SIZE > static_cast<float>(image.width) ||
        y + TILE_SIZE > static_cast<float>(image.height))
    {
        LOG_ERROR("Error: Coordinates");
        UnloadImage(image);
        return texture;
    }

    const Image subImage = ImageFromImage(image, {x, y, TILE_SIZE, TILE_SIZE});
    Texture2D subTexture = LoadTextureFromImage(subImage);

    UnloadImage(image);
    UnloadImage(subImage);

    return subTexture;
}
