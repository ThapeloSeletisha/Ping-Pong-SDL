#include "Game.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"

Game* Game::s_pInstance = nullptr;

Game::Game()
{
    m_pWindow = nullptr;
    m_pRenderer = nullptr;
    m_running = true;
}

Game* Game::Instance()
{
    if (!s_pInstance) {
        s_pInstance = new Game();
    }
    return s_pInstance;
}

bool Game::I_init(const char* title, int x, int y, int w, int h)
{
    // Initialize the SDL2 library
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        cout << "Failed to initialize SDL2" << endl;
        cout << "SDL Error: " << SDL_GetError() << endl;
        return false;
    }

    // Initialize window
    Uint32 flags = SDL_WINDOW_SHOWN;
    m_pWindow = SDL_CreateWindow(title, 
        x, y,
        w, h, flags);
    
    if(!m_pWindow)
    {
        cout << "Failed to create window" << endl;
        cout << "SDL Error: " << SDL_GetError() << endl;
        return false;
    }

    // Initialize renderer
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 
        SDL_RENDERER_ACCELERATED);

    if (!m_pRenderer)
    {
        cout << "Failed to create renderer" << endl;
        cout << "SDL Error: " << SDL_GetError() << endl;
        return false;
    }
    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

    GameStateMachine::pushState(new MenuState());

    return true;
}

/*Initializes SDL and its window and renderer

Args:
    title: The title at to be displayed on the windows navbar
    x: The horizontal position of the window in px
    y: The veritical position of the window in px
    w: The width of the window in px
    h: The height of the window in px

Returns:
    True if successful and False otherwise

*/
bool Game::init(const char* title, int x, int y, int w, int h)
{
    return Instance()->I_init(title ,x ,y ,w ,h);
}

void Game::I_render()
{
    SDL_RenderClear(m_pRenderer);
    GameStateMachine::render();
    // SDL_RenderCopy(texture)
    SDL_RenderPresent(m_pRenderer);
}

/*
*/
void Game::render()
{
    Instance()->I_render();
}

void Game::I_handleEvents()
{
    InputHandler::update();
}

/*Processes all events
*/
void Game::handleEvents()
{
    Instance()->I_handleEvents();
}

void Game::I_update()
{
    GameStateMachine::update();
}

/*
*/
void Game::update()
{
    Instance()->I_update();
}

void Game::I_clean()
{
    // empty
}

/*
*/
void Game::clean()
{
    Instance()->I_clean();
}

void Game::I_quit()
{
    m_running = false;
}

/*Starts the sequence to close the program
*/ 
void Game::quit()
{
    Instance()->I_quit();
}

SDL_Renderer* Game::I_getRenderer()
{
    return m_pRenderer;
}

/*
Args:

Returns:
    The renderer for the SDL_Window
*/ 
SDL_Renderer* Game::getRenderer()
{
    return Instance()->I_getRenderer();
}

bool Game::I_isRunning()
{
    return m_running;
}

/*
Args:

Returns:
    False if the game is to be stopped and True otherwise
*/
bool Game::isRunning()
{
    return Instance()->I_isRunning();
}