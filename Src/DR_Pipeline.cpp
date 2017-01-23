#include "DR_Pipeline.h"
#include <iostream>

Pipeline::Pipeline()
{

}

const Matrix4f Pipeline::TransMatrix()
{

    Matrix4f Trans, temp, Proj, View;

    Trans.InitIdentity();

//    Trans.InitPersProjTransform(pipe_perspetiveProj);
    temp.InitTranslationTransform(pipe_pos.x, pipe_pos.y, pipe_pos.z);
    Proj.InitPersProjTransform(pipe_perspetiveProj);
    View.InitCameraTransform(pipe_LookAt, pipe_Up);
    return  Proj * View * temp * Trans;



}

void Pipeline::SetPerspectiveProj(const PersProjInfo &p)
{
    pipe_perspetiveProj = p;
}

void Pipeline::SetCamera(Spectator Camera)
{
    pipe_pos = Camera.getPos();
    pipe_LookAt = Camera.getLookAt();
    pipe_Up = Camera.getUp();

}
