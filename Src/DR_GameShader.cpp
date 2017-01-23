#include "DR_GameShader.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <fstream>
#include <stdio.h>

#include <ogldev_util.h>


GameShader::GameShader(const char *vFilename, const char *fFilename)
{

    GLuint ShaderProgram_ = glCreateProgram();

    if (ShaderProgram_ == 0) {
        fprintf(stderr, "Error creating shader program\n");
        exit(1);
    }

    string vs, fs;

    if (!ReadFile(vFilename, vs)) {
        exit(1);
    };

    if (!ReadFile(fFilename, fs)) {
        exit(1);
    };

//vertex shading

    vertexShaderObj_ = glCreateShader(GL_VERTEX_SHADER);

    if (vertexShaderObj_== 0) {
        fprintf(stderr, "Error creating shader type %d\n", GL_VERTEX_SHADER);
        exit(1);
    }

    const GLchar* p[1];
    p[0] = vs.c_str();
    GLint Lengths[1];
    Lengths[0]= strlen( p[0] );

    glShaderSource(vertexShaderObj_, 1, p, Lengths);
    glCompileShader(vertexShaderObj_);
    GLint success;
    glGetShaderiv(vertexShaderObj_, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar InfoLog[1024];
        glGetShaderInfoLog(vertexShaderObj_, 1024, NULL, InfoLog);
        fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_VERTEX_SHADER, InfoLog);
        exit(1);
    }

    glAttachShader(ShaderProgram_, vertexShaderObj_);

//fragment shading

    fragmentShaderObj_ = glCreateShader(GL_FRAGMENT_SHADER);

    if (fragmentShaderObj_ == 0) {
        fprintf(stderr, "Error creating shader type %d\n", GL_FRAGMENT_SHADER);
        exit(1);
    }

    p[0] = fs.c_str();
    Lengths[0]= strlen( p[0] );

    glShaderSource(fragmentShaderObj_, 1, p, Lengths);
    glCompileShader(fragmentShaderObj_);
    glGetShaderiv(fragmentShaderObj_, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar InfoLog[1024];
        glGetShaderInfoLog(fragmentShaderObj_, 1024, NULL, InfoLog);
        fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_FRAGMENT_SHADER, InfoLog);
        exit(1);
    }

    glAttachShader(ShaderProgram_, fragmentShaderObj_);

    success = 0;
    GLchar ErrorLog[1024] = { 0 };


// Compile shaders
    glLinkProgram(ShaderProgram_);

    glGetProgramiv(ShaderProgram_, GL_LINK_STATUS, &success);
    if (success == 0) {
        glGetProgramInfoLog(ShaderProgram_, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
        exit(1);
    }

    glValidateProgram(ShaderProgram_);
    glGetProgramiv(ShaderProgram_, GL_VALIDATE_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ShaderProgram_, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Invalid shader program: '%s'\n", ErrorLog);
        exit(1);
    }

    glUseProgram(ShaderProgram_);

    glDetachShader(ShaderProgram_, vertexShaderObj_);
    glDetachShader(ShaderProgram_, fragmentShaderObj_);
    glDeleteShader(vertexShaderObj_);
    glDeleteShader(fragmentShaderObj_);

    GW = glGetUniformLocation(ShaderProgram_, "gWorld");
    //assert(gWorldLocation != 0xFFFFFFFF);
}

