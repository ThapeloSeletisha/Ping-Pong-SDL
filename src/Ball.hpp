#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.hpp"
using namespace std;

class Ball 
{
private:
    SDL_Texture* m_pTexture;
    SDL_Rect srcRect, dstRect;

public:

    Ball(int x = 0, int y = 0);
    ~Ball();
    void draw();
    void update();
    void clean();
};