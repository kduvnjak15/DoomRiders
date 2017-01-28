#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>
#include <SOIL/SOIL.h>

using namespace std;

class CubemapTexture
{
public:

    CubemapTexture(const string& Directory,
                   const string& PosXFilename,
                   const string& NegXFilename,
                   const string& PosYFilename,
                   const string& PosYFilename,
                   const string& PosZFilename,
                   const string& PosZFilename);
    ~CubemapTexture();

    bool Load();

    void Bind(GLenum TextureUnit);

private:

    string m_fileNames[6];
    GLuint m_textureObj;
};

#endif // TEXTURE_H

