#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("") {
    std::cout << "Animal Default Constructor Called!" << std::endl;
}

Animal::Animal(const Animal &ref) : type(ref.type) {
    std::cout << "Animal Copy Constructor Called!" << std::endl;
}

Animal &Animal::operator=(const Animal &ref) {
    this->type = ref.type;
    return *this;
}

Animal::~Animal() { std::cout << "Animal Destructor Called!" << std::endl; }

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout
        << "Animal's makeSound method called. Implementation class required!"
        << std::endl;
}