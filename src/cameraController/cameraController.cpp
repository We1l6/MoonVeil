#include "cameraController.h"


CameraController::CameraController(const float screenWidth,
                                   const float screenHeight)
    : camera{.target = {0, 0},
             .offset = {screenWidth / 2.0f, screenHeight / 2.0f},
             .rotation = 0.0f,
             .zoom = 1.0f}
{
}


void CameraController::Update(const float deltaTime,
                              const Vector2 &targetPosition)
{
    constexpr float ZOOM_SENSITIVITY = 0.05f;
    constexpr float SMOOTHNESS = 5.0f;
    constexpr Vector2 TARGET_OFFSET{70.0f, 64.0f};

    camera.zoom =
        std::clamp(camera.zoom + (GetMouseWheelMove() * ZOOM_SENSITIVITY),
                   0.5f,  // min zoom
                   3.0f); // max zoom

    const Vector2 targetWithOffset = targetPosition + TARGET_OFFSET;
    camera.target = {
        Lerp(camera.target.x, targetWithOffset.x, SMOOTHNESS * deltaTime),
        Lerp(camera.target.y, targetWithOffset.y, SMOOTHNESS * deltaTime)};
}