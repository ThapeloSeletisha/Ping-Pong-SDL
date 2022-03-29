#include "PlayState.hpp"
#include "MenuState.hpp"

const StateID PlayState::s_ID = PLAY;


void PlayState::update()
{
    detectCollisions();
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

void PlayState::detectCollisions()
{
    int ball_x = m_ball.getPosition().getX();
    int ball_y = m_ball.getPosition().getY();
    int ball_w = m_ball.getWidth();
    int ball_h = m_ball.getHeight();

    int leftPaddle_x = m_leftPaddle.getPosition().getX();
    int leftPaddle_y = m_leftPaddle.getPosition().getY();
    int leftPaddle_w = m_leftPaddle.getWidth();
    int leftPaddle_h = m_leftPaddle.getHeight();

    int rightPaddle_x = m_rightPaddle.getPosition().getX();
    int rightPaddle_y = m_rightPaddle.getPosition().getY();
    int rightPaddle_w = m_rightPaddle.getWidth();
    int rightPaddle_h = m_rightPaddle.getHeight();

    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(Game::getRenderer(), 
        &windowWidth, &windowHeight);

    if (ball_y < 0)
    {
        m_ball.bounce(DOWN);
    }
    if (ball_y + ball_h > windowHeight)
    {
        m_ball.bounce(UP);
    }

    
}