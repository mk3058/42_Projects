#include "Fixed.hpp"

Fixed::Fixed() { this->num = 0; }

Fixed::Fixed(const int num) { this->num = num * (1 << this->width); }

Fixed::Fixed(const float num) { this->num = roundf(num * (1 << this->width)); }

Fixed::Fixed(const Fixed &ref) { *this = ref; }

Fixed &Fixed::operator=(const Fixed &ref) {
    if (this != &ref) {
        this->num = ref.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const { return (this->num); }

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