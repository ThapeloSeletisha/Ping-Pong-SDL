#include "Score.hpp"

Score::Score(int points)
{
    m_points = points;

    loadTexture("score", "fonts/font.ttf", 45, to_string(m_points), 
        Game::getRenderer());
}

void Score::loadTexture(string id, string path,
        int size, string text, SDL_Renderer* renderer)
{
    SDL_Colour white = {255, 255, 255};
    TextureManager::loadTextTexture(
        id, path, white, size, text, Game::getRenderer());
}

void Score::draw()
{
    TextureManager::drawText("score", HORIZONTAL_CENTRE, 15,
        Game::getRenderer());
}

void Score::update()
{

}

void Score::clean()
{

}

void Score::handleInput()
{

}

void Score::increase()
{
    m_points++;

    cout << m_points << endl;
    TextureManager::removeTexture("score");

    loadTexture("score", "fonts/font.ttf", 45, to_string(m_points), 
        Game::getRenderer());
}