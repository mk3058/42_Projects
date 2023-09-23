#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default Constructor Called" << std::endl;
    this->num = 0;
}

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << std::endl;
    this->num = num * (1 << this->width);
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    this->num = roundf(num * (1 << this->width));
}

Fixed::Fixed(const Fixed &ref) {
    std::cout << "Copy constructor called" << std::endl;
    *this = ref;
}

Fixed &Fixed::operator=(const Fixed &ref) {
    std::cout << "Copy Assignment Operator called" << std::endl;
    if (this != &ref) {
        this->num = ref.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->num);
}

void Fixed::setRawBits(int const raw) { this->num = raw; }

float Fixed::toFloat() const {
    return (static_cast<float>(this->num) / (1 << this->width));
}

std::ostream &operator<<(std::ostream &os, const Fixed &ref) {
    os << ref.toFloat();
    return (os);
}

int Fixed::toInt() const { return (this->num / (1 << this->width)); }

bool Fixed::operator>(const Fixed &rval) const {
    return (this->toFloat() > rval.toFloat());
}

bool Fixed::operator<(const Fixed &rval) const {
    return (this->toFloat() < rval.toFloat());
}
bool Fixed::operator>=(const Fixed &rval) const {
    return (this->toFloat() >= rval.toFloat());
}
bool Fixed::operator<=(const Fixed &rval) const {
    return (this->toFloat() <= rval.toFloat());
}

bool Fixed::operator==(const Fixed &rval) const {
    return (this->toFloat() == rval.toFloat());
}
bool Fixed::operator!=(const Fixed &rval) const {
    return (this->toFloat() != rval.toFloat());
}

Fixed Fixed::operator+(const Fixed &rval) const {
    return (Fixed(this->toFloat() + rval.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rval) const {
    return (Fixed(this->toFloat() - rval.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rval) const {
    return (Fixed(this->toFloat() * rval.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rval) const {
    return (Fixed(this->toFloat() / rval.toFloat()));
}

Fixed &Fixed::operator++() {
    this->num++;
    return (*this);
} // prefix

Fixed Fixed::operator++(int n) {
    Fixed tmp;
    (void)n;

    tmp.setRawBits(++this->num);
    return (tmp);
} // postfix

Fixed &Fixed::operator--() {
    this->num--;
    return (*this);
}

Fixed Fixed::operator--(int n) {
    Fixed tmp;
    (void)n;

    tmp.setRawBits(--this->num);
    return (tmp);
}

const Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a.toFloat() > b.toFloat() ? b : a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a.toFloat() > b.toFloat() ? b : a);
}

const Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a.toFloat() > b.toFloat() ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a.toFloat() > b.toFloat() ? a : b);
}