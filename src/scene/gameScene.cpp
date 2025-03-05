#include "gameScene.h"


void GameScene::HandleInput() {
    player.HandleInput();
}
    
void GameScene::Update() {
    player.Update();
}
    
void GameScene::Render() {
    player.Draw();
}