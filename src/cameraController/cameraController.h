#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include "raylib.h"
#include "raymath.h"
class CameraController {

    public:
        
        Camera2D camera;
        CameraController(float screenWidth, float screenHeight);
        void Update(float deltaTime, const Vector2& targetPosition);
};

#endif //CAMERACONTROLLER_H