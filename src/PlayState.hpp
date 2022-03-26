#pragma once
#include <iostream>
#include "GameState.hpp"
using namespace std;

class PlayState : public GameState
{
private:

    static const StateID s_ID;

public:

    PlayState(){};
    virtual ~PlayState(){};

    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();
    
    virtual StateID getStateID() const;
};