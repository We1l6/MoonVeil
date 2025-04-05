#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H


#include "raylib.h"
#include "raymath.h"
#include <algorithm>

class CameraController
{
    Camera2D camera;

  public:
    [[nodiscard]] Camera2D GetCamera() const { return camera; }
    CameraController(const float screenWidth, const float screenHeight);
    void Update(const float deltaTime, const Vector2 &targetPosition);
};


#endif // CAMERACONTROLLER_H