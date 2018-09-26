#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"
#include <string>
#include <fstream>
#include <sstream>




class Object
{
  public:
    Object(char** argv);
    ~Object();
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

#endif /* OBJECT_H */
