#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.hpp"

using namespace std;

class GameObject
{ 
protected:
    Vector2D m_position, m_velocity, m_acceleration;
    int m_width, m_height;
    
public:
    GameObject(){};
    virtual ~GameObject(){};

    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    virtual void handleInput() = 0;

    virtual Vector2D getPosition() {return m_position;};
    virtual int getWidth() {return m_width;};
    virtual int getHeight() {return m_height;};
};