#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include "Vector.hpp"

class Point {
  private:
    const Fixed x;
    const Fixed y;
    Point &operator=(const Point &rval);

  public:
    Point();
    Point(const Point &ref);
    ~Point();
    Point(const float x, const float y);
    Fixed getX() const;
    Fixed getY() const;
    static bool bsp(const Point a, const Point b, const Point c,
                    const Point point);
};

#endif