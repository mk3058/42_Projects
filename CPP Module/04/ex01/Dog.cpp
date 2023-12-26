#include "Dog.hpp"
#include <iostream>

static const std::string typeName = "Dog";

Dog::Dog() {
    brain = new Brain();
    this->type = typeName;
    std::cout << "Dog Default Constructor Called!" << std::endl;
}

Dog::Dog(const Dog &ref) : Animal() {
    brain = new Brain(*ref.brain);
    this->type = ref.type;
    std::cout << "Dog Copy Constructor Called!" << std::endl;
}

Dog &Dog::operator=(const Dog &rval) {
    if (this == &rval) {
        return *this;
    }
    delete brain;
    brain = new Brain(*rval.brain);
    this->type = rval.type;
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog Destructor Called!" << std::endl;
}

void Dog::makeSound() const { std::cout << "bark!" << std::endl; }

void Dog::addIdea(std::string idea) { brain->add(idea); }

std::string Dog::getIdea(unsigned int index) { return brain->get(index); }