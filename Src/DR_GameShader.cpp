#include "DR_GameShader.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include <ogldev_util.h>


/*
Technique::Technique()
{
    m_shaderProg = 0;
}

Technique::~Technique()
{
    for (ShaderObjList::iterator it = m_shaderObjList.begin(); it != m_shaderObjList.end(); it++ )
    {
        glDeleteShader(*it);
    }

    if (m_shaderProg != 0)
    {
        glDeleteProgram(m_shaderProg);
        m_shaderProg = 0;
    }
}

bool Technique::Init()
{
    m_shaderProg = glCreateProgram();

    if (m_shaderProg = 0 )
    {
        fprintf(stderr, "Error creating shader program\n");
        return false;
    }

    return true;
}

bool Technique::AddShader(GLenum ShaderType, const char *pFileName)
{
    string s;

    if ( !ReadFile(pFileName, s))
    {
        return false;
    }

    GLuint ShaderObj = glCreateShader(ShaderType);

    if (ShaderObj == 0)
    {
        fprintf(stderr, "Error creating shader type %d\n", ShaderType);
        return false;
    }

    // Save the shader object - will be deleted in destructor
    m_shaderObjList.push_back(ShaderObj);

    const GLchar* p[1];
    p[0] = s.c_str();
    GLint Lengths[1] = { (GLint)s.size() };

    glShaderSource(ShaderObj, 1, p, Lengths);
    glCompileShader(ShaderObj);

    GLint success;
    glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        GLchar InfoLog[1024];
        glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
        fprintf(stderr, "Error compiling '%s':   '%s'\n", pFileName, InfoLog );
        return false;
    }

    glAttachShader(m_shaderProg, ShaderObj);

    return true;
}


//After all the shader have been added to the program
//call this function to link and validate the program
bool Technique::Finalize()
{
    GLint success = 0;
    GLchar ErrorLog[1024] = {0};

    glLinkProgram(m_shaderProg);

    glGetProgramiv(m_shaderProg, GL_LINK_STATUS, &success);

    if (success == 0)
    {
        glGetProgramInfoLog(m_shaderProg, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
        return false;
    }

    glValidateProgram(m_shaderProg);
    glGetProgramiv(m_shaderProg, GL_VALIDATE_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(m_shaderProg, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Invalid shader progam '%s'\n", ErrorLog);
    }

    // Delete the intermediate shader object that have been added to the program

    for ( ShaderObjList::iterator it = m_shaderObjList.begin(); it != m_shaderObjList.end(); it++)
    {
        glDeleteShader(*it);
    }

    m_shaderObjList.clear();

    return GLCheckError();
}

void Technique::Enable()
{
    glUseProgram(m_shaderProg);
}

GLint Technique::GetUniformLocation(const char *pUniformName)
{
    GLint Location = glGetUniformLocation(m_shaderProg, pUniformName);

    if ( Location == INVALID_UNIFORM_LOCATION)
    {
        fprintf(stderr, "Warning! Unable to get the location of the uniform variable '%s'\n", pUniformName);
    }
    return Location;
}

GLint Technique::GetProgramParam(GLint param)
{
    GLint ret;
    glGetProgramiv(m_shaderProg, param, &ret);
    return ret;
}

*/



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
    gSampler = glGetUniformLocation(ShaderProgram_, "textureSampler");
   // assert(gSampler!= 0xFFFFFFFF);
}

