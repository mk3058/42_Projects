#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
  private:
    bool isSigned;
    const std::string name;
    const int signGrade;
    const int executeGrade;
    Form();
    Form &operator=(const Form &rval);

  public:
    Form(std::string name, const int signGrade, const int executeGrade);
    Form(const Form &ref);
    ~Form();
    std::string getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    bool getIsSigned() const;
    void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif