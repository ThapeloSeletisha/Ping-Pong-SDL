#include "Vector2D.hpp"

Vector2D::Vector2D():
    m_x(-1), m_y(-1){}

Vector2D::Vector2D(double x, double y): 
    m_x(x), m_y(y){}

double Vector2D::getX() const
{
    return m_x;
}

double Vector2D::getY() const
{
    return m_y;
}

void Vector2D::setX(double x)
{
    m_x = x;
}

void Vector2D::setY(double y)
{
    m_y = y;
}

/*Returns the length of the vector
*/
double Vector2D::length()
{
    return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

/*Vector addition
*/
Vector2D Vector2D::operator+(const Vector2D& v2) const
{
    return Vector2D(m_x + v2.getX(),
        m_y + v2.getY());
}

/*Vector addition
*/
Vector2D& Vector2D::operator+=(const Vector2D& v2)
{
    m_x = m_x + v2.getX();
    m_y = m_y + v2.getY();
    return *this;
}

/*Vector scalar product
*/
Vector2D Vector2D::operator*(double scalar) const
{
    return Vector2D(m_x * scalar,
        m_y * scalar);
}

/*Vector scalar product
*/
Vector2D& Vector2D::operator*=(double scalar)
{
    m_x = m_x * scalar;
    m_y = m_y * scalar;
    return *this;
}

/*Vector difference
*/
Vector2D Vector2D::operator-(const Vector2D& v2) const
{
    return Vector2D(m_x - v2.getX(),
        m_y - v2.getY());
}

/*Vector scalar product
*/
Vector2D& Vector2D::operator-=(const Vector2D& v2)
{
    m_x = m_x - v2.getX();
    m_y = m_y - v2.getY();
    return *this;
}

/*Vector scalar division
*/
Vector2D Vector2D::operator/(double scalar) const
{
    return Vector2D(m_x / scalar,
        m_y / scalar);
}

/*Vector scalar division
*/
Vector2D& Vector2D::operator/=(double scalar)
{
    m_x = m_x / scalar;
    m_y = m_y / scalar;
    return *this;
}

Vector2D::operator string() const
{
    return to_string(m_x) + "," + to_string(m_y);
}