#pragma once
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "GameObject.hpp"

using namespace std;

class Score : public GameObject
{
private:
    int m_points;

    void loadTexture(string id, string path, 
        int size, string text, SDL_Renderer* renderer);
public:

    Score(int points = 0);
    ~Score(){};

    void draw();
    void update();
    void clean();
    void handleInput();

    void increase();
    int getPoints();

};