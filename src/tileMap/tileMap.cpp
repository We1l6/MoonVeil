#include "tileMap.h"
#include <string> // Для использования std::string

TileMap::TileMap()
{
    map = LoadTMX("resources/dangeon.tmx");
    if (!map)
    {
        throw std::runtime_error("Failed to loadz TMX map");
    }
}

void TileMap::Draw() const
{
    if (map)
    {
        DrawTMX(map, 0, 0, RAYWHITE);
    }
}

tmx_layer *TileMap::GetLayerByName(tmx_map *map, const std::string &name) const
{
    if (!map)
        return nullptr;

    tmx_layer *layer = map->ly_head;
    while (layer)
    {
        if (layer->name && name == layer->name)
        {
            return layer;
        }
        layer = layer->next;
    }
    return nullptr;
}

TileMap::~TileMap()
{
    if (map)
    {
        tmx_map_free(map);
        map = nullptr;
    }
}

bool TileMap::CheckCollisionWithObjects(const std::string &layer_name,
                                        const Rectangle &object) const
{
    if (!map)
        return false;

    tmx_layer *layer = GetLayerByName(map, layer_name.c_str());
    if (!layer || layer->type != L_OBJGR)
    {
        return false;
    }

    tmx_object *obj = layer->content.objgr->head;
    while (obj)
    {
        if (obj->obj_type == OT_SQUARE)
        {
            const Rectangle obj_rect{static_cast<float>(obj->x),
                                     static_cast<float>(obj->y),
                                     static_cast<float>(obj->width),
                                     static_cast<float>(obj->height)};

            if (CheckCollisionRecs(object, obj_rect))
            {
                return true;
            }
        }
        obj = obj->next;
    }

    return false;
}