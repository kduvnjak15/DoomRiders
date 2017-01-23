#pragma once

#define STEP_SCALE 1.0f

#include "ogldev_math_3d.h"
#include <iostream>

class Spectator
{
public:
    Spectator();

    void moveForward(float s = STEP_SCALE);

    void moveBackward(float s = STEP_SCALE);

    void strafeLeft(float s = STEP_SCALE);

    void strafeRight(float s = STEP_SCALE);

    void rise(float s = STEP_SCALE);

    void fall(float s = STEP_SCALE);


    void updateOrientation(int X, int Y);

    Vector3f getPos();

    Vector3f getLookAt();

    Vector3f getUp();

    void writePos();

    void writeOrientation();

private:
    Vector3f m_pos;
    Vector3f m_LookAt;
    Vector3f m_Up;

    float angle_H;
    float angle_V;

    Vector2i mousePos;
};
