#include <iostream>

#include "engine.h"
#include "OBJ_Loader.h"
#include "window.h"




int main(int argc, char **argv)
{

     
    objl::Loader loader;

   loader.LoadFile("dragon.obj");

  std::cout << loader.LoadedMeshes[0].MeshName << std::endl;


  // Start an engine and run it then cleanup after
 /* Engine *engine = new Engine("Tutorial Window Name", 800, 600);
  if(!engine->Initialize())
  {
    printf("The engine failed to start.\n");
    delete engine;
    engine = NULL;
    return 1;
  } 



  
  
  engine->Run();
  delete engine;
  engine = NULL;
  return 0; */
}



