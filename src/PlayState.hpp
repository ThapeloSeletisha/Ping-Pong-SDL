#pragma once
#include <iostream>
#include "GameState.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Score.hpp"
using namespace std;

class PlayState : public GameState
{
private:

    static const StateID s_ID;
    Ball m_ball;
    Paddle m_leftPaddle, m_rightPaddle;
    Score m_score;

    void detectCollisions();
    void ballPaddleCollission(int ballRadius, Vector2D ballCentre);
    void ballEdgeCollision(int ballRadius, Vector2D ballCentre);
    bool gameOver(int ballRadius, Vector2D ballCentre);
    void speedUp();

public:

    PlayState(){};
    virtual ~PlayState(){};

    virtual void update();
    virtual void render();
    virtual void handleInput();

    virtual bool onEnter();
    virtual bool onExit();
    
    virtual StateID getStateID() const;
};