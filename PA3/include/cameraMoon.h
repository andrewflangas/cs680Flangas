#ifndef CAMERAMOON_H
#define CAMERAMOON_H

#include "graphics_headers.h"

class CameraMoon
{
  public:
    CameraMoon();
    ~CameraMoon();
    bool Initialize(int w, int h);
    glm::mat4 GetProjection();
    glm::mat4 GetView();
  
  private:
    glm::mat4 projection;
    glm::mat4 view;
};

#endif /* CAMERAMOON_H */