#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"
#include <fstream>

class Object
{
  public:
    Object();
    ~Object();
    void Update(unsigned int dt, unsigned int dt2, unsigned int keyPress);
    void Render();

    glm::mat4 GetModel();

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    float angle;
    float angle2;
    bool swap;
};

#endif /* OBJECT_H */
