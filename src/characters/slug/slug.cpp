#include "slug.h"


Slug::Slug(TileMap &tilemap,
           Vector2 position,
           std::vector<std::shared_ptr<Ability>> &gameObjects,
           std::shared_ptr<Player> &player)
    : Enemy(
          tilemap,
          ObjectAttributes{.objectType = ObjectType::Enemy,
                           .hitbox = {.height = SlugConstants::HEIGHT,
                                      .width = SlugConstants::WIDTH,
                                      .x = position.x,
                                      .y = position.y},

                           .idleTexture =
                               {
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 0),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 1),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 2),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 3),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 4),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 5),
                               },

                           .moveTextures =
                               {
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 0),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 1),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 2),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 3),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 4),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 5),
                               },

                           .attackTextures =
                               {
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 0),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 1),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 2),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 3),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 4),
                                   ResourceManager::GetSubTexture(
                                       SlugConstants::TEXTURE_RUN_PATH, 0, 5),
                               },

                           .velocity = {0.0f, 0.0f}},
          FrameAtributes{.currentFrame = 0, .frameCounter = 0, .frameSpeed = 3},
          SlugConstants::INITIAL_HEALTH,
          gameObjects,
          player)
{
}