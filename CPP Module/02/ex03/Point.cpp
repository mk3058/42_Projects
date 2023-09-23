#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const Point &ref) : x(ref.x), y(ref.y) {}

Point::~Point() {}

Point &Point::operator=(const Point &rval) {
    (void)rval;

    std::cout
        << "Cannot change the coordinate values. This attempt will be ignored."
        << std::endl;
    return (*this);
}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Fixed Point::getX() const { return this->x; }
Fixed Point::getY() const { return this->y; }

bool is_inside(const Vector &normal, const Vector &pointToVertex) {
    if (Vector::dotProduct(normal, pointToVertex) > 0)
        return (true);
    return (false);
}

bool Point::bsp(const Point a, const Point b, const Point c,
                const Point point) {

    Vector normalA = Vector::getNormal(Vector(a, b), Vector::OUT);
    Vector normalB = Vector::getNormal(Vector(b, c), Vector::OUT);
    Vector normalC = Vector::getNormal(Vector(c, a), Vector::OUT);
    if (is_inside(normalA, Vector(point, b)) == true &&
        is_inside(normalB, Vector(point, c)) == true &&
        is_inside(normalC, Vector(point, a)) == true)
        return (true);
    return (false);
}