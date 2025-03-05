#include "menuScene.h"


void MenuScene::HandleInput() {
    if (IsKeyPressed(KEY_ENTER)) {
        m_game->ChangeScene(new GameScene(m_game));
    }
}

void MenuScene::Render() {
    DrawText("MENU: Press ENTER to Start", 200, 250, 20, BLACK);
}
void MenuScene::Update(){
    
}