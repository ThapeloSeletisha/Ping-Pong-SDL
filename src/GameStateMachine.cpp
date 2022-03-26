# include "GameStateMachine.hpp"

#include "MenuState.hpp"
#include "PlayState.hpp"

GameStateMachine* GameStateMachine::s_pInstance = nullptr;

GameStateMachine::GameStateMachine()
{
    m_gameStates = stack<GameState*, vector<GameState*>>();
}

GameStateMachine* GameStateMachine::Instance()
{
    if (!s_pInstance)
    {
        s_pInstance = new GameStateMachine();
    }

    return s_pInstance;
}

void GameStateMachine::I_pushState(GameState* state)
{
    m_gameStates.push(state);
    m_gameStates.top()->onEnter();
}

void GameStateMachine::I_changeState(GameState* state)
{
    if (!m_gameStates.empty())
    {
        GameState* top = m_gameStates.top();

        if (top->getStateID() == state->getStateID())
        {
            return;
        }
        popState();
    }

    m_gameStates.push(state);
    m_gameStates.top()->onEnter();
}

void GameStateMachine::I_popState()
{
    if (!m_gameStates.empty())
    {
        GameState* top = m_gameStates.top();

        if (top->onExit())
        {
            m_gameStates.pop();
            top->onExit();
            delete top;
        }
    }
}

void GameStateMachine::I_update()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.top()->update();
    }
}

void GameStateMachine::I_render()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.top()->render();
    }
}

void GameStateMachine::pushState(GameState* state)
{
    Instance()->I_pushState(state);
}

void GameStateMachine::changeState(GameState* state)
{
    Instance()->I_changeState(state);
}

void GameStateMachine::popState()
{
    Instance()->I_popState();
}

void GameStateMachine::update()
{
    Instance()->I_update();
}

void GameStateMachine::render()
{
    Instance()->I_render();
}