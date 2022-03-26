#include "Ball.hpp"
#include <stdio.h>
Ball::Ball(int x, int y)
{
    string path = "assets/ball.png";
    SDL_Surface* pSurface = IMG_Load(path.c_str());

    if (!pSurface)
    {
        cout << "Failed to load image" << endl;
        cout << SDL_GetError() << endl;
        return;
    }

    m_pTexture = SDL_CreateTextureFromSurface
                            (Game::getRenderer(), pSurface);
    if(!m_pTexture)
    {
        cout << "Failed to create texture" << endl;
        cout << SDL_GetError() << endl;
        return;
    }

    m_position.x = x; m_position.y = y;
    m_position.w = m_position.h = 30;
    SDL_FreeSurface(pSurface);
}

Ball::~Ball()
{
    // SDL_DestroyTexture(m_pTexture);
    // delete m_pTexture;
}

void Ball::draw()
{
    SDL_RenderCopy(Game::getRenderer(), m_pTexture, nullptr, &m_position);
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

SDL_Rect Ball::getPosition()
{
    return m_position;
}