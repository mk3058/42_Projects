#include "Vector.hpp"
#include "Point.hpp"

Vector::Vector() : x(Fixed(0)), y(Fixed(0)) {}

Vector::Vector(const Vector &ref) : x(ref.x), y(ref.y) {}

Vector &Vector::operator=(const Vector &rval) {
    this->x = rval.x;
    this->y = rval.y;
    return (*this);
}

Vector::~Vector() {}

Vector::Vector(const Fixed &x, const Fixed &y) : x(x), y(y) {}

Vector::Vector(const Point &from, const Point &to) {
    this->x = to.getX() - from.getX();
    this->y = to.getY() - from.getY();
}

Fixed Vector::dotProduct(const Vector &a, const Vector &b) {
    return (Fixed(a.x * b.x + a.y * b.y));
}

Vector Vector::getNormal(const Vector &a, Direction dir) {
    return Vector(a.y * (dir), a.x * (dir * -1));
}
