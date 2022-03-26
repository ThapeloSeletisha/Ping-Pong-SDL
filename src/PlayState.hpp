#pragma once
#include <iostream>
#include "GameState.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
using namespace std;

class PlayState : public GameState
{
private:

    static const StateID s_ID;
    Ball ball;
    Paddle leftPaddle, rightPaddle;

public:

    PlayState(){};
    virtual ~PlayState(){};

    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();
    
    virtual StateID getStateID() const;
};