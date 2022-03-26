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

    srcRect.x = srcRect.y = 0;
    srcRect.w = pSurface->w;
    srcRect.h = pSurface->h;

    dstRect.x = x; dstRect.y = y;
    dstRect.w = dstRect.h = 30;
    SDL_FreeSurface(pSurface);
}

Ball::~Ball()
{
    // SDL_DestroyTexture(m_pTexture);
    // delete m_pTexture;
}

void Ball::draw()
{
    SDL_RenderCopy(Game::getRenderer(), m_pTexture, nullptr, &dstRect);
}

void Ball::update()
{

}

void Ball::clean()
{
    
}