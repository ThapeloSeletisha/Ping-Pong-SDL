#include <iostream>
#include <SDL2/SDL.h>
#include "Game.hpp"

using namespace std;

const int FPS = 60;
const int MS_PER_FRAME = 1000.0 / FPS;

Uint32 frameStart;

void frameDelay(Uint32 frameTime);

int main(int argc, char* args[])
{
    if (!Game::init("Ping Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480)) 
    {
        cout << "Failed to initialize game" << endl;
        return -1;  
    }

    
    while (Game::isRunning())
    {
        frameStart = SDL_GetTicks();

        Game::handleEvents();
        Game::update();
        Game::render();

        frameDelay(SDL_GetTicks() - frameStart);
    }

    return 0;
}

void frameDelay(Uint32 frameTime)
{
    if (frameTime < MS_PER_FRAME)
    {
        SDL_Delay((int) (MS_PER_FRAME - frameTime));
    }
}