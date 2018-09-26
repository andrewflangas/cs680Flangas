#ifndef SHADER_H
#define SHADER_H

#include <vector>
  
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>



#include "graphics_headers.h"

class Shader
{
  public:
    Shader();
    ~Shader();
    bool Initialize();
    void Enable();
    bool AddShader(GLenum ShaderType);
    bool Finalize();
    GLint GetUniformLocation(const char* pUniformName);
    std::string readFile(const char *filePath);

  private:
    GLuint m_shaderProg;    
    std::vector<GLuint> m_shaderObjList;
};

#endif  /* SHADER_H */
