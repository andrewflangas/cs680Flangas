#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
using namespace std;

#include "graphics_headers.h"
#include "camera.h"
#include "cameraMoon.h"
#include "shader.h"
#include "shaderMoon.h"
#include "object.h"
#include "objectMoon.h"




class Graphics
{
  public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height);
    void Update(unsigned int dt);
     void Reverse(unsigned int dt);
    void Render();

  private:
    std::string ErrorString(GLenum error);

    Camera *m_camera;
    CameraMoon *m_cameraMoon;
    
    Shader *m_shader;
    ShaderMoon *m_shaderMoon;
    

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;

    GLint m_projectionMatrixMoon;
    GLint m_viewMatrixMoon;
    GLint m_modelMatrixMoon;



    Object *m_cube;
    ObjectMoon *m_cubeMoon;
     
    
    
};

#endif /* GRAPHICS_H */
