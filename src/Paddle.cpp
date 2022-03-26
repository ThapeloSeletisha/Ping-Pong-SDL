#include "Paddle.hpp"

Paddle::Paddle(Side side)
{
    m_side = side;
    switch (m_side)
    {
    case LEFT:
        m_position.x = 20;
        m_position.y = 50;
        m_position.w = 15;
        m_position.h = 80;
        break;

    case MIDDLE:
        cout << "Paddle may not be in the middle" << endl;
        break;

    case RIGHT:
        int w, h;
        SDL_GetRendererOutputSize(
            Game::getRenderer(), &w, &h);
        m_position.x = w - 40;
        m_position.y = 50;
        m_position.w = 15;
        m_position.h = 80;
        break;
    }
}

void Paddle::draw()
{
    SDL_SetRenderDrawColor(Game::getRenderer(), 255, 255, 255, 255);
    SDL_RenderFillRect(Game::getRenderer(), &m_position);
    SDL_SetRenderDrawColor(Game::getRenderer(), 0, 0, 0, 255);
}

void Paddle::update()
{

}

void Paddle::clean()
{

}

void Paddle::handleInput()
{

}