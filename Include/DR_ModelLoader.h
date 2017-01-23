#include <vector>


#include <GL/glew.h>
#include "ogldev_math_3d.h"
#include "ImageMagick-6/Magick++.h"

typedef struct triangle
{
    unsigned int f1, f2, f3;

    triangle(int a, int b, int c)
        : f1(a), f2(b), f3(c)
    {
    }

}FACE;




class Texturing
{
public:
    Texturing(GLenum TextureTarget, const std::string& FileName);

    bool Load();

    void Bind(GLenum TextureUnit);

private:
    const char* fileName_;




};











class Model
{
public:
    Model(const char* meshFilename);

    void Draw();
    vector<Vector3f>& getVertices();
    vector<FACE>& getFaces();

private:

    void loadMesh();

    const char* meshPath_;
    vector<Vector3f> vertices_;
    vector<FACE> faces_;

};
