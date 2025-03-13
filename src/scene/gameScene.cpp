#include "gameScene.h"
#include "raymath.h"


void GameScene::HandleInput(float deltaTime) {
    player.HandleInput(deltaTime);
}
    
void GameScene::Update(float deltaTime) {
    camera.zoom += ((float)GetMouseWheelMove() * 0.05f);
    float smoothness = 5.0f;
    Vector2 playerPosition = player.getPosition();

    camera.target.x = Lerp(camera.target.x, playerPosition.x, smoothness * deltaTime);
    camera.target.y = Lerp(camera.target.y, playerPosition.y, smoothness * deltaTime);
}
    
void GameScene::Render() {
    BeginMode2D(camera);
    tileMap.Draw();
    player.Draw();
    EndMode2D();
}