#include "Paddle.hpp"

Paddle::Paddle(Side side)
{
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(
        Game::getRenderer(), &windowWidth, &windowHeight);
    m_side = side;
    switch (m_side)
    {
    case LEFT:
        m_position.setX(20);
        m_position.setY(windowHeight / 2 - 40);
        m_width = 15;
        m_height = 80;
        break;

    case MIDDLE:
        break;

    case RIGHT:
        m_position.setX(windowWidth - 40);
        m_position.setY(windowHeight / 2 - 40);
        m_width = 15;
        m_height = 80;
        break;

    default:
        break;
    }
    m_speed = 5;
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
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(
        Game::getRenderer(), &windowWidth, &windowHeight);
    
    m_position += m_velocity;

    // Bound paddle movement
    if (m_position.getY() < 0)
    {
        m_position.setY(0);
    }
    else if (m_position.getY() + m_height > windowHeight)
    {
        m_position.setY(windowHeight - m_height);
    }
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
        m_velocity.setY(-m_speed);
    }
    else if (down)
    {
        m_velocity.setY(m_speed);
    } else {
        m_velocity.setY(0);
    }
}

void Paddle::speedUp()
{
    GameObject::speedUp();
}