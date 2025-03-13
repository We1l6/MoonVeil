#include "resourceManager.h"

std::unordered_map<std::string, Texture2D> ResourceManager::textures;

Texture2D ResourceManager::GetTexture(const std::string& path) {
    if (textures.find(path) == textures.end()) {
        textures[path] = LoadTexture(path.c_str());
    }
    return textures[path];
}

Texture2D ResourceManager::GetSubTexture(const std::string& path, int row, int col) {
    Texture2D texture = GetTexture(path);

    if (texture.id == 0) {
        TraceLog(LOG_ERROR, "Ошибка: текстура не загружена!");
        return texture;
    }

    // Загружаем изображение из текстуры
    Image image = LoadImageFromTexture(texture);

    // Вычисляем координаты для вырезания
    float x = col * 128;
    float y = row * 128;

    // Проверяем, что координаты находятся в пределах изображения
    if (x + 128 > image.width || y + 128 > image.height) {
        TraceLog(LOG_ERROR, "Ошибка: координаты выходят за пределы текстуры!");
        UnloadImage(image);
        return texture;
    }

    // Вырезаем часть изображения
    Image subImage = ImageFromImage(image, { x, y, 128, 128 });

    // Создаем текстуру из вырезанного изображения
    Texture2D subTexture = LoadTextureFromImage(subImage);

    // Освобождаем ресурсы
    UnloadImage(image);
    UnloadImage(subImage);

    return subTexture;
}

std::string ResourceManager::GetTileMap(const std::string& path) {
    std::ifstream file(path);

    if (file.is_open()) {
        std::stringstream buffer;
        std::string line;

        while (std::getline(file, line)) {
            buffer << line << "\n"; 
        }

        file.close(); 

        return buffer.str(); 
    } 
    return "";
}