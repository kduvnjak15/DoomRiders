#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "DR_ModelLoader.h"
#include "SOIL/src/SOIL.h"



Texturing::Texturing(const std::string& FileName)
{
    int width, height;
    unsigned char* image = SOIL_load_image("../Content/bricks.jpg", &width, &height, 0, SOIL_LOAD_RGB);

    std::cout<<image<<std::endl;

    glGenTextures(1, &Texture_);
    glBindTexture(GL_TEXTURE_2D, Texture_);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glGenerateMipmap(GL_TEXTURE_2D);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texturing::Bind(GLenum TextureUnit)
{
    glBindTexture(GL_TEXTURE_2D, Texture_);
}


Model::Model(const char* meshFilename)
{
    meshPath_ = meshFilename;
    std::cout<<"model "<<meshPath_<<" -> " <<this<<std::endl;
    std::cout<<faces_.size()<<std::endl;
    loadMesh();
    std::cout<<faces_.size()<<std::endl;
    std::cout<<&faces_<<" -- "<<&getFaces()<<std::endl;
}

void Model::loadMesh()
{
    std::ifstream ifs;

    ifs.open ( meshPath_ , std::ifstream::in);

    float x, y, z;

    string line;
    while(std::getline(ifs, line))
    {
        stringstream ss(line);
        string primitive;

        ss >> primitive >> x >> y >> z;

//        if ( strcmp(primitive.c_str(), "v") == 0 )
//            std::cout<<"|"<<primitive.c_str()<<"| "<<x<<" "<< y<<" " << z <<std::endl;

        if (strcmp(primitive.c_str(), "v") == 0)
        {
           vertices_.push_back(Vector3f(x,y,z));
        }
        if (strcmp(primitive.c_str(), "f") == 0)
        {
            faces_.push_back(FACE(x, y, z));
        }
    }

    ifs.close();
}

vector<FACE>& Model::getFaces()
{
    return faces_;
}

vector<Vector3f>& Model::getVertices()
{
    return vertices_;
}
