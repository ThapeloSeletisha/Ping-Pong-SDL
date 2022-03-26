#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "InputHandler.hpp"
using namespace std;

class Game
{
private:

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    bool m_running;
    static Game* s_pInstance;
    
    Game();
    static Game* Instance();
    
    // Implementation functions for static functions
    bool I_init(const char* title, int x, int y, int w, int h);

    void I_render(); 
    void I_handleEvents();
    void I_update();
    
    void I_clean();
    void I_quit();

    SDL_Renderer* I_getRenderer();
    bool I_isRunning();

public:

    
    static bool init(const char* title, int x, int y, int w, int h);

    Game(Game& game) = delete; // Delete copy operator
    void operator=(const Game&) = delete; // Delete Assignment operator

    static void render();
    static void handleEvents();
    static void update();
    
    static void clean();
    static void quit();

    static SDL_Renderer* getRenderer();
    static bool isRunning();

};