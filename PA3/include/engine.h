#ifndef ENGINE_H
#define ENGINE_H

#include <sys/time.h>
#include <assert.h>
#include <GLUT/glut.h>
#include <cstring>
#include <string.h>

#include "window.h"
#include "graphics.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "imconfig.h"
#include "imstb_rectpack.h"
#include "imstb_textedit.h"
#include "imstb_truetype.h"



class Engine
{
  public:
    Engine(string name, int width, int height);
    Engine(string name);
    ~Engine();
    bool Initialize();
    void displayText( float x, float y, int r, int g, int b, const char *string );
    void Run();
    void Runmoon();
    void RunReverse();
    void RunReversemoon();
    void Keyboard();
    unsigned int getDT();
    long long GetCurrentTimeMillis();
    void Menu();


  
  private:
    // Window related variables
    Window *m_window;   
    string m_WINDOW_NAME;
    int m_WINDOW_WIDTH;
    int m_WINDOW_HEIGHT;
    bool m_FULLSCREEN;
    SDL_Event m_event;

    Graphics *m_graphics;
    
    unsigned int m_DT;
    long long m_currentTimeMillis;
    bool m_running;





};

#endif // ENGINE_H
