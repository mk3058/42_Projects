#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Fixed.hpp"

class Point;

class Vector {
  private:
    Fixed x;
    Fixed y;

  public:
    Vector();
    Vector(const Vector &ref);
    Vector &operator=(const Vector &rval);
    ~Vector();
    Vector(const Fixed &x, const Fixed &y);
    Vector(const Point &from, const Point &to);
    enum Direction { IN = -1, OUT = 1 };
    static Fixed dotProduct(const Vector &a, const Vector &b);
    static Vector getNormal(const Vector &a, Direction dir);
};

#endif