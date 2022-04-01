#include "MenuState.hpp"
#include "InputHandler.hpp"

const StateID MenuState::s_ID = MENU;

void MenuState::menuToPlay() // callback function
{
    GameStateMachine::changeState(new PlayState());
}

void MenuState::exitFromMenu() // callback function
{
    GameStateMachine::popState();
    Game::quit();
}

void MenuState::update()
{
    
}

void MenuState::render()
{
    // empty
}

void MenuState::handleInput()
{
    if (InputHandler::getMouseButtonState(LEFT))
    {
        GameStateMachine::changeState(new PlayState());
    }
}

bool MenuState::onEnter()
{
    cout << "entering MenuState" << endl;
    return true;
}

bool MenuState::onExit()
{
    return true;
}

StateID MenuState::getStateID() const
{
    return s_ID;
}