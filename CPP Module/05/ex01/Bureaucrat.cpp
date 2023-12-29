#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

const static int highestGrade = 1;
const static int lowestGrade = 150;

Bureaucrat::Bureaucrat() : name("none"), grade(lowestGrade) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    if (grade < highestGrade) {
        throw GradeTooHighException();
    }
    if (grade > lowestGrade) {
        throw GradeTooLowException();
    }

    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
    : name(ref.getName()), grade(ref.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rval) {
    this->grade = rval.getGrade();

    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::increaseGrade(int amount) {
    if (amount > grade - highestGrade) {
        throw GradeTooHighException();
    }

    this->grade -= amount;
}

void Bureaucrat::decreaseGrade(int amount) {
    if (amount > lowestGrade - grade) {
        throw GradeTooLowException();
    }

    this->grade += amount;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref) {
    os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";

    return os;
}

void Bureaucrat::signForm(Form &form) const {

    try {
        form.beSigned(*this);
    } catch (GradeTooLowException &e) {
        std::cout << this->name << " couldn’t sign " << form.getName()
                  << " because '" << e.what() << "'" << std::endl;
    }

    std::cout << this->name << " signed " << form.getName() << std::endl;
}