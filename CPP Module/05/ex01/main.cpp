#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat a("a", 30);
        Bureaucrat b("b", 101);
        Form form("form", 100, 30);

        a.signForm(form);
        b.signForm(form);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}