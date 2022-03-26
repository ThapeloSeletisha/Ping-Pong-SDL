#include "InputHandler.hpp"

InputHandler* InputHandler::s_pInstance = nullptr;

InputHandler::InputHandler()
{
    m_mouseButtonStates = vector<bool>(3);
    int x, y;
    SDL_GetMouseState(&x, &y);
    m_mousePosition.setX(x);
    m_mousePosition.setY(y);
}

InputHandler* InputHandler::Instance()
{
    if (!s_pInstance) {
        s_pInstance = new InputHandler();
    }
    return s_pInstance;
}

/*Updates the mouse position
*/
void InputHandler::onMouseMove(SDL_Event& e)
{
    m_mousePosition.setX(e.motion.x);
    m_mousePosition.setY(e.motion.y);
}

/*Updates mouseButtonStates for mouse down event
*/
void InputHandler::onMouseButtonDown(SDL_Event& e)
{
    if (e.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = true;
    }
    if (e.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = true;
    }
    if (e.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = true;
    }
}

/*Updates mouseButtonStates for mouse up event
*/
void InputHandler::onMouseButtonUp(SDL_Event& e)
{
    if (e.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = false;
    }
    if (e.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = false;
    }
    if (e.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = false;
    }
}

void InputHandler::I_update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                Game::quit();
                break;

            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;

            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;

            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;
        }
    }
}

/*Updates member variables when there is a new event
*/
void InputHandler::update()
{
    Instance()->I_update();
}

void InputHandler::I_clean()
{
    delete s_pInstance;
    s_pInstance = nullptr;
}

/*
*/
void InputHandler::clean()
{
    Instance()->I_clean();
}

bool InputHandler::I_getMouseButtonState(MouseButton button)
{
    return m_mouseButtonStates[button];
}

/*Checks if mouse button is down or up

Args: 
    button: enum for which mouse button to check

Returns:
    true if button is down and false otherwise
*/
bool InputHandler::getMouseButtonState(MouseButton button)
{
    return Instance()->I_getMouseButtonState(button);
}

bool InputHandler::I_isKeyDown(SDL_Scancode key)
{
    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    bool isDown = false;
    if (keyboardState)
    {
        if (keyboardState[key] == 1)
        {
            isDown = true;
        }
    }

    return isDown;
}

/*Checks if the given key is down

Args:
    key: the key that is to be checked

Returns:
    True if key is down and false otherwise
*/
bool InputHandler::isKeyDown(SDL_Scancode key)
{
    return Instance()->I_isKeyDown(key);
    /*Consider adding onKeyDown() and onKeyUp() functions
    */
}

const Vector2D& InputHandler::getMousePosition()
{
    return Instance()->m_mousePosition;
}