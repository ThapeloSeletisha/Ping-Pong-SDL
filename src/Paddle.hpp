#include <iostream>
#include <SDL2/SDL.h>
#include "GameObject.hpp"
#include "Game.hpp"

using namespace std;

class Paddle : public GameObject
{
private:
    SDL_Rect m_position;
    Side m_side;

public:
    Paddle(){};
    Paddle(Side side);

    void draw();
    void update();
    void clean();
    void handleInput();

    SDL_Rect getPosition();

};