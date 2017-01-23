#pragma once

#include <GL/glew.h>


class GameShader
{
public:
    GameShader(const char* vFilename, const char* fFilename);

    GLuint GW;

private:
    GLuint ShaderProgram_;
    GLuint vertexShaderObj_;
    GLuint fragmentShaderObj_;
};
