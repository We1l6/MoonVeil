#include "cameraController.h"

CameraController::CameraController(float screenWidth, float screenHeight)
{
    camera.target = {0, 0};
    camera.offset = {screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void CameraController::Update(float deltaTime, const Vector2 &targetPosition)
{
    camera.zoom += static_cast<float>(GetMouseWheelMove()) * 0.05f;
    float smoothness = 5.0f;
    camera.target.x =
        Lerp(camera.target.x, targetPosition.x + 70, smoothness * deltaTime);
    camera.target.y =
        Lerp(camera.target.y, targetPosition.y + 64, smoothness * deltaTime);
}