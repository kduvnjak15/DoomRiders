#pragma once

#include <list>
#include <GL/glew.h>

//class Technique
//{
//public:
//    Technique();

//    virtual ~Technique();

//    virtual bool Init();

//    void Enable();


//protected:

//    bool AddShader(GLenum ShaderType, const char* pFileName);

//    bool Finalize();

//    GLint GetUniformLocation(const char* pUniformName);

//    GLint GetProgramParam(GLint param);

//    GLint m_shaderProg;

//private:

//    typedef std::list<GLuint> ShaderObjList;
//    ShaderObjList m_shaderObjList;

//};




class GameShader
{
public:
    GameShader(const char* vFilename, const char* fFilename);

    GLuint GW;

    GLuint ShaderProgram_;

private:

    GLuint vertexShaderObj_;
    GLuint fragmentShaderObj_;
    GLuint gSampler;
};
