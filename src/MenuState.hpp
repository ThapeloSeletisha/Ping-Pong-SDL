#pragma once
#include <iostream>
#include "GameStateMachine.hpp"
#include "Game.hpp"
#include "PlayState.hpp"
using namespace std;

class MenuState : public GameState
{
private:

    static const StateID s_ID;

public:

    void menuToPlay(); // callback
    void exitFromMenu(); // callback

    MenuState(){};
    virtual ~MenuState(){};
    
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual StateID getStateID() const;

};