#include "player.h"

Player::Player() {
    position = { 400, 300 };
    speed = 0.1f;
}

void Player::HandleInput() {
    if (IsKeyDown(KEY_A)) position.x -= speed;
    if (IsKeyDown(KEY_D)) position.x += speed;
    if (IsKeyDown(KEY_W)) position.y -= speed;
    if (IsKeyDown(KEY_S)) position.y += speed;
}

void Player::Update() {}

void Player::Draw() {
    DrawCircleV(position, 20, BLUE);
}
