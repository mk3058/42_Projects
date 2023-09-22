#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
  int num;
  static const int width = 8;

 public:
  Fixed();
  Fixed(const Fixed &ref);
  Fixed &operator=(const Fixed &ref);
  ~Fixed();
  int getRawBits() const;
  void setRawBits(int const raw);
};

#endif