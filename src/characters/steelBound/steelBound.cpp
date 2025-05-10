#include "steelBound.h"


SteelBound::SteelBound(TileMap &tilemap,
                       Vector2 position,
                       std::vector<std::shared_ptr<Ability>> &gameObjects,
                       std::shared_ptr<Player> &player)
    : Enemy(
          tilemap,
          ObjectAttributes{
              .objectType = ObjectType::Enemy,
              .hitbox = {.height = SteelBoundConstants::HEIGHT,
                         .width = SteelBoundConstants::WIDTH,
                         .x = position.x,
                         .y = position.y},

              .idleTexture =
                  {
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 0),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 1),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 2),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 3),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 4),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 5),
                  },

              .moveTextures =
                  {
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 0),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 1),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 2),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 3),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 4),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 5),
                  },

              .attackTextures =
                  {
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 0),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 1),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 2),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 3),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 4),
                      ResourceManager::GetSubTexture(
                          SteelBoundConstants::TEXTURE_RUN_PATH, 0, 5),
                  },

              .velocity = {100.0f, 0.0f}},
          FrameAtributes{.currentFrame = 0, .frameCounter = 0, .frameSpeed = 3},
          SteelBoundConstants::INITIAL_HEALTH,
          gameObjects,
          player)
{
}