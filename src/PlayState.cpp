#include "PlayState.hpp"
#include "MenuState.hpp"

const StateID PlayState::s_ID = PLAY;


void PlayState::update()
{
    if (InputHandler::getMouseButtonState(RIGHT))
    {
        GameStateMachine::changeState(new MenuState());
    }
    ball.update();
}

void PlayState::render()
{
    ball.draw();
}

bool PlayState::onEnter()
{
    ball = Ball(100, 100);
    cout << "entering PlayState" << endl;
    return true;
}

bool PlayState::onExit()
{
    return true;
}

StateID PlayState::getStateID() const
{
    return s_ID;
}