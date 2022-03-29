#include <iostream>
#include <SDL2/SDL.h>
#include "GameObject.hpp"
#include "Game.hpp"

using namespace std;

class Paddle : public GameObject
{
private:
    Vector2D m_position;
    int m_width, m_height;
    Side m_side;

public:
    Paddle(){};
    Paddle(Side side);

    void draw();
    void update();
    void clean();
    void handleInput();


};