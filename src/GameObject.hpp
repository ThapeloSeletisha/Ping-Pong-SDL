#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class GameObject
{ 
private:

public:
    GameObject(){};
    virtual ~GameObject(){};

    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    virtual void handleInput() = 0;
};