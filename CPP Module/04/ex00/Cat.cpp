#include "Cat.hpp"
#include <iostream>

static const std::string typeName = "Cat";

Cat::Cat() {
    this->type = typeName;
    std::cout << "Cat Default Constructor Called!" << std::endl;
}

Cat::Cat(const Cat &ref) : Animal() {
    this->type = ref.type;
    std::cout << "Cat Copy Constructor Called!" << std::endl;
}

Cat &Cat::operator=(const Cat &rval) {
    this->type = rval.type;
    return *this;
}

Cat::~Cat() { std::cout << "Cat Destructor Called!" << std::endl; }

void Cat::makeSound() const { std::cout << "mewooo~" << std::endl; }