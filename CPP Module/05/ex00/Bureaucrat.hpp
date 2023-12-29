#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
  private:
    const std::string name;
    int grade;
    Bureaucrat();

  public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &ref);
    Bureaucrat &operator=(const Bureaucrat &rval);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void increaseGrade(int amount);
    void decreaseGrade(int amount);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref);

#endif