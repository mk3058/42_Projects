#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void) {
    Point a(0, 0);
    Point b(10.0, 0);
    Point c(5.0, 10);
    Point inside(5, 1);
    Point outside(11, 1);
    Point onVertex(0, 0);
    Point onEdge(3, 0);

    std::cout << Point::bsp(a, b, c, inside) << std::endl;
    std::cout << Point::bsp(a, b, c, outside) << std::endl;
    std::cout << Point::bsp(a, b, c, onVertex) << std::endl;
    std::cout << Point::bsp(a, b, c, onEdge) << std::endl;
}
