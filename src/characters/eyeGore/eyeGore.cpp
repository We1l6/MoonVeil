#include "eyeGore.h"


EyeGore::EyeGore(TileMap &tilemap,
                 Vector2 position,
                 std::vector<std::shared_ptr<Ability>> &gameObjects,
                 std::shared_ptr<Player> &player)
    : Enemy(
          tilemap,
          ObjectAttributes{
              .objectType = ObjectType::Enemy,
              .hitbox = {.height = EyeGoreConstants::HEIGHT,
                         .width = EyeGoreConstants::WIDTH,
                         .x = position.x,
                         .y = position.y},

              .idleTexture =
                  {
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 0),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 1),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 2),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 3),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 4),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 5),
                  },

              .moveTextures =
                  {
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 0),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 1),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 2),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 3),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 4),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 5),
                  },

              .attackTextures =
                  {
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 0),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 1),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 2),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 3),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 4),
                      ResourceManager::GetSubTexture(
                          EyeGoreConstants::TEXTURE_RUN_PATH, 0, 5),
                  },

              .velocity = {0.0f, 0.0f}},
          FrameAtributes{.currentFrame = 0, .frameCounter = 0, .frameSpeed = 3},
          EyeGoreConstants::INITIAL_HEALTH,
          gameObjects,
          player)
{
}