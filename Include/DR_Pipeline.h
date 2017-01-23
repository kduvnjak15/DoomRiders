#pragma once

#include "ogldev_math_3d.h"
#include "DR_Spectator.h"

class Pipeline
{
public:
    Pipeline();


    void Scale(float s);
    void Scale(const Vector3f& scale);
    void Scale(float x, float y, float z);

    void WorldPos(float x, float y, float z);
    void WorldPos(const Vector3f& Pos);

    void Rotate(float RotateX, float RotateY, float RotateZ);
    void Rotate(const Vector3f& r);

    void SetPerspectiveProj(const PersProjInfo& p);

    void SetCamera(Spectator Camera);

    const Matrix4f TransMatrix();

private:
    Vector3f pipe_pos;
    Vector3f pipe_LookAt;
    Vector3f pipe_Up;

    PersProjInfo pipe_perspetiveProj;

};
