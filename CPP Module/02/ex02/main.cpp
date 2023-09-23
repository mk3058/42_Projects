#include "Fixed.hpp"
#include <iostream>

// int main(void) {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));

//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max(a, b) << std::endl;
//     return 0;
// }

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "<++, -- operators test>" << std::endl;
    std::cout << "initialized: " << a << std::endl;
    std::cout << "prefix ++  : " << ++a << std::endl;
    std::cout << "current a  : " << a << std::endl;
    std::cout << "postfix ++ : " << a++ << std::endl;
    std::cout << "current a  : " << a << std::endl;
    std::cout << "prefix --  : " << --a << std::endl;
    std::cout << "current a  : " << a << std::endl;
    std::cout << "postfix -- : " << a-- << std::endl;
    std::cout << "current a  : " << a << std::endl;

    a = Fixed(10.1016f);
    std::cout << "\n<Comparison operators test>" << std::endl;
    std::cout << (a > b) << std::endl;
    std::cout << (a >= b) << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << (a <= b) << std::endl;
    std::cout << (a == b) << std::endl;

    a = Fixed(10);
    std::cout << "\n<Arithmetic operators test>" << std::endl;
    std::cout << "initialized: " << b << std::endl;
    std::cout << "+ operator : " << b + a << std::endl;
    std::cout << "- operator : " << b - a << std::endl;
    std::cout << "* operator : " << b * a << std::endl;
    std::cout << "/ operator : " << b / a << std::endl;
    // a = Fixed(0);
    // std::cout << "/ by 0     : " << b / a << std::endl;

    a = Fixed(-10.1f);
    std::cout << "\n<min/max test>" << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
}
