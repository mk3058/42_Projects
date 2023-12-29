#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooLowException.hpp"

const static int lowestGrade = 150;

Form::Form()
    : isSigned(false), name("none"), signGrade(lowestGrade),
      executeGrade(lowestGrade) {}

Form::Form(std::string name, const int signGrade, const int executeGrade)
    : isSigned(false), name(name), signGrade(signGrade),
      executeGrade(executeGrade) {}

Form::Form(const Form &ref)
    : isSigned(ref.getIsSigned()), name(ref.getName()),
      signGrade(ref.getSignGrade()), executeGrade(ref.getExecuteGrade()) {}

Form &Form::operator=(const Form &rval) {
    this->isSigned = rval.getIsSigned();

    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return name; }

int Form::getSignGrade() const { return signGrade; }

int Form::getExecuteGrade() const { return executeGrade; }

bool Form::getIsSigned() const { return isSigned; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->signGrade) {
        throw GradeTooLowException();
    }

    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << form.getName() << ", sign grade " << form.getSignGrade()
       << ", execute grade " << form.getExecuteGrade() << ".";

    return os;
}