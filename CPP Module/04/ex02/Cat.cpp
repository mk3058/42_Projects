#include "Cat.hpp"
#include <iostream>

static const std::string typeName = "Cat";

Cat::Cat() {
    brain = new Brain();
    this->type = typeName;
    std::cout << "Cat Default Constructor Called!" << std::endl;
}

Cat::Cat(const Cat &ref) : AbstractAnimal() {
    brain = new Brain(*ref.brain);
    this->type = ref.type;
    std::cout << "Cat Copy Constructor Called!" << std::endl;
}

Cat &Cat::operator=(const Cat &rval) {
    if (this == &rval) {
        return *this;
    }
    this->type = rval.type;
    delete brain;
    brain = new Brain(*rval.brain);

    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat Destructor Called!" << std::endl;
}

void Cat::makeSound() const { std::cout << "mewooo~" << std::endl; }

void Cat::addIdea(std::string idea) { brain->add(idea); }

std::string Cat::getIdea(unsigned int index) { return brain->get(index); }