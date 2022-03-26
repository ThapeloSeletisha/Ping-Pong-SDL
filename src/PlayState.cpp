#include "PlayState.hpp"
#include "MenuState.hpp"

const StateID PlayState::s_ID = PLAY;


void PlayState::update()
{
    m_ball.update();
    m_leftPaddle.update();
    m_rightPaddle.update();
}

void PlayState::handleInput()
{
    if (InputHandler::getMouseButtonState(RIGHT))
    {
        GameStateMachine::changeState(new MenuState());
    }
    m_leftPaddle.handleInput();
    m_rightPaddle.handleInput();
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