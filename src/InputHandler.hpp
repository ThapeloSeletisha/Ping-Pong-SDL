#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Vector2D.hpp"
using namespace std;

// Consider adding onKeyDown() and onKeyUp() functions

enum MouseButton
{
    LEFT, MIDDLE, RIGHT
};

class InputHandler
{
private:

    static InputHandler* s_pInstance;
    vector<bool> m_mouseButtonStates;
    Vector2D m_mousePosition;

    void onMouseMove(SDL_Event& e);
    void onMouseButtonDown(SDL_Event& e);
    void onMouseButtonUp(SDL_Event& e);

    InputHandler();
    static InputHandler* Instance();

    // Implementation of static functions
    void I_update();
    void I_clean();

    bool I_getMouseButtonState(MouseButton button);
    bool I_isKeyDown(SDL_Scancode key);

public:

    static void update();
    static void clean();

    static bool getMouseButtonState(MouseButton button);
    static bool isKeyDown(SDL_Scancode key);
    static const Vector2D& getMousePosition();

};

