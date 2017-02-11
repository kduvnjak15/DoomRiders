#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "DR_ModelLoader.h"


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
        if (strcmp(primitive.c_str(), "vt") == 0)
        {
            texVertices_.push_back(Vector2f(x, y));
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
