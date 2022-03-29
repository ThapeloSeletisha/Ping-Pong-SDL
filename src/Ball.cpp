#include "Ball.hpp"
#include <stdio.h>

Ball::Ball(int radius)
{
    string path = "assets/ball.png";
    TextureManager::loadTexture("ball", path, Game::getRenderer());

    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(Game::getRenderer(),
        &windowWidth, &windowHeight);

    srand(time(0));
    int initBallY = rand() % (windowHeight - (radius * 2));

    m_position.setX(windowWidth / 2 - radius);
    m_position.setY(initBallY);

    m_width = radius * 2;
    m_height = radius * 2;

    // Randomizes between -3 and 3 for both axis
    m_velocity.setX(6 * (rand() % 2) - 3);
    m_velocity.setY(6 * (rand() % 2) - 3);
}

Ball::~Ball()
{
    // SDL_DestroyTexture(m_pTexture);
    // delete m_pTexture;
}

void Ball::draw()
{
    TextureManager::draw("ball", m_position.getX(), m_position.getY(),
        m_width, m_height, Game::getRenderer());
}

void Ball::update()
{
    m_position += m_velocity;
}

void Ball::clean()
{

}

void Ball::handleInput()
{
    
}

void Ball::bounce(Side direction)
{
    switch (direction){
        case LEFT:
            m_velocity.setX(-1 * abs(m_velocity.getX()));
            break;

        case RIGHT:
            m_velocity.setX(abs(m_velocity.getX()));
            break;

        case UP:
            m_velocity.setY(-1 * abs(m_velocity.getY()));
            break;

        case DOWN:
            m_velocity.setY(abs(m_velocity.getY()));
            break;

        default:
            break;
    }

}