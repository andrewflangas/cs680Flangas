#ifndef OBJECTMOON_H
#define OBJECTMOON_H

#include <vector>
#include "graphics_headers.h"

class ObjectMoon
{
  public:
    ObjectMoon();
    ~ObjectMoon();
    void Update(unsigned int dt);
    void Reverse(unsigned int dt);
    void Render();

    glm::mat4 GetModel();

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

     

    float angle;
};

#endif /* OBJECTMOON_H */
