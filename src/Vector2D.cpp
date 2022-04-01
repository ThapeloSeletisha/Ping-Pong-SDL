#include "Vector2D.hpp"

Vector2D::Vector2D():
    m_x(0), m_y(0){}

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

/*Clamps the values of a point to some range

Args:
    corner_1 (Vector2D): coordinate of one corner of the rectangle
    corner_2 (Vector2D): coordinate of another corner of the rectangle
    point (Vector2D): the point which we are finding the closest point to

Returns:
    Vector2D: Returns the coordinate of the closest point on a rectangle's perimeter to some other point

*/
Vector2D Vector2D::clampVector(Vector2D corner_1, Vector2D corner_2, Vector2D point)
{
    int x = clampScalar(corner_1.getX(), corner_2.getX(), point.getX());
    int y = clampScalar(corner_1.getY(), corner_2.getY(), point.getY());
    return Vector2D(x, y);
}

/*Clamps the some value to some interval

Args:
    boundery_1 (int): the upper/lower bound of the range
    boundary_2 (int): the other bound of the range
    value (int): the value which is to be clamps

Returns:
    int: a value in the range thats closest to the given value
*/
int Vector2D::clampScalar(int boundary_1, int boundary_2, int value)
{
    if (value > max(boundary_1, boundary_2))
    {
        return max(boundary_1, boundary_2);
    }
    else if (value < min(boundary_1, boundary_2))
    {
        return min(boundary_1, boundary_2);
    }
    return value;
}

Vector2D::operator string() const
{
    return to_string(m_x) + "," + to_string(m_y);
}