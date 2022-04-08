#include "Ball.hpp"
#include <stdio.h>

Ball::Ball(int radius)
{
    string path = "assets/ball.png";
    TextureManager::loadImageTexture("ball", path, Game::getRenderer());

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
    m_speed = 3;
    m_velocity.setX(2 * m_speed * (rand() % 2) - m_speed);
    m_velocity.setY(2 * m_speed * (rand() % 2) - m_speed);
}

Ball::~Ball()
{
    // SDL_DestroyTexture(m_pTexture);
    // delete m_pTexture;
}

void Ball::draw()
{
    TextureManager::drawImage("ball", m_position.getX(), m_position.getY(),
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

void Ball::speedUp()
{
    GameObject::speedUp();
    m_velocity.setX(
        m_velocity.getX() / abs(m_velocity.getX()) * m_speed);
    m_velocity.setY(
        m_velocity.getY() / abs(m_velocity.getY()) * m_speed);

}

/*Changes the direction of the ball's velocity in some axis

Args:
    direction (Side): enum to specify to what direction the ball should bounce

*/
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