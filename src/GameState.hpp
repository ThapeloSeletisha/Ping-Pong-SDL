#pragma once
#include <iostream>
using namespace std;

enum StateID 
{
    PLAY, MENU, GAMEOVER, PAUSE
};

class GameState
{
public:
    GameState(){};
    virtual ~GameState(){};

    virtual void update() = 0;
    virtual void render() = 0;

    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;

    virtual StateID getStateID() const = 0;
};