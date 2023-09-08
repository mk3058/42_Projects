#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
 private:
  int num;
  static const int width = 8;

 public:
  Fixed();
  Fixed(const int num);
  Fixed(const float num);
  Fixed(const Fixed &ref);
  Fixed &operator=(const Fixed &ref);
  ~Fixed();
  int getRawBits() const;
  void setRawBits(int const raw);
  float toFloat() const;
  int toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &ref);

#endif