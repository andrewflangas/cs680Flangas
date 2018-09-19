#include "engine.h"





Engine::Engine (string name, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  m_FULLSCREEN = false;


}

Engine::Engine (string name)
{
  m_WINDOW_NAME = name;
  m_WINDOW_HEIGHT = 0;
  m_WINDOW_WIDTH = 0;
  m_FULLSCREEN = true;
}

Engine::~Engine ()
{
  delete m_graphics;
  delete m_window;
  m_graphics = NULL; 
  m_window = NULL;
  
}

bool Engine::Initialize()
{
  // Start a window

  m_window = new Window();
  if(!m_window->Initialize(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT))
  {
    printf("The window failed to initialize.\n");
    return false;
  }


  // Start the graphics
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }


  // Set the time
  m_currentTimeMillis = GetCurrentTimeMillis();

  // No errors
  
  return true;


}


void Engine::displayText( float x, float y, int r, int g, int b, const char *string ) {
  int j = strlen( string );
 
  glColor3f( r, g, b );
  glRasterPos2f( x, y );
  for( int i = 0; i < j; i++ ) {
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
  }
}



void Engine::Run()
{
  m_running = true;

  while(m_running)
  {
    // Update the DT
    m_DT = getDT();

    // Check the keyboard input
    while(SDL_PollEvent(&m_event) != 0)
    {
      Keyboard();
    }

    // Update and render the graphics
    m_graphics->Update(m_DT);
    m_graphics->Render();

    // Swap to the Window
    m_window->Swap();
    

  }
}


void Engine ::RunReverse()
{
  m_running = true;

  while(m_running)
  {
    // Update the DT
    m_DT = getDT();

    // Check the keyboard input
    while(SDL_PollEvent(&m_event) != 0)
    {
      Keyboard();
    }

    // Update and render the graphics
    m_graphics->Reverse(m_DT);
    m_graphics->Render();

    // Swap to the Window
    m_window->Swap();
    
  } 
}



void Engine::Keyboard()
{
  if(m_event.type == SDL_QUIT)
  {
    m_running = false;
  }
  else if ((m_event.type == SDL_KEYDOWN) || (m_event.type == SDL_MOUSEBUTTONDOWN))
  {
    // handle key down events here
    if (m_event.key.keysym.sym == SDLK_ESCAPE)
    {

      m_running = false;
      

    }
    if ((m_event.key.keysym.sym == SDLK_a) || (m_event.button.button == SDL_BUTTON_LEFT) || (m_event.key.keysym.sym == SDLK_LEFT))
    {

      
      RunReverse();
      displayText(0, 0, 0, 1, 0, "Planet and moon are moving counterclockwise.");


    }

    if ((m_event.key.keysym.sym == SDLK_s) || (m_event.button.button == SDL_BUTTON_RIGHT) || (m_event.key.keysym.sym == SDLK_RIGHT))
    {

      
      Run();
      displayText(0, 0, 0, 1, 0, "Planet and moon are moving clockwise.");
      

    }

    
  }

}



unsigned int Engine::getDT()
{
  long long TimeNowMillis = GetCurrentTimeMillis();
  assert(TimeNowMillis >= m_currentTimeMillis);
  unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
  m_currentTimeMillis = TimeNowMillis;
  return DeltaTimeMillis;
}

long long Engine::GetCurrentTimeMillis()
{
  timeval t;
  gettimeofday(&t, NULL);
  long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
  return ret;
}

/*void Engine ::Menu(){            //Nomatter what I tried it kept giving me a linking error, literally tried
                                  // everthing to fix this and no luck. Just decided to leave off on this 
                                 //feable attempt 
ImGui::Text("Reverse Rotation");  
if (ImGui::Button("Switch"))
{
    RunReverse();
}
if (ImGui::Button("Switch Back"))
{
    Run();
}

}*/







































