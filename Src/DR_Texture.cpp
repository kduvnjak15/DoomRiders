#include <iostream>
#include "DR_Texture.h"
#include "ogldev_util.h"

static const GLenum types[6] = { GL_TEXTURE_CUBE_MAP_POSITIVE_X,
                                 GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
                                 GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
                                 GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
                                 GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
                                 GL_TEXTURE_CUBE_MAP_NEGATIVE_Z};

CubemapTexture::CubemapTexture(const string &Directory,
                               const string &PosXFilename,
                               const string &NegXFilename,
                               const string &PosYFilename,
                               const string &PosYFilename,
                               const string &PosZFilename,
                               const string &PosZFilename)
{

    string::const_iterator it = Directory.end();
    it--;
    string BaseDir = (*it == '/') ? Directory : Directory + "/";

    m_fileNames[0] = BaseDir + PosXFilename;
    m_fileNames[1] = BaseDir + NegXFilename;
    m_fileNames[2] = BaseDir + PosYFilename;
    m_fileNames[3] = BaseDir + NegYFilename;
    m_fileNames[4] = BaseDir + PosZFilename;
    m_fileNames[5] = BaseDir + NegZFilename;

    m_textureObj = 0;
}

CubemapTexture::~CubemapTexture()
{
    if (m_textureObj != 0 )
    {
        glDeleteTextures(1, &m_textureObj);
    }
}

bool CubemapTexture::Load()
{
    glGenTextures(1, &m_textureObj);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureObj);
    unsigned int width, height;

    unsigned char* image = NULL;

    for (unsigned int i = 0; i<ARRAY_SIZE_IN_ELEMENTS(types); i++)
    {
        image = SOIL_load_image(m_fileNames[i], &width, &height, 0, SOIL_LOAD_RGB);
        glTexImage2D(types[i], 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);


    }

    return true;
}

void CubemapTexture::Bind(GLenum TextureUnit)
{
    glActiveTexture(TextureUnit);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureObj);
}
