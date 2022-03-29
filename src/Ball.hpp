#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include "Game.hpp"
#include "GameObject.hpp"
using namespace std;

class Ball :  public GameObject
{
private:
    

public:

    Ball(int radius = 15);
    ~Ball();

    void draw();
    void update();
    void clean();
    void handleInput();

};