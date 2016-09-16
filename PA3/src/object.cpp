#include "object.h"

Object::Object()
{  
  /*
    # Blender File for a Cube
    o Cube
    v 1.000000 -1.000000 -1.000000
    v 1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 -1.000000
    v 1.000000 1.000000 -0.999999
    v 0.999999 1.000000 1.000001
    v -1.000000 1.000000 1.000000
    v -1.000000 1.000000 -1.000000
    s off
    f 2 3 4
    f 8 7 6
    f 1 5 6
    f 2 6 7
    f 7 8 4
    f 1 4 8
    f 1 2 4
    f 5 8 6
    f 2 1 6
    f 3 2 7
    f 3 7 4
    f 5 1 8
  */

  Vertices = {
    {{1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}},
    {{1.0f, -1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
    {{-1.0f, -1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
    {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}},
    {{1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 0.0f}},
    {{1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}},
    {{-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}},
    {{-1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}}
  };

  Indices = {
    2, 3, 4,
    8, 7, 6,
    1, 5, 6,
    2, 6, 7,
    7, 8, 4,
    1, 4, 8,
    1, 2, 4,
    5, 8, 6,
    2, 1, 6,
    3, 2, 7,
    3, 7, 4,
    5, 1, 8
  };

  // The index works at a 0th index
  for(unsigned int i = 0; i < Indices.size(); i++)
  {
    Indices[i] = Indices[i] - 1;
  }

  angle = 0.0f;
  angle2 = 0.0f;
  for (int i=0; i<4; i++)
  {
    angles[i] = 0.0f;
  }
  swap = false;

  rotator = 1;
  translator = 1;
  priorRotate = 1;
  priorTranslate = 1;

  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);
}

Object::~Object()
{
  Vertices.clear();
  Indices.clear();
}

void Object::Update(unsigned int dt, unsigned int keyPress)
{
  switch (keyPress)
  {
    //counterclockwise rotation
    // 'a'
    case 97:
      priorRotate = rotator;
      rotator = 1;
      break;

    //clockwise rotation
    // 's'
    case 115:
      priorRotate = rotator;
      rotator = -1;      
      break;

    //counterclockwise translation
    // 'q'
    case 113:
      priorTranslate = translator;
      translator = 1;
      break;

    //clockwise translation
    // 'w'
    case 119:
      priorTranslate = translator;    
      translator = -1;
      break;

    //freezes entire object
    // left mouse button
    case 1:     
      translator = 0;
      rotator = 0;
      break;

    //restores object to its prior state
    // right mouse button
    case 3:
      rotator = priorRotate;
      translator = priorTranslate;
      break;

    //freezes rotation
    // 'z'
    case 122:
      rotator = 0;
      break;

    //restores previous rotation state
    // 'x'
    case 120:
      rotator = priorRotate;
      break;

    //freezes translation
    // 'c' 
    case 99:
      translator = 0;
      break;

    //restores previous translation state
    // 'v'
    case 118:
      translator = priorTranslate;
      break;
  }


  //change translation direction
  if (translator == 1)
  {
    angles[1] += dt * M_PI/5000;
  }
  else if (translator == -1)
  {
    angles[1] -= dt * M_PI/5000; 
  }


  //change rotation direction
  if (rotator == 1)
  {
    angles[0] += dt * M_PI/10000;
    //angles[2] += dt * M_PI/400;    
  }
  else if (rotator == -1)
  {
    angles[0] -= dt * M_PI/10000;
    //angles[2] -= dt * M_PI/400;    
  }
  angles[2] += dt * M_PI/400;
  angles[3] += dt * M_PI/5000;

  //apply seperate times to object for rotation and translation
  model = glm::translate(glm::mat4(1.0f), glm::vec3 (sin(angles[1])*10, 0.0f, cos(angles[1])*10));
  model *= glm::rotate(glm::mat4(1.0f), (angles[0])*10, glm::vec3(0.0, 1.0, 0.0));

  moon = glm::translate(model, glm::vec3(cos(angles[2])*3, 0.0f, sin(angles[2])*3));
  moon *= glm::rotate(glm::mat4(1.0f), (angles[3]*10), glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Object::GetModel()
{
  return model;
}

glm::mat4 Object::GetMoon()
{
  return moon;
}

void Object::Render()
{
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

  glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}
