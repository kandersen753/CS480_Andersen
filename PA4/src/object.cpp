#include "object.h"
#include <fstream>
#include <ctime>
#include <cstdlib>

Object::Object()
{  
  srand(time(NULL));

  float x, y, z;
  unsigned int val;

  std::string fileName;
  std::string filePath;

  std::cout << "Input file name you wish to load from the objects folder (exclude the .obj): ";
  std::cin >> fileName;

  filePath = "../objects/";
  filePath += fileName;
  filePath += ".obj";

  std::ifstream fin;
  fin.open(filePath.c_str());
  std::string s;
  char trash[200];


  if (fin.good())
    {
    //bypass title lines
    for (int i=0; i<4; i++)
    {
      fin.getline(trash, 200);
    }

    //get to the v line
    fin >> s;

    //loop through all 
    while (s.compare("v") == 0)
    {
      fin >> x;
      fin >> y;
      fin >> z;

      Vertices.push_back(Vertex(glm::vec3(x,y,z), 
                    glm::vec3((float)(rand()%1000)/1000, (float)(rand()%1000)/1000, (float)(rand()%1000)/1000)));
      fin >> s;
    }
    while (!fin.eof())
    {
      while (s.compare("f") != 0 && !fin.eof())
      {
        fin >> s;
      }

      while (s.compare("f") == 0 && !fin.eof())
      {
        for (int i=0; i<3; i++)
        {
          fin >> val;

          if (fin.peek() == '/')
          {
            fin >> s;
          }

          Indices.push_back(val);
        }

        fin >> s;
      }
    }
    
    fin.close();
  }



  // The index works at a 0th index
  for(unsigned int i = 0; i < Indices.size(); i++)
  {
    Indices[i] = Indices[i] - 1;
  }

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

void Object::Update(unsigned int dt, unsigned int dt2, unsigned int keyPress)
{
  angle += dt * M_PI/10000;
  model = glm::translate(glm::mat4(1.0f), glm::vec3 (0.0f, 0.0f, 0.0f));
  model *= glm::rotate (glm::mat4(1.0f), angle, glm::vec3 (1.0f, 1.0f, 0.0f));
}

glm::mat4 Object::GetModel()
{
  return model;
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

