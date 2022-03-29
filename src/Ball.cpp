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
