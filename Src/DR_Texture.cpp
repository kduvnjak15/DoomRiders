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
    int width, height;

    unsigned char* image =SOIL_load_image("../Content/bricks.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(textureTarget_, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glTexParameterf(textureTarget_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(textureTarget_, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(textureTarget_, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(textureTarget_, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(textureTarget_, GL_TEXTURE_WRAP_R, GL_REPEAT);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(textureTarget_, 0);

    SOIL_free_image_data(image);

    return true;
}

void Texture::Bind(GLenum TextureUnit)
{
    glActiveTexture(TextureUnit);
    glBindTexture(textureTarget_, textureObj_);
}
