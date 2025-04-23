#include "bloodClaws.h"


BloodClaws::BloodClaws(TileMap &tilemap,
                       Vector2 position,
                       std::vector<std::shared_ptr<Ability>> &gameObjects,
                       std::shared_ptr<Player> &player)
    : Enemy(
          tilemap,
          ObjectAttributes{.objectType = ObjectType::Enemy,
                           .hitbox = {.height = 128,
                                      .width = 128,
                                      .x = position.x,
                                      .y = position.y},

                           .idleTexture =
                               {
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 0),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 1),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 2),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 3),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 4),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 5),
                               },

                           .moveTextures =
                               {
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 0),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 1),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 2),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 3),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 4),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 5),
                               },

                           .attackTextures =
                               {
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 0),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 1),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 2),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 3),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 4),
                                   ResourceManager::GetSubTexture(
                                       "resources/BloodclawsRUN.png", 0, 5),
                               },

                           .velocity = {0.0f, 0.0f}},
          FrameAtributes{.currentFrame = 0, .frameCounter = 0, .frameSpeed = 3},
          100,
          gameObjects,
          player)
{
}