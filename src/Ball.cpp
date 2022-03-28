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
    int initBallY = rand() % (windowHeight - radius * 2);

    m_position.setX(windowWidth / 2 - radius);
    m_position.setY(initBallY);

    m_width = radius * 2;
    m_height = radius * 2;
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

}

void Ball::clean()
{

}

void Ball::handleInput()
{
    
}

Vector2D Ball::getPosition()
{
    return m_position;
}