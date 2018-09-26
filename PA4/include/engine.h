#ifndef ENGINE_H
#define ENGINE_H

#include <sys/time.h>
#include <assert.h>

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
    Engine(string name, int width, int height, char** argv);
    Engine(string name);
    ~Engine();
    bool Initialize();
    void Run();
    void RunReverse();
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
    char** lol; 





};

#endif // ENGINE_H
