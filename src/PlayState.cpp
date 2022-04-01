#include "PlayState.hpp"
#include "MenuState.hpp"

const StateID PlayState::s_ID = PLAY;


void PlayState::update()
{
    detectCollisions();
    m_ball.update();
    m_leftPaddle.update();
    m_rightPaddle.update();
}

void PlayState::handleInput()
{
    if (InputHandler::getMouseButtonState(RIGHT))
    {
        GameStateMachine::changeState(new MenuState());
    }
    m_leftPaddle.handleInput();
    m_rightPaddle.handleInput();
}

void PlayState::render()
{
    m_leftPaddle.draw();
    m_rightPaddle.draw();
    m_ball.draw();
}

bool PlayState::onEnter()
{
    m_leftPaddle = Paddle(LEFT);
    m_rightPaddle = Paddle(RIGHT);
    cout << "entering PlayState" << endl;
    return true;
}

bool PlayState::onExit()
{
    return true;
}

StateID PlayState::getStateID() const
{
    return s_ID;
}

/*Detect and handle collisions
*/
void PlayState::detectCollisions()
{
    Vector2D ballCentre;
    int ball_r = m_ball.getHeight() / 2;
    ballCentre.setX(m_ball.getPosition().getX() + ball_r);
    ballCentre.setY(m_ball.getPosition().getY() + ball_r);

    ballPaddleCollission(ball_r, ballCentre);
    ballEdgeCollision(ball_r, ballCentre);

    if (gameOver(ball_r, ballCentre))
    {
        cout << "Game over!!!" << endl;
    }
}

/*Detects and handles ball-paddle collisions

Args:
    ballRadius (int): ball radius in pixels
    ballCentre (Vector2D): vector coordinate of ball's centre
*/
void PlayState::ballPaddleCollission(int ballRadius, Vector2D ballCentre)
{
    int paddleWidth = m_leftPaddle.getWidth();
    int paddleHeight = m_leftPaddle.getHeight();

    Vector2D leftPaddleCornerTL = m_leftPaddle.getPosition();
    Vector2D leftPaddleCornerBR;
    leftPaddleCornerBR.setX(leftPaddleCornerTL.getX() + paddleWidth);
    leftPaddleCornerBR.setY(leftPaddleCornerTL.getY() + paddleHeight);

    Vector2D rightPaddleCornerTL = m_rightPaddle.getPosition();
    Vector2D rightPaddleCornerBR;
    rightPaddleCornerBR.setX(rightPaddleCornerTL.getX() + paddleWidth);
    rightPaddleCornerBR.setY(rightPaddleCornerTL.getY() + paddleHeight);

    Vector2D ballLeftPaddleClamp = Vector2D::clampVector(
        leftPaddleCornerTL, leftPaddleCornerBR, ballCentre);
    Vector2D ballRightPaddleClamp = Vector2D::clampVector(
        rightPaddleCornerTL, rightPaddleCornerBR, ballCentre);

    if ((ballLeftPaddleClamp - ballCentre).length() < ballRadius)
    {
        cout << "left paddle collision" << endl;
        if (ballLeftPaddleClamp.getX() == leftPaddleCornerBR.getX())
        {
            m_ball.bounce(RIGHT);

            if (ballLeftPaddleClamp.getY() == leftPaddleCornerTL.getY())
            {
                m_ball.bounce(UP);
            }
            else if (ballLeftPaddleClamp.getY() == leftPaddleCornerBR.getY())
            {
                m_ball.bounce(DOWN);
            }
        }
        else 
        {
            if (ballRightPaddleClamp.getY() == rightPaddleCornerTL.getY())
            {
                m_ball.bounce(UP);
            }
            else if (ballRightPaddleClamp.getY() == rightPaddleCornerBR.getY())
            {
                m_ball.bounce(DOWN);
            }
        }
    }
    else if ((ballRightPaddleClamp - ballCentre).length() < ballRadius)
    {
        cout << "right paddle collision" << endl;
        if (ballRightPaddleClamp.getX() == rightPaddleCornerTL.getX())
        {
            m_ball.bounce(LEFT);

            if (ballRightPaddleClamp.getY() == rightPaddleCornerTL.getY())
            {
                m_ball.bounce(UP);
            }
            else if (ballRightPaddleClamp.getY() == rightPaddleCornerBR.getY())
            {
                m_ball.bounce(DOWN);
            }
        }
        else
        {
            if (ballRightPaddleClamp.getY() == rightPaddleCornerTL.getY())
            {
                m_ball.bounce(UP);
            }
            else if (ballRightPaddleClamp.getY() == rightPaddleCornerBR.getY())
            {
                m_ball.bounce(DOWN);
            }
        }

    }
}

/*Detects and handles ball-window edge collisions (only for horizontal edges)

Args:
    ballRadius (int): ball radius in pixels
    ballCentre (Vector2D): vector coordinate of ball's centre
*/
void PlayState::ballEdgeCollision(int ballRadius, Vector2D ballCentre)
{
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(Game::getRenderer(), 
        &windowWidth, &windowHeight);

    Vector2D topLeft = Vector2D(0, 0);
    Vector2D topRight = Vector2D(windowWidth, 0);
    Vector2D bottomLeft = Vector2D(0, windowHeight);
    Vector2D bottomRight = Vector2D(windowWidth, windowHeight);

    Vector2D ballTopClamp = Vector2D::clampVector(topLeft, topRight, ballCentre);
    Vector2D ballBottomClamp = Vector2D::clampVector(bottomLeft, bottomRight, ballCentre);

    if ((ballTopClamp - ballCentre).length() < ballRadius)
    {
        m_ball.bounce(DOWN);
    }
    else if ((ballBottomClamp - ballCentre).length() < ballRadius)
    {
        m_ball.bounce(UP);
    }
}

/*Detects whether the ball is out of the windows bounds

Args:
    ballRadius (int): ball radius in pixels
    ballCentre (Vector2D): vector coordinate of ball's centre
*/
bool PlayState::gameOver(int ballRadius, Vector2D ballCentre)
{
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(Game::getRenderer(), 
        &windowWidth, &windowHeight);

    Vector2D topLeft = Vector2D(0, 0);
    Vector2D topRight = Vector2D(windowWidth, 0);
    Vector2D bottomLeft = Vector2D(0, windowHeight);
    Vector2D bottomRight = Vector2D(windowWidth, windowHeight);

    Vector2D ballLeftClamp = Vector2D::clampVector(topLeft, bottomLeft, ballCentre);
    Vector2D ballRightClamp = Vector2D::clampVector(topRight, bottomRight, ballCentre);

    if ((ballLeftClamp - ballCentre).length() < ballRadius)
    {
        return true;
    }
    else if ((ballRightClamp - ballCentre).length() < ballRadius)
    {
        return true;
    }

    return false;
}