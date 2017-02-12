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

const char* pVSFileName = "shader.vs";
const char* pFSFileName = "shader.fs";

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
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glFrontFace(GL_CW);
        glCullFace(GL_BACK);
        glEnable(GL_CULL_FACE);
      //  glEnable(GL_DEPTH_TEST);

        defineCallbacks();

        std::cout<<meshPtr_<<std::endl;
        meshPtr_ = new Model("../Content/cube3.obj");

        CreateVertexBuffer();
        CreateIndexBuffer();

        GameShader(pVSFileName, pFSFileName);
        texturePtr = new Texture("bricks.jpg");
        texturePtr->Load();
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

        // First attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0,        // attribute, no particular reason, must mach layout in the shader
                              3,        // size
                              GL_FLOAT, // type
                              GL_FALSE, // normalized?
                              0,        // stride
                              (const void* )0); // array buffer offset

        // Second attribute buffer : UVs
        glEnableVertexAttribArray(1);
      //  glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(1,    // atribute
                              2,    // size
                              GL_FLOAT, //type
                              GL_FALSE, // normalized
                              0,        //stride
                              (const GLvoid*)12 );

        glBindBuffer(GL_ARRAY_BUFFER, TBO);
        texturePtr->Bind(GL_TEXTURE0);
//        glDrawElements(GL_TRIANGLES, 72, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles


        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
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

    void CreateVertexBuffer()
    {

#define novi_kod
#ifdef novi_kod


        static const GLfloat g_vertex_buffer_data[] = {
            -1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,
             1.0f, 1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,
             1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
             1.0f,-1.0f,-1.0f,
             1.0f, 1.0f,-1.0f,
             1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
             1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
             1.0f,-1.0f, 1.0f,
             1.0f, 1.0f, 1.0f,
             1.0f,-1.0f,-1.0f,
             1.0f, 1.0f,-1.0f,
             1.0f,-1.0f,-1.0f,
             1.0f, 1.0f, 1.0f,
             1.0f,-1.0f, 1.0f,
             1.0f, 1.0f, 1.0f,
             1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,
             1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
             1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,
             1.0f,-1.0f, 1.0f
        };
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);


        static const GLfloat g_uv_buffer_data[] = {
            0.000059f, 1.0f-0.000004f,
            0.000103f, 1.0f-0.336048f,
            0.335973f, 1.0f-0.335903f,
            1.000023f, 1.0f-0.000013f,
            0.667979f, 1.0f-0.335851f,
            0.999958f, 1.0f-0.336064f,
            0.667979f, 1.0f-0.335851f,
            0.336024f, 1.0f-0.671877f,
            0.667969f, 1.0f-0.671889f,
            1.000023f, 1.0f-0.000013f,
            0.668104f, 1.0f-0.000013f,
            0.667979f, 1.0f-0.335851f,
            0.000059f, 1.0f-0.000004f,
            0.335973f, 1.0f-0.335903f,
            0.336098f, 1.0f-0.000071f,
            0.667979f, 1.0f-0.335851f,
            0.335973f, 1.0f-0.335903f,
            0.336024f, 1.0f-0.671877f,
            1.000004f, 1.0f-0.671847f,
            0.999958f, 1.0f-0.336064f,
            0.667979f, 1.0f-0.335851f,
            0.668104f, 1.0f-0.000013f,
            0.335973f, 1.0f-0.335903f,
            0.667979f, 1.0f-0.335851f,
            0.335973f, 1.0f-0.335903f,
            0.668104f, 1.0f-0.000013f,
            0.336098f, 1.0f-0.000071f,
            0.000103f, 1.0f-0.336048f,
            0.000004f, 1.0f-0.671870f,
            0.336024f, 1.0f-0.671877f,
            0.000103f, 1.0f-0.336048f,
            0.336024f, 1.0f-0.671877f,
            0.335973f, 1.0f-0.335903f,
            0.667969f, 1.0f-0.671889f,
            1.000004f, 1.0f-0.671847f,
            0.667979f, 1.0f-0.335851f
        };


        glGenBuffers(1, &TBO);
        glBindBuffer(GL_ARRAY_BUFFER, TBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

#else
        float vertices[ meshPtr_->getVertices().size() * 3];

        for (int i = 0; i< meshPtr_->getVertices().size(); i++)
        {
            Vector3f f_ = meshPtr_->getVertices()[i];


            vertices[i*3] = f_.x;
            vertices[i*3+1] = f_.y;
            vertices[i*3+2] = f_.z;
        }

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
#endif
    }

    void CreateIndexBuffer()
    {
        unsigned int indices[ meshPtr_->getFaces().size() *3  ];

        std::cout<<"sizeofindices"<<sizeof(indices )*3/sizeof(FACE)<<std::endl;

        for (int i = 0; i< meshPtr_->getFaces().size(); i++)
        {
            FACE f_ = meshPtr_->getFaces()[i];

            indices[i*3] = f_.f1;
            indices[i*3+1] = f_.f2;
            indices[i*3+2] = f_.f3;
        }

        glGenBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        std::cout<<"indexbuff"<<std::endl;


    }


private:
    Spectator* camera_ ;
    GLuint VBO;
    GLuint IBO;
    GLuint TBO;
    GLfloat s;
    GLuint gWorldLocation;
    Model* meshPtr_;
    Texture* texturePtr;



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
