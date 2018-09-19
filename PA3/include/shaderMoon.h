#ifndef SHADERMOON_H
#define SHADERMOON_H

#include <vector>
  
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>



#include "graphics_headers.h"

class ShaderMoon
{
  public:
    ShaderMoon();
    ~ShaderMoon();
    bool Initialize();
    void Enable();
    bool AddShaderMoon(GLenum ShaderMoonType);
    bool Finalize();
    GLint GetUniformLocation(const char* pUniformName);
    std::string readFile(const char *filePath);

  private:
    GLuint m_ShaderMoonProg;    
    std::vector<GLuint> m_ShaderMoonObjList;
};

#endif  /* SHADERMOON_H */
