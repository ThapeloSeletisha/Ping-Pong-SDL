#include "Ball.hpp"
#include <stdio.h>
Ball::Ball(int x, int y, int width, int height)
{
    string path = "assets/ball.png";
    TextureManager::loadTexture("ball", path, Game::getRenderer());

    m_position.setX(x);
    m_position.setY(y);
    m_width = width;
    m_height = height;
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