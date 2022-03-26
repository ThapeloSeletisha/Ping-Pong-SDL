#pragma once
#include <iostream>
#include <stack>
#include <vector> 
#include "GameState.hpp"
using namespace std;

class GameStateMachine
{
private:

    static GameStateMachine* s_pInstance;
    stack <GameState*, vector<GameState*>> m_gameStates;

    GameStateMachine();
    static GameStateMachine* Instance();

    // Implementation of static functions

    void I_pushState(GameState* state);
    void I_changeState(GameState* state);
    void I_popState();

    void I_update();
    void I_render();

public:

    static void pushState(GameState* state);
    static void changeState(GameState* state);
    static void popState();

    static void update();
    static void render();
};