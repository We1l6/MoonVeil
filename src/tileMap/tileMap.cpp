#include "tilemap.h"
#include <iostream>
#include <algorithm> // Для std::max і std::min

Tilemap::Tilemap(const std::string& asciiMap) {
    size_t start = 0;
    size_t end = asciiMap.find('\n');
    while (end != std::string::npos) {
        std::string row = asciiMap.substr(start, end - start);
        std::vector<char> mapRow(row.begin(), row.end());
        map.push_back(mapRow);
        start = end + 1;
        end = asciiMap.find('\n', start);
    }

    if (start < asciiMap.size()) {
        std::string row = asciiMap.substr(start);
        std::vector<char> mapRow(row.begin(), row.end());
        map.push_back(mapRow);
    }

    // Встановлюємо розміри карти
    mapHeight = map.size();
    if (mapHeight > 0) {
        mapWidth = map[0].size();
    } else {
        mapWidth = 0;
    }

    // Перевірка розмірів
    if (mapHeight == 0 || mapWidth == 0) {
        std::cerr << "Error: Invalid map size! Map is empty." << std::endl;
        map.clear();
    }
}

Tilemap::~Tilemap() {
    UnloadTextures();
}

void Tilemap::LoadTextures() {
    tex_grass = LoadTexture("resources/grass.png");
    tex_wall = LoadTexture("resources/wall.png");
}

void Tilemap::Draw() {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            Vector2 pos = {(float)(x * tileSize), (float)(y * tileSize)};
            if (map[y][x] == '#') DrawTexture(tex_wall, pos.x, pos.y, WHITE);
            else DrawTexture(tex_grass, pos.x, pos.y, WHITE);
        }
    }
}

bool Tilemap::IsWalkable(int x, int y) const {
    if (x < 0 || x >= mapWidth || y < 0 || y >= mapHeight) return false;
    return map[y][x] != '#';
}

bool Tilemap::IsColliding(float x, float y, float width, float height) const {
    int leftTile = static_cast<int>(x / tileSize);
    int rightTile = static_cast<int>((x + width) / tileSize);
    int topTile = static_cast<int>(y / tileSize);
    int bottomTile = static_cast<int>((y + height) / tileSize);

    // Обмеження значень, щоб уникнути виходу за межі
    leftTile = std::max(0, leftTile);
    rightTile = std::min(mapWidth - 1, rightTile);
    topTile = std::max(0, topTile);
    bottomTile = std::min(mapHeight - 1, bottomTile);

    for (int ty = topTile; ty <= bottomTile; ty++) {
        for (int tx = leftTile; tx <= rightTile; tx++) {
            if (!IsWalkable(tx, ty)) {
                return true;
            }
        }
    }

    return false;
}

void Tilemap::UnloadTextures() {
    UnloadTexture(tex_grass);
    UnloadTexture(tex_wall);
}