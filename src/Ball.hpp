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

    Ball(int x = 0, int y = 0, int width = 30, int height = 30);
    ~Ball();

    void draw();
    void update();
    void clean();
    void handleInput();

    Vector2D getPosition();
};