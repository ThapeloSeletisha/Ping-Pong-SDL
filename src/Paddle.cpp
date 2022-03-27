#include "Paddle.hpp"

Paddle::Paddle(Side side)
{
    m_side = side;
    switch (m_side)
    {
    case LEFT:
        m_position.setX(20);
        m_position.setY(50);
        m_width = 15;
        m_height = 80;
        break;

    case MIDDLE:
        cout << "Paddle may not be in the middle" << endl;
        break;

    case RIGHT:
        int w, h;
        SDL_GetRendererOutputSize(
            Game::getRenderer(), &w, &h);
        m_position.setX(w - 40);
        m_position.setY(50);
        m_width = 15;
        m_height = 80;
        break;
    }
}

void Paddle::draw()
{
    SDL_Rect dstRect;
    dstRect.x = m_position.getX();
    dstRect.y = m_position.getY();
    dstRect.w = m_width;
    dstRect.h = m_height;
    SDL_SetRenderDrawColor(Game::getRenderer(), 255, 255, 255, 255);
    SDL_RenderFillRect(Game::getRenderer(), &dstRect);
    SDL_SetRenderDrawColor(Game::getRenderer(), 0, 0, 0, 255);
}

void Paddle::update()
{
    m_position += m_velocity;
}

void Paddle::clean()
{

}

void Paddle::handleInput()
{
    bool up = InputHandler::isKeyDown(SDL_SCANCODE_UP) ||
        InputHandler::isKeyDown(SDL_SCANCODE_W);
    bool down = InputHandler::isKeyDown(SDL_SCANCODE_DOWN) ||
        InputHandler::isKeyDown(SDL_SCANCODE_S);
    if (up && down)
    {
        m_velocity.setY(0);
    }
    else if (up) {
        m_velocity.setY(-3);
    }
    else if (down)
    {
        m_velocity.setY(3);
    } else {
        m_velocity.setY(0);
    }
}

Vector2D Paddle::getPosition()
{
    return m_position;
}