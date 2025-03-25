#include "tileMap.h"
#include <iostream>
#include <algorithm> // Для std::max і std::min

TileMap::TileMap(const std::string& asciiMap) {
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

TileMap::~TileMap() {
    UnloadTextures();
}

void TileMap::LoadTextures() {
    // Загружаем текстуры снега (3x3 тайла)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Texture2D texture = ResourceManager::GetSubTexture("resources/snow.png", i, j);
            if (texture.id == 0) {
                TraceLog(LOG_ERROR, "Не удалось загрузить текстуру snow.png для (%d, %d)", i, j);
            }
            tex_snow[i * 3 + j] = texture;
        }
    }

    // Загружаем остальные текстуры
    tex_grass = ResourceManager::GetTexture("resources/grass.png");
    tex_wall = ResourceManager::GetTexture("resources/wall.png");
    tex_water = ResourceManager::GetTexture("resources/water.png");
    tex_yellow = ResourceManager::GetTexture("resources/yellow.png");
    tex_purple = ResourceManager::GetTexture("resources/purple.png");

    // Проверяем загрузку остальных текстур
    if (tex_grass.id == 0) TraceLog(LOG_ERROR, "Не удалось загрузить текстуру grass.png");
    if (tex_wall.id == 0) TraceLog(LOG_ERROR, "Не удалось загрузить текстуру wall.png");
    if (tex_water.id == 0) TraceLog(LOG_ERROR, "Не удалось загрузить текстуру water.png");
    if (tex_yellow.id == 0) TraceLog(LOG_ERROR, "Не удалось загрузить текстуру yellow.png");
    if (tex_purple.id == 0) TraceLog(LOG_ERROR, "Не удалось загрузить текстуру purple.png");
}

void TileMap::Draw() {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            Vector2 pos = {(float)(x * tileSize), (float)(y * tileSize)};
            switch (map[y][x]) {
                case '#': DrawTexture(tex_wall, pos.x, pos.y, WHITE); break;
                case 'w': DrawTexture(tex_water, pos.x, pos.y, WHITE); break;
                case 'y': DrawTexture(tex_yellow, pos.x, pos.y, WHITE); break;
                case 'p': DrawTexture(tex_purple, pos.x, pos.y, WHITE); break;
                case 's': DrawTexture(tex_snow[0], pos.x, pos.y, WHITE); break;
                case '1': DrawTexture(tex_snow[1], pos.x, pos.y, WHITE); break;
                case '2': DrawTexture(tex_snow[2], pos.x, pos.y, WHITE); break;
                case '3': DrawTexture(tex_snow[3], pos.x, pos.y, WHITE); break;
                case '4': DrawTexture(tex_snow[4], pos.x, pos.y, WHITE); break;
                case '5': DrawTexture(tex_snow[5], pos.x, pos.y, WHITE); break;
                case '6': DrawTexture(tex_snow[6], pos.x, pos.y, WHITE); break;
                case '7': DrawTexture(tex_snow[7], pos.x, pos.y, WHITE); break;
                case '8': DrawTexture(tex_snow[8], pos.x, pos.y, WHITE); break;
                default:  DrawTexture(tex_grass, pos.x, pos.y, WHITE); break;
            }
        }
    }
}
bool TileMap::IsWalkable(int x, int y) const {
    if (x < 0 || x >= mapWidth || y < 0 || y >= mapHeight) return false;
    return map[y][x] != '#' && map[y][x] != 'w';
}

bool TileMap::IsColliding(float x, float y, float width, float height) const {
    int leftTile = static_cast<int>(x / tileSize);
    int rightTile = static_cast<int>((x + width) / tileSize);
    int topTile = static_cast<int>(y / tileSize);
    int bottomTile = static_cast<int>((y + height) / tileSize);

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

void TileMap::UnloadTextures() {
    UnloadTexture(tex_grass);
    UnloadTexture(tex_wall);
}