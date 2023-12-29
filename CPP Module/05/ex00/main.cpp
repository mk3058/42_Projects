#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include <iostream>

int main() {
    Bureaucrat highest("highest", 1);
    Bureaucrat lowest("lowest", 150);

    try {
        std::cout << highest << std::endl;
        highest.increaseGrade(1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n";

    try {
        std::cout << lowest << std::endl;
        lowest.decreaseGrade(1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n";

    try {
        Bureaucrat invalid("invalid", -10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n";

    lowest.increaseGrade(149);
    std::cout << lowest << std::endl;

    std::cout << "\n";

    highest.decreaseGrade(149);
    std::cout << highest << std::endl;
}