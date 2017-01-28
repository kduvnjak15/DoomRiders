#include <iostream>
#include "DR_Texture.h"
#include "SOIL/SOIL.h"

Texture::Texture(const char *textureFileName)
{
    textureTarget_ = GL_TEXTURE_2D;
    textureFilename_ = textureFileName;
}

bool Texture::Load()
{
    glGenTextures(1, &textureObj_);
    glBindTexture(textureTarget_, textureObj_);
    std::cout<<"Samo hrabro"<<std::endl;
    int width, height;
    std::cout<<"Samo hrabro"<<std::endl;

    unsigned char* image =SOIL_load_image("../Content/bricks.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    std::cout<<"Samo hrabro"<<image<<std::endl;
    glTexImage2D(textureTarget_, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    std::cout<<"Samo hrabro"<<std::endl;

    glTexParameterf(textureTarget_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(textureTarget_, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(textureTarget_, 0);

    return true;
}

void Texture::Bind(GLenum TextureUnit)
{
    glActiveTexture(TextureUnit);
    glBindTexture(textureTarget_, textureObj_);
}
