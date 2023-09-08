#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default Constructor Called" << std::endl;
  this->num = 0;
}

Fixed::Fixed(const int num) {
  std::cout << "Int constructor called" << std::endl;
  this->num = num << Fixed::width;
}

Fixed::Fixed(const float num) {
  std::cout << "Float constructor called" << std::endl;
  this->num = roundf(num * (1 << this->width));
}

Fixed::Fixed(const Fixed &ref) {
  std::cout << "Copy constructor called" << std::endl;
  this->num = ref.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &ref) {
  std::cout << "Copy Assignment Operator called" << std::endl;
  if (this != &ref) {
    this->num = ref.getRawBits();
  }
  return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &ref) {
  os << ref.toFloat();
  return (os);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->num);
}

void Fixed::setRawBits(int const raw) { this->num = raw; }

float Fixed::toFloat() const { return ((float)this->num / (1 << this->width)); }

int Fixed::toInt() const { return (this->num >> this->width); }