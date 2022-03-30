#include <iostream>
#include <SDL2/SDL.h>
#include "GameObject.hpp"
#include "Game.hpp"

using namespace std;

class Paddle : public GameObject
{
private:
    Side m_side;

public:
    Paddle(){};
    Paddle(Side side);
    ~Paddle(){};

    void draw();
    void update();
    void clean();
    void handleInput();
};