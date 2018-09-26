#include "object.h"


Object::Object(char** argv)
{  
  /*
    # Blender fin for a Cube
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

 /* Vertices = {
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
  };       */ 


  std::ifstream fin; 
  std::ifstream mfin;
  Vertex ver({0,0,0}, {0,0,0});
  char* standin;
  long fla;
  std::string strTemp; 
  std::string w, mw;

  if(std::string(argv[1])=="dragon"){

    fin.open("../Object/dragon.obj");
  }
  else if(std::string(argv[1])=="table"){

    fin.open("../Object/table.obj");

  }
  if(!fin){

    std::cerr<< "Unable to open fin";
    exit(1);

  }
  //std::string w, mw;
  while(fin>>w){

    if(w == "v"){

      if(std::string(argv[2])== "random"){

        fin >> ver.vertex.x;
        fin >> ver.vertex.y;
        fin >> ver.vertex.z;
        std::cout << ver.vertex.x<<""<<ver.vertex.y<<""<<ver.vertex.z << std::endl; 
        ver.color.r=(rand()%100)/100.0;
        ver.color.g=(rand()%100)/100.0;
        ver.color.b=(rand()%100)/100.0;

      }
      else if(std::string(argv[2])=="material"){

        fin >> ver.vertex.x;
        fin >> ver.vertex.y;
        fin >> ver.vertex.z;

        std::cout << ver.vertex.x<<""<<ver.vertex.y<<""<<ver.vertex.z<<std::endl;



      }

        Vertices.push_back(ver);
    }

    else if(w == "f"){

      for(int i =1; i<=3; i++){

        fin>>strTemp;
        fla=strtol(strTemp.c_str(), &standin,10);
        Indices.push_back(fla);
        std::cout<<fla<<" ";


      }

      std::cout<<std::endl;

    }
    else if(w=="mtllib"){

      fin>>w;
      mfin.open(w);
      while(mfin>>mw){
        if(mw =="Kd"){

          mfin >> ver.color.r;
          mfin >> ver.color.g;
          mfin >> ver.color.b;
          break;

        }
        else{

          mfin.ignore(100,'\n');
        }


      }
      mfin.close();

    }
    else{

      fin.ignore(100, '\n');

    }

  }
  fin.close();













  // The fla works at a 0th fla
  for(unsigned int i = 0; i < Indices.size(); i++)
  {
    Indices[i] = Indices[i] - 1;
  }

  angle = 0.0f;

  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW); 

// Read our .obj fin
  




}







Object::~Object()
{
  Vertices.clear();
  Indices.clear();
}

void Object::Update(unsigned int dt)
{

  angle += dt * M_PI/1000;

  //model = glm::rotate(glm::mat4(1.0f), (angle), glm::vec3(0.0, 1.0, 0.0));

  glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), (angle), glm::vec3(0.0, 1.0, 0.0));

  glm::mat4 ViewTranslate = glm::translate(rotation, glm::vec3(5.0, 0.0, 0.0));


  model = glm::rotate(ViewTranslate, (angle), glm::vec3(0.0, 1.0, 0.0)); 

  
}

void Object::Reverse(unsigned int dt)
{


 /* angle += dt * M_PI/1000;

  //model = glm::rotate(glm::mat4(1.0f), (angle), glm::vec3(0.0, 1.0, 0.0));

   glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), (angle), glm::vec3(0.0, -1.0, 0.0));

  glm::mat4 ViewTranslate = glm::translate(rotation, glm::vec3(5.0, 0.0, 0.0));


  model = glm::rotate(ViewTranslate, (angle), glm::vec3(0.0, -1.0, 0.0));

  */

  
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






























