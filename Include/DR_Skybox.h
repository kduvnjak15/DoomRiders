#ifndef SKYBOX_H
#define SKYBOX_H

#include "DR_GameShader.h"
#include "ogldev_math_3d.h"
#include "DR_Texture.h"

class SkyboxMethod : public Technique
{
public:
    SkyboxMethod();

    virtual bool Init();

    void SetWVP(const Matrix4f& WVP);
    void SetTextureUnit(unsigned int TextureUnit);

private:

    GLuint m_WVPLocation;
    GLuint m_textureLocation;
};


class SkyBox
{
public:
    SkyBox(const Camera* pCamera, const PersProjInfo& p);

    ~SkyBox();

    bool Init(const string& Directory,
              const string& PosXFilename,
              const string& NegXFilename,
              const string& PosYFilename,
              const string& NegYFilename,
              const string& PosZFilename,
              const string& NegZFilename);

    void Render();

private:

    SkyboxMethod* m_pSkyboxMethod;
    const camera* m_pCamera;
    CubemapTexture* m_pCubemapTex;
    Mesh* m_pMesh;
    PersProjInfo m_persProjInfo;


};

#endif // SKYBOX_H
