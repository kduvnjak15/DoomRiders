#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>

using namespace std;

class Texture
{
public:

    Texture(const char* textureFileName);

    bool Load();

    void Bind(GLenum TextureUnit);

private:

    GLuint textureTarget_;
    GLuint textureObj_;
    const char* textureFilename_ ;

};

#endif // TEXTURE_H

