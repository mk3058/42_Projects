#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default Constructor Called" << std::endl;
  this->num = 0;
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

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->num);
}

void Fixed::setRawBits(int const raw) { this->num = raw; }