#include <iostream>
#include <fstream>


#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>


#include "ogldev_math_3d.h"

#include "DR_GameShader.h"
#include "DR_Pipeline.h"
#include "DR_Spectator.h"
#include "DR_ModelLoader.h"
#include "DR_Texture.h"



#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768


const static float EDGE_STEP = 0.5f;
const static int MARGIN = 10;


class initialCallbacks // abstract class; cannot be instatiated
{
public:

    virtual void RenderScene() {}

    virtual void Keyboard(unsigned char z, int x, int y) {}

    virtual void Mouse( unsigned int x,unsigned int y) {}

};




// Points to the object implementing the ICallbacks interface which was delivered to
// GLUTBackendRun(). All events are forwarded to this object.
static initialCallbacks* s_pCallbacks = NULL;


PersProjInfo gPersProjInfo;

const char* pVSFileName = "../Shaders/shader.vs";
const char* pFSFileName = "../Shaders/shader.fs";

class DoomRiders : public initialCallbacks
{
public:

    bool Init(int argc, char** argv)
    {
        gPersProjInfo.FOV = 45.0f;
        gPersProjInfo.Height = WINDOW_HEIGHT;
        gPersProjInfo.Width = WINDOW_WIDTH;
        gPersProjInfo.zNear = 0.0f;
        gPersProjInfo.zFar = 10000.0f;

        s_pCallbacks = this;

        return initializeGLUT(argc, argv);
    }

    bool Run()
    {
        glClearColor(0.0f, 0.1f, 0.2f, 0.1f);
        glFrontFace(GL_CW);
        glCullFace(GL_BACK);
        glEnable(GL_CULL_FACE);
      //  glEnable(GL_DEPTH_TEST);

        defineCallbacks();

        std::cout<<meshPtr_<<std::endl;
        meshPtr_ = new Model("../Content/cube3.obj");


        CreateVAO();

        glBindVertexArray(mVAO_);

        shader_ = new GameShader(pVSFileName, pFSFileName);

        texturePtr = new Texture("bricks.jpg");
        texturePtr->Load();
        texturePtr->Bind(GL_TEXTURE0);

        glUniform1i(glGetUniformLocation(shader_->ShaderProgram_, "gSampler"), 0);

        camera_ = new Spectator();

        glutMainLoop();
        return true;
    }

private:

    static void RenderSceneCB()
    {
        s_pCallbacks->RenderScene();
    }

    static void KeyboardCB(unsigned char Key, int x, int y)
    {
        s_pCallbacks->Keyboard( Key,  x,  y);
    }

    static void MouseCB( int x, int y)
    {
        s_pCallbacks->Mouse(x, y);
    }

    virtual void RenderScene()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Pipeline P;
        P.SetCamera(*camera_);
        P.SetPerspectiveProj(gPersProjInfo);


        glUniformMatrix4fv(gWorldLocation, 1, GL_TRUE, (const GLfloat*)P.TransMatrix());

        texturePtr->Bind(GL_TEXTURE0);

        glDrawElements(GL_TRIANGLES, 72, GL_UNSIGNED_INT, 0);

        glutSwapBuffers();
    }

    virtual void Keyboard(unsigned char z, int x, int y)
    {

        if (z == 'q')
            glutLeaveMainLoop();
        if (z == 'w')
            camera_->moveForward();
        if (z == 's')
            camera_->moveBackward();
        if (z == 'a')
            camera_->strafeLeft();
        if (z == 'd')
            camera_->strafeRight();
        if (z == 'u')
            camera_->rise();
        if (z == 'i')
            camera_->fall();

        camera_->writePos();
        glutPostRedisplay();
    }


    virtual void Mouse( unsigned int x, unsigned int y)
    {
        camera_->updateOrientation(x, y);
        glutPostRedisplay();
    }

    static void defineCallbacks()
    {
        glutDisplayFunc(RenderSceneCB);
        glutIdleFunc(RenderSceneCB);
        glutKeyboardFunc(KeyboardCB);
        glutPassiveMotionFunc(MouseCB);
    }

    bool initializeGLUT(int argc, char** argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
        glutInitWindowPosition(150, 100);
        glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

        glutCreateWindow("DoomRiders");


        GLenum res = glewInit();
        if (res != GLEW_OK)
        {
            fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
            return false;
        }

        return true;
    }

    void CreateVAO()
    {

        glGenVertexArrays(1, &mVAO_);
        glBindVertexArray( mVAO_);

        CreateVertexBuffer();
        CreateIndexBuffer();

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (const GLvoid*)0);
        glEnableVertexAttribArray(0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (const GLvoid*)(2*sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);
    }

    void CreateVertexBuffer()
    {
        float vertices[ meshPtr_->getVertices().size() * 5];

        for (int i = 0; i< meshPtr_->getVertices().size(); i++)
        {
            Vector3f f_ = meshPtr_->getVertices()[i];

            vertices[i*5]   = f_.x ;
            vertices[i*5+1] = f_.y ;
            vertices[i*5+2] = f_.z ;
        }

        for (int i = 0; i< meshPtr_->getTexVertices().size(); i++)
        {
            Vector2f vt_ = meshPtr_->getTexVertices()[i];

            vertices[i*5+3] = vt_.x;
            vertices[i*5+4] = vt_.y;
        }

        for (int i = 0; i<meshPtr_->getVertices().size()*5; i++)
        {
            std::cout<<vertices[i]<<", ";
        }
        std::cout<<std::endl;

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    }

    void CreateIndexBuffer()
    {
        unsigned int indices[ meshPtr_->getFaces().size() *3  ];

        std::cout<<"sizeofindices"<<sizeof(indices )*3/sizeof(FACE)<<std::endl;

        for (int i = 0; i< meshPtr_->getFaces().size(); i++)
        {
            FACE f_ = meshPtr_->getFaces()[i];

            indices[i*3] = f_.f1;
            indices[i*3+1] = f_.f2 ;
            indices[i*3+2] = f_.f3 ;
        }

        for (int i = 0; i<meshPtr_->getFaces().size()*3; i++)
        {
            std::cout<<indices[i]<<", ";
        }
        std::cout<<std::endl;
        glGenBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        std::cout<<"indexbuff"<<std::endl;


    }


private:
    Spectator* camera_ ;
    GLuint mVAO_;
    GLuint VBO;
    GLuint IBO;
    GLfloat s;
    GLuint gWorldLocation;
    Model* meshPtr_;
    Texture* texturePtr;
    GameShader* shader_;



};

int main(int argc, char** argv)
{

    DoomRiders* gamePtr = new DoomRiders;

    if (!gamePtr->Init(argc, argv))
    {
        std::cout<<"Game initialization failed"<<std::endl;
        return false;
    }
    else
    {
        std::cout<<"Game initialization OK"<<std::endl;
    }


    if (!gamePtr->Run())
    {
        std::cout<<"Game run failed"<<std::endl;
        return false;
    }
    else
    {
        std::cout<<"Game exited normally"<<std::endl;
        return 0;
    }

    gamePtr->~DoomRiders();
    delete gamePtr;

	return 0; 
}
