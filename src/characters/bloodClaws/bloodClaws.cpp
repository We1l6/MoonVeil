#include "bloodClaws.h"


BloodClaws::BloodClaws(std::shared_ptr<TileMap> &tilemap,
                       Vector2 position,
                       std::vector<std::shared_ptr<Ability>> &gameObjects,
                       std::shared_ptr<Player> &player,
                       float attackDamage,
                       float initialHealth)
    : Enemy(
          tilemap,
          ObjectAttributes{
              .objectType = ObjectType::Enemy,
              .hitbox = {.height = BloodClawsConstants::HEIGHT,
                         .width = BloodClawsConstants::WIDTH,
                         .x = position.x,
                         .y = position.y},

              .idleTexture =
                  {
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 0),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 1),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 2),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 3),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 4),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 5),
                  },

              .moveTextures =
                  {
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 0),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 1),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 2),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 3),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 4),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 5),
                  },

              .attackTextures =
                  {
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 0),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 1),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 2),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 3),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 4),
                      ResourceManager::GetSubTexture(
                          BloodClawsConstants::TEXTURE_RUN_PATH, 0, 5),
                  },

              .velocity = {100.0f, 0.0f}},
          FrameAtributes{.currentFrame = 0, .frameCounter = 0, .frameSpeed = 3},
          initialHealth,
          gameObjects,
          player,
          attackDamage)
{
}