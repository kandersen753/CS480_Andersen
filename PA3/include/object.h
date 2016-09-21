#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object();
    ~Object();
    void Update(unsigned int dt, unsigned int keyPress);
    void Render();

    glm::mat4 GetModel();
    glm::mat4 GetMoon();

  private:
    glm::mat4 model;
    glm::mat4 moon;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    float angle;
    float angle2;
    float angles[4];
    bool swap;

    int rotator;
    int translator;
    int moonTrans;
    int moonRot;
    int priorMoonTrans;
    int priorMoonRot;
    int priorRotate;
    int priorTranslate;
};

#endif /* OBJECT_H */
