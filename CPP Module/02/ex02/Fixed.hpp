#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>

class Fixed {
  private:
    int num;
    static const int width = 8;

  public:
    Fixed();
    Fixed(const Fixed &ref);
    Fixed &operator=(const Fixed &ref);
    ~Fixed();
    Fixed(const int num);
    Fixed(const float num);
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
    bool operator>(const Fixed &rval) const;
    bool operator<(const Fixed &rval) const;
    bool operator>=(const Fixed &rval) const;
    bool operator<=(const Fixed &rval) const;
    bool operator==(const Fixed &rval) const;
    bool operator!=(const Fixed &rval) const;
    Fixed operator+(const Fixed &rval) const;
    Fixed operator-(const Fixed &rval) const;
    Fixed operator*(const Fixed &rval) const;
    Fixed operator/(const Fixed &rval) const;
    Fixed &operator++();
    Fixed operator++(int n);
    Fixed &operator--();
    Fixed operator--(int n);
    static const Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &ref);

#endif