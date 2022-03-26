#pragma once
#include <iostream>
#include <math.h>
#include <string> 
using namespace std;

class Vector2D
{
private:
    double m_x, m_y;

public:

    Vector2D(double x, double y);
    Vector2D();

    double getX() const, getY() const;
    void setX(double x), setY(double y);

    double length();

    Vector2D operator+(const Vector2D& v2) const;
    Vector2D& operator += (const Vector2D& v2);

    Vector2D operator*(double scalar) const;
    Vector2D& operator*=(double scalar);

    Vector2D operator-(const Vector2D& v2) const;
    Vector2D& operator -= (const Vector2D& v2);

    Vector2D operator/(double scalar) const;
    Vector2D& operator/=(double scalar);

    operator string() const;

};