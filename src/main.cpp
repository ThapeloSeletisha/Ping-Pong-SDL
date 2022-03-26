#include <iostream>
#include <SDL2/SDL.h>
#include "Game.hpp"

using namespace std;

int main(int argc, char* args[])
{
    if (!Game::init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480)) 
    {
        cout << "Failed to initialize game" << endl;
        return -1;  
    }

    while (Game::isRunning())
    {
        Game::handleEvents();
        Game::update();
        Game::render();
    }

    return 0;
}