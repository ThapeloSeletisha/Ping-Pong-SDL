#include "PlayState.hpp"
#include "MenuState.hpp"

const StateID PlayState::s_ID = PLAY;


void PlayState::update()
{
    if (InputHandler::getMouseButtonState(RIGHT))
    {
        GameStateMachine::changeState(new MenuState());
    }
    m_ball.update();
}

void PlayState::render()
{
    m_leftPaddle.draw();
    m_rightPaddle.draw();
    m_ball.draw();
}

bool PlayState::onEnter()
{
    m_ball = Ball(100, 100);
    m_leftPaddle = Paddle(LEFT);
    m_rightPaddle = Paddle(RIGHT);
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