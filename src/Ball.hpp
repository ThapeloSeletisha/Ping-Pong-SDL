#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include "Game.hpp"
#include "GameObject.hpp"
using namespace std;

class Ball :  public GameObject
{
private:
    SDL_Texture* m_pTexture;
    SDL_Rect m_position;

public:

    Ball(int x = 0, int y = 0);
    ~Ball();

    void draw();
    void update();
    void clean();
    void handleInput();

    SDL_Rect getPosition();
};