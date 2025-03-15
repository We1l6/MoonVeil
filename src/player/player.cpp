#include "player.h"
#include "raylib.h"


Player::Player(const Tilemap& tilemap) : tilemap(tilemap) {
    position = { 600, 700 };
    speed = 155.0f;
    david = ResourceManager::GetTexture("resources/David.png");
}

void Player::HandleInput(float deltaTime) {
    float velocity = speed * deltaTime;
    Vector2 newPosition = position; 

    if (IsKeyDown(KEY_A)) newPosition.x -= velocity;
    if (IsKeyDown(KEY_D)) newPosition.x += velocity;
    if (IsKeyDown(KEY_W)) newPosition.y -= velocity;
    if (IsKeyDown(KEY_S)) newPosition.y += velocity;


    if (!tilemap.IsColliding(newPosition.x+32, newPosition.y+40, 48, 84)) {
        position = newPosition; 
    }
    
}

void Player::Update() {}

void Player::Draw() {
    DrawTexture(david, position.x, position.y, RAYWHITE);
    //DrawRectangle(position.x+32, position.y+40, 48, 84, RED);
}

Vector2 Player::getPosition(){
    return position;
}