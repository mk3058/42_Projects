#include "Dog.hpp"
#include <iostream>

static const std::string typeName = "Dog";

Dog::Dog() {
    this->type = typeName;
    std::cout << "Dog Default Constructor Called!" << std::endl;
}

Dog::Dog(const Dog &ref) : Animal() {
    this->type = ref.type;
    std::cout << "Dog Copy Constructor Called!" << std::endl;
}

Dog &Dog::operator=(const Dog &rval) {
    this->type = rval.type;
    return *this;
}

Dog::~Dog() { std::cout << "Dog Destructor Called!" << std::endl; }

void Dog::makeSound() const { std::cout << "bark!" << std::endl; }