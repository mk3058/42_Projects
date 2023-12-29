#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat {
  private:
    const std::string name;
    int grade;
    Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &rval);

  public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &ref);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void increaseGrade(int amount);
    void decreaseGrade(int amount);
    void signForm(Form &form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref);

#endif