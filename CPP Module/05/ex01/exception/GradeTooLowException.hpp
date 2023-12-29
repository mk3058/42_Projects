#ifndef GRADETOOLOWECXEPTION_HPP
#define GRADETOOLOWEXCEPTION_HPP

#include <exception>

class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
};

#endif